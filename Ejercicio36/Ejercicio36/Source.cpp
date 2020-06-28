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
    int numOp, dia, h, min;
    std::string orden, m, p;
    consultorio c;

    std::cin >> numOp;
    if (!std::cin)
        return false;

    for (int i = 0; i < numOp; ++i) {
        std::cin >> orden;
        try {
            if (orden == "nuevoMedico") {
                std::cin >> m;
                c.nuevoMedico(m);
            }
            if (orden == "pideConsulta") {
                std::cin >> p >> m >> dia >> h; std::cin.ignore(); std::cin >> min;
                Fecha f = Fecha(dia, h, min);
                c.pideConsulta(p, m, f);
            }
            if (orden == "listaPacientes") {
                std::cin >> m >> dia;
                std::vector<std::pair<std::string, Fecha>> l = c.listaPacientes(m, dia);
                std::cout << "Doctor " << m << " dia " << dia << std::endl;
                for (auto it = l.cbegin(); it != l.cend(); ++it) {
                    Fecha f = it->second;
                    std::cout << it->first << " " << std::setfill('0') << std::setw(2) << f.getHora() << ":" << std::setfill('0') << std::setw(2) << f.getMin() << std::endl;
                }
            }
            if (orden == "siguientePaciente") {
                std::cin >> m;
                std::string pac = c.siguientePaciente(m);
                std::cout << "Siguiente paciente doctor " << m << std::endl;
                std::cout << pac << std::endl;
            }
            if (orden == "atiendeConsulta") {
                std::cin >> m;
                c.atiendeConsulta(m);
            }
        }
        catch (std::exception& e) {
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