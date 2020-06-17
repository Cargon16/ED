// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "treemap_eda.h"
#include "list_eda.h"

// función que resuelve el problema
list<std::pair<std::string, int>> resolver(const map<std::string, list<std::string>> &m) {
    list<std::pair<std::string, int>> l;
    for (auto it = m.cbegin(); it != m.cend(); ++it) {
        int resultado = 0;
        for (auto it2 = it->valor.cbegin(); it2 != it->valor.cend(); ++it2) {
            if (*it2 == "INCORRECTO") resultado -= 1;
            else resultado += 1;
        }
        if(resultado != 0)
        l.push_back({ it->clave, resultado });
    }
    return l;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numEjercicios;

    std::cin >> numEjercicios;
    if (numEjercicios == 0)
        return false;

    map<std::string, list<std::string>> m;
    std::string nombre, estado;
    for (int i = 0; i < numEjercicios; ++i) {
        list<std::string> l;
        std::cin.ignore();
        std::getline(std::cin, nombre);
        std::cin >> estado;

        if (m.count(nombre) != 0)
            m.find(nombre)->valor.push_back(estado);
        else {
            l.push_back(estado);
            m.insert({ nombre, l });
        }
        
    }

    list<std::pair<std::string, int>> r = resolver(m);
    for (auto it = r.cbegin(); it != r.cend(); ++it)
        std::cout << it->first << ", " << it->second << std::endl;

    std::cout << "---" << std::endl;
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