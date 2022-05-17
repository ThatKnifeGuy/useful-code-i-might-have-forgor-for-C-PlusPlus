/*Bernard alexandre
24/11/21
programme qui affiche un menu à l'infini mais en utilisant des fonctions
*/
#include <iostream>
using namespace std;
/*-------------------------------------------partie fonctions---------------------------------------*/

void affichage()
{                                      //fonction d'affichage
	cout<<"----------------------------------\n"
	"pour choisir l'option 1, saisir 1.\n"
	"pour choisir l'option 2, saisir 2.\n"
	"pour choisir l'option 3, saisir 3.\n"
	"pour sortir, saisir 0.\n"
	"----------------------------------\n"<<endl;
}

int valeur()
{                                          //fonction des valeur entré et sortie
	int i;
	cin>>i;
	while (i>0)
	{
		cout<<i<<"\n vous avez choisi l'option"<<i<<endl;
		affichage();
		cin>>i;

		if (i==0)
		{
			break;
		}

	}
}

/*-------------------------------------------programme principal---------------------------------------*/

int main(int argc, char const *argv[])
{
	affichage();
	valeur();

	return 0;
}