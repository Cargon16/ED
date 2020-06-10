// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include "bintree_eda.h"

bintree<int> construyeArbol(std::vector<int> &preorden, std::vector<int> &inorden, int pini, int pfin, int iini, int ifin) {
    if (pini > pfin) return {};
    else {

        int raiz = preorden[pini];
        int posRaizInorden = std::distance(inorden.begin()+ iini,std::find(inorden.begin() + iini, inorden.begin() + ifin, raiz));
        bintree<int> izq = construyeArbol(preorden, inorden, pini + 1, pini + posRaizInorden, iini, iini + posRaizInorden - 1);
        bintree<int> der = construyeArbol(preorden, inorden, pini + posRaizInorden + 1, pfin, iini + posRaizInorden + 1, ifin);

        return { izq, raiz, der };
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    std::string linea;
    int num;

    getline(std::cin, linea);
    if (!std::cin)
        return false;
    
    std::stringstream s(linea);
    std::vector<int> preorden;
    std::vector<int> inorden;

    while (s >> num) { 
        preorden.push_back(num); 
    }

    getline(std::cin, linea);
    std::stringstream s1(linea);
    while (s1 >> num) {
        inorden.push_back(num);
    }
    int pini = 0, pfin = preorden.size() - 1, iini = 0, ifin = inorden.size() - 1;
    bintree<int> a = construyeArbol(preorden, inorden, pini, pfin, iini, ifin);

    std::vector<int> v = a.postorder();

    for (int i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
    }
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