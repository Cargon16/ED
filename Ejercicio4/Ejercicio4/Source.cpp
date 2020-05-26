// Nombre del alumno Carlos González Torres
// Usuario del Juez F26


#include <iostream>
#include <iomanip>
#include <fstream>
#include "polinomio.h"
#include <cmath>

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int exp, coef, evaluar;
    polinomio p;
    std::cin >> coef;
    if (!std::cin)
        return false;

    std::cin >> exp;
    while (coef != 0 || exp != 0) {
        if (coef != 0) {
            p.addMonomio(coef, exp);
        }
        std::cin >> coef >> exp;
    }
   
    std::cin >> evaluar;
    std::vector<int> valores(evaluar);
    for (int i = 0; i < evaluar; ++i) {
        std::cin >> valores[i];
    }
    for (int i = 0; i < evaluar - 1; ++i) {
        std::cout << p.evaluar(valores.at(i)) << " ";
    }
    // escribir sol
    std::cout << p.evaluar(valores.at(valores.size()-1)) << std::endl;

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