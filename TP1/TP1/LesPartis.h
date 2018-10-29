#ifndef LESPARTIS_H
#define LESPARTIS_H

#include <iomanip>
#include <string>

using namespace std;

/* classe permettant de gérer les partis politiques lus dans le fichier. 
   elle permet l'affichage de l'entête et des partis appelés
   Cette class retourne certains arguments utilent pour les fonctions membres de MonMenu.h*/
   
class LesPartis
{
	string no, nbVote, nbCandi, nbElu;
	string tauxVote;
	string nom, abrv;
	
public:
	LesPartis(){};
	// constructeur avec les différents champs nécesaire pour l'affichage 
	LesPartis(string no, string nom, string abrv, string nbVote, string tauxVote, string nbCandi, string nbElu)
	{
		this->no = no;
		this->nom = nom;
		this->abrv = abrv;
		this->nbVote = nbVote;
		this->tauxVote = tauxVote;
		this->nbCandi = nbCandi;
		this->nbElu = nbElu;
	}
	
	friend ostream& operator << (ostream&, const LesPartis&);
	
	/* affiche l'entête du tableau. Le parti choisi pour afficher cette entête n'a pas d'importance.*/
	void enTete()
	{
		cout << setw(2) << left << "No" << "\t" <<
			setw(60) << left << "Nom" << "\t" <<
			setw(20) << left << "Abreviation" << "\t" <<
			setw(10) << right << "Nbrevotes" << "\t" << 
			setw(12) << right << "Tauxdevote" << "\t" << 
			setw(15) << "Nbrecandidats" << "\t" <<
			setw(20) << "Nbrecandidatselus" << "\t" << endl;
		cout << setw(164) <<  setfill('-') << "-" << endl;
		cout << setfill(' ');
	}
	/* getters */
	int getNbElu()
	{
		return stoi(nbElu.c_str());
	}
	string getNom()
	{
		return nom;
	}

};
/* surcharge d'affichage */
ostream& operator << (ostream& sortie, const LesPartis &parti)
{
	sortie << setw(2) << right << parti.no << "\t" << 
			  setw(60) << left << parti.nom << "\t" << 
			  setw(20) << left << parti.abrv << "\t" <<
			  setw(10) << right << parti.nbVote << "\t" <<
			  setw(12) << right << parti.tauxVote << "\t" <<
			  setw(15) << right << parti.nbCandi << "\t" <<
			  setw(20) << right << parti.nbElu << "\t" <<  endl;
	
	return sortie;
}

#endif // LESPARTIS_H
