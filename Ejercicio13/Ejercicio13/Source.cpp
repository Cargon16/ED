// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "deque_eda.h"

template <class T>
class listaExt :public deque<T> {
    using Nodo = typename deque<T>::Nodo;

public :
    void mostrar() {
        Nodo* act = this->fantasma->sig;
        while (act != this->fantasma) {
            std::cout << act->elem << " ";
            act = act->sig;
        }
        std::cout << std::endl;
    }

    void reordenar() {
        Nodo* act = this->fantasma->sig;
        Nodo* menor = this->fantasma->sig;
        Nodo* aux = nullptr;

        while (act != this->fantasma) {
            if (act->elem <= menor->elem && act != menor) {
                aux = act->sig;
                menor->ant->sig = act;
                act->ant->sig = act->sig;
                act->sig->ant = act->ant;
                act->ant = menor->ant;
                menor->ant = act;
                act->sig = menor;
                menor = act;

                act = aux;
            }
            else act = act->sig;
        }
    }

};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tam;
    std::cin >> tam;

    if (tam ==0)
        return false;

    listaExt<int> cola;
    int num;
    for (int i = 0; i < tam; ++i) {
        std::cin >> num;
        cola.push_back(num);
    }
    // escribir sol
    cola.reordenar();
    cola.mostrar();

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