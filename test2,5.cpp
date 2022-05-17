/*Bernard alexandre
08/12/21
programme qui calcul la somme des carrés des n premiers entiers
*/
#include <iostream>
using namespace std;

/*-------------------------------------------partie fonctions---------------------------------------*/

int Somme(int n){
  int resultat,quo;

  quo=((n+1)*(2*n+1));

  resultat=(n*quo)/6;
  
  return resultat;
}
/*-------------------------------------------programme principal---------------------------------------*/

int main(int argc, char const *argv[])
{
	int val;

	cout<<"Entré votre nombre.."<<endl;

	cin>>val;

	cout<<Somme(val)<<endl;



	return 0;
}

