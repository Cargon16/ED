// Nombre del alumno Carlos González Torres
// Usuario del Juez F26


#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue_eda.h"

template <class T>
class listaExt :public queue<T> {
    using Nodo = typename queue<T>::Nodo;

public:
    void imprime() {
        Nodo *aux = this->prim;
        while (aux != nullptr) {
            std::cout << aux->elem << " ";
            aux = aux->sig;
        }
        std::cout << std::endl;
    }

    void duplicarLista() {
        Nodo* aux = this->prim;
        Nodo* nuevo = nullptr;
        for (int i = 0; i < this->size(); i= i+2) {
            nuevo = new Nodo(aux->elem, aux->sig);
            aux->sig = nuevo;
            aux = nuevo->sig;
            this->nelems++;
        }
        this->ult = nuevo;
    }


};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int num;
    listaExt<int> cola;
    std::cin >> num;

    if (!std::cin)
        return false;

    while (num != 0) {
        cola.push(num);
        std::cin >> num;
    }

    cola.duplicarLista();
    cola.imprime();

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