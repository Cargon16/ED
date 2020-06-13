// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "set_eda.h"

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tam, num;

    
    std::cin >> tam;
    if (tam == 0)
        return false;

    set<int>s;
    for (int i = 0; i < tam; ++i) {
        std::cin >> num;
        s.insert(num);
    }
    std::cin >> tam;
    std::pair<bool, int> p;
    for (int i = 0; i < tam; i++) {
        std::cin >> num;
        p = s.lower_bound(num);
        if (p.first)
            std::cout << p.second << std::endl;
        else std::cout << "NO HAY" << std::endl;
    }
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