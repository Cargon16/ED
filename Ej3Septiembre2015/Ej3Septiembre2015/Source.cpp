// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

// función que resuelve el problema

template <typename T>
bool coinciden(const bintree<T>& a, const std::vector<T>& pre, std::vector<int>::const_iterator &it) {
    bool iz = true, der = true;
    if (a.empty() || it == pre.cend()) return a.empty() && pre.empty();
    if (a.left().empty() && a.right().empty())
        return a.root() == *it;

    if (a.root() != *it) return false;
    if (!a.left().empty()) {
        iz = coinciden(a.left(), pre, ++it);
    }
    if (!a.right().empty()) der = coinciden(a.right(), pre, ++it);

    return iz && der;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> a;
    std::vector<int> pre;

    a = leerArbol(-1);
    int tam, num;
    std::cin >> tam;

    for (int i = 0; i < tam; ++i) {
        std::cin >> num;
        pre.push_back(num);
    }
    std::vector<int>::const_iterator it = pre.cbegin();
    if (coinciden(a, pre, it)) std::cout << "SI" << std::endl;
    else std::cout << "NO" << std::endl;


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