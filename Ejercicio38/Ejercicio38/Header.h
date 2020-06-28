#ifndef IPUD_H
#define IPUD_H

#include <iostream>
#include "hashmap_eda.h"
#include "list_eda.h"

struct tCancion {
	int dur;
	std::string autor;
	list<std::string>::iterator playL;
	list<std::string>::iterator repro;
};

class ipud {

private:
	unordered_map<std::string, tCancion> c;
	list<std::string> playList;
	list<std::string> reproducidas;

public:
	ipud() {};

	void addSong(std::string &s, std::string &a, int d) {
		if (c.count(s) == 0) {
			c[s] = { d, a, playList.end(), reproducidas.end() };
		}
		else throw std::domain_error("ERROR addSong");
	}

	void addToPlaylist(std::string &s) {
		if (c.count(s) == 0) throw std::domain_error("ERROR addToPlaylist");
		else {
			if (c[s].playL == playList.end()) {
				c[s].playL = playList.insert(playList.end(), s);
			}
		}
	}

	std::string current() {
		if (playList.empty()) throw std::domain_error("ERROR current");
		else return *playList.cbegin();
	}

	std::string play() {
		std::string nombre;
		if (!playList.empty()) {
			if (c[*playList.begin()].repro != reproducidas.end())
				reproducidas.erase(c[*playList.begin()].repro);
			nombre = *playList.cbegin();
			reproducidas.push_front(nombre);
			c[*playList.begin()].repro = reproducidas.begin();
			c[*playList.begin()].playL = playList.end();
			playList.erase(playList.begin());

			return nombre;
		}
		else throw std::domain_error("No hay canciones en la lista");
	}

	int totalTime() {
		int suma = 0;
		for (auto it = playList.cbegin(); it != playList.cend(); ++it)
			suma += c[*it].dur;

		return suma;
	}

	list<std::string> recent(int n) {
		list<std::string> l;
		if (reproducidas.empty()) throw std::domain_error("No hay canciones recientes");
		else {
			int i = 0;
			for (auto it = reproducidas.cbegin(); i < n && it != reproducidas.cend(); ++it) {
				l.push_back(*it);
				++i;
			}
			return l;
		}
	}

	void deleteSong(std::string& s) {
		if (c.count(s) != 0) {
			if (c[s].repro != reproducidas.end())
				reproducidas.erase(c[s].repro);
			if (c[s].playL != playList.end())
				playList.erase(c[s].playL);

			c.erase(s);
		}
	}
};

#endif