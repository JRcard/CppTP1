#ifndef MESFICHIERS_H
#define MESFICHIERS_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include "LesParties.h"

using namespace std;

class MesFichiers
{	
	
	int error = 0;
	ifstream fIndiv, fGlobal;
	
public:
	MesFichiers(){};

	/*bool ok(string indiv, string global)
	{	

		fIndiv.open(indiv);
		fGlobal.open(global);
		
		if  (!fIndiv.is_open())
		{
			cerr << "Erreur lors de la lecture du fichier : " << indiv << endl;
			error++;
		}
		if (!fGlobal.is_open())
		{
			cerr << "Erreur lors de la lecture du fichier : " << global << endl;
			error++;
		}
	
		if (error > 0) return false;
		else return true;
		
		fIndiv.close();
		fGlobal.close();
	}
	
void lireRemplir(string nomALire, LesParties& p)
{   int no, nbVote, nbCandi, nbElu;
	float tauxVote;
	string nom, abrv;
	
	ifstream  aLire (nomALire, ios::in); // localiser et ouvrir pour la lecture
	
	int n = 0;
	while (aLire >> no >> nom >> abrv >> nbVote >> tauxVote >> nbCandi >> nbElu)     
	{ 
	string ligneLue;
	
// tant que getline peut lire une ligne dans le fichier aLire jusqu'au caractere de demilitation \n et la placer dans ligneLue
// les données seront placées dans les variables qui serviront a instancifier les Nations placées ensuite dans la liste FIFO.
	while (getline(aLire, ligneLue, '\n'))
	{
        no = ligneLue[1];
		nom = ligneLue.substr(2,62);	
		abrv  = ligneLue.substr(63,83);	
		nbVote = atoi(ligneLue.substr(84,94).c_str()); // conversion de la chaine de caractere en nombre entier
		tauxVote = atof(ligneLue.substr(95, 107).c_str()); 
		nbCandi = atoi(ligneLue.substr(108, 123).c_str()); 
		nbElu = atoi(ligneLue.substr(124).c_str());
		
		p[n++] = LesParties(no, nom, abrv, nbVote, tauxVote, nbCandi, nbElu);               
	}
	aLire.close();   
}*/
	
	int getError()
	{
		return error;
	}

	void affiche(char sel)
	{
		cout << "mesfichiers\n";
	}
};

#endif // MESFICHIERS_H
