#ifndef _Personne_h
#define _Personne_h
#include <iostream>
#include <string>
using namespace std;

class Personne
{
	protected:
		string nom;
		string prenom;
	public:
		string affiche();
		string get_nom();
		string get_prenom();
		Personne (string n, string p);
		~Personne();
};
#endif