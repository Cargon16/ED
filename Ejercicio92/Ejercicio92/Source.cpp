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
    int tam;

    std::cin >> tam;
    if (tam == 0)
        return false;

    unordered_map<int, int> d;
    int c;
    for (int i = 0; i < tam; ++i) {
        std::cin >> c;
        d.insert({c, 0});
    }
    for (auto it = d.begin(); it != d.end();) {
        if (it->clave % 2 == 0)
            it = d.erase(it);
        else ++it;
    }
    for (auto it = d.cbegin(); it != d.cend(); ++it)
        if (it->clave % 2 == 0) exit(EXIT_FAILURE);

    std::cout << "TODO BIEN" << std::endl;


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