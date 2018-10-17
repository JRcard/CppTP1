#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <getopt.h>
#include <iomanip>
#include <string>
#include "MesOptions.h"
#include "MesFichiers.h"
#include "MonMenu.h"
#include "LesParties.h"

using namespace std;

bool ok(string indiv, string global)
{	
	int error = 0;
	ifstream fIndiv (indiv);
	ifstream fGlobal (global);
	
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
	
void lireRemplir(const string& fichier, LesParties parties[], int & n)
{   
	string nbVote, nbCandi, nbElu;
	string tauxVote;
	string no, nom, abrv;
	string lu;
	
	//istringstream aLire (fichier);
	
	ifstream  aLire (fichier, ios::in); // localiser et ouvrir pour la lecture
	
	n = 0;
// test 1
/*	while (aLire >> no >> nom >> abrv >> nbVote >> tauxVote >> nbCandi >> nbElu)     
	{ 
		parties[n++] = LesParties(no, nom, abrv, nbVote, tauxVote, nbCandi, nbElu); 
	}*/
	
// fin du test 1

	
// test 2
	while (!aLire.eof())
	{
		getline(aLire, no, ',');
		getline(aLire, nom, ',');
		getline(aLire, abrv, ',');
		getline(aLire, nbVote, ',');
		getline(aLire, tauxVote, ',');
		getline(aLire, nbCandi, ',');
		getline(aLire, nbElu, '\n');
		cout << n++ << " TEST!!! " << "NO: " << no << " Nom: "<< nom << endl;
/*		
		no = get(lu, 2, ',');*/
		
/*		no = get(lu, 2, ',');
		
		parties[n++] = LesParties(no, nom, abrv, nbVote, tauxVote, nbCandi, nbElu);*/    
	}
	// fin du test 2.
	//aLire.close();   
}

int main(int argc, char* argv[])
{
	const int MAX_PARTIES = 20 ;
	int nbPartie;
	MonMenu menu;
	MesOptions options;
	MesFichiers fichiers;
	LesParties partie[MAX_PARTIES];

	options.setOpt(argc, argv);
	cout << "erreur d'option: " << options.getError() << endl;

	if (options.getStatus())
	{
		/*fichiers(options.getdFlg(), options.getrFlg());*/

		if (ok(options.getdVal(), options.getrVal()))
		{
			// lire fichier et remplir tab de partie
			lireRemplir(options.getdVal(), partie, nbPartie);
			// lire fichier global et attendre l'appel
			cout << menu;
			//menu.menuOpt();
			cout << "Nb de partie: " << nbPartie << endl;
			partie[2].affiche();
		}
		
		else cout << "erreur de fichier: " << fichiers.getError() << endl;
	}

	return 0;
}
