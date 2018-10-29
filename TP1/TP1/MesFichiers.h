#ifndef MESFICHIERS_H
#define MESFICHIERS_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include "LesPartis.h"

using namespace std;

/* class permettant de créer un tableau avec les données inscrites dans le fichier rese2014sommaire.csv
   facilitant l'affichage par la suite. */
class Global
{
	string total, nb, pourcent;
	
	public:
		Global(){};
		
		/* constructeur avec les champs nécessaire à l'affichage.
		 * le paramètre pourcent est initialisé a "null" 
		 * puisqu'il n'y a pas de pourcentage à toutes les lignes du tableau dans le fichier source.*/
		 
		Global(string total, string nb, string pourcent = "Null")
		{
			this->total = total;
			this->nb = nb;
			this->pourcent = pourcent;
		}
		
		friend ostream& operator << (ostream&, const Global&);

};
// surcharge d'affichage de la class Global
ostream& operator << (ostream& sortie, const Global& s)
{
	sortie << left << setw(30) << s.total + ":" << "\t" 
		   << right << setw(10) << s.nb;
	
	return sortie;
}

/* L'ouverture, la vérification et la lecture des fichiers passés en argument du programme principal
   se fait par cette class.*/
class MesFichiers
{	
	
	int error = 0;
	ifstream fIndiv, fGlobal;
	
public:
	MesFichiers(){};

/* cette fonction membre vérifie la validité des fichiers à lire.
   elle affiche les messages d'erreur en plus de retourner un bool
   permettant au programme soit de continuer l'execution ou de fermer. */
   
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
		
		fIndiv.close();
		fGlobal.close();
		
		if (error > 0) return false;
		else return true;

	}
	/* lis le fichier des résultats sommaires et remplis un tableau de "Global" 
	 * permettant son affichage */
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
			nb.erase(remove(nb.begin(), nb.end(), ' '), nb.end());
			tab[n++] = Global(total, nb, pourcent);
		}
		fGlobal.close();
	}
	/*lis le fichier des résultats pour chaque parti et remplis un tableau de partie.*/
	void lirePartis(const string& fichier, LesPartis partis[], int & n)
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
				partis[n++] = LesPartis(no, nom, abrv, nbVote, tauxVote, nbCandi, nbElu); 
			}
		}
		fIndiv.close();   
	}
};


#endif // MESFICHIERS_H
