#ifndef _Prof_h
#define _Prof_h
#include "Personne.h"
#include <iostream>
#include <string>
using namespace std;

class Prof : public Personne
{
	public:
		string enseigner();
		Prof(string n, string p);
		~Prof();
		string affiche();
};
#endif