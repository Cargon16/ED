#ifndef VENTALIBROS_H
#define VENTALIBROS_H


#include <iostream>
#include "hashmap_eda.h"
#include "treemap_eda.h"
#include "list_eda.h"

struct tDetalles{
	int unidades = 0;
	int vendidos = 0;
	list<std::string>::iterator it;
};

class ventaLibros {
private:
	unordered_map<std::string, tDetalles>libros;
	map<int, list<std::string>, std::greater<int>> ventas;

public:
	ventaLibros() {};

	void nuevoLibro(int n, std::string& x) {
		libros[x].unidades += n;
	}
	void comprar(std::string &x) {
		if (libros.count(x) == 0)
			throw std::invalid_argument("Libro no existente");
		else {
			if (libros[x].unidades == 0)
				throw std::out_of_range("No hay ejemplares");
			else {
				if (libros[x].vendidos != 0)
					ventas[libros[x].vendidos].erase(libros[x].it);
				libros[x].vendidos++;
				libros[x].unidades--;
				ventas[libros[x].vendidos].push_front(x);
				libros[x].it = ventas[libros[x].vendidos].begin();
			}
		}
	}

	bool estaLibro(std::string& x) {
		if (libros.count(x) == 0) return false;
		else return true;
	}

	void elimLibro(std::string& x) {
		if (libros.count(x) != 0) {
			if (libros[x].vendidos != 0)
				ventas[libros[x].vendidos].erase(libros[x].it);
			libros.erase(x);
		}
	}

	int numEjemplares(std::string& x) {
		if (libros.count(x) == 0)
			throw std::invalid_argument("Libro no existente");
		else {
			return libros[x].unidades;
		}
	}

	list<std::string> top10() {
		list<std::string>l;
		auto it = ventas.cbegin();
		for (int i = 0; i < 10 && it != ventas.cend(); ++it) {
			for (auto it2 = it->valor.cbegin(); it2 != it->valor.cend() && i < 10; ++i) {
				l.push_back(*it2);
				++it2;
			}
		}

		return l;
	}
};


#endif