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
    std::string orden, s, a;
    int d;

    std::cin >> orden;
    if (!std::cin)
        return false;

    ipud p;

    while (orden != "FIN") {
        try {
            if (orden == "addSong") {
                std::cin >> s >> a >> d;
                p.addSong(s, a, d);
            }
            if (orden == "addToPlaylist") {
                std::cin >> s;
                p.addToPlaylist(s);
            }
            if (orden == "play") {
                std::string n = p.play();
                std::cout << "Sonando " << n << std::endl;
            }
            if (orden == "totalTime") {
                int n = p.totalTime();
                std::cout << "Tiempo total " << n << std::endl;
            }
            if (orden == "deleteSong") {
                std::cin >> s;
                p.deleteSong(s);
            }
            if (orden == "recent") {
                list<std::string> l;
                std::cin >> d;
                l = p.recent(d);
                std::cout << "Las " << l.size() << " mas recientes" << std::endl;
                for (auto it = l.cbegin(); it != l.cend(); ++it)
                    std::cout << "    " << *it << std::endl;
            }
            if (orden == "current") {
                p.current();
            }
        }
        catch (std::exception& e) {
            std::cout << e.what() << std::endl;
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