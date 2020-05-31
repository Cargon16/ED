// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "list_eda.h"
#include <string>
#include <algorithm>


struct persona {
    int edad;
    std::string nombre;
};
template <class T>
class listaExt :public list<T> {

public:
    template <class Predicate>
    void elimina_if(Predicate pred) {
        auto it = this->begin();
        persona p;
        while (it != this->end()) {
            if (!pred(*it)) it = this->erase(it);
            else ++it;
        }
    }


};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int p, min, max;

    std::cin >> p >> min >> max;
    if (p ==0 && min ==0 && max == 0)
        return false;

    int edad;
    std::string nombre;
    listaExt<persona> l;
    persona a;
    for (int i = 0; i < p; i++) {
        std::cin >> a.edad;
        std::cin.ignore();
        std::getline(std::cin, a.nombre);
        l.push_back(a);
    }
    
    l.elimina_if([max, min](persona &p) {return p.edad >= min && p.edad <= max; });
    for (int i = 0; i < l.size(); i++) {
        std::cout << l.at(i).nombre << std::endl;
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