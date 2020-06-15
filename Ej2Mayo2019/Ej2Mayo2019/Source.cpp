// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

// función que resuelve el problema
bool resolver(const bintree<int>& a, int suma, int& maximo, bool ancestro) {
    bool iz = true, der = true;
    if (a.empty()) return false;
    if (a.left().empty() && a.right().empty()) {
        if (ancestro && maximo < suma + a.root()) maximo = suma + a.root();
        return suma + a.root() > 0 && ancestro;
    }

    if (!a.left().empty() && ancestro) 
        iz = resolver(a.left(), suma + a.root(), maximo, ancestro && suma+a.root() > 0);
    if (!a.right().empty() && ancestro)
        der = resolver(a.right(), suma + a.root(), maximo, ancestro && suma + a.root() > 0);

    return iz || der;

}
/*bool resolver(const bintree<int> &a, int suma, int &maximo, bool ancestro) {
    bool iz = false, der = false;
    int maximoIz = 0, maximoDer = 0;
    if (a.left().empty() && a.right().empty()) {
        if (ancestro && maximo < suma + a.root()) maximo = suma + a.root();
        return suma + a.root() > 0 && ancestro;
    }
    if (!a.left().empty()) {
        if(ancestro && suma + a.root() > 0)
        iz = resolver(a.left(), suma + a.root(), maximoIz, true);
        else
            iz = resolver(a.left(), suma + a.root(), maximoIz, false);
    }
    if (!a.right().empty()) {
        if (ancestro && suma + a.root() > 0)
            der = resolver(a.right(), suma + a.root(), maximoDer, true);
        else
            der = resolver(a.right(), suma + a.root(), maximoDer, false);
    }
    if (iz && der) {
        maximo = std::max(maximoIz, maximoDer);
        return true;
    }
    else {
        if (iz || der) {
            if (iz) maximo = maximoIz;
            else maximo = maximoDer;
            return true;
        }
        else return false;
    }
}
*/
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> a;
    a = leerArbol(0);
    int suma = 0, maximo = 0;
    bool ancestro = true;

    if (resolver(a, suma, maximo, ancestro))
        std::cout << "SI " << maximo << std::endl;
    else 
        std::cout << "NO " << std::endl;

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