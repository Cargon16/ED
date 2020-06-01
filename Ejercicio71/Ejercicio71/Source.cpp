// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue_eda.h"

struct horas {
    int hora;
    int minutos;
    int segundos;
};

template <class T>
class listaExt :public queue<T> {
    using Nodo = typename queue<T>::Nodo;

public:
    void eliminarPares() {
        Nodo* act = this->prim;
        Nodo* ant = this->prim;
        int cont = 0;
        while (act != nullptr) {
            if (cont % 2 != 0) {
                ant->sig = act->sig;
                ant = act->sig;
                
                this->nelems--;
            }
            act = act->sig;
            cont++;
        }
        if(this->size() %2 == 0)
        this->ult = ant;
    }

    void mostrar() {
        Nodo* act = this->prim;
        horas h;
        while (act != nullptr) {
            h = act->elem;
            std::cout << std::setfill('0') << std::setw(2) << h.hora << ":" << std::setfill('0') << std::setw(2) << h.minutos << ":" << std::setfill('0') << std::setw(2) << h.segundos << " ";
            act = act->sig;
        }
        std::cout << std::endl;
    }




};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tam;
    horas h;
    std::cin >> tam;

    if (tam == 0)
        return false;

    listaExt<horas> q;
    for (int i = 0; i < tam; ++i) {
        std::cin >> h.hora; std::cin.ignore(); std::cin >> h.minutos; std::cin.ignore(); std::cin >> h.segundos;
        q.push(h);
    }

    q.eliminarPares();
    q.mostrar();

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