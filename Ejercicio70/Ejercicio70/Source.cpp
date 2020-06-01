// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue_eda.h"

template <class T>
class listaExt :public queue<T> {
    using Nodo = typename queue<T>::Nodo;

public:
    void intercambio() {
        Nodo* act = this->prim;
        Nodo* ant = nullptr;
        Nodo* aux = nullptr;
        if(this->size() > 1)
        for(int i =0; i < this->size()/ 2; ++i){
            aux = act->sig;
            act->sig = aux->sig;
            aux->sig = act;
            if (ant == nullptr) {
                this->prim = aux;
            }
            else {
                ant->sig = aux;
            }
            ant = act;
            act = act->sig;
        }
        if (this->size() % 2 != 0)
            this->ult = act;
        else this->ult = ant;
    }

    void mostrar() {
        Nodo* act = this->prim;
        while (act != nullptr) {
            std::cout << act->elem << " ";
            act = act->sig;
        }
        std::cout << std::endl;
    }


};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tam, num;

    std::cin >> tam;
    if (tam == 0)
        return false;

    listaExt<int> l;
    for (int i = 0; i < tam; ++i) {
        std::cin >> num;
        l.push(num);
    }
    l.intercambio();
    l.mostrar();

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