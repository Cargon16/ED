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
    void mezclaOrdenada(listaExt<int>& cola) {
        Nodo* act1 = this->prim;
        Nodo* act2 = cola.prim;
        Nodo* aux = nullptr;
        Nodo* ant = nullptr;

        if (this->empty()){
			//this->copia(cola);
			this->prim = cola.prim;
			this->nelems = cola.nelems;
			this->ult = cola.ult;
		}
        else {
            while (act1 != nullptr) {
                while (act2 != nullptr && act1->elem >= act2->elem) {
                    if (act1->elem >= act2->elem) {
                        aux = act2->sig;
                        act2->sig = act1;
                        if (ant != nullptr)
                            ant->sig = act2;
                        else
                            this->prim = act2;

                        ant = act2;
                        act2 = aux;
                        this->nelems++;
                    }
                }
                ant = act1;
                act1 = act1->sig;
            }
            if (act2 != nullptr && act2->elem >= this->ult->elem) {
                this->ult->sig = act2;
                this->ult = cola.ult;
            }
        }


    }
    void mostrar() {
        Nodo* aux = this->prim;
        while (aux != nullptr) {
            std::cout << aux->elem << " ";
            aux = aux->sig;
        }
        std::cout << std::endl;
    }
    void destruye() {
        this->prim = nullptr;
        this->ult = nullptr;
        this->nelems = 0;
    }
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int num;
    listaExt<int> cola;
    listaExt<int> cola2;
    std::cin >> num;
    while (num != 0) {
        cola.push(num);
        std::cin >> num;
    }

    std::cin >> num;
    while (num != 0) {
        cola2.push(num);
        std::cin >> num;
    }

    cola.mezclaOrdenada(cola2);
    cola.mostrar();
    cola.destruye();
    cola2.destruye();


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