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
#include "mysql.h"
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream> 
#include <vector>
#include <map>
#include <string>
#include <cstdio>
using namespace std;

#ifndef _MYSQL_H
#define _MYSQL_H


#include <map>
using namespace std;
#include <vector>
using namespace std;

//Cette classe est la classe de base pour la gestion d'une base de données MySql.
//À compiler avec la ligne suivante : 
//g++ *.cpp  -lmysqlclient  -I/usr/include/mysql/
class Mysql {
  public:
    // constructeur : ouvre si possible la base de données "bd" en utilisant le "port" (mettre à 0 si inconnu)
    // "host" est le serveur qui héberge la base
    // "user" et "passwd" sont les login et mot de passe de l'utilisateur autorisé à se connecter à cette base.
    Mysql(string host, string user, string passwd, string db, unsigned int port);

    ~Mysql();

    // retourne la valeur de la connexion
    // 1 : connexion ok, 0 : pb
    bool get_myok();

    // execute la requete "query" sur la base
    // retourne :
    //	le nombre de ligne affectée par une requete de type "update" ou "delete"
    //	l'identifiant d'une colonne auto-incrément générée par une requete de type "insert" (mysql_insert_id())
    //	le nombre de ligne sélectionnée par une requete de type "select" (mysql_num_rows)
    //	un nombre négatif en cas d'erreur dont la valeur absolue représente le type d'erreur
    int execQuery(string query);

    //renvoie la dernière erreur lièe à la connexion courante.
    string getLastError();

    //map des données :
    // - string vaut le nom du champ
    // - vector<char*> représente le vecteur des données associé au champ.
    //les éléments de ce vector sont des char*, il appartiendra à l'utilisateur (ou à la classe dérivée)
    //de caster les éléments dans le type de données du champ.
    inline const map<string, vector<char*> > & get_mapData() const;

    //pointeur sur l'ensemble des champs solicités par la requête : 
    //c'est une struture où l'on trouve :
    //  name --------> le nom du champs
    //  type ---------> le type du champs (FIELD_TYPE_TINY, FIELD_TYPE_SHORT, ...)
    //  length -------> la taille maximum que peut prendre le champs.
    //  max_length -> la taille maximum atteinte actuellement par le champs.
    //On accède à ces information par : tabChamps[i].name
    //ce pointeur est mis à jour grâce à la fonction : mysql_fetch_fields(result);
    //où result est le pointeur sur les résultats.
    //Les type des champs sont accessibles en incluant "mysql.h"
    inline const MYSQL_FIELD * get_tabChamps() const;

    //nombre de champs de tabChamps. (voir MYSQL_FIELD * get_tabCamps()).
    inline const unsigned long get_nbChamps() const;


  private:
    //le pointeur sur la structure MYSQL
    //il est créé par la mysql_init(NULL), et mis à jour la fonction mysql_real_connect(...)
    //qui réalise la connexion.
    MYSQL * ptrbd;

    // indique si la connexion est ok.
    // true : connexion ok, false : pb
    bool myok;

    //champ de résultat d'une requête : 
    //vaut NULL si la requête était de type insert, delete ou update.
    //sinon (si c'était une requête sélective) ce pointeur désigne le champ de résultat.
    //on l'obtient gràce à la fonction : mysql_store_result(ptrbd);
    //où ptrbd désigne un pointeur sur une structure MYSQL.
    MYSQL_RES * result;

    //map des données :
    // - string vaut le nom du champ
    // - vector<char*> représente le vecteur des données associé au champ.
    //les éléments de ce vector sont des char*, il appartiendra à l'utilisateur (ou à la classe dérivée)
    //de caster les éléments dans le type de données du champ.
    map<string, vector<char*> > mapData;

    //pointeur sur l'ensemble des champs solicités par la requête : 
    //c'est une struture où l'on trouve :
    //  name --------> le nom du champs
    //  type ---------> le type du champs (FIELD_TYPE_TINY, FIELD_TYPE_SHORT, ...)
    //  length -------> la taille maximum que peut prendre le champs.
    //  max_length -> la taille maximum atteinte actuellement par le champs.
    //On accède à ces information par : tabChamps[i].name
    //ce pointeur est mis à jour grâce à la fonction : mysql_fetch_fields(result);
    //où result est le pointeur sur les résultats.
    //Les type des champs sont accessibles en incluant "mysql.h"
    MYSQL_FIELD * tabChamps;

    //nombre de champs de tabChamps
    unsigned long nbChamps;

    // cette méthode privée permet d'effacer toute les données 
    // de mapData. 
    void menageMapData();

    //Cette méthode privée met à jour l'attribut mapData.
    void miseAJourMapData();
    
    // différentes méthodes permettant de renvoyer une 
    // struct tm en C, à partir de formats de date retournés par mysql
    struct tm getYear(string year);
    struct tm getTime(string time);
    struct tm getDatetime(string datetime);
    struct tm getDate(string date);
    

};
inline const map<string, vector<char*> > & Mysql::get_mapData() const {
  return mapData;
}

inline const MYSQL_FIELD * Mysql::get_tabChamps() const {
  return tabChamps;
}

inline const unsigned long Mysql::get_nbChamps() const {
  return nbChamps;
}

#endif
