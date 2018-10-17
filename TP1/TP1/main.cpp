#include <cstdio>
#include <cstdlib>
#include <getopt.h>
#include <iomanip>
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
	
void lireRemplir(const char nomALire[], LesParties parties[], int & n)
{   
	int no, nbVote, nbCandi, nbElu;
	float tauxVote;
	string nom, abrv;
	char lu[200];
	
	ifstream  aLire (nomALire, ios::in); // localiser et ouvrir pour la lecture
	
	n = 0;
// test 1
/*	while (aLire >> no >> nom >> abrv >> nbVote >> tauxVote >> nbCandi >> nbElu)     
	{ 
		parties[n++] = LesParties(no, nom, abrv, nbVote, tauxVote, nbCandi, nbElu); 
	}*/
	
// fin du test 1

	
// test 2
	while (getline(aLire, lu, '\n'))
	{
		cout << lu << endl;
		parties[n++] = LesParties(no, nom, abrv, nbVote, tauxVote, nbCandi, nbElu);               
	}
	// fin du test 2.
	aLire.close();   
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

		if (ok(options.getdFlg(), options.getrFlg()))
		{
			// lire fichier et remplir tab de partie
			lireRemplir(options.getdFlg(), partie, nbPartie);
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
