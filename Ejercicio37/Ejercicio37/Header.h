#ifndef AUTOESCUELA_H
#define AUTOESCUELA_H

#include <iostream>
#include "list_eda.h"
#include "hashmap_eda.h"
#include "treemap_eda.h"

class autoescuela {
private:
	unordered_map<std::string, map<std::string, int>> academia;
	unordered_map<std::string, std::string> ap;

public:
	autoescuela() {};

	void alta(std::string& a, std::string &p) {
		if (ap.count(a) == 0) {
			academia[p].insert({a, 0});
			ap[a] = p;
		}
		else {
			int puntos = academia[ap[a]].find(a)->valor;
			academia[ap[a]].erase(a);
			academia[p].insert({ a, puntos });
			ap[a] = p;
		}
	}

	bool es_alumno(std::string& a, std::string& p) {
		return ap[a] == p;
	}

	int puntuacion(std::string& a) {
		if (ap.count(a) == 0)
			throw std::domain_error("El alumno " + a + " no esta matriculado");
		else return academia[ap[a]].find(a)->valor;
	}

	void actualizar(std::string& a, int n) {
		if (ap.count(a) == 0) throw std::domain_error("El alumno " + a + " no esta matriculado");
		else {
			academia[ap[a]].find(a)->valor += n;
		}
	}

	list<std::string> examen(std::string& p, int n) {
		list<std::string> l;
		for (auto it = academia[p].cbegin(); it != academia[p].cend(); ++it) {
			if (it->valor >= n)
				l.push_back(it->clave);
		}

		return l;
	}

	void aprobar(std::string& a) {
		if (ap.count(a) == 0) throw std::domain_error("El alumno " + a + " no esta matriculado");
		else {
			academia[ap[a]].erase(a);
			ap.erase(a);
		}
	}

};


#endif