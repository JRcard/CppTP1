#ifndef MESOPTIONS_H
#define MESOPTIONS_H

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <getopt.h>
#include "MesFichiers.h"
#include "MonMenu.h"

using namespace std;

/* Cette class gère les arguments passés lors de l'exécution du programe.*/
class MesOptions
{
private:

	int error = 0;
	int getIn;
	int dFlg = 0;
	int rFlg = 0;
	int sFlg = 0;
	string dVal, rVal, sVal;

	bool goodOpt = false;
	
public:
	MesOptions(){};
	/* fonction membre qui valide la présence des arguments et receuille l'information.*/
	void setOpt(int argc, char* argv[])
	{
		if (argc == 1)
		{
			error++;
		}
		
		else
		{
			while ((getIn = getopt(argc, argv, "d:r:s:?")) != EOF) 
			{	
			switch (getIn) 
				{
				case 'd':
					dVal = optarg;
					dFlg = 1;
					break;
					
				case 'r':
					rVal = optarg;
					rFlg = 1;
					break;
					
				case 's':
				sVal = optarg;
					sFlg = 1;
					break;
					
				case '?':
					error++;
					break;
				}
			}
		}
		// envois les données receuillies dans la fonction memebre optCheck() pour vérification.
		optCheck(dFlg, rFlg, sFlg, error);
	}
	
	/* Cette fonction membre test les valeurs receuillis avec la fonction setOpt() 
	 * envois les messages d'erreur, si il y en a, dans le flux d'erreur 
	 * et fait en sorte que "goodOpt" retourne true ou false.*/
	 
	void optCheck(int dFlg, int rFlg, int  sFlg, int error)
	{
		if (dFlg == 0 && rFlg == 0)
		{
			cerr << "Ce programme ne peut pas s’exécuter. Les options « -d » et « -r » sont manquantes.\n";
			cerr << "tp1.exe -d rese2014partis.csv (obligatoire) -r rese2014sommaire.csv (obligatoire) -s fichierdesortie (optionnelle)" << endl;
		}
		
		else if (dFlg == 0) 
		{
			cerr << "Ce programme ne peut pas s’exécuter. L'options « -d » est manquante.\n";
			cerr << "tp1.exe -d rese2014partis.csv (obligatoire) -r rese2014sommaire.csv (obligatoire) -s fichierdesortie (optionnelle)" << endl;
		}
		else if (rFlg == 0)
		{
			cerr << "Ce programme ne peut pas s’exécuter. L'options « -r » est manquante.\n";
			cerr << "tp1.exe -d rese2014partis.csv (obligatoire) -r rese2014sommaire.csv (obligatoire) -s fichierdesortie (optionnelle)" << endl;		
		}
		else if (error != 0)
			cerr << "tp1.exe -d rese2014partis.csv (obligatoire) -r rese2014sommaire.csv (obligatoire) -s fichierdesortie (optionnelle)" << endl;
			
		if (dFlg == 1 && rFlg == 1)
		{ 	
			goodOpt = true;
		}
	}

	
/* getters 
 * Permet la véréfication dans le main que tout les option obligatoire y sont. 
 * Permettant ainsi la poursuite du programme.*/

	bool getStatus()
	{
		return goodOpt;
	}
	// retourne le nom du fichier
	string getdVal()
	{
		return dVal;
	}
	string getrVal()
	{
		return rVal;
	}
	string getsVal()
	{
		return sVal;
	}
	// retourne le flag pour tester si le fichier de sortie est demandé.
	int getsFlg()
	{
		return sFlg;
	}
};

#endif // MESOPTIONS_H
