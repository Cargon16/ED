// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

int esGenealogico(const bintree<int> &a, int &edad, int &maximo) {
    int edadIz, edadDer;
    int alturaIz = 0, alturaDer=0;
    if (a.left().empty() && a.right().empty()) {
        edad = a.root();
        if (maximo < 1) maximo = 1;
        return 1;
    }
    if (a.left().empty()) {
        return -1;
    }
    if (a.right().empty()) {
        alturaIz += esGenealogico(a.left(), edadIz, maximo);
        if (edadIz != -1 && a.root() - edadIz >= 18) {
            alturaIz += 1;
            if (alturaIz > maximo) maximo = alturaIz;
            edad = a.root();
            return alturaIz;
        }
        else return -1;
    }
    else {
        alturaIz = esGenealogico(a.left(), edadIz, maximo);
        alturaDer = esGenealogico(a.right(), edadDer, maximo);

        if (alturaIz == -1 || alturaDer == -1) return -1;
        if (edadIz - edadDer < 2) return -1;
        if (a.root() - edadDer >= 18 && a.root() - edadIz >= 18) {
            int alt = std::max(alturaDer, alturaIz);
            alt += 1;
            if (alt > maximo) maximo = alt;
            edad = a.root();
            return alt;
        }
        else return -1;

    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> a;
    a = leerArbol(-1);
    int altura = 0, maximo = 0;
    if(a.empty()) std::cout << "SI " << maximo << std::endl;
    else {
        int altura = esGenealogico(a, altura, maximo);
        if (altura == -1) std::cout << "NO" << std::endl;
        else std::cout << "SI " << maximo << std::endl;
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