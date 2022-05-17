/*Bernard alexandre
07/12/21
programme qui donne la valeur absolue d'un short
*/
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	short val;

	cout<<"Entré votre nombre.."<<endl;

	cin>>val;

	cout<<"la valeur absolue de votre nombre est : "<<abs(val)<<endl;


	return 0;
}