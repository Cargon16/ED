// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include "treemap_eda.h"
#include "list_eda.h"

// función que resuelve el problema
void resolver(map<std::string, std::pair<std::string, char>> &d, const map<std::string, std::string> &d2, list<std::string> &add, list<std::string>& del, list<std::string>& mod) {
    for (auto it = d2.cbegin(); it != d2.cend(); ++it) {
        //char c = it->clave;
        if (d.find(it->clave) == d.end()) { 
            d.insert({ it->clave, {it->valor, '+' } }); 
        }
        else {
            if (d.find(it->clave)->valor.first != it->valor) d.find(it->clave)->valor.second = '*';
            if (d.find(it->clave)->valor.first == it->valor) d.find(it->clave)->valor.second = '/';
        }
    }
    for (auto it2 = d.begin(); it2 != d.end(); ++it2) {
        if (it2->valor.second == '-') del.push_back(it2->clave);
        if(it2->valor.second == '+') add.push_back(it2->clave);
        if (it2->valor.second == '*') mod.push_back(it2->clave);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    map<std::string, std::pair<std::string, char>> d;
    map<std::string, std::string> d2;
    list<std::string> add, mod, del;
    
    std::string s, c, v;
    std::getline(std::cin, s);
    std::stringstream s1(s);
    while (s1 >> c) {
        s1 >> v;
        d.insert({ c, {v, '-' }});
    }
    std::getline(std::cin, s);
    std::stringstream s2(s);
    while (s2 >> c) {
        s2 >> v;
        d2.insert({ c, v});
    }

    resolver(d, d2, add, del, mod);
    if (add.empty() && del.empty() && mod.empty()) std::cout << "Sin cambios" << std::endl;
    else {
        if (!add.empty()) {
            std::cout << "+ ";
            for (auto it = add.cbegin(); it != add.cend(); ++it) std::cout << *it << " ";
            std::cout << std::endl;
        }
        if (!del.empty()) {
            std::cout << "- ";
            for (auto it = del.cbegin(); it != del.cend(); ++it) std::cout << *it << " ";
            std::cout << std::endl;
        }
        if (!mod.empty()) {
            std::cout << "* ";
            for (auto it = mod.cbegin(); it != mod.cend(); ++it) std::cout << *it << " ";
            std::cout << std::endl;
        }
    }
    std::cout << "---" << std::endl;


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
    std::cin.ignore();
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}