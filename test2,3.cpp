/*Bernard alexandre
02/12/21
programme qui donne le plus petit et plus grand d'un nombre
*/
#include <iostream>
using namespace std;

/*-------------------------------------------partie fonctions---------------------------------------*/

int min(int valeur1, int valeur2)
{
	if (valeur1 > valeur2)
	{
		return valeur2;
	}
	else
	{
		return valeur1;
	}

}


int max(int valeur1, int valeur2)
{

	if (valeur1 < valeur2)
	{
		return valeur2;
	}
	else
	{
		return valeur1;
	}

}


/*-------------------------------------------programme principal---------------------------------------*/
int main(int argc, char const *argv[])
{
	int val1,val2;

	cout<<"Entré vos nombres.."<<endl;
	cin>>val1;
	cin>>val2;

	cout<<"le plus petit nombre est:"<<min(val1,val2)<<endl;
	cout<<"le plus grand nombre est:"<<max(val1,val2)<<endl;


	return 0;
}