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
	int dFlg = 0;
	int rFlg = 0;
	int sFlg = 0;
	string dVal, rVal, sVal;

	bool goodOpt = false;
	
public:
	MesOptions(){};
	
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
		
		optCheck(dFlg, rFlg, sFlg, error);
	}
	
	void optCheck(int dFlg, int rFlg, int  sFlg, int error)
	{
		if (dFlg == 0 && rFlg == 0)
		{
			cout << "Ce programme ne peut pas s’exécuter. Les options « -d » et « -r » sont manquantes.\n";
			cout << "tp1.exe -d rese2014partis.csv (obligatoire) -r rese2014sommaire.csv (obligatoire) -s fichierdesortie (optionnelle)" << endl;
		}
		
		else if (dFlg == 0) 
		{
			cout << "Ce programme ne peut pas s’exécuter. L'options « -d » est manquante.\n";
			cout << "tp1.exe -d rese2014partis.csv (obligatoire) -r rese2014sommaire.csv (obligatoire) -s fichierdesortie (optionnelle)" << endl;
		}
		else if (rFlg == 0)
		{
			cout << "Ce programme ne peut pas s’exécuter. L'options « -r » est manquante.\n";
			cout << "tp1.exe -d rese2014partis.csv (obligatoire) -r rese2014sommaire.csv (obligatoire) -s fichierdesortie (optionnelle)" << endl;		
		}
		else if (error != 0)
			cout << "tp1.exe -d rese2014partis.csv (obligatoire) -r rese2014sommaire.csv (obligatoire) -s fichierdesortie (optionnelle)" << endl;
			
		if (dFlg == 1 && rFlg == 1)
		{ 	
/*			cout << "dFlg = " << dFlg << ", rFlg = " << rFlg << ", sFlg = " << sFlg << endl;
			cout << endl;*/
			goodOpt = true;
		}
	}

	
/* getters */
	bool getStatus()
	{
		return goodOpt;
	}
		
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
	
	int getError()
	{
		return error;
	}
	
	~MesOptions()
	{ cout << "deleted\n"; }

};



#endif // MESOPTIONS_H
