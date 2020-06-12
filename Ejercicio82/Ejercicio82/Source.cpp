// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

// función que resuelve el problema
int resolver(const bintree<int> &a, int &navegar, bool primero) {
    int iz = 0, der = 0;
    if (a.left().empty() && a.right().empty()) return 1;
    if (!a.left().empty() || !a.right().empty()) {
        if (!a.left().empty())
            iz = resolver(a.left(), navegar, false);
        if (!a.right().empty())
            der = resolver(a.right(), navegar, false);
        if (iz + der - a.root() >= 3 && !primero) navegar++;
        if (iz + der - a.root() >= 0)  return iz + der - a.root();
        else return 0;
       
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> a;
    a = leerArbol(-1);
    int navegar = 0;
    bool primero = true;

    if(!a.empty()) 
    resolver(a, navegar, primero);
    std::cout << navegar << std::endl;


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