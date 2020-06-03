// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "list_eda.h"


// función que resuelve el problema
list<int> resolver(list<int> &l, int inf, int sup) {
    list<int> q;
    for (int i = inf; i <= sup; ++i) q.push_back(i);
    auto it = q.begin();
    for (auto j = l.begin(); j != l.end(); ++j) {
        if (*j <= sup) {
            while (it != q.end() && *it != *j) ++it;
            if(it != q.end())
            q.erase(it);
            it = q.begin();
        }
    }

    return q;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int num, inf, sup;

    std::cin >> num;
    if (!std::cin)
        return false;

    list<int> l;
    while (num != 0) {
        l.push_back(num);
        std::cin >> num;
    }
    std::cin >> inf >> sup;
    
    l = resolver(l, inf, sup);
    for (auto it = l.begin(); it != l.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

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