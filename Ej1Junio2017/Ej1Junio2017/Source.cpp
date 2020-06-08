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
    int num, pos, dist;

    std::cin >> num;
    if (num == -1)
        return false;

    queue<int> q;
    while (num != -1) {
        q.push(num);
        std::cin >> num;
    }

    std::cin >> pos >> dist;
    if (pos < 1 || pos > q.size()) std::cout << "Posicion inexistente" << std::endl;
    else
        if (dist > 0) {
            q.desplaza(pos, dist);
            q.mostrar();
        }


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