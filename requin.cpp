#include <iostream>
#include "requin.h"
using namespace std;

unsigned short requin::get_nbDents(){
	return nbDents;
}

unsigned short requin::get_masse(){
	return masse;
}

void requin::manger(unsigned short m,unsigned short S){
	if (nbDents<=5)
	{
		cout<<"le requin n'a plus assez dents pour manger et mourra de faim"<<endl;
		cout<<"                    ▒▒▒▒                                    "<<endl; 
   		cout<<"                     ▒▒▒▒▒▒                                 "<<endl; 
   		cout<<"                     ▒▒░░░░▒▒                               "<<endl; 
    	cout<<"                       ▒▒░░░░▒▒                             "<<endl; 
    	cout<<"                       ▒▒░░░░▒▒                             "<<endl; 
    	cout<<"                       ▒▒░░░░░░▒▒                           "<<endl; 
    	cout<<"                       ▒▒░░░░░░▒▒                           "<<endl; 
    	cout<<"                       ▒▒░░░░░░▒▒                           "<<endl; 
    	cout<<"                       ▒▒░░░░░░░░▒▒                         "<<endl; 
    	cout<<"                         ▒▒░░░░░░▒▒▒▒                       "<<endl; 
    	cout<<"                         ▒▒░░░░░░░░▒▒▒▒                     "<<endl; 
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
    	cout<<"    ▒▒░░░░░░░░░░░░░░░░██  ██░░░░░░▒▒░░▒▒░░    ░░            "<<endl;
    	cout<<"  ░░░░░░░░░░░░░░░░░░░░  ██  ░░░░░░▒▒░░    ░░░░░░            "<<endl;
   	 	cout<<"  ▒▒░░░░░░░░░░░░░░░░░░██  ██░░░░      ▒▒▒▒▒▒▒▒▒▒░░░░        "<<endl;
    	cout<<"    ▒▒░░░░░░░░░░░░░░░░            ▒▒▒▒          ▒▒▒▒░░      "<<endl;
    	cout<<"      ▒▒▒▒              ▒▒▒▒▒▒▒▒▒▒                  ▒▒▒▒    "<<endl;
    	cout<<"          ░░░░░░░░░░░░░░                                ░░░░"<<endl;
    	cout<<"                   GAME            OVER                     "<<endl;
	}
	else
	{
		if (nbDents <= 50) //mange moins bien si la moitiés des dents sont perdue
		{
			m=masse+2;
			masse=m;
		}
		else
		{
			m=masse+4;
			masse=m;
		}

		if (masse>284) //limite de son poid
		{
			cout<<"le requin ne peut pas prende plus que le double son poid"<<endl;
			masse=284;
		}

		if (S>=3)
		{
			cout<<"le requin vien de perdre une dents après avoir manger"<<endl;
			nbDents = nbDents-1;
		}

		if (S>=6)
		{
			cout<<"le requin vien de perdre plus de dents après avoir tros manger"<<endl;
			nbDents = nbDents-3;
		}
	}
}

void requin::nager(unsigned short SS){
	int choix,distance,nage;

	cout<<"---------------------------------------------------------------"<<endl;
	cout<<"vous le laisser nager comme il veut ou vous donner la distance?\n(1 pour le laisser,2 pour choisir)"<<endl;
	cout<<"----------------------------------"<<endl;
	
	cin>>choix;

	if (choix==1)
	{
		masse=masse-1; //perd 1kg tous les 10 m
	}
	else if(choix==2)
	{
		cout<<"de combien de mètre notre requin vas nager?\n(valeurs au-dessus de 1420m donne au requin son poid d'origine)"<<endl;
		cin>>distance;

		nage=distance/10;
		masse=masse-nage;
		nbDents=nbDents+nage;

		if (masse<142)
		{	
			cout<<"le requin ne peut pas perdre plus que son poid de naissance"<<endl;
			masse=142;
		}
	}

	if (nbDents>=300)
		{
			cout<<"le requin a ateint tout ces dents"<<endl;
			nbDents=300;
		}

	if (SS>=3)
	{
		if (nbDents>=300)
		{
			cout<<"le requin a ateint tout ces dents"<<endl;
			nbDents=300;
		}
		else
		{
			cout<<"le requin vien de re-pousser une dents après avoir bien nager"<<endl;
			nbDents = nbDents+1;
		}
	}

}

requin::requin(int value1,int value2){
	masse=value1;
	nbDents=value2;
}

requin::~requin(){
}

