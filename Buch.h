/* Buch.h
* Abschlusstestat
* J. Durchstecher
* 20.01.2021
*/

#pragma once
#include "Medium.h"

class Buch : public Medium
{
private:
	int seitenzahl;		

public:
	Buch(string autor = string("Strobel"), string titel = string("Die App"),
		string signatur = string("0INF011(02)-01+02"),int zahl = 361);
	Buch(const Buch& f);
	~Buch() {};
	int getSeitenzahl() const { return seitenzahl; }
	void setSeitenzahl(int seitenzahl) { this->seitenzahl = seitenzahl; }

	virtual void ausgabe(ostream& s);
	virtual void eingabe(istream& s);
	virtual bool vergleiche(const Medium& z);
	virtual Buch* clone() const;

	const Buch& operator = (const Buch& f);
	friend bool operator == (const Buch& z1, const Buch& z2);
	friend bool operator != (const Buch& z1, const Buch& z2);

	friend ostream& operator << (ostream& s, const Buch& z);
	friend istream& operator >> (istream& s, Buch& z);
};

