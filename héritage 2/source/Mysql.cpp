/*
 *                    GNU GENERAL PUBLIC LICENSE
 *                       Version 3, 29 June 2007
 * 
 *    classe Mysql : classe utile pour gérer une connexion à un serveur mySql en langage c++
 *    cette classe peut être utilisée comme classe mère ou directement pour un développement objet.
 * 
 *    Elle n'est pas terminée et pourrait être améliorée en utilisant des vector ou/et liste pour gérer
 *    des objets grâce à des templates.
 * 
 *    à compiler avec la commande suivante :
 *    g++ *.cpp  -lmysqlclient  -I/usr/include/mysql/
 * 
 *    Copyright (C) 2014  françois GUILLET
 * 
 *    This program is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 * 
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 * 
 *    You should have received a copy of the GNU General Public License
 *    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#include "Mysql.h"



// conversion de DATE : YYYY-MM-DD en struct tm
struct tm Mysql::getDate(string date)
{
  struct tm retour;
  string annee = date.substr (0, 4);
  string mois = date.substr (5, 2);
  string jour = date.substr (8, 2);
  
  retour.tm_hour = 0;
  retour.tm_min = 0;
  retour.tm_sec = 0;
  retour.tm_year = atoi(annee.c_str()) - 1900;
  retour.tm_mon = atoi(mois.c_str());
  retour.tm_mday = atoi(jour.c_str());
  
  return retour;
}

// conversion de DATETIME, TIMESTAMP : YYYY-MM-DD HH:MM:SS en struct tm
struct tm Mysql::getDatetime(string datetime)
{
  struct tm retour;
  string annee = datetime.substr (0, 4);
  string mois = datetime.substr (5, 2);
  string jour = datetime.substr (8, 2);
  string heure = datetime.substr (11, 2);
  string minute = datetime.substr (14, 2);
  string seconde = datetime.substr (17, 2);
  
  retour.tm_hour = atoi(heure.c_str());
  retour.tm_min = atoi(minute.c_str());;
  retour.tm_sec = atoi(seconde.c_str());;
  retour.tm_year = atoi(annee.c_str()) - 1900;
  retour.tm_mon = atoi(mois.c_str());
  retour.tm_mday = atoi(jour.c_str());
  
  return retour;
}

// conversion de TIME : HHH:MM:SS en struct tm
struct tm Mysql::getTime(string time)
{
  int pos2point = time.find (":");
  int heure = atoi(time.substr (0, pos2point).c_str());
  int minute = atoi(time.substr(pos2point + 1 , 2).c_str());
  int seconde = atoi(time.substr(pos2point + 4 , 2).c_str());
  
  struct tm retour;
  retour.tm_hour = heure;
  retour.tm_min = minute;
  retour.tm_sec = seconde;
  retour.tm_year = 0;
  retour.tm_mon = 0;
  retour.tm_mday = 0;
  
  return retour;
}

// conversion de YEAR : YY ou YYYY en struct tm
struct tm Mysql::getYear(string year)
{
  struct tm retour;
  retour.tm_hour = 0;
  retour.tm_min = 0;
  retour.tm_sec = 0;
  retour.tm_year = 0;
  retour.tm_mon = 0;
  retour.tm_mday = 0;
  
  if (year.size() == 4)
    retour.tm_year = atoi(year.c_str()) - 1900;
  else
    retour.tm_year = atoi(year.c_str());
  return retour;
}

// constructeur : ouvre si possible la base de données "bd" en utilisant le "port" (mettre à 0 si inconnu)
// "host" est le serveur qui héberge la base
// "user" et "passwd" sont les login et mot de passe de l'utilisateur autorisé à se connecter à cette base.
Mysql::Mysql(string host, string user, string passwd, string db, unsigned int port){
  Mysql::ptrbd = mysql_init(NULL);
  Mysql::myok = false;
  
  //        cout << user.c_str() << endl;
  
  // se connecter à la base : 
  Mysql::ptrbd = mysql_real_connect(
    Mysql::ptrbd,	// pointeur retourné par mysql_init
    host.c_str(),	//hôte abritant le serveur mysql : nom de domaine, adresse IP ou "localhost" ou "127.0.0.1"
    user.c_str(),	//identifiant MySQL de l'utilisateur
    passwd.c_str(), //mot de passe de l'utilisateur
    db.c_str(),	// nom de la base de donnée à laquelle on se connecte
    port,		// port (0 si on ne le connaît pas ou alors le vrai port (3306))
  NULL,		// socket unix ou tunnel nommé à utiliser
  0		// client_flag qui peut spécifier des options (voire doc mysql)
  );
  
  result = NULL;
  
  
  if (ptrbd != NULL)
  {
    Mysql::myok  = true;
    
    // pour avoir une transaction en utf8 : 
    mysql_query(ptrbd, "SET NAMES utf8");
  }
  else
  {
    printf("Impossible de se connecter à la base de données, erreur : %s\n",
	    mysql_error(ptrbd));
    
  }
}

Mysql::~Mysql(){
  if (result)
    mysql_free_result(result);
  if (myok)
    mysql_close(Mysql::ptrbd);
  menageMapData();
}

// retourne la valeur de la connexion
// 1 : connexion ok, 0 : pb
bool Mysql::get_myok() {
  return Mysql::myok;
}

// execute la requete "query" sur la base
// retourne :
//	le nombre de ligne affectée par une requete de type "update" ou "delete"
//	l'identifiant d'une colonne auto-incrément générée par une requete de type "insert" (mysql_insert_id())
//	le nombre de ligne sélectionnée par une requete de type "select" (mysql_num_rows)
//	un nombre négatif en cas d'erreur dont la valeur absolue représente le type d'erreur
int Mysql::execQuery(string query) {
  
  // on efface le resultat précédent : 
  mysql_free_result(result);
 
  int retour = mysql_real_query(Mysql::ptrbd, query.c_str(), query.size());
  //	mysql_query(MYSQL *mysql, const char *query)
  // traitement des erreurs de requête
  if (retour > 0)
  {
//     switch(retour)
//     {
// 	case CR_COMMANDS_OUT_OF_SYNC : cout << "Les commandes n'ont pas ete executees dans le bon ordre." << endl;
// 	case CR_SERVER_GONE_ERROR : cout << "Le serveur MySQL ne réponds pas." << endl;
// 	case CR_SERVER_LOST : cout << "La connexion au serveur a ete perdue au cours la requete." << endl;
// 	case CR_UNKNOWN_ERROR : cout << "Une erreur inconnue s'est produite." << endl;
//     }
//     
//     return -retour;
  }
  
  // si on arrive ici, c'est qu'il n'y a pas d'erreur
  result = mysql_store_result(Mysql::ptrbd);
  
  // si la requete query est non sélective (insert, update, delete) ou erreur
  if (result == NULL)
  {
    // on écarte l'erreur : 
    if (mysql_error(Mysql::ptrbd) != NULL)
    {
      return -mysql_errno(Mysql::ptrbd);
    }
    else
    {
      // si on a une requete de type "insert", on retourne le lastInsertId
      
      // étude de la requête : savoir si elle est de type select :
      // pour cela on travaille sur une copie :
      string requete = query;
      // trim (enlève les espaces au début et à la fin)
      while (requete[0] == ' ')  {requete.erase (requete.begin());}
      while (requete[requete.length() - 1] ==  ' '){requete.erase (requete.end()-1);}
      // on passe tout en minuscule
      for (int i = 0; i < requete.length(); i++)
	requete[i] = tolower(requete[i]);
      string insert = requete.substr (0,6);
      
      // si c'est une requête d'insertion on retourne le lastInsertId
      if (insert == "insert")
	return  (int) mysql_insert_id(Mysql::ptrbd);
      // sinon on retourne le nomre de ligne affectées (requete de type delete ou update)
	else
	  return (int) mysql_affected_rows(Mysql::ptrbd);
    }	
  }
  else
  {
    // mise à jour de la map des données ...
    miseAJourMapData();
//     return (int)result;
    // retourne qqchose si c'est une requete de type select
    return 0;
  }
}

//renvoie la dernière erreur lièe à la connexion courante.
string Mysql::getLastError() {
  return string(mysql_error(Mysql::ptrbd));
}

// cette méthode privée permet d'effacer toute les données 
// de mapData. 
void Mysql::menageMapData() {
  // déclaration d'un itérateur pour le parcours de la map :
  map<string, vector<char*> >::iterator i;
  // parcours mapData
  for( i = mapData.begin(); i != mapData.end(); ++i){
    vector<char*> vecteurChamp = (*i).second;
    vecteurChamp.clear();
  }
  mapData.clear();
}

//Cette méthode privée met à jour l'attribut mapData.
void Mysql::miseAJourMapData() {
  
  // initialisation de mapData :
  // on fait d'abord le ménage :
  menageMapData();

  // et puis on y va :
  MYSQL_ROW ligne_courante;	// une ligne issue d'une requête mysql
  nbChamps = mysql_num_fields(result);
  tabChamps = mysql_fetch_fields(result);
  
  for (int i = 0; i < nbChamps; i++)
  {
    vector<char*> vecteurChamp;
    mapData.insert(pair<string, vector<char*> >(string(tabChamps[i].name), vecteurChamp));
  }
  
  // remplissage de mapData : ligne par ligne
  while ((ligne_courante = mysql_fetch_row(result)))
  {
    unsigned long *lengths;
    lengths = mysql_fetch_lengths(result);
    
    for (int i = 0; i < nbChamps; i++)
    {
      if(ligne_courante[i])
      {
	mapData[string(tabChamps[i].name)].push_back(ligne_courante[i]);
      }
      else
	mapData[string(tabChamps[i].name)].push_back(NULL);
    }
  }
}

