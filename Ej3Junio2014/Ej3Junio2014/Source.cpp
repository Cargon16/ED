// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

// función que resuelve el problema
void resolver(const bintree<std::string> &a, int cont, int &max, std::string &nombre) {
    if (!a.empty()) {
        if (a.left().empty() && a.right().empty()) {
            if (cont < max || max == 0) {
                nombre = a.root();
                max = cont;
            }
        }
        else {
            if (a.root() == "Dragon") cont = cont + 1;
            if (!a.left().empty())
                resolver(a.left(), cont, max, nombre);
            if (!a.right().empty())
                resolver(a.right(), cont, max, nombre);
        }
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<std::string> a;
    std::string cent = "#";
    a = leerArbol(cent);

    int cont = 0, max = 0;
    std::string nombre;

    resolver(a, cont, max, nombre);
    std::cout << nombre << std::endl;


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