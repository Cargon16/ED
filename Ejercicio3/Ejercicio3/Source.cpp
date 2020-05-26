// Nombre del alumno Carlos González Torres
// Usuario del Juez F26


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Complejo.h"


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int itera, i =0;
    float parteR, parteI;
    std::cin >> parteR >> parteI >> itera;
    complejo z = complejo(0, 0);
    complejo c = complejo(parteR, parteI);
    while (z.modulo() <= 2 && i < itera) {
        z = (z * z) + c;
        i++;
    }

    if (i == itera) std::cout << "SI" << std::endl;
    else std::cout << "NO" << std::endl;
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