#include "Etudiant.h"
#include <iostream>
#include <string>
using namespace std;

string Etudiant::etudier()
{
	return "j'étudie en clasee de " + classe;
}

Etudiant::Etudiant(string n, string p, string c):Personne(n,p)
{
	nom = n;
	prenom = p;
	classe = c;
}

Etudiant::~Etudiant()
{
}

