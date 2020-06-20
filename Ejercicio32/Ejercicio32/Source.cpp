// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "hashmap_eda.h"
#include <string>
#include <algorithm>

bool esMayus(std::string& p) {
    return (std::tolower(p[0]) != p[0]);
}
bool compFirst(const std::pair<std::string, int> &a, const std::pair<std::string, int> &b) { 
    if (a.second == b.second) return a.first < b.first;
    else
    return a.second > b.second; 
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    std::string deporte;

    std::cin >> deporte;
    if (!std::cin)
        return false;

    std::string nombre;
    unordered_map<std::string, int> d;
    unordered_map<std::string, std::string> p;

    while (deporte != "_FIN_") {
        d.insert({ deporte, 0 });
        std::cin >> nombre;
        while (!esMayus(nombre) && nombre != "_FIN_") {
            if (p.find(nombre) == p.end()) {
                p.insert({ nombre, deporte });
                d.find(deporte)->valor++;
            }
            else {
                if (p.find(nombre)->valor != "BORRADO" && p.find(nombre)->valor != deporte) {
                    d.find(p.find(nombre)->valor)->valor--;
                    p.find(nombre)->valor = "BORRADO";
                }
            }
            std::cin >> nombre;
        }
        deporte = nombre;
    }
    // escribir sol
    std::vector<std::pair<std::string, int>> l;
    for (auto it = d.cbegin(); it != d.cend(); ++it)
        l.push_back({it->clave, it->valor});
    std::sort(l.begin(), l.end(), compFirst);

    for (auto it = l.cbegin(); it != l.cend(); ++it)
        std::cout << it->first << " " << it->second << std::endl;

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