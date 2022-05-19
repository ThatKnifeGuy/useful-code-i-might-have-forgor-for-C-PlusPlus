#include <iostream>
using namespace std;

#include "Base.h"

int main()
{

  
  Base *base = new Base("127.0.0.1", "root", "root", "sn11", 3306);


  
  if (base->get_myok())
  {
    cout << "connecté" << endl;
    
    base->inserer("benfucémoi", "humphrey");
    
  }
  else
    cout << "pas connecté" << endl;
  
  
  delete base;
  
  return 0;
}
