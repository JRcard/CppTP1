#ifndef MESFICHIERS_H
#define MESFICHIERS_H

#include <iostream>
#include <fstream>

using namespace std;

class MesFichiers
{	
	
	int error = 0;
	ifstream fIndiv, fGlobal;
	
public:
	MesFichiers(){};
	
	MesFichiers(string indiv, string global)
	{	

		fIndiv.open(indiv);
		fGlobal.open(global);
		
		if  (!fIndiv.is_open())
		{
			cerr << "Erreur lors de la lecture du fichier : " << indiv << endl;
			this->error++;
		}
		if (!fGlobal.is_open())
		{
			cerr << "Erreur lors de la lecture du fichier : " << global << endl;
			this->error++;
		}
		
	}

	bool ok()
	{
		if (this->error > 0) return false;
		else return true;
	}
	
	int getError()
	{
		return this->error;
	}

	void affiche(char sel)
	{
		cout << "mesfichiers\n";
	}
};

#endif // MESFICHIERS_H
