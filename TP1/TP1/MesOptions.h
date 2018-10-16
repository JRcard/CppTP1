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
					dFlg = optarg;
					break;
					
				case 'r':
					rFlg = optarg;
					break;
					
				case 's':
					sFlg = optarg;
					break;
					
				case '?':
					error++;
					break;
				}
			}
		}
		
		optCheck(dFlg, rFlg, sFlg, error);
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
		
	string getdFlg()
	{
		return dFlg;
	}
		
	string getrFlg()
	{
		return rFlg;
	}
	
	string getsFlg()
	{
		return sFlg;
	}
	
	int getError()
	{
		return error;
	}
	
	~MesOptions()
	{ cout << "deleted\n"; }

};



#endif // MESOPTIONS_H
