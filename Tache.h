//                           AUTEUR: Nan ZHOU

#ifndef TACHE
#define TACHE
#include<vector>
using namespace std;

class Tache
{
	int jourDebut_;
	int moisDebut_;
	int anneeDebut_;
	int jourFin_;
	int moisFin_;
	int anneeFin_;
	string tache_;
public:
	Tache(int jourDebut, int moisDebut, int anneeDebut, int jourFin, int moisFin, int anneeFin, string &tache);

	int getJourDebut() { return jourDebut_; }
	int getMoisDebut() { return moisDebut_; }
	int getAnneeDebut() { return anneeDebut_; }
	int getJourFin() { return jourFin_; }
	int getMoisFin() { return moisFin_; }
	int getAnneeFin() { return anneeFin_; }
	string getTache() { return tache_; }
	string getInfo();
	string getDebut();
	string getFin();

	void setTache();
	void setTemps();
	int duree();
};


#endif // !TACHE
