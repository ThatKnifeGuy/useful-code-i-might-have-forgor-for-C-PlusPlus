#include "Base.h"
#include <iostream> 


using namespace std;

Base::Base(string host, string user, string passwd, string db, uint port):Mysql(host,user,passwd,db,port)
{

}

Base::~Base()
{

}

void Base::inserer(string nom, string prenom)
{

}	


