/*Bernard alexandre
24/11/21
programme qui calcul le millieu d'un segement
*/
#include <iostream>
using namespace std;

/*-------------------------------------------partie fonctions---------------------------------------*/
void Msegement(double xA,double xB,double yA,double yB)
{

	double x;
	double y;

	x = (xA + xB)/2;
	y = (yA + yB)/2;

	cout<<"les coordonners du milieu du segment A et B sont: x="<<x<<" et y="<<y<<endl;
}


/*-------------------------------------------programme principal---------------------------------------*/

int main(int argc, char const *argv[])
{
	double x1,x2,y1,y2;

	cout<<"renseigner x et y de A, et x et y de B"<<endl;

	cin>>x1;
	cin>>x2;
	cin>>y1;
	cin>>y2;

	Msegement(x1, x2, y1, y2);

	return 0;
}