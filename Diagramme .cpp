#include<iostream>
#include<fstream>
#include<list>
#include<string>
#include<ctime>
#include <stdlib.h>
#include <time.h>
#include<stdio.h>
#include"Diagramme .h"
#include"Menu.h"
#include"Tache.h"
#include"CImg.h"
using namespace std;
using namespace cimg_library;

void Diagramme::saisirTache()
{
	int jourDebut, moisDebut, anneeDebut, jourFin, moisFin, anneeFin;
	string tache;

	char a;
	do
	{
		cout << "Voulez-vous saisir une nouvelle tache ? Y/N ";
		cin >> a;
		while (a != 'Y' && a != 'N'&&a != 'y'&&a != 'n')
		{
			cout << "Saisir Y ou N : ";
			cin >> a;
		}
		if (a == 'Y' || a == 'y')
		{
			cout << "Saisir la date de debut :" << endl << "Annee : ";
			cin >> anneeDebut;
			cout << "Mois : ";
			cin >> moisDebut;
			while (moisDebut < 1 || moisDebut>12)
			{
				cout << "Mois doit entre 1 et 12 . Ressaisir : ";
				cin >> moisDebut;
			}
			if (moisDebut == 1 || moisDebut == 3 || moisDebut == 5 || moisDebut == 7 || moisDebut == 8 || moisDebut == 10 || moisDebut == 12)
			{
				cout << "Jour : ";
				cin >> jourDebut;
				while (jourDebut < 1 || jourDebut>31)
				{
					cout << "Jour doit entre 1 et 31 . Ressaisir : ";
					cin >> jourDebut;
				}
			}
			if (moisDebut == 4 || moisDebut == 6 || moisDebut == 9 || moisDebut == 11)
			{
				cout << "Jour : ";
				cin >> jourDebut;
				while (jourDebut < 1 || jourDebut>30)
				{
					cout << "Jour doit entre 1 et 30 . Ressaisir : ";
					cin >> jourDebut;
				}
			}
			if (moisDebut == 2)
			{
				if (anneeDebut % 4 == 0 && (anneeDebut % 100 == 0 || anneeDebut % 400 == 0))
				{
					cout << "Jour : ";
					cin >> jourDebut;
					while (jourDebut < 1 || jourDebut>29)
					{
						cout << "Jour doit entre 1 et 29 . Ressaisir : ";
						cin >> jourDebut;
					}
				}
				else
				{
					cout << "Jour : ";
					cin >> jourDebut;
					while (jourDebut < 1 || jourDebut>28)
					{
						cout << "Jour doit entre 1 et 28 . Ressaisir : ";
						cin >> jourDebut;
					}
				}
			}

			cout << "Saisir la date de fin :" << endl << "Annee : ";
			cin >> anneeFin;
			while (anneeFin < anneeDebut)
			{
				cout << "Annee de fin ne doit pas moins d'annee de debut. Ressaisir : " << endl;
				cin >> anneeFin;
			}
			cout << "Mois : ";
			cin >> moisFin;
	
			while (moisFin < 1 || moisFin>12)
			{
				cout << "Mois doit entre 1 et 12 . Ressaisir : ";
				cin >> moisFin;
			}
			while (anneeFin == anneeDebut && moisDebut > moisFin)
			{
				cout << "Mois de fin ne doit pas moins de mois de debut. Ressaisir : " << endl;
				cin >> moisFin;
			}

			if (moisFin == 1 || moisFin == 3 || moisFin == 5 || moisFin == 7 || moisFin == 8 || moisFin == 10 || moisFin == 12)
			{
				cout << "Jour : ";
				cin >> jourFin;
				while (jourFin < 1 || jourFin>31)
				{
					cout << "Jour doit entre 1 et 31 . Ressaisir : ";
					cin >> jourFin;
				}
				while (anneeDebut == anneeFin && moisDebut == moisFin && jourDebut > jourFin)
				{
					cout << "Jour de fin ne doit pas moins de jour de debut. Ressaisir : " << endl;
					cin >> jourFin;
				}
			}
			if (moisFin == 4 || moisFin == 6 || moisFin == 9 || moisFin == 11)
			{
				cout << "Jour : ";
				cin >> jourFin;
				while (jourFin < 1 || jourFin>30)
				{
					cout << "Jour doit entre 1 et 30 . Ressaisir : ";
					cin >> jourFin;
				}
				while (anneeDebut == anneeFin && moisDebut == moisFin && jourDebut > jourFin)
				{
					cout << "Jour de fin ne doit pas moins de jour de debut. Ressaisir : " << endl;
					cin >> jourFin;
				}
			}
			if (moisFin == 2)
			{
				if (anneeFin % 4 == 0 && (anneeFin % 100 == 0 || anneeFin % 400 == 0))
				{
					cout << "Jour : ";
					cin >> jourFin;
					while (jourFin < 1 || jourFin>29)
					{
						cout << "Jour doit entre 1 et 29 . Ressaisir : ";
						cin >> jourFin;
					}
					while (anneeDebut == anneeFin && moisDebut == moisFin && jourDebut > jourFin)
					{
						cout << "Jour de fin ne doit pas moins de jour de debut. Ressaisir : " << endl;
						cin >> jourFin;
					}
				}
				else
				{
					cout << "Jour : ";
					cin >> jourFin;
					while (jourFin < 1 || jourFin>28)
					{
						cout << "Jour doit entre 1 et 28 . Ressaisir : ";
						cin >> jourFin;
					}
					while (anneeDebut == anneeFin && moisDebut == moisFin && jourDebut > jourFin)
					{
						cout << "Jour de fin ne doit pas moins de jour de debut. Ressaisir : " << endl;
						cin >> jourFin;
					}
				}
			}

			cin.ignore(1000, '\n');
			cout << "Saisir la tache : " << endl;
			getline(cin, tache);

			Tache t(jourDebut, moisDebut, anneeDebut, jourFin, moisFin, anneeFin, tache);
			int size = tache_.size();
			if (tache_.empty())
			{
				tache_.push_back(t);

			}
			else
			{
				list<Tache>::iterator it;
				for (it = tache_.begin(); it != tache_.end(); it++)
				{
					if (t.getAnneeDebut() < (*it).getAnneeDebut())
					{
						tache_.insert(it, t);
						break;
					}
					else if (t.getAnneeDebut() == (*it).getAnneeDebut())
					{
						if (t.getMoisDebut() < (*it).getMoisDebut())
						{
							tache_.insert(it, t);
							break;
						}
						if (t.getMoisDebut() == (*it).getMoisDebut())
						{
							if (t.getJourDebut() <= (*it).getJourDebut())
							{
								tache_.insert(it, t);
								break;
							}
						}
					}

				}

				if (tache_.size() == size) {
					tache_.push_back(t);
				}
				else {

				}



			}

		}
		if (a == 'N' || a == 'n')
			break;
	} while (a == 'Y' || a == 'y');
}

void Diagramme::enregistrerTache(string &fichier)
{
	ofstream ofTaches(fichier);
	int n = tache_.size();
	if (!ofTaches.is_open())
		cout << "Erreur d'ouverture" << endl;
	else
	{
		ofTaches << n << endl;
		list<Tache>::iterator it;
		it = tache_.begin();
		for (it = tache_.begin(); it != tache_.end(); it++)
		{
			ofTaches << (*it).getInfo() << endl;
		}
		if (!ofTaches.good())
			cout << "Erreur d'ecriture" << endl;
		else
			cout << "Enregistrement termine" << endl;
		ofTaches.close();
	}
}

void Diagramme::lireTache(string &fichier)
{
	string s1,s2;
	string tache;
	int jourDebut, moisDebut, anneeDebut, jourFin, moisFin, anneeFin;
	ifstream ifTaches(fichier);
	tache_.clear();
	if(!ifTaches.is_open())
		cout << "Erreur d'ouverture" << endl;
	else
	{
				int n, k, j, m;
				ifTaches >> n;
				for (int i = 0; i < n; i++)
				{
					k = 1;
					j = 0;
					m = 0;
					ifTaches >> s1;
					while (j != string::npos)
					{
						j = s1.find_first_of(",", m);
						if (j == string::npos)
						{
							s2 = s1.substr(m, string::npos);
							anneeFin = stoi(s2);
						}
						else
						{
							s2 = s1.substr(m, j - 1);
							if (k == 1)
							{
								tache = s2;
							}
							if (k == 2)
							{
								jourDebut = stoi(s2);
							}
							if (k == 3)
							{
								moisDebut = stoi(s2);
							}
							if (k == 4)
							{
								anneeDebut = stoi(s2);
							}
							if (k == 5)
							{
								jourFin = stoi(s2);
							}
							if (k == 6)
							{
								moisFin = stoi(s2);
							}
						}
						m = j + 1;
						k = k + 1;
					}
					Tache t(jourDebut, moisDebut, anneeDebut, jourFin, moisFin, anneeFin, tache);
					tache_.push_back(t);
				}


		if (!ifTaches.good())
			cout << "Erreur de lecture." << endl;
		else
			cout << "Lecture terminee." << endl;
	}
}




void Diagramme::supprimerTache()
{
	int i;
	cout << "Voulez-vous supprimer les premieres taches? (Saisir le nombre) " << endl;
	cin >> i;
	list<Tache>::iterator it;
	it = tache_.begin();
	advance(it, i-1);
	tache_.erase(it);
	drawDiagramme();
}

void Diagramme::modifierTache()
{
	int i;
	cout << "Voulez-vous modifier les premieres taches? (Saisir le nombre) " << endl;
	cin >> i;
	list<Tache>::iterator it;
	it = tache_.begin();
	advance(it, i-1);
	cout << "Pour la tache : " << endl;
	(*it).setTache();
	cout << "Pour la date : " << endl;
	(*it).setTemps();
	Tache t((*it).getJourDebut(), (*it).getMoisDebut(), (*it).getAnneeDebut(), (*it).getJourFin(), (*it).getMoisFin(), (*it).getAnneeFin(), (*it).getTache());
	tache_.erase(it);
	int size = tache_.size();
	if (tache_.empty())
	{
		tache_.push_back(t);

	}
	else
	{
		for (it = tache_.begin(); it != tache_.end(); it++)
		{
			if (t.getAnneeDebut() < (*it).getAnneeDebut())
			{
				tache_.insert(it, t);
				break;
			}
			else if (t.getAnneeDebut() == (*it).getAnneeDebut())
			{
				if (t.getMoisDebut() < (*it).getMoisDebut())
				{
					tache_.insert(it, t);
					break;
				}
				if (t.getMoisDebut() == (*it).getMoisDebut())
				{
					if (t.getJourDebut() <= (*it).getJourDebut())
					{
						tache_.insert(it, t);
						break;
					}
				}
			}

		}

		if (tache_.size() == size) {
			tache_.push_back(t);
		}
		else {

		}



	}

	drawDiagramme();
}

void Diagramme::insererTache()
{
	saisirTache();
	drawDiagramme();
}

int Diagramme::dureeTotal()
{
	int anneeFin, moisFin, jourFin;
	list<Tache>::iterator it;
	it = tache_.begin();
	anneeFin = (*it).getAnneeFin();
	moisFin = (*it).getMoisFin();
	jourFin = (*it).getJourFin();
	for (it = tache_.begin(); it != tache_.end(); it++)
	{
		if (anneeFin < (*it).getAnneeFin())
		{
			anneeFin = (*it).getAnneeFin();
		}
		if (anneeFin == (*it).getAnneeFin())
		{
			if (moisFin < (*it).getMoisFin())
			{
				moisFin = (*it).getMoisFin();
			}
			if (moisFin == (*it).getMoisFin())
			{
				if(jourFin < (*it).getJourFin())
				jourFin = (*it).getJourFin();
			}
		}
	}

	
	struct tm t1 { 0 };
	struct tm t2 { 0 };
	double seconds;
	int duree;
	
	t1.tm_year = (*tache_.begin()).getAnneeDebut() - 1900; t1.tm_mon = (*tache_.begin()).getMoisDebut() - 1; t1.tm_mday = (*tache_.begin()).getJourDebut();
	t2.tm_year = anneeFin - 1900; t2.tm_mon = moisFin - 1; t2.tm_mday = jourFin;
	seconds = difftime(mktime(&t2), mktime(&t1));
	duree = seconds / 86400;
	return duree;
}

int Diagramme::dureePoint(list<Tache>::iterator it)
{
	struct tm t1 { 0 };
	struct tm t2 { 0 };
	double seconds;
	int duree;

	t1.tm_year = (*tache_.begin()).getAnneeDebut() - 1900; t1.tm_mon = (*tache_.begin()).getMoisDebut() - 1; t1.tm_mday = (*tache_.begin()).getJourDebut();
	t2.tm_year = (*it).getAnneeDebut() - 1900; t2.tm_mon = (*it).getMoisDebut() - 1; t2.tm_mday = (*it).getJourDebut();
	seconds = difftime(mktime(&t2), mktime(&t1));
	duree = seconds / 86400;
	return duree;
}

int Diagramme::dureeZoom(list<Tache>::iterator it, int jourDebut, int moisDebut, int anneeDebut)
{
	struct tm t1 { 0 };
	struct tm t2 { 0 };
	double seconds;
	int duree;

	t1.tm_year = anneeDebut - 1900; t1.tm_mon = moisDebut - 1; t1.tm_mday = jourDebut;
	t2.tm_year = (*it).getAnneeDebut() - 1900; t2.tm_mon = (*it).getMoisDebut() - 1; t2.tm_mday = (*it).getJourDebut();
	seconds = difftime(mktime(&t2), mktime(&t1));
	duree = seconds / 86400;
	return duree;
}


void Diagramme::drawDiagramme()
{
	CImg<unsigned char> image(1500, 1000, 1, 3);
	image.fill(0);

	unsigned char noir[] = { 0,0,0 };
	unsigned char blanc[] = { 255,255,255 };



	CImg<unsigned char> ajouter("ajouter.ppm");
	CImg<unsigned char> enregistrer("enregistrer.ppm");
	CImg<unsigned char> modifier("modifier.ppm");
	CImg<unsigned char> supprimer("supprimer.ppm");
	CImg<unsigned char> zoomer("zoomer.ppm");
	ajouter.resize(50, 50);
	enregistrer.resize(50, 50);
	modifier.resize(50, 50);
	supprimer.resize(50, 50);
	zoomer.resize(50, 50);

	image.draw_image(1220, 25, ajouter);
	image.draw_image(1400, 25, enregistrer);
	image.draw_image(1280, 25, modifier);
	image.draw_image(1340, 25, supprimer);
	image.draw_image(1160, 25, zoomer);


	image.draw_text(550, 45, "Diagramme de Gantt", blanc, noir, 1.0F, 53U);

	int x0, y0, k;
	x0 = 50;
	y0 = 150;
	k = tache_.size();



	int j = 0;
	list<Tache>::iterator it;
	it = tache_.begin();
	image.draw_line(250, 150, 1450, 150, blanc);
	float s = dureeTotal();
	srand((unsigned)time(NULL));
	for (it = tache_.begin(); it != tache_.end(); it++)
	{
		int a, b, c;
		
		a = rand() % (256);
		b = rand() % (256);
		c = rand() % (256);
		unsigned char random[] = { a,b,c };


		image.draw_line(250 + 1200 * dureePoint(it) / s, 150, 250 + 1200 * dureePoint(it) / s, 140, random);
		image.draw_text(250 + 1200 * dureePoint(it) / s, 150, (*it).getDebut().c_str(), random);
		if (k <= 5)
		{
			image.draw_rectangle(x0, y0 + 160 * j, x0 + 200, y0 + 160 * (j + 1), random);
			image.draw_text(x0 + 60, y0 - 5 + 80 * (2 * j + 1), (*it).getTache().c_str(), noir, random, 1.0F, 23U);
			image.draw_text(250 + 1200 * dureePoint(it) / s, y0 + 80 * (2 * j + 1), (*it).getDebut().c_str(), random);
			image.draw_arrow(250 + 1200 * dureePoint(it) / s, y0 + 80 * (2 * j + 1), 250 + 1200 * dureePoint(it) / s + 1200 * (*it).duree() / s, y0 + 80 * (2 * j + 1), random);
			image.draw_text(250 + 1200 * dureePoint(it) / s + 600 * (*it).duree() / s, y0 + 80 * (2 * j + 1), to_string((*it).duree()).c_str(), random);
			image.draw_text(250 + 1200 * dureePoint(it) / s + 1200 * (*it).duree() / s, y0 + 80 * (2 * j + 1), (*it).getFin().c_str(), random);
		}
		if (k > 5 && k <= 10)
		{
			image.draw_rectangle(x0, y0 + 80 * j, x0 + 200, y0 + 80 * (j + 1), random);
			image.draw_text(x0 + 60, y0 - 3 + 40 * (2 * j + 1), (*it).getTache().c_str(), noir, random, 1.0F, 23U);
			image.draw_text(250 + 1200 * dureePoint(it) / s, y0 + 40 * (2 * j + 1), (*it).getDebut().c_str(), random);
			image.draw_arrow(250 + 1200 * dureePoint(it) / s, y0 + 40 * (2 * j + 1), 250 + 1200 * dureePoint(it) / s + 1200 * (*it).duree() / s, y0 + 40 * (2 * j + 1), random);
			image.draw_text(250 + 1200 * dureePoint(it) / s + 600 * (*it).duree() / s, y0 + 40 * (2 * j + 1), to_string((*it).duree()).c_str(), random);
			image.draw_text(250 + 1200 * dureePoint(it) / s + 1200 * (*it).duree() / s, y0 + 40 * (2 * j + 1), (*it).getFin().c_str(), random);
		}
		j++;
	}

	

	CImgDisplay w(image);
	while (!w.is_closed())
	{
		if (w.button())
		{
			if (w.mouse_x() >= 1160 && w.mouse_x() <= 1210 && w.mouse_y() >= 25 && w.mouse_y() <= 75)
			{
				zoom();
			}
			if (w.mouse_x() >= 1220 && w.mouse_x() <= 1270 && w.mouse_y() >= 25 && w.mouse_y() <= 75) 
			{
				insererTache();
			}
			if (w.mouse_x() >= 1280 && w.mouse_x() <= 1330 && w.mouse_y() >= 25 && w.mouse_y() <= 75)
			{
				modifierTache();
			}
			if (w.mouse_x() >= 1340 && w.mouse_x() <= 1390 && w.mouse_y() >= 25 && w.mouse_y() <= 75)
			{
				supprimerTache();
			}
			if (w.mouse_x() >= 1400 && w.mouse_x() <= 1450 && w.mouse_y() >= 25 && w.mouse_y() <= 75)
			{
				string nomSave = getSaveFileName("Nom du fichier ?sauvegarder :", "Fichiers textes (*.txt *.cpp)");
				enregistrerTache(nomSave);
			}
		}

		w.wait();

	}



}

void Diagramme::zoom()
{
	int jourDebut, moisDebut, anneeDebut, jourFin, moisFin, anneeFin;
	list<Tache> zoom;
	cout << "Saisir unn duree pour zoomer : " << endl;
	cout << "Saisir la date de debut :" << endl << "Annee : ";
	cin >> anneeDebut;
	cout << "Mois : ";
	cin >> moisDebut;
	while (moisDebut < 1 || moisDebut>12)
	{
		cout << "Mois doit entre 1 et 12 . Ressaisir : ";
		cin >> moisDebut;
	}
	if (moisDebut == 1 || moisDebut == 3 || moisDebut == 5 || moisDebut == 7 || moisDebut == 8 || moisDebut == 10 || moisDebut == 12)
	{
		cout << "Jour : ";
		cin >> jourDebut;
		while (jourDebut < 1 || jourDebut>31)
		{
			cout << "Jour doit entre 1 et 31 . Ressaisir : ";
			cin >> jourDebut;
		}
	}
	if (moisDebut == 4 || moisDebut == 6 || moisDebut == 9 || moisDebut == 11)
	{
		cout << "Jour : ";
		cin >> jourDebut;
		while (jourDebut < 1 || jourDebut>30)
		{
			cout << "Jour doit entre 1 et 30 . Ressaisir : ";
			cin >> jourDebut;
		}
	}
	if (moisDebut == 2)
	{
		if (anneeDebut % 4 == 0 && (anneeDebut % 100 == 0 || anneeDebut % 400 == 0))
		{
			cout << "Jour : ";
			cin >> jourDebut;
			while (jourDebut < 1 || jourDebut>29)
			{
				cout << "Jour doit entre 1 et 29 . Ressaisir : ";
				cin >> jourDebut;
			}
		}
		else
		{
			cout << "Jour : ";
			cin >> jourDebut;
			while (jourDebut < 1 || jourDebut>28)
			{
				cout << "Jour doit entre 1 et 28 . Ressaisir : ";
				cin >> jourDebut;
			}
		}
	}

	cout << "Saisir la date de fin :" << endl << "Annee : ";
	cin >> anneeFin;
	while (anneeFin < anneeDebut)
	{
		cout << "Annee de fin ne doit pas moins d'annee de debut. Ressaisir : " << endl;
		cin >> anneeFin;
	}
	cout << "Mois : ";
	cin >> moisFin;

	while (moisFin < 1 || moisFin>12)
	{
		cout << "Mois doit entre 1 et 12 . Ressaisir : ";
		cin >> moisFin;
	}
	while (anneeFin == anneeDebut && moisDebut > moisFin)
	{
		cout << "Mois de fin ne doit pas moins de mois de debut. Ressaisir : " << endl;
		cin >> moisFin;
	}

	if (moisFin == 1 || moisFin == 3 || moisFin == 5 || moisFin == 7 || moisFin == 8 || moisFin == 10 || moisFin == 12)
	{
		cout << "Jour : ";
		cin >> jourFin;
		while (jourFin < 1 || jourFin>31)
		{
			cout << "Jour doit entre 1 et 31 . Ressaisir : ";
			cin >> jourFin;
		}
		while (anneeDebut == anneeFin && moisDebut == moisFin && jourDebut > jourFin)
		{
			cout << "Jour de fin ne doit pas moins de jour de debut. Ressaisir : " << endl;
			cin >> jourFin;
		}
	}
	if (moisFin == 4 || moisFin == 6 || moisFin == 9 || moisFin == 11)
	{
		cout << "Jour : ";
		cin >> jourFin;
		while (jourFin < 1 || jourFin>30)
		{
			cout << "Jour doit entre 1 et 30 . Ressaisir : ";
			cin >> jourFin;
		}
		while (anneeDebut == anneeFin && moisDebut == moisFin && jourDebut > jourFin)
		{
			cout << "Jour de fin ne doit pas moins de jour de debut. Ressaisir : " << endl;
			cin >> jourFin;
		}
	}
	if (moisFin == 2)
	{
		if (anneeFin % 4 == 0 && (anneeFin % 100 == 0 || anneeFin % 400 == 0))
		{
			cout << "Jour : ";
			cin >> jourFin;
			while (jourFin < 1 || jourFin>29)
			{
				cout << "Jour doit entre 1 et 29 . Ressaisir : ";
				cin >> jourFin;
			}
			while (anneeDebut == anneeFin && moisDebut == moisFin && jourDebut > jourFin)
			{
				cout << "Jour de fin ne doit pas moins de jour de debut. Ressaisir : " << endl;
				cin >> jourFin;
			}
		}
		else
		{
			cout << "Jour : ";
			cin >> jourFin;
			while (jourFin < 1 || jourFin>28)
			{
				cout << "Jour doit entre 1 et 28 . Ressaisir : ";
				cin >> jourFin;
			}
			while (anneeDebut == anneeFin && moisDebut == moisFin && jourDebut > jourFin)
			{
				cout << "Jour de fin ne doit pas moins de jour de debut. Ressaisir : " << endl;
				cin >> jourFin;
			}
		}
	}

	list<Tache>::iterator it;
	for (it = tache_.begin(); it != tache_.end(); it++)
	{
		if (anneeDebut < (*it).getAnneeDebut())
		{
			if (anneeFin > (*it).getAnneeFin())
			{
				zoom.push_back(*it);
			}
			if (anneeFin == (*it).getAnneeFin())
			{
				if (moisFin > (*it).getMoisFin())
				{
					zoom.push_back(*it);
				}
				if (moisFin == (*it).getMoisFin())
				{
					if (jourFin >= (*it).getJourFin())
					{
						zoom.push_back(*it);
					}
				}
			}
		}
		if (anneeDebut == (*it).getAnneeDebut())
		{
			if (moisDebut < (*it).getMoisDebut())
			{
				if (anneeFin > (*it).getAnneeFin())
				{
					zoom.push_back(*it);
				}
				if (anneeFin == (*it).getAnneeFin())
				{
					if (moisFin > (*it).getMoisFin())
					{
						zoom.push_back(*it);
					}
					if (moisFin == (*it).getMoisFin())
					{
						if (jourFin >= (*it).getJourFin())
						{
							zoom.push_back(*it);
						}
					}
				}
			}
			if (moisDebut == (*it).getMoisDebut())
			{
				if (jourDebut <= (*it).getJourDebut())
				{
					if (anneeFin > (*it).getAnneeFin())
					{
						zoom.push_back(*it);
					}
					if (anneeFin == (*it).getAnneeFin())
					{
						if (moisFin > (*it).getMoisFin())
						{
							zoom.push_back(*it);
						}
						if (moisFin == (*it).getMoisFin())
						{
							if (jourFin >= (*it).getJourFin())
							{
								zoom.push_back(*it);
							}
						}
					}
				}
			}
		}
	}

	CImg<unsigned char> image(1500, 1000, 1, 3);
	image.fill(0);
	unsigned char noir[] = { 0,0,0 };
	unsigned char blanc[] = { 255,255,255 };
	unsigned char rouge[] = { 255,0,0 };
	image.draw_text(550, 45, "Diagramme de Zoom", blanc, noir, 1.0F, 53U);

	int x0, y0, k;
	x0 = 50;
	y0 = 150;
	k = zoom.size();



	int j = 0;
	string debut, fin;
	debut = to_string(jourDebut) + "," + to_string(moisDebut) + "," + to_string(anneeDebut);
	fin = to_string(jourFin) + "," + to_string(moisFin) + "," + to_string(anneeFin);
	it = zoom.begin();
	image.draw_line(250, 150, 1450, 150, blanc);
	image.draw_line(250, 150, 250, 140, rouge);
	image.draw_text(250, 150, debut.c_str(), rouge);
	image.draw_line(1450, 150, 1450, 140, rouge);
	image.draw_text(1450, 150, fin.c_str(), rouge);

	float s;
	struct tm t1 { 0 };
	struct tm t2 { 0 };
	double seconds;
	int duree;

	t1.tm_year = anneeDebut - 1900; t1.tm_mon = moisDebut - 1; t1.tm_mday = jourDebut;
	t2.tm_year = anneeFin - 1900; t2.tm_mon = moisFin - 1; t2.tm_mday = jourFin;
	seconds = difftime(mktime(&t2), mktime(&t1));
	duree = seconds / 86400;
	s = duree;


	srand((unsigned)time(NULL));
	for (it = zoom.begin(); it != zoom.end(); it++)
	{
		int a, b, c;

		a = rand() % (256);
		b = rand() % (256);
		c = rand() % (256);
		unsigned char random[] = { a,b,c };

		image.draw_line(250 + 1200 * dureeZoom(it, jourDebut, moisDebut, anneeDebut) / s, 150, 250 + 1200 * dureeZoom(it, jourDebut, moisDebut, anneeDebut) / s, 140, random);
		image.draw_text(250 + 1200 * dureeZoom(it, jourDebut, moisDebut, anneeDebut) / s, 150, (*it).getDebut().c_str(), random);
		if (k <= 5)
		{
			image.draw_rectangle(x0, y0 + 160 * j, x0 + 200, y0 + 160 * (j + 1), random);
			image.draw_text(x0 + 60, y0 - 5 + 80 * (2 * j + 1), (*it).getTache().c_str(), noir, random, 1.0F, 23U);
			image.draw_arrow(250 + 1200 * dureeZoom(it, jourDebut, moisDebut, anneeDebut) / s, y0 + 80 * (2 * j + 1), 250 + 1200 * dureeZoom(it, jourDebut, moisDebut, anneeDebut) / s + 1200 * (*it).duree() / s, y0 + 80 * (2 * j + 1), random);
			image.draw_text(250 + 1200 * dureeZoom(it, jourDebut, moisDebut, anneeDebut) / s + 600 * (*it).duree() / s, y0 + 80 * (2 * j + 1), to_string((*it).duree()).c_str(), random);
			image.draw_text(250 + 1200 * dureeZoom(it, jourDebut, moisDebut, anneeDebut) / s + 1200 * (*it).duree() / s, y0 + 80 * (2 * j + 1), (*it).getFin().c_str(), random);
		}
		if (k > 5 && k <= 10)
		{
			image.draw_rectangle(x0, y0 + 80 * j, x0 + 200, y0 + 80 * (j + 1), random);
			image.draw_text(x0 + 60, y0 - 3 + 40 * (2 * j + 1), (*it).getTache().c_str(), noir, random, 1.0F, 23U);
			image.draw_arrow(250 + 1200 * dureeZoom(it, jourDebut, moisDebut, anneeDebut) / s, y0 + 40 * (2 * j + 1), 250 + 1200 * dureeZoom(it, jourDebut, moisDebut, anneeDebut) / s + 1200 * (*it).duree() / s, y0 + 40 * (2 * j + 1), random);
			image.draw_text(250 + 1200 * dureeZoom(it, jourDebut, moisDebut, anneeDebut) / s + 600 * (*it).duree() / s, y0 + 40 * (2 * j + 1), to_string((*it).duree()).c_str(), random);
			image.draw_text(250 + 1200 * dureeZoom(it, jourDebut, moisDebut, anneeDebut) / s + 1200 * (*it).duree() / s, y0 + 40 * (2 * j + 1), (*it).getFin().c_str(), random);
		}
		j++;
	}

		CImgDisplay t(image);
		while (!t.is_closed())
		{

			t.wait();

		}
	
}
