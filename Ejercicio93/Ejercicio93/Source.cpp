// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "treemap_eda.h"

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int linea, arg =0, lineaN = 10;
    std::string ins;
    map<int, std::pair<std::string, int>> d;
    map<int, int> actualizacion;

        std::cin >> linea;
    while (linea != 0) {
        std::cin >> ins;
        if(ins != "RETURN")
        std::cin >> arg;
        d.insert({ linea, {ins, arg} });
        actualizacion.insert({linea, lineaN});
        lineaN += 10;
        std::cin >> linea;

    }

    for (auto it = d.cbegin(); it != d.cend(); ++it) {
        if (it->valor.first != "RETURN")
            std::cout << actualizacion.find(it->clave)->valor << " " << it->valor.first << " " << actualizacion.find(it->valor.second)->valor << std::endl;
        else
            std::cout << actualizacion.find(it->clave)->valor << " " << it->valor.first << std::endl;
    }
    std::cout << "---" <<std::endl;
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