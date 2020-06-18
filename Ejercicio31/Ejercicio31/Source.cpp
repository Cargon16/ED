// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "treemap_eda.h"

std::string toLowerCase(std::string& s) {
    std::string aux;
    for (int i = 0; i < s.size(); ++i) {
        aux.push_back(tolower(s[i]));
    }

    return aux;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int num, linea = 1;
    std::string s, p;
    std::stringstream s1;
    map<std::string, std::vector<int>> d;
    bool puede = true;

    std::cin >> num;
    if (num == 0) return false;

    std::cin.ignore();
    for (int i = 0; i < num; ++i) {
        std::getline(std::cin, s);
        std::stringstream s1(s);
        while (s1 >> p) {
            if (d.find(toLowerCase(p)) != d.end() && d.find(toLowerCase(p))->valor.at(d.find(toLowerCase(p))->valor.size() - 1) != linea)
                d.find(toLowerCase(p))->valor.push_back(linea);
            else {
                if (p.size() > 2) {
                    std::vector<int>v;
                    v.push_back(linea);
                    d.insert({ toLowerCase(p) , v });
                }
            }
        }
        linea++;
    }
    for (auto it = d.cbegin(); it != d.cend(); ++it) {
        std::cout << it->clave << " ";
        for (auto it2 = it->valor.cbegin(); it2 != it->valor.cend(); ++it2)
            std::cout << *it2 << " ";
        std::cout << std::endl;
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


    
    while(resuelveCaso());


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}