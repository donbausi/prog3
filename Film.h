/* Buch.h
* Abschlusstestat
* J. Durchstecher
* 20.01.2021
*/

#pragma once
#include "Medium.h"

class Film : public Medium
{
private:
	int laenge;

public:
	Film(string autor = string("Film:Strobel"), string titel = string("Ein Film"),
		string signatur = string("DIN- FILM 02023323"), int zahl = 128);
	Film(const Film& f);
	~Film() {};
	int getLaenge() const { return laenge; }
	void setLaenge(int laenge) { this->laenge = laenge; }

	virtual void ausgabe(ostream& s);
	virtual void eingabe(istream& s);
	virtual bool vergleiche(const Medium& z);
	virtual Film* clone() const;

	const Film& operator = (const Film& f);
	friend bool operator == (const Film& z1, const Film& z2);
	friend bool operator != (const Film& z1, const Film& z2);

	friend ostream& operator << (ostream& s, const Film& z);
	friend istream& operator >> (istream& s, Film& z);
};

