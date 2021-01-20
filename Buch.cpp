/* Buch.cpp
* Abschlusstestat 
* J. Durchstecher
* 20.01.2021
*/

#include "Buch.h"

Buch::Buch(string autor, string titel, string signatur, int zahl) : Medium(autor,titel,signatur)
{
	setSeitenzahl(zahl);
}

Buch::Buch(const Buch& st)
{
	if (this != &st) *this = st;
}

const Buch& Buch::operator = (const Buch& f)
{
	*((Medium*) this) = (Medium) f;
	setSeitenzahl(f.seitenzahl);
	return *this;
}

Buch* Buch::clone()  const
{
	return (Buch*) new Buch(*this);
}

void Buch::ausgabe(ostream& s)
{
	if (getVerfuegbar())
		s << *this << endl;
}

bool Buch::vergleiche(const Medium& z)
{
	return ((Buch&) z) == *this;
}

bool operator == (const Buch& z1, const Buch& z2)
{
	if (strcmp(z1.getAutor().c_str(), z2.getAutor().c_str()) == 0 && 
		strcmp(z1.getTitel().c_str(), z2.getTitel().c_str()) == 0) 
		return true;
	else return false;
}

bool operator != (const Buch& z1, const Buch& z2)
{
	return !(z1 == z2);
}

ostream& operator << (ostream& s, const Buch& z)
{
	if (typeid(s) == typeid(cout))
	{
		s << "Buch = {" << ((Medium) z) << ", " << z.getSeitenzahl() << "}";
	}
	return s;
}

void Buch::eingabe(istream& s)
{
	s >> *this;
}

istream& operator >> (istream& s, Buch& z)
{
	Medium m;
	if (typeid(s) == typeid(cin))
	{
		s >> m;
		cout << "Geben Sie die Seitenzahl ein: " << endl;
		s >> z.seitenzahl;
	}
	return s;
}
