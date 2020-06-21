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
    int numOp, n;
    std::string orden, x;
    ventaLibros v;

    std::cin >> numOp;
    if (!std::cin)
        return false;

    for (int i = 0; i < numOp; ++i) {
        std::cin >> orden;
        try{
            if (orden == "nuevoLibro") {
                std::cin >> n;
                std::cin.ignore();
                std::getline(std::cin, x);
                v.nuevoLibro(n, x);
            }
            if (orden == "comprar") {
                std::cin.ignore();
                std::getline(std::cin, x);
                v.comprar(x);
            }
            if (orden == "numEjemplares") {
                std::cin.ignore();
                std::getline(std::cin, x);
                int num = v.numEjemplares(x);
                std::cout << "Existen " << num << " ejemplares del libro " << x << std::endl;
            }
            if (orden == "top10") {
                list<std::string> l = v.top10();
                std::cout << "TOP10" << std::endl;
                for (auto it = l.cbegin(); it != l.cend(); ++it)
                    std::cout << "    " << *it << std::endl;
            }
            if (orden == "estaLibro") {
                std::cin.ignore();
                std::getline(std::cin, x);
                bool ok = v.estaLibro(x);
                if (ok)
                    std::cout << "El libro " << x << " esta en el sistema" << std::endl;
                else
                    std::cout << "No existe el libro " << x  << " en el sistema" << std::endl;
            }
            if (orden == "elimLibro") {
                std::cin.ignore();
                std::getline(std::cin, x);
                v.elimLibro(x);
            }
        }
        catch (std::exception e) {
            std::cout << e.what() << std::endl;
        }
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