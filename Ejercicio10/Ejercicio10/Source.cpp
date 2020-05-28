// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue_eda.h"


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tam, num, pos;

    std::cin >> tam;

    if (!std::cin)
        return false;

    queue<int> cola;
    queue<int> colaAux;

    for (int i = 0; i < tam; ++i) {
        std::cin >> num;
        cola.push(num);
    }

    std::cin >> tam >> pos;
    for (int i = 0; i < tam; ++i) {
        std::cin >> num;
        colaAux.push(num);
    }

    cola.insertar(colaAux, pos);
    cola.mostrar();
    colaAux.destruye();

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