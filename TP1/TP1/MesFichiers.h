#ifndef MESFICHIERS_H
#define MESFICHIERS_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include "LesParties.h"

using namespace std;

class Global
{
	string total, nb, pourcent;
	
	public:
		Global(){};
		
		Global(string total, string nb, string pourcent = "Null")
		{
			this->total = total;
			this->nb = nb;
			this->pourcent = pourcent;
		}
		
		friend ostream& operator << (ostream&, const Global&);
};
ostream& operator << (ostream& sortie, const Global& s)
{
	sortie << left << s.total << ":" << 
			  setw(45) << left << s.nb << endl;
	
	return sortie;
}

class MesFichiers
{	
	
	int error = 0;
	ifstream fIndiv, fGlobal;
	
public:
	MesFichiers(){};

	bool ok(string indiv, string global)
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
	
	void lireGlobal(const string& fichier, Global tab[], int& n)
	{
		string total, nb, pourcent;
		n = 0;
		
		ifstream fGlobal(fichier);
		
		while(!fGlobal.eof())
		{
			getline(fGlobal, total, ',');
			getline(fGlobal, nb, ',');
			getline(fGlobal, pourcent, '%');
			tab[n++] = Global(total, nb, pourcent);
		}
		
	}
// lis le fichier des résultats pour chaque partie et remplis un tableau de partie.
	void lireParties(const string& fichier, LesParties parties[], int & n)
	{   
		string nbVote, nbCandi, nbElu;
		string tauxVote;
		string no, nom, abrv;
		string lu;
		n = -1;
		
		ifstream  fIndiv (fichier); // localiser et ouvrir pour la lecture

		while (!fIndiv.eof())
		{
			getline(fIndiv, no, ',');
			getline(fIndiv, nom, ',');
			getline(fIndiv, abrv, ',');
			getline(fIndiv, nbVote, ',');
			getline(fIndiv, tauxVote, ',');
			getline(fIndiv, nbCandi, ',');
			getline(fIndiv, nbElu, '\n');

			if(n == -1)
			{
				n++;
			}
			else 
			{
				parties[n++] = LesParties(no, nom, abrv, nbVote, tauxVote, nbCandi, nbElu); 
			}
		}
		fIndiv.close();   
	}
// crée et ouvre un fichier de sortie selon le nom donné par l'utilisateur et sert pour la sortie des informations.
/*	void sortie(const string& fichier)
	{
		ofstream out(fichier);
		if(!fichier.is_open())
			cerr << "Erreur lors de l’ouverture/écriture dans le fichier " << fichier << endl;
	}
	
	int getError()
	{
		return error;
	}

	void affiche(char sel)
	{
		cout << "Individuel\n";
	}*/
};


#endif // MESFICHIERS_H
