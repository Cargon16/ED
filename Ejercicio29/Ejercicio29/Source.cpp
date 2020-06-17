// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "hashmap_eda.h"

// función que resuelve el problema
int resolver(const std::vector<int> &v) {
    unordered_map<int, int> m;
    int max = 0, pos = 1, actual = 0, ini = 1;
    for (int i = 1; i <= v.size(); ++i) {
        if (m[v[i-1]] >= ini) {
            ini = m[v[i-1]] + 1;
            actual = i - m[v[i-1]];
        }
        else {
            ++actual;
            if (actual > max)
                max = actual;
        }
        m[v[i-1]] = i;
    }
    return max;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int episodios;
    int capitulo;
    std::vector<int> v;

    std::cin >> episodios;
    for (int i = 0; i < episodios; ++i) {
        std::cin >> capitulo;
        v.push_back(capitulo);
    }

    std::cout << resolver(v) << std::endl;
    // escribir sol


}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}