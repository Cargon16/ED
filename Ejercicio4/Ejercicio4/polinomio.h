#ifndef POLINOMIO_H
#define POLINOMIO_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

class polinomio {

private:
	std::vector<std::pair<int, int>>v;



public:
	polinomio() { ; };

	void addMonomio(int coeficiente, int exponente) {
		this->v.push_back({ exponente, coeficiente });
		std::sort(this->v.begin(), this->v.end());
	 }
	 
	int evaluar(int variable) {
		int suma = 0;
		for (int i = 0; i < this->v.size(); ++i) {
			suma += this->v.at(i).second * (std::pow(variable, this->v.at(i).first));
		}

		return suma;
	}


};



#endif // !1
