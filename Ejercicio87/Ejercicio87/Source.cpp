// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

// función que resuelve el problema
void resolver(const bintree<int> &a, int &actual, int &maximo) {
    int aIz = 0, aDer = 0;
    if (!a.empty()) {
        if (a.left().empty() && a.right().empty()) {
            if (a.root() % 2 == 0) actual++;
            if (actual > maximo) maximo = actual;
        }
        else
            if (!a.left().empty() || !a.right().empty()) {
                if (!a.left().empty()) {
                    resolver(a.left(), aIz, maximo);
                }
                if (!a.right().empty()) {
                    resolver(a.right(), aDer, maximo);
                }
            }
                if (a.root() % 2 == 0) {
                    if (aIz != 0 && aDer != 0 && aIz + aDer + 1 > maximo) maximo = aIz + aDer + 1;
                    else {
                        if(maximo < std::max(aIz, aDer) + 1)
                        maximo = std::max(aIz, aDer) + 1;
                    }
                    actual = std::max(aIz, aDer) + 1;
                }
                else {
                    if (maximo < std::max(aIz, aDer)) maximo = std::max(aIz, aDer);
                    actual = 0;
                }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    bintree<int> a;
    a = leerArbol(-1);
    int actual = 0, maximo = 0;
    resolver(a, actual, maximo);
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