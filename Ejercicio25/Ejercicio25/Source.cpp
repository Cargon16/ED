// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

bool esPrimo(int numero) {
    // Casos especiales
    if (numero == 0 || numero == 1 || numero == 4) return false;
    for (int x = 2; x < numero / 2; x++) {
        if (numero % x == 0) return false;
    }
    // Si no se pudo dividir por ninguno de los de arriba, sí es primo
    return true;
}

// función que resuelve el problema
void resolver(const bintree<int> &a, int altura, std::pair<int, int> &sol) {
    std::pair<int, int> iz = { -1, -1 }, der = { -1, -1 };
    if (!a.empty()) {
        if (a.left().empty() && a.right().empty()) {
            if (a.root() % 7 == 0 && (altura + 1 < sol.second || sol.second == -1) && !esPrimo(a.root())) {
                sol.first = a.root();
                sol.second = altura + 1;
            }
        }
        else {
            if (!a.left().empty() && !esPrimo(a.root()) )
                resolver(a.left(), altura + 1, iz);
            if (!a.right().empty() && !esPrimo(a.root()))
                resolver(a.right(), altura + 1, der);

            if (iz.first != -1) {
                sol.first = iz.first;
                sol.second = iz.second;
            }
            else {
                sol.first = der.first;
                sol.second = der.second;
            }
            if (a.root() % 7 == 0 && (altura + 1 < sol.second || sol.second == -1) && !esPrimo(a.root())) {
                sol.first = a.root();
                sol.second = altura + 1;
            }
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> a;
    a = leerArbol(-1);
    std::pair<int, int> p = { -1, -1 };
    int altura = 0;
    resolver(a, altura, p);
    if (p.first == -1) std::cout << "NO HAY" << std::endl;
    else std::cout << p.first << " " << p.second << std::endl;


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