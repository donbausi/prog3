/* Film.cpp
* Abschlusstestat
* J. Durchstecher
* 20.01.2021
*/

#include "Film.h"

Film::Film(string autor, string titel, string signatur, int zahl) : Medium(autor, titel, signatur)
{
	setLaenge(zahl);
}

Film::Film(const Film& st)
{
	if (this != &st) *this = st;
}

const Film& Film::operator = (const Film& f)
{
	*((Medium*)this) = (Medium)f;
	setLaenge(f.laenge);
	return *this;
}

Film* Film::clone()  const
{
	return (Film*) new Film(*this);
}

void Film::ausgabe(ostream& s)
{
	if (getVerfuegbar())
		s << *this << endl;
}

bool Film::vergleiche(const Medium& z)
{
	return ((Film&)z) == *this;
}

bool operator == (const Film& z1, const Film& z2)
{
	if (strcmp(z1.getAutor().c_str(), z2.getAutor().c_str()) == 0 &&
		strcmp(z1.getTitel().c_str(), z2.getTitel().c_str()) == 0)
		return true;
	else return false;
}

bool operator != (const Film& z1, const Film& z2)
{
	return !(z1 == z2);
}

ostream& operator << (ostream& s, const Film& z)
{
	if (typeid(s) == typeid(cout))
	{
		s << "Film = {" << ((Medium)z) << ", " << z.getLaenge() << "}";
	}
	return s;
}

void Film::eingabe(istream& s)
{
	s >> *this;
}

istream& operator >> (istream& s, Film& z)
{
	Medium m;
	if (typeid(s) == typeid(cin))
	{
		s >> m;
		cout << "Geben Sie die Seitenzahl ein: " << endl;
		s >> z.laenge;
	}
	return s;
}
