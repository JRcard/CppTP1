#ifndef LESPARTIES_H
#define LESPARTIES_H

#include <iomanip>

using namespace std;

class LesParties
{
	int no, nbVote, nbCandi, nbElu;
	float tauxVote;
	string nom, abrv;
	
public:
	LesParties(){};
	
	LesParties(int no, string nom, string abrv, int nbVote, float tauxVote, int nbCandi, int nbElu)
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
		cout << no << nom << endl;
	}
};

ostream& operator << (ostream& sortie, const LesParties &parties)
{
	sortie.setf(ios::fixed);
	sortie.setf(ios::showpoint);
	
	sortie << "No" << setw(6) << "Nom" << 
			setw(6) << "Abrevition" << 
			setw(7) << "NbeVotes" << 
			setw(10) << "TauxdeVote" <<
			setw(12) << "NbreCandidats" <<
			setw(12) << "NbreCandidatselus" << endl;
	sortie << setw(139) << setfill('-') << endl;
	sortie << parties.no << parties.abrv << endl;
	
	return sortie;
}

#endif // LESPARTIES_H
