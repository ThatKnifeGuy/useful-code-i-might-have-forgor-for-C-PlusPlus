#include "Personne.h"
#include "Etudiant.h"
#include "Prof.h"
#include <iostream>
using namespace std;

int main()
{
	/*debug
	Personne* etudiant = new Personne("Rizo","thau");

	cout << etudiant->affiche() << endl;

	delete etudiant;
	*/

 	
	Etudiant* etudiant1 = new Etudiant("Frigo", "Roméo", "ir1");
	Etudiant* etudiant2 = new Etudiant("Talut", "Jean", "ir1");
	
	Prof* prof = new Prof("Ptitegoute", "Anne");
	cout << prof->affiche();
	cout << " dit : " << prof->enseigner() << endl;
	
	cout << etudiant1->affiche();
	cout << " dit : " << etudiant1->etudier() << endl;
	
	cout << etudiant2->affiche();
	cout << " dit : " << etudiant1->etudier() << endl;
	
	return 0;
}