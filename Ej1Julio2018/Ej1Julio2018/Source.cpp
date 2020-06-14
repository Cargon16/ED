// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

// función que resuelve el problema
int resolver(const bintree<int> &a, int &cont) {
    int iz = 0, der = 0;
    if (!a.empty()) {
        if (a.left().empty() && a.right().empty()) {
            return a.root();
        }
        if (!a.left().empty() || !a.right().empty()) {
            if (!a.left().empty()) {
                iz = resolver(a.left(), cont);
            }
            if (!a.right().empty()) {
                der = resolver(a.right(), cont);
            }
            if (iz + der == a.root()) cont++;
            return iz + der + a.root();
        }
    }
    else return 0;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> a;
    a = leerArbol(-1);
    int cont = 0;
    resolver(a, cont);

    std::cout << cont << std::endl;

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