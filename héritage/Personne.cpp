#include "Personne.h"
#include <iostream>
#include <string>
using namespace std;

string Personne::affiche()
{
	return nom + " " + prenom; //on peu return plusieur fois si les variables sont des chaînes de charactères.
}

string Personne::get_nom()
{
	return nom;
}

string Personne::get_prenom()
{
	return prenom;
}

Personne::Personne(string n,string p)
{
	nom = n;
	prenom = p;
}

Personne::~Personne()
{
}

