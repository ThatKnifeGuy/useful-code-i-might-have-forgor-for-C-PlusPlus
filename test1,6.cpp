/*Bernard alexandre
10/11/21
programme de tent que.. affichant un menu infini 
*/
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int i;
	cout<<"----------------------------------\n"
	"pour choisir l'option 1, saisir 1.\n"
	"pour choisir l'option 2, saisir 2.\n"
	"pour choisir l'option 3, saisir 3.\n"
	"pour sortir, saisir 0.\n"
	"----------------------------------\n"<<endl;
	cin>>i;

	while (i>0)
	{
		cout<<i<<"\n vous avez choisi l'option"<<i<<endl;

		cout<<"----------------------------------\n"
		"pour choisir l'option 1, saisir 1.\n"
		"pour choisir l'option 2, saisir 2.\n"
		"pour choisir l'option 3, saisir 3.\n"
		"pour sortir, saisir 0.\n"
		"----------------------------------\n"<<endl;
		cin>>i;

		if (i==0)
		{
			break;
		}

	}

	return 0;
}