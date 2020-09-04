#include<iostream>
#include<list>
#include<string>
#include<Windows.h>
#include<ShlObj.h>
#include"Menu.h"
#include"Diagramme .h"

using namespace std;

void printMenu()
{
	cout << "1 . Creer un nouveau diagramme. " << endl << "2 . Lire un diagramme. " << endl << "3 . Retirer. " << endl;

}


void Debut()
{
	Diagramme d;
	int choise = 0;
	cout << "Bienvenue!" << endl << endl;
	do
	{

		cout << endl;
		printMenu();
		cin >> choise;
		switch (choise)
		{
		case 1:
		{
			d.saisirTache();
			d.drawDiagramme();
			break;
		}
		case 2:
		{
			string nomOpen = getOpenFileName("Nom du fichier ?ouvrir :", "Fichiers textes (*.txt *.cpp)");
			d.lireTache(nomOpen);
			d.drawDiagramme();
			break;
		}
		case 3:
		{
			cout << endl << endl << endl;
			cout << "Merci bien d'utiliser! Au revoir! " << endl;
			break;
		}
		default:
			cout << "Saisir un nombre entre 1 et 3. " << endl << endl;
			break;
		}
	} while (choise != 3);
}


string getOpenFileName(const string &title, const string &filter, const string &initialDir)
{

	// Processing of the filter
	size_t begin_pos = filter.find_first_of('(');
	size_t end_pos = filter.find_last_of(')');
	size_t nb = end_pos - begin_pos;
	string ext;
	if (begin_pos != string::npos && end_pos != string::npos && nb > 1) {
		ext = filter.substr(begin_pos + 1, nb - 1);
		for (unsigned i = 0; i < ext.size(); i++) if (ext[i] == ' ') ext[i] = ';';
	}
	string ext_filter = filter + '\0' + ext + '\0';

	char name[MAX_PATH] = "";
	OPENFILENAME of;
	memset(&of, 0, sizeof(of));
	of.lStructSize = sizeof(of);
	of.lpstrFile = name;
	of.lpstrInitialDir = initialDir.c_str();
	of.lpstrFilter = &ext_filter[0];
	of.nMaxFile = MAX_PATH;
	of.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
	of.lpstrTitle = title.c_str();

	string name_string;
	if (GetOpenFileName(&of)) name_string = string(name);
	return name_string;
}

string getSaveFileName(const string &title, const string &filter, const string &initialDir)
{

	// Processing of the filter
	size_t begin_pos = filter.find_first_of('(');
	size_t end_pos = filter.find_last_of(')');
	size_t nb = end_pos - begin_pos;
	string ext;
	if (begin_pos != string::npos && end_pos != string::npos && nb > 1) {
		ext = filter.substr(begin_pos + 1, nb - 1);
		for (unsigned i = 0; i < ext.size(); i++) if (ext[i] == ' ') ext[i] = ';';
	}
	string ext_filter = filter + '\0' + ext + '\0';

	char name[MAX_PATH] = "";
	OPENFILENAME of;
	memset(&of, 0, sizeof(of));
	of.lStructSize = sizeof(of);
	of.lpstrFile = name;
	of.lpstrInitialDir = initialDir.c_str();
	of.lpstrFilter = &ext_filter[0];
	of.nMaxFile = MAX_PATH;
	of.Flags = OFN_PATHMUSTEXIST | OFN_OVERWRITEPROMPT;
	of.lpstrTitle = title.c_str();

	string name_string;
	if (GetSaveFileName(&of)) name_string = string(name);
	return name_string;
}