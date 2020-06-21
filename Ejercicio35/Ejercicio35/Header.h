#ifndef CARNET_H
#define CARNET_H

#include <iostream>
#include <string>
#include <vector>
#include "hashmap_eda.h"
#include "list_eda.h"

const int MAX_PUNTOS = 15;

class carnet {
private:
	unordered_map<std::string, std::pair<int, list<std::string>::iterator>> carnetPuntos;
	std::vector<list<std::string>> totales;

public:

	carnet() {
		totales.resize(MAX_PUNTOS + 1, list<std::string>());
	}
	void nuevo(std::string& dni) {
		if (carnetPuntos.find(dni) == carnetPuntos.end()) {
			totales[15].push_front(dni);
			carnetPuntos.insert({ dni, {15 , totales[15].begin()} });
		}
		else throw std::domain_error("Conductor duplicado");
	}
	void recuperar(std::string& dni, int puntos) {
		if (carnetPuntos.find(dni) != carnetPuntos.end()) {
			int ind = carnetPuntos[dni].first;
			if (ind < MAX_PUNTOS) {
				totales[ind].erase(carnetPuntos[dni].second);
				carnetPuntos[dni].first += puntos;
				if (carnetPuntos[dni].first > MAX_PUNTOS) carnetPuntos[dni].first = 15;
				totales[carnetPuntos[dni].first].push_front(dni);
				carnetPuntos[dni].second = totales[carnetPuntos[dni].first].begin();
			}

		}
		else throw std::domain_error("Conductor inexistente");
	}
	void quitar(std::string& dni, int puntos) {
		if (carnetPuntos.find(dni) != carnetPuntos.end()) {
			int ind = carnetPuntos[dni].first;
			if(ind > 0){
				totales[ind].erase(carnetPuntos[dni].second);
				carnetPuntos[dni].first -= puntos;
				if (carnetPuntos[dni].first < 0) carnetPuntos[dni].first = 0;
				totales[carnetPuntos[dni].first].push_front(dni);
				carnetPuntos[dni].second = totales[carnetPuntos[dni].first].begin();
			}
		}
		else throw std::domain_error("Conductor inexistente");
	}

	int consultar(std::string& dni) {
		if (carnetPuntos.find(dni) != carnetPuntos.end())
			return carnetPuntos[dni].first;
		else
			throw std::domain_error("Conductor inexistente");
	}

	int cuantos_con_puntos(int puntos) {
		if (puntos < 0 || puntos > MAX_PUNTOS) throw std::domain_error("Puntos no validos");
		else
			return totales.at(puntos).size();
	}
	list<std::string> lista_por_puntos(int puntos) {
		if (puntos < 0 || puntos > MAX_PUNTOS) throw std::domain_error("Puntos no validos");
		else
			return totales.at(puntos);
	}



};







#endif