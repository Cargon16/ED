// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "deque_eda.h"

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta

void resolver(deque<int> &cola, int coger, int n) {
    deque<int> aux;
    int mayor = -1, i = 0;

    for (int j = 0; j < (n - coger + 1); ++j) {
        if (coger != 1) {
            while (i < coger && !cola.empty()) {
                if (mayor < cola.front()) mayor = cola.front();
                while (!aux.empty() && aux.front() < cola.front()) {
                    aux.pop_front();
                }
                aux.push_back(cola.front());
                cola.pop_front();
                i++;
            }
            std::cout << mayor << " ";
            i = aux.size();
            if (aux.size() == coger && !cola.empty()) {
                i = coger - 1;
                aux.pop_front();
                mayor = aux.front();
            }
        }
        else {
            std::cout << cola.front() << " ";
            cola.pop_front();
        }

    }
    std::cout << std::endl;
}
bool resuelveCaso() {
    // leer los datos de la entrada
    int sobres, num, sobre;

    std::cin >> sobres >> num;

    if (sobres == 0 && num == 0)
        return false;

    deque<int> cola;
    for (int i = 0; i < sobres; ++i) {
        std::cin >> sobre;
        cola.push_back(sobre);
    }
    
    resolver(cola, num, sobres);

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