//                           AUTEUR: Nan ZHOU

#ifndef DIAGRAMME
#define DIAGRAMME
#include"Tache.h"
#include<string>
#include<list>
#include<iterator>
using namespace std;

class Diagramme
{
	list<Tache> tache_;
public:
	Diagramme(){}
	void saisirTache();
	void enregistrerTache(string &fichier);
	void lireTache(string &fichier);
	void supprimerTache();
	void modifierTache();
	void insererTache();
	int dureeTotal();
	int dureePoint(list<Tache>::iterator it);
	int dureeZoom(list<Tache>::iterator it, int jourDebut, int moisDebut, int anneeDebut);


	void drawDiagramme();
	void zoom();

};

#endif // !DIAGRAMME