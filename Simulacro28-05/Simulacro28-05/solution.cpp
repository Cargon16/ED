/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 */

/*
 * Nombre y apellidos: Carlos González Torres
 */

#include <iostream>
#include <fstream>
#include "deque_eda.h"

template<typename T>
class deque_partition : public deque<T> {
  protected:
    using Nodo = typename deque<T>::Nodo;

  private:
    // Declara aquí métodos auxiliaries, si
    // los necesitas

  public:

    // Implementa aquí el método pedido
    void partition(int pivot) {
        Nodo* aux = this->fantasma->sig;
        Nodo* menor = nullptr;
        Nodo* mayor = nullptr;
        Nodo* sig = this->fantasma->sig;
        while (aux != this->fantasma) {
            if (aux->elem <= pivot) {
                if (menor != nullptr && menor->sig != aux) {
                    sig = aux->ant;
                    aux->ant->sig = aux->sig;
                    aux->sig->ant = aux->ant;
                    aux->sig = menor->sig;
                    aux->ant = menor;
                    menor->sig->ant = aux;
                    menor->sig = aux;
                }
                menor = aux;
            }
            else {
                if (mayor != nullptr && mayor->sig != aux) {
                    sig = aux->ant;
                    aux->ant->sig = aux->sig;
                    aux->sig->ant = aux->ant;
                    aux->sig = mayor->sig;
                    aux->ant = mayor;
                    mayor->sig->ant = aux;
                    mayor->sig = aux;
                }
                mayor = aux;
            }
            sig = sig->sig;
            aux = sig;
        }
    }

    // Método para imprimir una doble cola por pantalla
    void display(std::ostream &out) const {
      if (this->fantasma->sig != this->fantasma) {
        out << this->fantasma->sig->elem;
        Nodo *cur = this->fantasma->sig->sig;
        while (cur != this->fantasma) {
          out << " " << cur->elem;
          cur = cur->sig;
        }
      }
    }
};


// Sobrecarga del operador << para dobles colas.
// Si quieres imprimir una doble cola 'dq' puedes hacer: cout << dq << "\n";
template<typename T>
std::ostream & operator<<(std::ostream &out, const deque_partition<T> deque) {
  deque.display(out);
  return out;
}

using namespace std;



// Función para leer los casos de entrada y llamar la método
// partition sobre cada uno de ellos.
void tratar_caso() {

  // Implementar
    deque_partition<int> lista;
    int num, pivot;
    std::cin >> num;
    while (num != 0) {
        lista.push_back(num);
        std::cin >> num;
    }
    std::cin >> pivot;
    lista.partition(pivot);
    std::cout << lista << std::endl;

}


int main() {
#ifndef DOMJUDGE
  std::ifstream in("sample.in");
  auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
  
  int num_casos;
  std::cin >> num_casos;

  for (int i = 0; i < num_casos; i++) {
    tratar_caso();
  }

#ifndef DOMJUDGE
  std::cin.rdbuf(cinbuf);
  // Descomentar si se trabaja en Windows
  // system("PAUSE");
#endif
  system("PAUSE");
  return 0;
}