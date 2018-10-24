#ifndef MONMENU_H
#define MONMENU_H

#include <iomanip>
#include "MesFichiers.h"
#include "LesParties.h"

using namespace std;

class MonMenu
{
	char option;
	
public:
	MonMenu(){};
	
	friend ostream& operator << (ostream&, const MonMenu&);
	void opt1();
	void opt2();
	void opt3();
	void opt4();
	void opt5();
	void opt6();
	void menuOpt();

};

void MonMenu::opt1()
{
	cout << "Opt -1- selectionnée.\n" << endl;
	Global global;
	for (int i = 0; i < nbGlobal; i++)
		cout << global[i];
}

void MonMenu::opt2()
{
	cout << "Opt -2- selectionnée.\n" << endl;
}

void MonMenu::opt3()
{
	cout << "Opt -3- selectionnée.\n" << endl;
}

void MonMenu::opt4()
{
	cout << "Opt -4- selectionnée.\n" << endl;
}

void MonMenu::opt5()
{
	cout << "Opt -5- selectionnée.\n" << endl;
}

void MonMenu::opt6()
{
	cout << "Opt -6- selectionnée.\n Merci d'avoir utilisé ce programme, à la prochaine!\n" << endl;
}

/*void MonMenu::menuOpt()
{ 
	while ((option = cin.get()) != EOF) 
	{
		switch (option)
		{
			case '1':
				opt1();
				break;
			case '2':
				opt2();
				break;
			case '3':
				opt3();
				break;
			case '4':
				opt4();
				break;
			case '5':
				opt5();
				break;
			case '6':
				opt6();
				break;
			default:
				cerr << option << " est une option incorrecte. Recommencez\n";
		}
	}
}*/

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
