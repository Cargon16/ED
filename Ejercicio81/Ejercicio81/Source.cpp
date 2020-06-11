// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

// función que resuelve el problema
bool resolver(const bintree<char> &iz, const bintree<char> &der) {
    if (iz.empty() && !der.empty())
        return false;
    if (!iz.empty() && der.empty())
        return false;
    if (iz.empty() && der.empty()) return true;
    else
        return resolver(iz.left(), der.right()) && resolver(iz.right(), der.left());

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<char> a;
    a = leerArbol('.');

    if (resolver(a.left(), a.right())) std::cout << "SI" << std::endl;
    else std::cout << "NO" << std::endl;
    // escribir sol


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