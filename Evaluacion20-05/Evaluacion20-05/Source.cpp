//Carlos González Torres
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <unordered_map>

class Supermercado {

private:

	std::unordered_map<std::string,int> cliente;

	std::unordered_map<int, std::list<std::string>> colasCaja;

	int numCajas;

	void eliminarClienteCola(const std::string &cliente, const int caja) {
		auto it = this->colasCaja.at(caja).cbegin();
		while (it != this->colasCaja.at(caja).cend() && *it != cliente) {
			++it;
		}
		if (it != this->colasCaja.at(caja).cend()) this->colasCaja.at(caja).erase(it);
	}

public:

	Supermercado(int numCajas) {
		this->numCajas = numCajas;
		std::list <std::string> colas;
		for (int i = 0; i < numCajas; ++i)
			this->colasCaja.insert({ i, colas});
	}

	// O(1)
	void nuevo_cliente(std::string &cod_cliente, int num_cola) {
		if (this->cliente.find(cod_cliente) == this->cliente.end()) {
			if (num_cola >= this->numCajas)
				throw std::domain_error("Cola inexistente");
			else {
				this->colasCaja.at(num_cola).push_back(cod_cliente);
				this->cliente.insert({ cod_cliente, num_cola });
			}
		}
		else
			throw std::domain_error("Cliente duplicado");
	}

	// O(n)
	void cambiar_cola(std::string &cod_cliente, int num_cola) {
		if (this->cliente.find(cod_cliente) != this->cliente.end()) {
			if (num_cola >= this->numCajas)
				throw std::domain_error("Cola inexistente");
			else {
				if (this->cliente.at(cod_cliente) != num_cola) {
					this->eliminarClienteCola(cod_cliente, this->cliente.at(cod_cliente));
					this->colasCaja.at(num_cola).push_back(cod_cliente);
					this->cliente.erase(cod_cliente);
					this->cliente.insert({ cod_cliente, num_cola });
				}
			}
		}
		else
			throw std::domain_error("Cliente inexistente");
	}

	// O(1)
	int consultar_cliente(const std::string& cod_cliente) {
		if (this->cliente.find(cod_cliente) != this->cliente.end()) {
			return this->cliente.at(cod_cliente);
		}
		else
			throw std::domain_error("Cliente inexistente");
	}

	// O(1)
	int cuantos_en_cola(const int num_cola) {
		if (num_cola >= this->numCajas)
			throw std::domain_error("Cola inexistente");
		else
			return this->colasCaja.at(num_cola).size();
	}

	// O(n)
	std::list<std::string> clientes_en_cola(const int num_cola) {
		if (num_cola < this->numCajas) {
			auto it = this->colasCaja.at(num_cola).cbegin();
			std::list<std::string> clienteCola;
			for (int i = 0; i < this->colasCaja.at(num_cola).size(); ++i) {
				clienteCola.push_front(*it);
				++it;
			}
			return clienteCola;
		}
		else
			throw std::domain_error("Cola inexistente");
		
	}

};

// O(n)
void mostrarLista(const std::list<std::string>& clientesCola) {
	auto it = clientesCola.cbegin();
	if (it != clientesCola.cend()){
		for (int i = 0; i < clientesCola.size() - 1; ++i) {
			std::cout << *it << " ";
			++it;
		}
	std::cout << *it;
	}
	std::cout << std::endl;
}

void resolver(const int numeroCajas) {

	std::string cod_cliente; 
	int numCaja;
	std::string opcion;
	Supermercado s = Supermercado(numeroCajas);

	std::cin >> opcion;
	while(opcion.compare("FIN") != 0){

		try {

			if(opcion.compare("consultar_cliente") == 0) {
				std::cin >> cod_cliente;
				int cola = s.consultar_cliente(cod_cliente);
				std::cout << "El cliente " << cod_cliente << " esta en la cola " << cola << std::endl;
				
			} else if(opcion.compare("cuantos_en_cola") == 0) {
				std::cin >> numCaja;
				int clientes = s.cuantos_en_cola(numCaja);
				std::cout << "En la cola " << numCaja << " hay " << clientes << " clientes" << std::endl;


			} else if(opcion.compare("clientes_en_cola") == 0) {
				std::cin >> numCaja;
				std::list<std::string> l = s.clientes_en_cola(numCaja);
				std::cout << "En la cola " << numCaja << " estan: ";
				mostrarLista(l);
				

			} else if(opcion.compare("nuevo_cliente") == 0) {
				std::cin >> cod_cliente >> numCaja;
				s.nuevo_cliente(cod_cliente, numCaja);

			}
			else if (opcion.compare("cambiar_cola") == 0) {
				std::cin >> cod_cliente >> numCaja;
				s.cambiar_cola(cod_cliente, numCaja);

			}


		} catch(const std::domain_error& e) {

			std::cout << "ERROR: " << e.what() << std::endl;

		}
		std::cin >> opcion;
	}

}

bool resuelveCaso() {

	int numeroCajas;
	std::cin >> numeroCajas;

	if(!std::cin)

		return false;

	resolver(numeroCajas);

	std::cout << "---" << std::endl;

	return true;

}

int main() {

	// Para la entrada por fichero.
// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

	while (resuelveCaso());

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

}