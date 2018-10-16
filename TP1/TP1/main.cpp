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
	
void lireRemplir(string nomALire, LesParties parties[], int & n)
{   
	int no, nbVote, nbCandi, nbElu;
	float tauxVote;
	string nom, abrv, lu;
	
	ifstream  aLire (nomALire, ios::in); // localiser et ouvrir pour la lecture
	
	n = 0;
// test 1
/*	while (aLire >> no >> nom >> abrv >> nbVote >> tauxVote >> nbCandi >> nbElu)     
	{ 
		parties[n++] = LesParties(no, nom, abrv, nbVote, tauxVote, nbCandi, nbElu); 
	}*/
	
// fin du test 1

	string ligneLue;
	
// test 2
	while (getline(aLire, ligneLue, '\n'))
	{
        no = ligneLue[1];
		nom = ligneLue.substr(2,62);	
		abrv  = ligneLue.substr(63,83);	
		nbVote = atoi(ligneLue.substr(84,94).c_str()); // conversion de la chaine de caractere en nombre entier
		tauxVote = atof(ligneLue.substr(95, 107).c_str()); 
		nbCandi = atoi(ligneLue.substr(108, 123).c_str()); 
		nbElu = atoi(ligneLue.substr(124).c_str());
		
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
