#include <fstream>
#include <iostream>
#include "MesOptions.h"
#include "MesFichiers.h"
#include "MonMenu.h"
#include "LesParties.h"

using namespace std;

int main(int argc, char* argv[])
{
	const int MAX_PARTIES = 20 ;
	int nbPartie;
	int nbGlobal;
	char option = '0';
	ofstream out;
	
	MesOptions options;
	MesFichiers fichiers;
	MonMenu menu;
	LesParties partie[MAX_PARTIES];
	Global global[MAX_PARTIES];

// récupère les options, les vérifies et affiche les message d'erreurs.
	options.setOpt(argc, argv);

// on récupère le statut de la class option. Si il n'y a pas d'erreur, le programme peut conituner.
	if (options.getStatus())
	{
		
// il y a une vérification de la validité des fichiers passés en argument du programme. 
// si il n'y a pas d'erreur le programme continue. Sinon "fichiers" affiche les messages d'erreur.
		if (fichiers.ok(options.getdVal(), options.getrVal()))
		{
			// lire fichier et remplir un tableau de partie
			fichiers.lireParties(options.getdVal(), partie, nbPartie);
			// lire fichier global et rempli un tableau des résultats globals.
			fichiers.lireGlobal(options.getrVal(), global, nbGlobal);
			
			// si l'option 's' est présente, les streams de sortie seront dirigés vers le fichier nommé par l'utilisateur.
			// sinon l'affichage se fera de façon standard.
			if(options.getsFlg() == 1)
			{
				out.open(options.getsVal());
				streambuf* streamBufferFile = out.rdbuf();
				cout.rdbuf(streamBufferFile);
				cout << "opt en construction!!" << endl;
			}
			int p=100; // sert a rien!!
			cout << menu;
			while (option != '6') 
			{	
				cin >> option;
				switch (option)
				{
					case '1':
						menu.opt1(global, nbGlobal);
						break;
					case '2':
						menu.opt2(partie, nbPartie);
						break;
					case '3':
						menu.opt3(partie, nbPartie);
						break;
					case '4':
					// marche pas!!
						menu.opt4(partie, nbPartie);
						while(p == 100)
						{
							p = (int) cin.get();
							partie[0].enTete();
							cout << partie[p];
						}
						break;
					case '5':
						menu.opt5(partie, nbPartie);
						break;
					case '6':
						break;
					default:
						cerr << option << " est une option incorrecte. Recommencez\n";
				}
			}
			cout << "Opt -6- selectionnée.\nMerci d'avoir utilisé ce programme, à la prochaine!\n" << endl;
		}
	}
	if (out.is_open())
		out.close();
	return 0;
}
