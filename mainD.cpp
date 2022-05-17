#include <iostream>

using namespace std;
#include "dés.h"

int main(int argc, char const *argv[])
{
	int faces;

	cout<< "hello world" << endl;
	cout << "combien de face voulez vous pour votre dé ? " << endl;
	cin>>faces;

	De * de = new De(faces);

	cout << "valeur du dé après sa création : " << de->get_valeur() << endl;

	de->lancer(faces);
	cout << "valeur du dé après l'avoir lancé : " << de->get_valeur() << endl;

	delete de;
	return 0;
}