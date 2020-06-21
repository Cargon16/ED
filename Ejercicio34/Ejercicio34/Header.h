#ifndef CARNET_H
#define CARNET_H

#include <iostream>
#include <string>
#include <vector>
#include "hashmap_eda.h"

const int MAX_PUNTOS = 15;

class carnet {
private:
	unordered_map<std::string, int> carnetPuntos;
	std::vector<int> totales;

public:

	carnet(){
		totales.resize(MAX_PUNTOS+1);
	}
	void nuevo(std::string& dni) {
		if (carnetPuntos.find(dni) == carnetPuntos.end()) {
			carnetPuntos.insert({ dni, 15 });
			totales[MAX_PUNTOS]++;
		}
		else throw std::domain_error("Conductor duplicado");
	}

	void quitar(std::string& dni, int puntos) {
		if (carnetPuntos.find(dni) != carnetPuntos.end()) {
			int ind = carnetPuntos[dni];
			totales[ind]--;
			if (carnetPuntos[dni] - puntos < 0) carnetPuntos[dni] = 0;
			else carnetPuntos[dni] -= puntos;
			totales[carnetPuntos[dni]]++;
		}
		else throw std::domain_error("Conductor inexistente");
	}

	int consultar(std::string& dni) {
		if (carnetPuntos.find(dni) != carnetPuntos.end())
			return carnetPuntos[dni];
		else
			throw std::domain_error("Conductor inexistente");
	}

	int cuantos_con_puntos(int puntos) {
		if (puntos < 0 || puntos > MAX_PUNTOS) throw std::domain_error("Puntos no validos");
		else
			return totales.at(puntos);
	}



};







#endif