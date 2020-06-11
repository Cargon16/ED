// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include "bintree_eda.h"


// función que resuelve el problema
bintree<int> construyeABusqueda(std::vector<int> &v, int ini, int fin) {
    bintree<int> iz, der;
    if (ini > fin) return {};
    else {
        int pos = ini + 1;
        while (pos <= fin && v[pos] < v[ini]) pos++;

        iz = construyeABusqueda(v, ini + 1, pos - 1);
        der = construyeABusqueda(v, pos, fin);
        return { iz, v[ini], der };
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    std::string linea;

    std::getline(std::cin, linea);
    if (!std::cin)
        return false;

    int pos;
    std::stringstream s(linea);
    std::vector<int> v;
    while (s >> pos) {
        v.push_back(pos);
    }

    // escribir sol
    int ini = 0, fin = v.size()-1;
    bintree<int> a = construyeABusqueda(v, ini, fin);
    v = a.postorder();
    for (int i = 0; i < v.size(); i++) std::cout << v[i] << " ";
    std::cout << std::endl;

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