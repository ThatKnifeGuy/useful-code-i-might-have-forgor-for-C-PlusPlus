#ifndef _Base_h
#define _Base_h
#include <iostream> 
#include "Mysql.h"

using namespace std;

class Base : public Mysql
{
	public:
		Base(string host, string user, string passwd, string db, uint port);
		~Base();
		void inserer(string nom, string prenom);
};
#endif