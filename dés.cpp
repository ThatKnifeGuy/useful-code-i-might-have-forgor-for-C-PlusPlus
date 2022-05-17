#include <iostream>
#include "dés.h"


De::De(unsigned int val){
	srand(time(NULL));           
	valeur = rand() % val + 1;
}

De::~De(){
}

unsigned int De::lancer(unsigned int val){
	int valeurL;          
	valeurL = rand() % val + 1;
	valeur = valeurL;
}

unsigned int De::get_valeur(){
	return valeur;
}
