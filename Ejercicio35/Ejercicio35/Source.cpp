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
    std::string orden;

    std::cin >> orden;
    if (!std::cin)
        return false;

    carnet c;
    while (orden != "FIN") {

        try {
            if (orden == "nuevo") {
                std::string dni;
                std::cin >> dni;
                c.nuevo(dni);
            }
            if (orden == "cuantos_con_puntos") {
                int puntos;
                std::cin >> puntos;
                int p = c.cuantos_con_puntos(puntos);
                std::cout << "Con " << puntos << " puntos hay " << p << std::endl;
            }
            if (orden == "quitar") {
                std::string dni;
                int puntos;
                std::cin >> dni >> puntos;
                c.quitar(dni, puntos);
            }
            if (orden == "consultar") {
                std::string dni;
                std::cin >> dni;
                int p = c.consultar(dni);
                std::cout << "Puntos de " << dni << ": " << p << std::endl;
            }
            if (orden == "recuperar") {
                std::string dni;
                int puntos;
                std::cin >> dni >> puntos;
                c.recuperar(dni, puntos);
            }
            if (orden == "lista_por_puntos") {
                int p;
                std::cin >> p;
                list<std::string> l = c.lista_por_puntos(p);
                std::cout << "Tienen " << p << " puntos:";
                for (auto it= l.cbegin(); it != l.cend(); ++it)
                    std::cout << " " << *it;
                std::cout << std::endl;
            }

        }
        catch (std::domain_error e) {
            std::cout << "ERROR: " << e.what() << std::endl;
        }

        std::cin >> orden;
    }
    std::cout << "---" << std::endl;


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