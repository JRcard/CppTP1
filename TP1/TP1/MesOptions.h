#ifndef MESOPTIONS_H
#define MESOPTIONS_H

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <getopt.h>
#include "MesFichiers.h"
#include "MonMenu.h"

using namespace std;

class MesOptions
{
private:

	int error = 0;
	int getIn;
	string dFlg = "Null";
	string rFlg = "Null";
	string sFlg = "Null";
	bool goodOpt = false;
	
public:
	MesOptions();
	
	void setOpt(int argc, char* argv[])
	{
		if (argc == 1)
		{
			this->error++;
		}
		
		else
		{
			while ((this->getIn = getopt(argc, argv, "d:r:s:?")) != EOF) 
			{	
			switch (this->getIn) 
				{
				case 'd':
					this->dFlg = optarg;
					break;
					
				case 'r':
					this->rFlg = optarg;
					break;
					
				case 's':
					this->sFlg = optarg;
					break;
					
				case '?':
					this->error++;
					break;
				}
			}
		}
		
		optCheck(this->dFlg, this->rFlg, this->sFlg, this->error);
	}
	
	void optCheck(string dFlg, string rFlg, string sFlg, int error)
	{
		if (dFlg == "Null" && rFlg =="Null")
		{
			cout << "Ce programme ne peut pas s’exécuter. Les options « -d » et « -r » sont manquantes.\n";
			cout << "tp1.exe -d rese2014partis.csv (obligatoire) -r rese2014sommaire.csv (obligatoire) -s fichierdesortie (optionnelle)" << endl;
		}
		
		else if (dFlg == "Null") 
		{
			cout << "Ce programme ne peut pas s’exécuter. L'options « -d » est manquante.\n";
			cout << "tp1.exe -d rese2014partis.csv (obligatoire) -r rese2014sommaire.csv (obligatoire) -s fichierdesortie (optionnelle)" << endl;
		}
		else if (rFlg == "Null")
		{
			cout << "Ce programme ne peut pas s’exécuter. L'options « -r » est manquante.\n";
			cout << "tp1.exe -d rese2014partis.csv (obligatoire) -r rese2014sommaire.csv (obligatoire) -s fichierdesortie (optionnelle)" << endl;		
		}
		else if (error != 0)
			cout << "tp1.exe -d rese2014partis.csv (obligatoire) -r rese2014sommaire.csv (obligatoire) -s fichierdesortie (optionnelle)" << endl;
			
		if (dFlg != "Null" && rFlg !="Null")
		{ 	
			cout << "dFlg = " << dFlg << ", rFlg = " << rFlg << ", sFlg = " << sFlg << endl;
			cout << endl;

			MonMenu menu;
			MesFichiers fichiers(dFlg, rFlg);
			cout << "erreur de fichier: " << fichiers.getError() << endl;
			cout << endl;
			
			if (fichiers.ok())
			{
				cout << menu;
				menu.menuOpt();
				this->goodOpt = true;
			}

		}
	}

	
/* getters */
	bool getStatus()
	{
		return this->goodOpt;
	}
		
	string getdFlg()
	{
		return this->dFlg;
	}
		
	string getrFlg()
	{
		return this->rFlg;
	}
	
	string getsFlg()
	{
		return this->sFlg;
	}
	
	int getError()
	{
		return this->error;
	}
	
	~MesOptions()
	{ cout << "deleted\n"; }

};



#endif // MESOPTIONS_H
