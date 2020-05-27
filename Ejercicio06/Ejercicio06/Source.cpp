// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "stack_eda.h"
#include <string>


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    std::string frase;

    std::getline(std::cin, frase);
    if (!std::cin)
        return false;

    bool correcto = true;
    int i = 0;
    stack<char> pila;
    while (correcto && i < frase.size()) {
        if (frase.at(i) == '(' || frase.at(i) == '{' || frase.at(i) == '[') pila.push(frase.at(i));
        else {
            if (frase.at(i) == ')' || frase.at(i) == '}' || frase.at(i) == ']') {
                if (!pila.empty()) {
                    if (frase.at(i) == ')' && pila.top() == '(') pila.pop();
                    else
                    if (frase.at(i) == '}' && pila.top() == '{') pila.pop();
                    else
                    if (frase.at(i) == ']' && pila.top() == '[') pila.pop();
                    else correcto = false;
                }
                else correcto = false;
            }
        }
        ++i;
    }
    if (correcto) std::cout << "SI" << std::endl;
    else std::cout << "NO" << std::endl;
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