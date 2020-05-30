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
    void mostrar() {
        Nodo* act = this->fantasma->sig;
        while (act != this->fantasma) {
            std::cout << act->elem << " ";
            act = act->sig;
        }
        std::cout << std::endl;
    }

    void intercalar(listaExt<int>& cola) {
        Nodo* act1 = this->fantasma->sig;
        Nodo* act2 = cola.fantasma->sig;
        Nodo* aux = nullptr;

        if (!cola.empty()) {
            while (act1 != this->fantasma) {
                aux = act2->sig;
                act2->sig = act1->sig;
                act2->sig->ant = act2;
                act1->sig = act2;
                act2->ant = act1;
                this->nelems++;

                act1 = act2->sig;
                act2 = aux;
            }
            if (act2 != cola.fantasma) {
                this->fantasma->ant->sig = act2;
                cola.fantasma->ant->sig = this->fantasma;
                this->fantasma->ant = cola.fantasma->ant;
                this->fantasma->ant->sig = this->fantasma;
            }
        }
        if (this->empty()) this->copia(cola);
    }
    void destruye() {
        this->fantasma->sig = nullptr;
        this->nelems = 0;
     }


};
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int tam, num;
    listaExt<int> cola;
    listaExt<int> cola2;

    std::cin >> tam;
    for (int i = 0; i < tam; ++i) {
        std::cin >> num;
        cola.push_back(num);
    }
    std::cin >> tam;
    for (int i = 0; i < tam; ++i) {
        std::cin >> num;
        cola2.push_back(num);
    }
    cola.intercalar(cola2);
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