// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "set_eda.h"


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    char tipo;
    int k;
    std::cin >> tipo;
    if (!std::cin)
        return false;

    std::cin >> k;
    if (tipo == 'P') {
        std::string p ="";
        set<std::string> s;

        std::cin >> p;
        while (p != "FIN") {
            s.insert(p);
            std::cin >> p;
        }
    }
    else {
        int n;
        set<int> s;

        std::cin >> n;
        while (n != -1) {
            s.insert(n);
            std::cin >> n;
        }
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