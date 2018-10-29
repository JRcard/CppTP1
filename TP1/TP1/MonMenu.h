#ifndef MONMENU_H
#define MONMENU_H

#include <iomanip>
#include <algorithm>
#include <string>
#include "MesFichiers.h"
#include "LesPartis.h"

using namespace std;

 /* cette class permet d'afficher le menu principal et 
  * contient les fonctions membres permettant d'executer les options choisis par l'utilisateur.*/
class MonMenu
{
	
public:
	MonMenu(){};
	
	friend ostream& operator << (ostream&, const MonMenu&);
	
	// (1) afficher le sommaire des résultats.
	void opt1(Global global[], int nbGlobal)
	{
		cout << "option -1- a été sélectionnée\n" << endl;
		for (int i = 0; i < nbGlobal; i++)
			cout << global[i];
		cout << "\n" << endl;
	}
	
	// (2) afficher tous les résultats.
	void opt2(LesPartis partis[], int nbParti)
	{
		cout << "option -2- a été sélectionnée\n\n" << endl;
		partis[0].enTete();
		for (int i = 0; i < nbParti-1; i++)
			cout << partis[i];
		cout << endl;
	}
	
	// (3) afficher les résultats détaillés du parti qui a gagné le plus de sièges à l’assemblée.
	void opt3(LesPartis partis[], int nbParti)
	{
		cout << "option -3- a été sélectionnée\n\n\n" << endl;
		partis[0].enTete();
		int indMax = 0;
	/*  vérifie à quel indice dans le tableau des partis  que le nombre d'élu est le plus nombreux.
		Place cette indice dans indMax et affiche le partie avec l'indMax. */
		for (int i = 0; i < nbParti-1; i++)
			if (partis[i].getNbElu() > partis[indMax].getNbElu())
				indMax = i;
		cout << partis[indMax];
		cout << endl;
	}
	
	// (4) afficher les résultats détaillés d’un parti politique en particulier.
	void opt4(LesPartis partis[], int nbParti)
	{	
		cout << "option -4- a été sélectionnée\n" << endl;
		cout << "Sélectionner un parti parmi la liste suivante:\n";
	// présente les choix à l'utilisateur.
		for (int i = 0; i < nbParti-1; i++)
		{
			cout << "(" << setw(2) << right << i << ")\t" <<
				left << partis[i].getNom() << endl;
		}
		cout << endl << endl;
		
	// En attente du choix de l'utilisateur.
		int choix;
		cin >> choix;
	/* si la valeur n'est pas entre 0 et le nombre de partie - 1, 
	   ça retourne une erreur et redemande de choisir.*/
		while(choix < 0 || choix > (nbParti-1))
		{
			cerr << "valeur incorrecte, essayer de nouveau" << endl;
			cin >> choix;
		}
	// affichage du choix avec l'entête.
		partis[choix].enTete();
		cout << partis[choix] << endl;
	}
	
	//(5) afficher les résultats des partis qui ont obtenu au moins un siège à l’assemblée.
	void opt5(LesPartis partis[], int nbParti)
	{
		cout << "option -5- a été sélectionnée\n\n" << endl << endl;
		partis[0].enTete();
		for (int i = 0; i <nbParti-1; i++)
			if (partis[i].getNbElu() > 0)
				cout << partis[i];
		cout << endl;
	}

};

/* surcharge d'affichage */
ostream& operator << (ostream& sortie, const MonMenu &menu)
{
	sortie  << "(1) afficher le sommaire des résultats.\n"
				"(2) afficher tous les résultats.\n"
				"(3) afficher les résultats détaillés du parti qui a gagné plus de sièges à l’assemblée.\n"
				"(4) afficher les résultats détaillés d’un parti politique en particulier.\n"
				"(5) afficher les résultats des parties qui ont obtenu au moins un siège à l’assemblée.\n"
				"(6) quitter le programme.\n" << endl;
	return sortie;       
}

#endif // MONMENU_H
