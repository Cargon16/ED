// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

struct valores {
    int min = -1;
    int max = -1;
};

valores esArboldeBusqueda(const bintree<int>& a) {
    valores vD, vI;
    if (a.left().empty() && a.right().empty()) return { a.root(), a.root() };
    if (!a.left().empty() && !a.right().empty()) {
        vI = esArboldeBusqueda(a.left());
        vD = esArboldeBusqueda(a.right());

        if (vI.max >= a.root() || vD.min <= a.root()) return { -1, -1 };
        if (vD.min == -1 || vI.max == -1) return { -1, -1 };
        else return { std::min(vI.min, vD.min),  std::max(vI.max, vD.max)};
    }
    else {
        if (a.left().empty()) {
            vD = esArboldeBusqueda(a.right());
            if (vD.max == -1 || vD.min <= a.root()) return { -1, -1 };
            else return { std::min(vD.min, a.root()), vD.max };
        }
        else {
            vI = esArboldeBusqueda(a.left());
            if (vI.max == -1 || vI.max >= a.root()) return { -1, -1 };
            else return { vI.min, std::max(vD.min, a.root()) };
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> a;
    a = leerArbol(-1);
    valores d;
    if (a.empty())std::cout << "SI" << std::endl;
    else {
        valores v = esArboldeBusqueda(a);
        if(v.max != -1 && v.min != -1) std::cout << "SI" << std::endl;
        else
        std::cout << "NO" << std::endl;
    }
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