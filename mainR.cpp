#include <iostream>
using namespace std;
#include "requin.h"

int main(int argc, char const *argv[])
{
	int vote = 0;
	int suiteM= 0;
	int suiteN = 0;
	int diner,menu = 1;

	requin MD(142,300);

	while (menu>=1)
	{
		if (MD.get_nbDents()<=5)
		{
			MD.manger(diner,suiteM);
			break;
		}
		else
		{
			cout<<"                 voici notre requin                         "<<endl;
			cout<<"                    ▒▒▒▒                                    "<<endl; 
   			cout<<"                     ▒▒▒▒▒▒                                 "<<endl; 
   			cout<<"                     ▒▒░░░░▒▒                               "<<endl; 
    		cout<<"                       ▒▒░░░░▒▒                             "<<endl; 
    		cout<<"                       ▒▒░░░░▒▒                             "<<endl; 
    		cout<<"                       ▒▒░░░░░░▒▒                           "<<endl; 
    		cout<<"                       ▒▒░░░░░░▒▒                           "<<endl; 
    		cout<<"                       ▒▒░░░░░░▒▒                           "<<endl; 
    		cout<<"                       ▒▒░░░░░░░░▒▒                         "<<endl; 
    		cout<<" nombre de dents         ▒▒░░░░░░▒▒▒▒        son poids en kg"<<endl; 
    		cout<<"  "<<MD.get_nbDents()<<"                    ▒▒░░░░░░░░▒▒▒▒             "<<MD.get_masse()<<"          "<<endl; 
    		cout<<"                         ▒▒░░░░░░▒▒▒▒░░▒▒▒▒                 "<<endl; 
    		cout<<"                       ▒▒░░░░░░▒▒░░▒▒░░░░░░▒▒               "<<endl; 
    		cout<<"                       ▒▒░░░░▒▒▒▒░░▒▒░░░░░░░░▒▒             "<<endl; 
    		cout<<"                       ▒▒░░▒▒  ▒▒░░▒▒░░░░░░░░░░▒▒           "<<endl; 
    		cout<<"                       ▒▒▒▒  ▒▒░░░░▒▒░░░░░░░░░░░░▒▒         "<<endl; 
   		 	cout<<"                             ▒▒░░░░░░░░░░░░░░░░░░▒▒         "<<endl; 
    		cout<<"                         ▒▒▒▒░░░░░░░░░░░░░░░░░░░░░░▒▒       "<<endl; 
    		cout<<"                       ▒▒░░▒▒░░░░░░░░░░░░░░░░░░░░░░▒▒       "<<endl; 
    		cout<<"                   ▒▒▒▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒       "<<endl; 
    		cout<<"               ▒▒▒▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒▒▒     "<<endl; 
    		cout<<"             ▒▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒▒▒▒▒▒▒ "<<endl;
    		cout<<"           ▒▒░░░░░░░░░░░░░░░░░░░░░░▒▒░░░░░░░░░░░░░░▒▒       "<<endl;
    		cout<<"         ▒▒░░░░░░░░░░░░░░░░░░░░▒▒░░░░▒▒░░░░░░░░░░░░▒▒       "<<endl;
    		cout<<"        ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░        "<<endl;  
    		cout<<"      ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒░░▒▒░░░░░░  ▒▒        "<<endl; 
    		cout<<"    ▒▒░░░░░░░░░░░░░░░░░░  ░░░░░░░░▒▒░░▒▒░░    ░░            "<<endl;
    		cout<<"  ░░░░░░░░░░░░░░░░░░░░  ██  ░░░░░░▒▒░░    ░░░░░░            "<<endl;
   		 	cout<<"  ▒▒░░░░░░░░░░░░░░░░░░░░  ░░░░░░      ▒▒▒▒▒▒▒▒▒▒░░░░        "<<endl;
    		cout<<"    ▒▒░░░░░░░░░░░░░░░░            ▒▒▒▒          ▒▒▒▒░░      "<<endl;
    		cout<<"      ▒▒▒▒              ▒▒▒▒▒▒▒▒▒▒                  ▒▒▒▒    "<<endl;
    		cout<<"          ░░░░░░░░░░░░░░                                ░░░░"<<endl;

			cout<<"voulez-vous le nourrir?(1 pour oui,2 pour non)"<<endl;
			cin>>vote;

			if (vote==1) //pour manger
			{
				MD.manger(diner,suiteM);
				suiteM=suiteM+1;
				suiteN=0;

			}	
			else if (vote==2) //pour nager
			{
				MD.nager(suiteN);
				suiteN=suiteN+1;
				suiteM=0;
			}

			cout<<"------------------------"<<endl;
			cout<<"notre requin à "<<MD.get_nbDents()<<" dents"<<endl;
			cout<<"et a une masse de "<<MD.get_masse()<<" kg"<<endl;
			cout<<"------------------------"<<endl;

			cout<<"voulez vous arreter?(1 pour non,0 pour oui)"<<endl;
			cin>>menu;

			if (menu==0)
			{
				break;
			}
		}
			

	}		
	return 0;
}
