#ifndef MONMENU_H
#define MONMENU_H

#include <iomanip>
#include <algorithm>
#include "MesFichiers.h"
#include "LesParties.h"

using namespace std;

class MonMenu
{
/*	char option;*/
	
public:
	MonMenu(){};
	
	friend ostream& operator << (ostream&, const MonMenu&);
	
	// (1) afficher le sommaire des résultats.
	void opt1(Global global[], int nbGlobal)
	{
		cout << "Opt -1- selectionnée.\n" << endl;
		for (int i = 0; i < nbGlobal; i++)
			cout << global[i];
			cout << endl;
	}
	
	// (2) afficher tous les résultats.
	void opt2(LesParties parties[], int nbPartie)
	{
		cout << "Opt -2- selectionnée.\n" << endl;
		parties[0].enTete();
		for (int i = 0; i < nbPartie-1; i++)
			cout << parties[i];
		cout << endl;
	}
	
	// (3) afficher les résultats détaillés du parti qui a gagné plus de sièges à l’assemblée.
	void opt3(LesParties parties[], int nbPartie)
	{
		cout << "Opt -3- selectionnée.\n" << endl;
		parties[0].enTete();
		int indMax = 0;
		for (int i = 0; i < nbPartie-1; i++)
			if (parties[i].getNbElu() > parties[indMax].getNbElu())
				indMax = i;
		cout << parties[indMax];
		cout << endl;
	}
	
	// (4) afficher les résultats détaillés d’un parti politique en particulier.
	void opt4(LesParties parties[], int nbPartie)
	{
		cout << "Opt -4- selectionnée.\n" << endl;
		cout << "Sélectionner un partie parmi la liste suivante:\n";
		for (int i = 0; i < nbPartie-1; i++)
		{
			cout << "(" << setw(2) << right << i << ")\t" <<
				left << parties[i].getNom() << endl;
		}
		cout << endl;
	}
	
	//(5) afficher les résultats des parties qui ont obtenu au moins un siège à l’assemblée.
	void opt5(LesParties parties[], int nbPartie)
	{
		cout << "Opt -5- selectionnée.\n" << endl;
		parties[0].enTete();
		for (int i = 0; i <nbPartie-1; i++)
			if (parties[i].getNbElu() > "0")
				cout << parties[i];
		cout << endl;
	}

};

ostream& operator << (ostream& sortie, const MonMenu &menu)
{
	sortie	<< "Faites un choix: \n"
			<< "(1) afficher le sommaire des résultats.\n"
			<< "(2) afficher tous les résultats.\n"
			<< "(3) afficher les résultats détaillés du parti qui a gagné le plus de sièges à l’assemblée.\n"
			<< "(4) afficher les résultats détaillés d’un parti politique en particulier.\n"
			<< "(5) afficher les résultats des parties qui ont obtenu au moins un siège à l’assemblée.\n"
			<< "(6) quitter le programme.\n" << endl;
	return sortie;       
}

#endif // MONMENU_H
