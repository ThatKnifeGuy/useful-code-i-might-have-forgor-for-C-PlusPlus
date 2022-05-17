/*Bernard alexandre
08/12/21
programme qui donne le factorielle d'un nombre
*/
#include <iostream>
using namespace std;

/*-------------------------------------------partie fonctions---------------------------------------*/

int facto(int n) {
  int resultat = 1;
  for(int i = 1; i <= n; i++) {
    resultat *= i;
  }
  return resultat;
}

/*-------------------------------------------programme principal---------------------------------------*/


int main(int argc, char const *argv[])
{
	int val;

	cout<<"Entré votre nombre.."<<endl;

	cin>>val;

	cout<<facto(val)<<endl;



	return 0;
}