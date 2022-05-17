/*Bernard alexandre
29/09/21
programme de saisie de valeurs
*/
#include <iostream>
using namespace std;
int main(int argc, char*argv[])
{
	int i;
	cin>>i;
	if (i*10>100)
	{
		cout <<"la valeur,"<<i<<",multipliée par 10 est supérieur à 100"<<endl;
	}
	else
	{
		cout<<"la valeur,"<<i<<",multipliée par 10 est inférieur à 100"<<endl;
	}
	return 0;
}

