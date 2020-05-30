// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include<string>
#include "stack_eda.h"
#include "list_eda.h"

void transformaAX1(list<char> &l) {
    auto it = ++l.begin();
    auto it2 = l.end();
    int cont = 1;
   while(cont < l.size()){
        it2 = l.insert(it2, *it);
        it = l.erase(it);
        ++it;
        cont = cont + 2;
    }
}
void transformaAX(list<char> &l) {
    stack<char> pila;
    auto it = l.begin();
    auto it2= l.begin();
    while(it != l.end()){
        while (it != l.end() && tolower(*it) != 'a' && tolower(*it) != 'e' && tolower(*it) != 'i' && tolower(*it) != 'o' && tolower(*it) != 'u') {
            pila.push(*it);
            ++it;
        }
        while (!pila.empty()) {
            l.insert(it2, pila.top());
            pila.pop();
            it2 = l.erase(it2);
        }
        if (it != l.end()) {
            it++;
            it2++;
        }
    }
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    char c;

    std::cin.get(c);

    if (!std::cin)
        return false;

    list<char> l;
    auto it = l.end();
    while(c != '\n'){
        l.insert(it, c);
        std::cin.get(c);
    }
    if (!l.empty()) {
        transformaAX1(l);
        transformaAX(l);
    }
    for (int i = 0; i < l.size(); ++i) {
        std::cout << l.at(i);
    }
    std::cout << std::endl;
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