// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "bintree_eda.h"

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    char tipo;

    std::cin >> tipo;
    if (!std::cin)
        return false;

    if (tipo == 'N') {
        bintree<int> a;
        a = leerArbol(-1);
        std::cout << a.menorElemento();
    }
    else {
        std::string fin = "#";
        bintree<std::string> a = leerArbol(fin);
        std::cout << a.menorElemento();
    }
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