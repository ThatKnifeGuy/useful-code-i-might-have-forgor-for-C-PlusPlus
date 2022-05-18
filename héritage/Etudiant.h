#ifndef _Etudiant_h
#define _Etudiant_h
#include "Personne.h"
#include <iostream>
#include <string>
using namespace std;

class Etudiant : public Personne
{
	private:
		string classe;
	public:
		string etudier();
		Etudiant(string n, string p, string c);
		~Etudiant();
};
#endif