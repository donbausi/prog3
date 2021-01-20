/* Bibliothek.h
* Abschlusstestat
* J. Durchstecher
* 20.01.2021
*/
#pragma once
//#define TEMPLATE

#include <iostream>
#include <string>
using namespace std;

// Eine Klasse zum definieren von eigenen Ausnahmen
class BibliothekException
{
private:
	string message;
public:
	BibliothekException(string message = string(""))
	{
		this->message = message;
	}
	string getMessage() const { return message; }
};

// Die Implementierung des Bibliotheks erfolgt als double bzw. als Template

template<class T>
class Bibliothek
{
private:
	/* Instanzvariablen */
	T ** data = nullptr;
	int size = 0, cnt = 0;
public:
	/* Konstruktoren */
	Bibliothek(int size = 3);
	Bibliothek(const Bibliothek& p) { if (this != &p) *this = p; }
	virtual ~Bibliothek();
	void add(T& medium);
	void set(T& medium, int i);
	T& get(int i) const;
	bool remove(T& medium);
	int sucheMedium(T& medium);
	bool ausleihenMedium(T& medium);
	bool rueckgebenMedium(T& medium);


	// Operator =
	const Bibliothek& operator = (const Bibliothek &st);
	const Bibliothek& operator += (const T &st);
	const Bibliothek& operator -= (T &st);
	T& operator [] (int id) const;

	void print(ostream& s);

	// E/A über Streams
	friend ostream& operator << <>(ostream& s, const Bibliothek& z);
	friend istream& operator >> <>(istream& s, Bibliothek& z);

	// E/A über Streams
	friend bool operator == <>(const Bibliothek& s1, const Bibliothek& s2);
	friend bool operator != <>(const Bibliothek& s1, const Bibliothek& s2);
}; 

#include "Bibliothek.cpp"
