// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>



// función que resuelve el problema
int resolver(int k, int nivel) {
    int hijos, cont =0;
    std::cin >> hijos;
    if (hijos == 0) {
        if (nivel >= k) return 1;
        else return 0;
    }
    else {
        for(int i =0; i < hijos; ++i)
        cont += resolver(k, nivel + 1);
    }

    return cont;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int k;

    std::cin >> k;
    if (!std::cin)
        return false;

    std::cout << resolver(k, 0) << std::endl;

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