#ifndef CONSULTORIO_H
#define CONSULTORIO_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

class Fecha {
private:
	int dia;
	int hora;
	int minutos;
public:
	Fecha(int d, int h, int m) {
		dia = d;
		hora = h;
		minutos = m;
	}
	const int getDia() {
		return dia;
	}
	const int getHora() {
		return hora;
	}
	const int getMin() {
		return minutos;
	}
	bool operator<(Fecha other) const {
		if (dia < other.dia) return true;
		else if (dia > other.dia) return false;
		else {
			if (hora < other.hora) return true;
			else if (hora > other.hora) return false;
			else {
				if (minutos < other.minutos) return true;
				else return false;
			}
		}
	}
};

class consultorio {

private:
	std::unordered_map<std::string, std::map<Fecha, std::string>> l;


public:
	consultorio() {};

	void nuevoMedico(std::string& m) {
		if (l.count(m) == 0) {
			l[m];
		}
	}

	void pideConsulta(std::string& p, std::string& m, Fecha& f) {
		if (l.count(m) == 0) throw std::domain_error("Medico no existente");
		else {
			if (l[m].count(f) != 0) throw std::domain_error("Fecha ocupada");
			else {
				l[m].insert({f, p});
			}
		}
	}

	std::string siguientePaciente(std::string &m) {
		if (l.count(m) == 0)
			throw std::domain_error("Medico no existente");
		else {
			if (l[m].empty())
				throw std::domain_error("No hay pacientes");
			else {
				return l[m].cbegin()->second;
			}
		}
	}

	void atiendeConsulta(std::string& m) {
		if (l.count(m) == 0)
			throw std::domain_error("Medico no existente");
		else {
			if (l[m].empty())
				throw std::domain_error("No hay pacientes");
			else {
				l[m].erase(l[m].begin()->first);
			}
		}
	}

	std::vector<std::pair<std::string, Fecha>> listaPacientes(std::string &m, int d) {
		std::vector<std::pair<std::string, Fecha>> aux;
		if (l.count(m) == 0)
			throw std::domain_error("Medico no existente");
		else {
			auto it = l[m].cbegin();
			while (it != l[m].cend()) {
				Fecha f = it->first;
				if(f.getDia() == d)
				aux.push_back({it->second, it->first});
				++it;
				
			}
			return aux;
		}
	}
};

#endif