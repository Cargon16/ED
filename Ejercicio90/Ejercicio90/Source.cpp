// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "hashmap_eda.h"

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tam, num;

    std::cin >> tam;
    if (!std::cin)
        return false;

    std::vector<int> v;
    unordered_map<int, int> d;
    for (int i = 0; i < tam; ++i) {
        std::cin >> num;
        if (d.find(num) != d.end()) ++d[num];
        else {
            d[num] = 1;
            v.push_back(num);
        }
    }

    for (auto it = v.cbegin(); it != v.cend(); ++it)
        std::cout << *it << " " << d.find(*it)->valor << std::endl;

    std::cout << "---" << std::endl;

    // escribir sol


    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}