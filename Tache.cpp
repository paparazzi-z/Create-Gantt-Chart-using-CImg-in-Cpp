#include<iostream>
#include<string>
#include<ctime>
#include"Tache.h"
using namespace std;

Tache::Tache(int jourDebut, int moisDebut, int anneeDebut, int jourFin, int moisFin, int anneeFin, string &tache)
{
	jourDebut_ = jourDebut;
	moisDebut_ = moisDebut;
	anneeDebut_ = anneeDebut;
	jourFin_ = jourFin;
	moisFin_ = moisFin;
	anneeFin_ = anneeFin;
	tache_ = tache;


}


string Tache::getInfo()
{
	string s;
	s = getTache() + ".," + to_string(getJourDebut()) + "," + to_string(getMoisDebut()) + "," + to_string(getAnneeDebut()) + "," + to_string(getJourFin()) + "," + to_string(getMoisFin()) + "," + to_string(getAnneeFin());
	return s;
}


void Tache:: setTache()
{
	string tache;
	cin.ignore(1000, '\n');
	cout << "Saisir le tache : " << endl;
	getline(cin, tache);
	tache_ = tache;
}


void Tache::setTemps()
{
	int jourDebut, moisDebut, anneeDebut, jourFin, moisFin, anneeFin;
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
	jourDebut_ = jourDebut;
	moisDebut_ = moisDebut;
	anneeDebut_ = anneeDebut;
	jourFin_ = jourFin;
	moisFin_ = moisFin;
	anneeFin_ = anneeFin;
}

string Tache::getDebut()
{
	string s;
	s = to_string(jourDebut_) + "," + to_string(moisDebut_) + "," + to_string(anneeDebut_);
	return s;
}

string Tache::getFin()
{
	string s;
	s = to_string(jourFin_) + "," + to_string(moisFin_) + "," + to_string(anneeFin_);
	return s;
}


int Tache::duree()
{
	struct tm t1 { 0 };
	struct tm t2 { 0 };
	double seconds;
	int duree;

	t1.tm_year = getAnneeDebut() - 1900; t1.tm_mon = getMoisDebut() - 1; t1.tm_mday = getJourDebut();
	t2.tm_year = getAnneeFin() - 1900; t2.tm_mon = getMoisFin() - 1; t2.tm_mday = getJourFin();
	seconds = difftime(mktime(&t2), mktime(&t1));
	duree = seconds / 86400;
	return duree;
}

