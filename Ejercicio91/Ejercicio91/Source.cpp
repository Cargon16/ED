// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "hashmap_eda.h"
#include "treemap_eda.h"

struct tSolucion {
    int veces=0;
    std::string pelicula;
    int minutos =0;
    std::vector<std::string> act;
};

// función que resuelve el problema
tSolucion resolver(const unordered_map<std::string, unordered_map<std::string, int>> &d, const unordered_map<std::string, int> &frecuencia, const std::vector<std::string> &v) {
    tSolucion s;
    map<std::string, int> actores;
    for (auto it = v.cbegin(); it != v.cend(); ++it) {
        if (frecuencia.find(*it)->valor >= s.veces) {
            s.veces = frecuencia.find(*it)->valor;
            s.pelicula = *it;
        }
    }
    for (auto it = d.cbegin(); it != d.cend(); ++it) {
        int tiempo = 0;
        for (auto it2 = it->valor.cbegin(); it2 != it->valor.cend(); ++it2) {
            if(frecuencia.find(it2->clave) != frecuencia.cend())
            tiempo += it2->valor * frecuencia.find(it2->clave)->valor;
        }
        actores.insert({it->clave, tiempo});
        if (s.minutos < tiempo) s.minutos = tiempo;
    }
    for (auto it = actores.cbegin(); it != actores.cend(); ++it)
        if (s.minutos == it->valor) s.act.push_back(it->clave);

    return s;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int pelis;

    std::cin >> pelis;
    if (pelis == 0)
        return false;

    unordered_map<std::string, unordered_map<std::string, int>> d;
    unordered_map<std::string, int> frecuencia;
    std::string titulo, actor;
    int numActores, minutos, pPuestas;

    for (int i = 0; i < pelis; i++) {
        std::cin >> titulo >> numActores;
        for (int j = 0; j < numActores; ++j) {
            std::cin >> actor >> minutos;
            d[actor].insert({ titulo, minutos });
        }
    }

    std::vector<std::string> v;
    std::cin >> pPuestas;
    for (int i = 0; i < pPuestas; ++i) {
        std::cin >> titulo;
        v.push_back(titulo);
        frecuencia[titulo]++;
    }

    tSolucion s = resolver(d, frecuencia, v);
    std::cout << s.veces << " " << s.pelicula << std::endl;
    std::cout << s.minutos << " ";
    for (auto it = s.act.cbegin(); it != s.act.cend(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;


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