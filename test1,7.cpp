/*Bernard alexandre
10/11/21
programme qui demande l'aire d'un rectangle (Lxl) à l'infini et qui donne le résultat
*/
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int L;
	int l;
	int A;
	int i;

	cout<<"saisir les dimensions du rectangle\n""Longeur:\n"<<endl;
	cin>>L;
	cout<<"Largeur:\n"<<endl;
	cin>>l;

	A=L*l;

	cout<<"l'aire du rectangle est de:"<<A<<endl;

	while(true)
	{
		cout<<"saisir les dimensions du rectangle\n""Longeur:\n"<<endl;
		cin>>L;
		cout<<"Largeur:\n"<<endl;
		cin>>l;

		A=L*l;

		cout<<"l'aire du rectangle est de:"<<A<<endl;
		
		cout<<"Si vous voulait arréter saisir 0"<<endl;
		cin>>i;
		if (i==0)
			{
				break;
			}
			else
			{
				cout<<"on continue"<<endl;
			}
	}
	return 0;
}