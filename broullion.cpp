#include <iostream>
#include <ctime>
using namespace std;

/*-------------------------------------------partie fonctions---------------------------------------*/


/*-------------------------------------------programme principal---------------------------------------*/

int main(int argc, char const *argv[])
{
	int annee,mois,jour;

 	time_t temps = time(NULL); //prend la date du moments depuis 1970

	cout<<temps<<endl;

	cout<<"Quand est votre anniversaire?\n"<<"jour:"<<endl;
	cin>>jour;
	cout<<"mois:\n"<<endl;
  	cin>>mois;
  	cout<<"annee:\n"<<endl;
  	cin>>annee;

	struct tm *naissance = localtime(&temps);



	cout<<"annee= "<<annee<<endl;
	cout<<"mois= "<<mois<<endl;
	cout<<"jour= "<<jour<<endl;
	
	cout<<naissance<<endl;

	return 0;
}
