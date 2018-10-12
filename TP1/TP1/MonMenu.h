#ifndef MONMENU_H
#define MONMENU_H

#include "MesFichiers.h"

using namespace std;

class MonMenu
{
	char option;
	
public:
	MonMenu(){};
	
	friend ostream& operator << (ostream&, const MonMenu&);
	
	void menuOpt()
	{ 
		while ((this->option = cin.get()) != EOF) 
		{
			switch (this->option)
			{
				case '1':
					cout << "Opt -1- selectionnée.\n" << endl;
					break;
				case '2':
					cout << "Opt -2- selectionnée.\n" << endl;
					break;
				case '3':
					cout << "Opt -3- selectionnée.\n" << endl;
					break;
				case '4':
					cout << "Opt -4- selectionnée.\n" << endl;
					break;
				case '5':
					cout << "Opt -5- selectionnée.\n" << endl;
					break;
				case '6':
					cout << "Opt -6- selectionnée.\n Merci d'avoir utilisé ce programme, à la prochaine!\n" << endl;
					break;
				default:
					cout << " est une option incorrecte. Recommencez\n";
					break;
			}
		}
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
