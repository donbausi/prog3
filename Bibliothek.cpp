/*
* Bibliothek<T>.cpp
* Abschlusstestat
* H. Loose
* 20.01.2021
*/
#include "Bibliothek.h"

// Operator =
template <class T> 
Bibliothek<T>::Bibliothek(int size)
{
	if (size <= 0) size = 3;
	this->size = size;
	this->cnt = 0;
	this->data = (T**) new T*[size];
}

template <class T> 
Bibliothek<T>::~Bibliothek<T>()
{
	if (data) 
	{
		for (int i = 0; i < cnt; i++)
			if (*(this->data + i)) delete *(this->data + i);
		this->size = 0;
		this->cnt = 0;
		if (this->data) delete[] this->data;
	}
}

template <class T> 
void Bibliothek<T>::add(T& ab)
{
	if (this->cnt < this->size)
		this->data[this->cnt++] = ab.clone();
	else
		throw exception("\nERROR: Bibliothek<T> ist voll.");
}

template <class T>
void  Bibliothek<T>::set(T& ab, int i)
{
	int k = i;
	if (i < this->cnt && i >= 0)
		this->data[i] = ab.clone();
	else if (i == this->cnt)
		add(ab);
	else
		throw exception("\nERROR: i ist unzuläsig.");
}

template <class T>
T&  Bibliothek<T>::get(int i) const
{
	if (i < this->cnt && i >= 0)
		return *this->data[i];
	else
	{
		throw exception("\nERROR: i ist unzuläsig.");
	}
}

template <class T>
bool Bibliothek<T>::remove(T& medium)
{
	int k = 0;
	bool ret = false;
	for ( ; k < cnt; k++)
		if (medium == *data[k])
		{
			delete data[k];
			ret = true;
			break;
		}
	cnt--;
	for (; k < cnt; k++)
	{
		data[k] = data[k + 1];
	}
	
	return ret;
}


template <class T>
int Bibliothek<T>::sucheMedium(T& medium)
{
	// 0 - vorhanden und ausleihbar, 1 - vorhanden und ausgeliehen, -1 - sonst
	for (int k = 0; k < cnt; k++)
		if (medium.vergleiche(*data[k]))
		//if ((data[k])->vergleiche(medium))
				//if (medium == data[k])
		{
			if ((data[k])->getVerfuegbar())
				return 0;
			else
				return 1;
		}
	return -1;
}

template <class T>
bool Bibliothek<T>::ausleihenMedium(T& medium)
{
	for (int k = 0; k < cnt; k++) {
		if (medium.vergleiche(*data[k]))
		{
			((Medium*)data[k])->setVerfuegbar(false);
			return true;
		}
	}	return false;
}

template <class T>
bool Bibliothek<T>::rueckgebenMedium(T& medium)
{
	for (int k = 0; k < cnt; k++) {
		if (medium.vergleiche(*data[k]))
		{
			((Medium*)data[k])->setVerfuegbar();
			return true;
		}
	}	return false;
}



template <class T>
void  Bibliothek<T>::print(ostream& s)
{
	s << "\nAusgabe mit print:" << endl;
	s << "Bibliothek enthält " << cnt << " Medien" << endl;
	for (int i = 0; i < cnt; i++)
		data[i]->ausgabe(s);
}

template <class T>
const Bibliothek<T>&  Bibliothek<T>::operator = (const Bibliothek<T>& p)
{
	if (this != &p)
	{
		if (data)
		{
			for (int i = 0; i < cnt; i++)
				if (*(this->data + i)) delete* (this->data + i);
			this->size = 0;
			this->cnt = 0;
			if (this->data) delete[] this->data;
		}
		size = p.size;
		cnt = p.cnt;
		data = (T**) new T*[size];
		for (int i = 0; i < cnt; i++)
			set(*p.data[i],i);
	}
	return *this;
}

template <class T>
bool operator == (const Bibliothek<T>& p1, const Bibliothek<T>& p2)
{
	bool ret = true;
	if (p1.size == p2.size)
		if (p1.cnt == p2.cnt)
		{
			for (int i = 0; i < p1.cnt; i++)
			{
				if (p1.data[i] != p2.data[i]) ret = false; break;
			}
		}
		else ret = false;
	else ret = false;
	return ret;
}

template <class T>
bool operator != (const Bibliothek<T>& p1, const Bibliothek<T>& p2)
{
	return !(p1 == p2);
}

template <class T>
ostream& operator << (ostream& s, const Bibliothek<T>& p)
{
	s << "Count: " << p.cnt << endl;
	for (int i = 0; i < p.cnt; i++)
	{
		if (((Medium) *p.data[i]).getVerfuegbar())
			s << *p.data[i];
	}
	return s;
}

template <class T>
istream& operator >> (istream& s, Bibliothek<T>& p)
{
	return s;
}
