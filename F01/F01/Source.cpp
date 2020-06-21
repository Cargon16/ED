// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "hashmap_eda.h"
#include <vector>
#include <sstream>
#include <string>


// función que resuelve el problema
std::vector<std::string> resolver(unordered_map < std::string, unordered_map<int, bool>> &d, unordered_map<std::string, int> &conteo, std::vector<int> &bingo) {
    std::vector<std::string> v;
    bool ganador = false;
    int i = 0;
    while (!ganador && i < bingo.size()) {
        for (auto it = d.begin(); it != d.end(); ++it) {
            if (it->valor.find(bingo[i]) != it->valor.end()) {
                it->valor.find(bingo[i])->valor = true;
                conteo.find(it->clave)->valor--;
                if (conteo.find(it->clave)->valor == 0) {
                    v.push_back(it->clave);
                    ganador = true;
                }
            }
        }
        i++;
    }
    return v;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int jugadores;

    std::cin >> jugadores;
    if (jugadores == 0)
        return false;

    unordered_map < std::string, unordered_map<int, bool>> d;
    unordered_map<std::string, int> conteo;
    std::vector<int> numeros;
    std::string nombre, bingo;
    int num;

    for (int i = 0; i < jugadores; ++i) {
        std::cin >> nombre >> num;
        while (num != 0) {
            d[nombre].insert({ num, false });
            conteo[nombre]++;
            std::cin >> num;
        }
    }
    std::cin.ignore();
    std::getline(std::cin, bingo);
    std::stringstream s(bingo);
    while (s >> num) {
        numeros.push_back(num);
    }

    std::vector<std::string> v = resolver(d, conteo, numeros);
    std::sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i)
        std::cout << v[i] << " ";
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