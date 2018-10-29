#include <fstream>
#include <iostream>
#include "MesOptions.h"
#include "MesFichiers.h"
#include "MonMenu.h"
#include "LesPartis.h"

using namespace std;

int main(int argc, char* argv[])
{
	//Déclaration des variables
	const int MAX_PARTI = 20 ;
	int nbParti;
	int nbGlobal;
	string option = "";
	int choix;
	ofstream out;
	
	// instanciation des class
	MesOptions options;
	MesFichiers fichiers;
	MonMenu menu;
	LesPartis partis[MAX_PARTI];
	Global global[MAX_PARTI];

// récupère les options, les vérifies et affiche les messages d'erreur.
	options.setOpt(argc, argv);

// récupère le statut de la class "options". Si il n'y a pas d'erreur, le programme peut conituner.
	if (options.getStatus())
	{
		
/* il y a une vérification de la validité des fichiers passés en argument du programme. 
   si il n'y a pas d'erreur le programme continue. Sinon "fichiers" affiche les messages d'erreur.*/
		if (fichiers.ok(options.getdVal(), options.getrVal()))
		{
			// lire fichier et remplir un tableau de partie
			fichiers.lirePartis(options.getdVal(), partis, nbParti);
			// lire fichier global et rempli un tableau des résultats globals.
			fichiers.lireGlobal(options.getrVal(), global, nbGlobal);
			
			/* si l'option 's' est présente, les streams de sortie seront dirigés vers le fichier nommé par l'utilisateur.
			   sinon l'affichage se fera de façon standard.*/
			if(options.getsFlg() == 1)
			{
				out.open(options.getsVal());
				streambuf* streamBufferFile = out.rdbuf();
				cout.rdbuf(streamBufferFile);
			}
			// affiche le menu par surcharge d'affichage.
			cout << menu;
			// attente d'une entrée de l'utilisaeur et appel de la méthode appropriée.
			while (option != "6") 
			{	
				cin >> option;
				choix = atoi(option.c_str());
				switch (choix)
				{
					case 1:
						menu.opt1(global, nbGlobal);
						break;
					case 2:
						menu.opt2(partis, nbParti);
						break;
					case 3:
						menu.opt3(partis, nbParti);
						break;
					case 4:
						menu.opt4(partis, nbParti);
						break;
					case 5:
						menu.opt5(partis, nbParti);
						break;
					case 6:
						break;
					default:
						cerr << option << " est une option incorrecte. Recommencez\n";
				}
			}
			cout << "option -6- a été sélectionnée\n\nMerci d'avoir utilisé ce programme, à la prochaine!" << endl;
		}
	}
	// si l'utilisateur a demandé un fichier de sortie, il sera fermé avant la fin du programme.
	if (out.is_open())
		out.close();
	return 0;
}
