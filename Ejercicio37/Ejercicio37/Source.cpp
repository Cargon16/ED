// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "Header.h"


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    std::string orden, a, p;
    int n;

    std::cin >> orden;
    if (!std::cin)
        return false;

    autoescuela ac;

    while (orden != "FIN") {
        try {
            if (orden == "alta") {
                std::cin >> a >> p;
                ac.alta(a, p);
            }
            if (orden == "es_alumno") {
                std::cin >> a >> p;
                bool b = ac.es_alumno(a, p);
                if (b) std::cout << a << " es alumno de " << p << std::endl;
                else std::cout << a << " no es alumno de " << p << std::endl;
            }
            if (orden == "puntuacion") {
                std::cin >> a;
                int p = ac.puntuacion(a);
                std::cout << "Puntuacion de " << a << ": " << p << std::endl;
            }
            if (orden == "actualizar") {
                std::cin >> a >> n;
                ac.actualizar(a, n);
            }
            if (orden == "aprobar") {
                std::cin >> a;
                ac.aprobar(a);
            }
            if (orden == "examen") {
                std::cin >> p >> n;
                list<std::string> l = ac.examen(p, n);
                std::cout << "Alumnos de " << p << " a examen:" << std::endl;
                for (auto it = l.cbegin(); it != l.cend(); ++it)
                    std::cout << *it << std::endl;
            }
        }
        catch (std::exception& e) {
            std::cout << "ERROR" << std::endl;
        }
        std::cin >> orden;
    }
    std::cout << "---" << std::endl;
    

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