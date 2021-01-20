/* Medium.cpp
* Abschlusstestat 
* J. Durchstecher
* 20.01.2021
*/

#include "Medium.h"

Medium::Medium(string autor, string titel,string signatur)
{
	setAutor(autor);
	setTitel(titel);
	setSignatur(signatur);
	setVerfuegbar();
}

Medium::Medium(const Medium& st)
{
	if (this != &st) *this = st;
	//setVerfuegbar();
}

inline void Medium::setAutor(string autor)
{
	if (autor[0] >= 'A' && autor[0] <= 'Z')
		this->autor = autor;
	else
		throw string("Autor muss mit Grossbuchstaben beginnen!");
}

const Medium& Medium::operator = (const Medium& f)
{
	setAutor(f.autor);
	setTitel(f.titel);
	setSignatur(f.signatur);
	setVerfuegbar(f.verfuegbar);
	return *this;
}

void Medium::ausgabe(ostream& s)
{
	if (verfuegbar)
		s << *this << endl;
}

bool Medium::vergleiche(const Medium& z)
{
	return *this == z;
}

Medium* Medium::clone()  const
{
	return (Medium*) new Medium(*this);
}

bool operator == (const Medium& z1, const Medium& z2)
{
	if (strcmp(z1.signatur.c_str(), z2.signatur.c_str()) == 0) return true;
	else return false;
}

bool operator != (const Medium& z1, const Medium& z2)
{
	return !(z1 == z2);
}

ostream& operator << (ostream& s, const Medium& z)
{
	if (typeid(s) == typeid(cout))
	{
		return s << "Medium = {" << z.getAutor() << ", " << z.getTitel()
			<< ", " << z.getSignatur() << "}";
	}
	return s;
}

void Medium::eingabe(istream& s)
{
	s >> *this;
}

istream& operator >> (istream& s, Medium& z)
{
	string autor,titel,signatur;
	if (typeid(s) == typeid(cin))
	{
		cout << "Geben Sie die Mediumdaten in der Reihenfolge Autor, Titel und Signatur ein: " << endl;
		s >> z.autor >> z.titel >> z.signatur;
	}
	return s;
}
