// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue_eda.h"


struct horas {
    int horas;
    int minutos;
    int segundos;
};

int segundos(horas& h) {
    return h.horas * 3600 + h.minutos * 60 + h.segundos;
}

template <class T>
class listaExt :public queue<T> {
    using Nodo = typename queue<T>::Nodo;
public:
    void eliminaDecrec() {
        Nodo* act = this->prim;
        Nodo* ant = this->prim;
        int mayor = 0;

        while (act != nullptr) {
            int seg = segundos(act->elem);
            if (seg >= mayor) {
                mayor = seg;
                ant = act;
                act = act->sig;
            }
            else {
                ant->sig = act->sig;
                this->nelems--;
                act = ant->sig;
                
            }
        }
    }

    void mostrar() {
        Nodo* act = this->prim;
        horas h;
        while (act != nullptr) {
            h = act->elem;
            std::cout << std::setfill('0') << std::setw(2) << h.horas << ":" << std::setfill('0') << std::setw(2) << h.minutos << ":" << std::setfill('0') << std::setw(2) << h.segundos << " ";
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

    std::cin >> tam;
    if (tam == 0)
        return false;
    
    listaExt<horas> l;
    horas h;
    for (int i = 0; i < tam; i++) {
        std::cin >> h.horas; std::cin.ignore(); std::cin >> h.minutos; std::cin.ignore(); std::cin >> h.segundos;
        l.push(h);
    }

    l.eliminaDecrec();
    l.mostrar();

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