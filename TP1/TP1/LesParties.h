#ifndef LESPARTIES_H
#define LESPARTIES_H

#include <iomanip>

using namespace std;

class LesParties
{
	string no, nbVote, nbCandi, nbElu;
	string tauxVote;
	string nom, abrv;
	
public:
	LesParties(){};
	
	LesParties(string no, string nom, string abrv, string nbVote, string tauxVote, string nbCandi, string nbElu)
	{
		this->no = no;
		this->nom = nom;
		this->abrv = abrv;
		this->nbVote = nbVote;
		this->tauxVote = tauxVote;
		this->nbCandi = nbCandi;
		this->nbElu = nbElu;
	}
	
	friend ostream& operator << (ostream&, const LesParties&);
	
	void affiche()
	{
		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
	
		cout << "No" << setw(8) << "Nom" << setw(69) << 
			"Abreviation" << setw(22) <<
			"NbreVotes" << setw(17) << 
			"TauxdeVote" << setw(18) << 
			"NbreCandidats" << setw(20) <<
			"NbreCandidatselus" << setw(20) << endl;
		cout << setw(165) << setfill('-') << '-' << endl;

	}
};

ostream& operator << (ostream& sortie, const LesParties &parties)
{
	sortie.setf(ios::fixed);
	sortie.setf(ios::showpoint);
	
/*	sortie << "No" << setw(8) << "Nom" << setw(69) << 
			"Abreviation" << setw(22) <<
			"NbreVotes" << setw(17) << 
			"TauxdeVote" << setw(18) << 
			"NbreCandidats" << setw(20) <<
			"NbreCandidatselus" << setw(20) << endl;
	sortie << setw(165) << setfill('-') << '-' << endl;*/
	sortie << setw(2) << left << parties.no << setw(60) << left << parties.nom << endl;
	
	return sortie;
}

#endif // LESPARTIES_H
