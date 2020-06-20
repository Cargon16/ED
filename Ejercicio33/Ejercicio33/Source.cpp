// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "hashmap_eda.h"

struct tProblema{
    int intentos = 0;
    std::string resultado;
    int tiempo;
};
struct tResultado {
    std::string equipo;
    int proResueltos = 0;
    int tiempo=0;
};
bool compFirst(const tResultado& a, const tResultado &b) {
    if (a.proResueltos == b.proResueltos) {
        if (a.tiempo == b.tiempo) {
            return a.equipo < b.equipo;
        }
        else return a.tiempo < b.tiempo;
    }
    else {
        return a.proResueltos > b.proResueltos;
    }
}
// función que resuelve el problema
std::vector<tResultado>  resolver(const unordered_map<std::string, unordered_map<std::string, tProblema>> &d) {
    std::vector<tResultado> l;
    for (auto it = d.cbegin(); it != d.cend(); ++it) {
        tResultado r;
        r.equipo = it->clave;
        for (auto it2 = d.find(it->clave)->valor.cbegin(); it2 != d.find(it->clave)->valor.cend(); ++it2) {
            if (it2->valor.resultado == "AC") {
                r.tiempo += it2->valor.tiempo + ((it2->valor.intentos - 1) * 20);
                r.proResueltos++;
            }
        }
        l.push_back(r);
    }
    std::sort(l.begin(), l.end(), compFirst);
    return l;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    unordered_map<std::string, unordered_map<std::string, tProblema>> d;
    std::string equipo, ejercicio, resultado;
    int tiempo;

    std::cin >> equipo;
    while (equipo != "FIN") {
        std::cin >> ejercicio >> tiempo >> resultado;
        if (d.find(equipo) == d.end()) {
            tProblema p = { 1, resultado, tiempo };
            unordered_map<std::string, tProblema> aux; aux.insert({ejercicio, p});
            d.insert({ equipo, aux });
        }
        else {
            if (d.find(equipo)->valor.find(ejercicio) == d.find(equipo)->valor.end()) {
                tProblema p = { 1, resultado, tiempo };
                d.find(equipo)->valor.insert({ ejercicio, p });
            }
            else {
                if (d.find(equipo)->valor.find(ejercicio)->valor.resultado != "AC") {
                    d.find(equipo)->valor.find(ejercicio)->valor.intentos++;
                    d.find(equipo)->valor.find(ejercicio)->valor.resultado = resultado;
                    d.find(equipo)->valor.find(ejercicio)->valor.tiempo = tiempo;
                }
            }
        }
        std::cin >> equipo;
    }
    std::vector<tResultado> l = resolver(d);
    for (auto it = l.cbegin(); it != l.cend(); ++it) {
        std::cout << it->equipo << " " << it->proResueltos << " " << it->tiempo << std::endl;
    }
    std::cout << "---" << std::endl;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}