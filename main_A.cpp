/* Main.cpp
* Abschlusstestat
* J. Durchstecher
* 20.01.2021
*/
#include <fstream>
#include "Buch.h"
#include "Film.h"
#include "Bibliothek.h"
#include "Person.h"

int main(int argc, char * arv[])
{

	printf("\n*************************************");
	printf("\nJ. Durchstecher --- Testat 2021_01_20");
	printf("\n*************************************");


	{
		try 
		{
			// ********* Test der Medien *************************** 
			cout << "Test der Medien" << endl;
			Medium m,m2;
			Film f;
			f.ausgabe(cout);
			Film f2(f);
			cout << "f == f2 ? " << (f == f2) << endl;
			f2.setTitel("Haus");
			f2.ausgabe(cout);
			Buch b, b2;
			cout << "f == f2 ? " << (f == f2) << endl;

			// ********* Test der Bibilothek *************************** 
			cout << endl << "Test der Bibilothek" << endl;
			Bibliothek <Medium> bibl(10);
			bibl.add(m);
			bibl.add(m2);
			bibl.add(f);
			bibl.add(f2);
			bibl.add(b);
			bibl.add(b2);
			bibl.print(cout);
			cout << endl;
			// ********* Test der Person *************************** 
			cout << endl << "Test der Person" << endl;
			Person p("Ammann", 12);
			cout << "p: " << p << endl;
			cout << endl << "     Leihe/Rückgabe eines Mediums" << endl;
			p.leiheMedium(f2, bibl);
			p.leiheMedium(b2, bibl);
			cout << "p: " << p << endl;
			cout << "Öffentliche Bibliothek " << endl;
			bibl.print(cout);
			p.rueckgabeMedium(f2, bibl);
			cout << "p: " << p << endl;
			cout << "Öffentliche Bibliothek " << endl;
			bibl.print(cout);
			p.rueckgabeMedium(b2, bibl);
			cout << "p: " << p << endl;
			cout << "Öffentliche Bibliothek " << endl;
			bibl.print(cout);
		}
		catch (string e)
		{
			cerr << e << endl;
		}
	}

	//system("pause");
	return 0;
}