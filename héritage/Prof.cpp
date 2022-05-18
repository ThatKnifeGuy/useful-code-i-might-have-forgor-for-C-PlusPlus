#include "Prof.h"
#include <iostream>
#include <string>
using namespace std;

string Prof::enseigner()
{
	return "j'enseigne.";
}

string Prof::affiche()
{
	return "le Professeur " + nom + " " + prenom;
}

Prof::Prof(string n, string p):Personne(n,p)
{
	nom = n;
	prenom = p;
}

Prof::~Prof()
{
}
