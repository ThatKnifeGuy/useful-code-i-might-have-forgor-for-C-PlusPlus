/*Bernard alexandre
10/11/21
programme qui demande l'age et qui en fonction de l'age,donne l'année de naissance
*/
#include <iostream>
#include <ctime>
using namespace std;

int main(int argc, char const *argv[])
{
  int age,annee,anniv;

  time_t temps = time(NULL); /*prend la date du moments depuis 1970*/

  cout<<"Quel est votre age?"<<endl;
  cin>>age;

  struct tm *now = localtime(&temps);

  annee = 1900 + now->tm_year;

  anniv=annee-age;

  cout << "vous êtes née en: " << anniv<< endl;

  return 0;
}
