/* Medium.h
* Abschlusstestat
* J. Durchstecher
* 20.01.2021
*/

#pragma once
#include <iostream>
#include <string>
using namespace std;

class Medium
{
private:
	string autor;			// beginnend mit Großbuchstaben 
	string titel;			
	string signatur;		// 0PNM011(06)-01+02 
	bool verfuegbar;

public:
	Medium(string autor = string("Stroustrup"), string titel = string("Programmierung c++"), 
		string signatur = string("0PNM011(06)-01+02"));
	Medium(const Medium& f);
	~Medium() {}
  	string getAutor() const { return autor; }
	void setAutor(string autor);// { this->autor = autor; }
	string getTitel() const { return titel; }
	void setTitel(string titel) { this->titel = titel; }
	string getSignatur() const { return signatur; }
	void setSignatur(string signatur) { this->signatur = signatur; }
	bool getVerfuegbar() { return verfuegbar; }
	void setVerfuegbar(bool verfuegbar = true) { this->verfuegbar = verfuegbar; }

	virtual void ausgabe(ostream& s);
	virtual void eingabe(istream& s);
	virtual bool vergleiche(const Medium& z);
	virtual Medium * clone() const;

	const Medium& operator = (const Medium& f);
	friend bool operator == (const Medium& z1, const Medium& z2);
	friend bool operator != (const Medium& z1, const Medium& z2);

	friend ostream& operator << (ostream& s, const Medium& z);
	friend istream& operator >> (istream& s, Medium& z);
};

