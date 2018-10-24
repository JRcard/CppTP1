#ifndef LESPARTIES_H
#define LESPARTIES_H

#include <iomanip>
#include <string>

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
	
	void enTete()
	{
		cout << setw(2) << left << "No" << "\t" <<
			setw(60) << left << "Nom" << "\t" <<
			setw(20) << left << "Abreviation" << "\t" <<
			setw(10) << right << "NbreVotes" << "\t" << 
			setw(12) << right << "TauxdeVote" << "\t" << 
			setw(15) << "NbreCandidats" << "\t" <<
			setw(20) << "NbreCandidatselus" << "\t" << endl;
		cout << setw(165) << setfill('-') << '-' << endl;
		cout << setfill(' ');
	}
	
	string getNbElu()
	{
		return nbElu;
	}
	string getNom()
	{
		return nom;
	}

};

ostream& operator << (ostream& sortie, const LesParties &parties)
{
	sortie << setw(2) << right << parties.no << "\t" << 
			  setw(60) << left << parties.nom << "\t" << 
			  setw(20) << left << parties.abrv << "\t" <<
			  setw(10) << right << parties.nbVote << "\t" <<
			  setw(12) << right << parties.tauxVote << "\t" <<
			  setw(15) << right << parties.nbCandi << "\t" <<
			  setw(20) << right << parties.nbElu << "\t" <<  endl;
	
	return sortie;
}

#endif // LESPARTIES_H
