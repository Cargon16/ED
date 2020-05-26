#ifndef COMPLEJO_H
#define COMPLEJO_H

#include <iostream>
#include <cmath>

class complejo {

private:
	double parteReal;
	double parteImaginaria;

public:
	complejo(float parteR, float parteI) {
		this->parteReal = parteR;
		this->parteImaginaria = parteI;

	}
	complejo operator + (complejo c) {
		complejo suma = complejo(0, 0);
		suma.parteImaginaria = c.parteImaginaria + this->parteImaginaria;
		suma.parteReal = c.parteReal + this->parteReal;

		return suma;
	}

	complejo operator * (complejo c) {
		complejo prod = complejo(0, 0);
		prod.parteImaginaria = this->parteReal * c.parteImaginaria + c.parteReal * this->parteImaginaria;
		prod.parteReal = this->parteReal * c.parteReal - this->parteImaginaria * c.parteImaginaria;

		return prod;
	}

	float modulo() {
		float suma = std::pow(this->parteReal, 2) + std::pow(this->parteImaginaria, 2);
		float r = std::sqrt(suma);
		return r;
	}
};







#endif // !COMPLEJO_H
