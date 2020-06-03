// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "deque_eda.h"

template <class T>
class listaExt :public deque<T> {
    using Nodo = typename deque<T>::Nodo;

public:
    void engordar(listaExt<int>& cola) {
        Nodo* act2 = cola.fantasma->sig;
        Nodo* aux = nullptr;
        bool orden = true;

        while (!cola.empty()) {
            aux = act2->sig;
            if (orden) {
                this->fantasma->sig->ant = act2;
                act2->sig = this->fantasma->sig;
                this->fantasma->sig = act2;
                act2->ant = this->fantasma;
                orden = false;
            }
            else {
                this->fantasma->ant->sig = act2;
                act2->ant = this->fantasma->ant;
                this->fantasma->ant = act2;
                act2->sig = this->fantasma;
                orden = true;
            }
            cola.nelems--;
            act2 = aux;
        }
    }

    void mostrar() {
        Nodo* act = this->fantasma->sig;
        while (act != this->fantasma) {
            std::cout << act->elem << " ";
            act = act->sig;
        }
        std::cout << std::endl;
    }

    void destruye() {
        this->fantasma->sig = nullptr;
        this->nelems = 0;
    }


};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tam, num;

    std::cin >> tam;
    if (!std::cin)
        return false;

    listaExt<int> l;
    for (int i = 0; i < tam; i++) {
        std::cin >> num;
        l.push_back(num);
    }
    
    std::cin >> tam;
    listaExt<int> l2;
    for (int i = 0; i < tam; i++) {
        std::cin >> num;
        l2.push_back(num);
    }
    // escribir sol
    l.engordar(l2);
    l.mostrar();
    l2.destruye();
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