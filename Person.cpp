/* Person.cpp
TestGross: Klassen
J. Durchstecher, 18.12.2019
*/

#include <iostream>
#include <string>
#include "Buch.h"
#include "Person.h"

////////////////////////////////////////////////////////////////////
// Erweiterungen - Anfang
Person::Person(string name, int alter)
{
	setName(name);
	setAlter(alter);
	anzahlMed = 0;
}

Person::Person(const Person& st)
{
	if (this != &st) *this = st;
}



void Person::leiheMedium(Medium f, Bibliothek <Medium> bib )
{
	medListe = new Medium * [5];
	medListe[anzahlMed++] = &f;
}

void Person::rueckgabeMedium(Medium f, Bibliothek <Medium> bib)
{
	medListe[anzahlMed--] = nullptr;
}

void Person::createMediumListe(Medium** fahrzeuge, int anzahl)
{
	if (anzahlMed = anzahl)
	{
		medListe = new Medium * [anzahl];
		for (int i = 0; i < anzahl; i++)
			medListe[i] = fahrzeuge[i];
	}
}

const Person& Person::operator = (const Person& f)
{
	setName(f.name);
	setAlter(f.alter);
	return *this;
}

ostream& operator << (ostream& s, const Person& z)
{
	if (typeid(s) == typeid(cout))
	{
		s << "Person = {" << z.getName() << ", " << z.getAlter() << "}" << endl;

		for (int n = 0; n < z.anzahlMed; n++)
		{
			s << z.medListe[n] << endl;
		}
		
		////////////////////////////////////////////////////////////////////
		
		// Erweiterungen - Ende
		////////////////////////////////////////////////////////////////////
	}
	return s;
}

