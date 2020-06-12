// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "bintree_eda.h"

// función que resuelve el problema
int resolver(const bintree<char> &a, int &maximo) {
    int hIz = 0, hDer = 0;
    if (a.empty()) return 0;
    else
    if (a.left().empty() && a.right().empty()) {
        if (maximo < 1) maximo = 1;
        return 1;
    }
    else
    if (!a.left().empty() || !a.right().empty()) {
        if(!a.left().empty())
        hIz = resolver(a.left(), maximo);
        if(!a.right().empty())
        hDer = resolver(a.right(), maximo);

        if (hIz > 0 && hDer > 0 && hIz == hDer) {
            if (maximo < hIz+1) maximo = hIz + 1;
            return hIz + 1;
        }
        else {
            if (maximo < std::max(hIz, hDer)) maximo = std::max(hIz, hDer);
            return std::min(hIz, hDer) + 1;
        }
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<char> a;
    a = leerArbol('.');
    int maximo = 0;
    int altura = resolver(a, maximo);
    std::cout << maximo << std::endl;

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