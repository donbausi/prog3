#pragma once
/* Person.h
TestGross: Klassen
- Person - konkret
J. Durchstecher, 18.12.2019
*/

#include <iostream>
#include <string>
#include <vector> 
#include "Medium.h"
#include "Bibliothek.h"
#include "Film.h"


using namespace std;

class Person 
{
////////////////////////////////////////////////////////////////////
// Erweiterungen - Anfang
private:
	string name;
	int alter;
	Medium** medListe;
	int anzahlMed;

public:
	Person(string name = "Meier", int alter = 50);
	Person(const Person& st);
	~Person()
	{
		////////////////////////////////////////////////////////////////////
		// Erweiterungen - Anfang
		// Erweiterungen - Ende
		////////////////////////////////////////////////////////////////////
	}

	string getName() const { return name; }
	void setName(string name) { this->name = name; }

	int getAlter() const { return alter; }
	void setAlter(int alter) { this->alter = alter; }

	///////////////////////////
	void leiheMedium(Medium f, Bibliothek <Medium> bib);
	void createMediumListe(Medium** meds, int anzahl);
	void rueckgabeMedium(Medium f, Bibliothek <Medium> bib);

	const Person& operator = (const Person& f);
	friend ostream& operator << (ostream& s, const Person& z);
};

