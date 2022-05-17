/*Bernard alexandre
10/11/21
programme qui demande la date d'anniv et qui donne l'age,mois et jour de la personne
*/
#include <iostream>
#include <ctime>
using namespace std;

int main(int argc, char const *argv[])
{
  int age,annee,annee1,mois,mois1,mois2,jour,jour1,jour2;

  time_t temps = time(NULL); /*prend la date du moments depuis 1970*/

  cout<<"Quand est votre anniversaire?\n"<<"jour:"<<endl;
  cin>>jour;
  cout<<"mois:\n"<<endl;
  cin>>mois;
  cout<<"annee:"<<endl;
  cin>>annee;


  struct tm *now = localtime(&temps);

  annee1 = 1900 + now->tm_year;
  mois1 = now->tm_mon + 1;
  jour1 = now->tm_mday - 1;

  age= annee1-annee;
  jour2= jour1-jour;
  mois2= mois1-mois;

  if (jour2<0)
  {
    mois2=mois2-1;
    jour2=jour2+31;
  }

  cout << "vous avez: "<<age<<"ans,"<<mois2<<"mois et "<<jour2<<"jour"<<endl;

  return 0;
}


