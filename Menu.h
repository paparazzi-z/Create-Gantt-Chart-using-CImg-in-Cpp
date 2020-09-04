//                           AUTEUR: Nan ZHOU

#ifndef MENU
#define MENU
#include<string>
using namespace std;


void Debut();

void printMenu();

string getOpenFileName(const string &title = "Open a file", const string &filter = "All files (*.*)", const string &initialDir = "");

string getSaveFileName(const string &title = "Save file as", const string &filter = "All files (*.*)", const string &initialDir = "");

#endif // !MENU
