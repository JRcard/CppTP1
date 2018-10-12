#ifndef MONMENU_H
#define MONMENU_H

#include "MesFichiers.h"

using namespace std;

class MonMenu
{

public:
	MonMenu();
	
	friend ostream& operator << (ostream&, const MonMenu&);
	
	void menuOpt()
	{ cout << "opt selectionne ## " << endl;
/*		while ((this->option = cin.get() != EOF) 
			switch (this->option)
			{
				case '1':
					fichiers = fichiers.getGlobal();
					while (!fichiers.eof())
						fichiers >> entree;
						cout << fichier;
				
			}*/
	}
};

ostream& operator << (ostream& sortie, const MonMenu &menu)
{
   sortie	<< "Faites un choix: \n"
			<< "(1) afficher le sommaire des résultats.\n"
			<< "(2) afficher tous les résultats.\n"
			<< "(3) afficher les résultats détaillés du parti qui a gagné plus de sièges à l’assemblée.\n"
			<< "(4) afficher les résultats détaillés d’un parti politique en particulier.\n"
			<< "(5) afficher les résultats des parties qui ont obtenu au moins un siège à l’assemblée.\n"
			<< "(6) quitter le programme.\n" << endl;
   return sortie;       
}

#endif // MONMENU_H
