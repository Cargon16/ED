// Nombre del alumno Carlos González Torres
// Usuario del Juez F26


#include <iostream>
#include <iomanip>
#include <fstream>
#include "stack_eda.h"
#include <vector>

struct accidente {
    std::string Fecha;
    int victimas;
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int lineas;
    bool encontrado = false;

    std::cin >> lineas;
    if (!std::cin)
        return false;

    std::vector<accidente> v(lineas);
    stack<accidente>  anteriores;
    for (int i = 0; i < lineas; ++i)
        std::cin >> v[i].Fecha >> v[i].victimas;

    for (int j = 0; j < lineas; ++j) {
        encontrado = false;
        if (anteriores.empty()) {
            std::cout << "NO HAY" << std::endl;
            anteriores.push(v[j]);
        }
        else {
            while (!anteriores.empty() && !encontrado) {
                if (anteriores.top().victimas <= v[j].victimas)
                    anteriores.pop();
                else encontrado = true;
            }
            if (encontrado) std::cout << anteriores.top().Fecha << std::endl;
            else std::cout << "NO HAY" << std::endl;

            anteriores.push(v[j]);
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