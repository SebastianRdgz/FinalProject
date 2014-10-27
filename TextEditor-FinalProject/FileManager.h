#pragma once
#include <iostream>
#include <fstream>
#include "MyMenu.h"
#include "EditorManager.h"
#include "MyString.h"
#include "Editor.h"

using namespace std;

const int MAX_FILES = 10;

class FileManager
{
private:
	string FileName[MAX_FILES]; //Guarda el nombre del file.
public:
	FileManager(string FileName = "");
	FileManager(const FileManager & aFileManager);
	~FileManager();
	string fixName(int &g); //A~ade .txt al nombre del file
	void openFile(int &g);
	void createFile(int &g, unsigned int &x, unsigned int &n, unsigned int &w);
	void askName();
	void copyDocument(int &g);
	bool operator == (string FileName) const;
	void Menu();
	int nameCount(); //Busca un indice vacio para colocar el nombre en el array.
	void RecentDocumentsSave();
	int exit();
	static inline void loadbar(unsigned int &x, unsigned int &n, unsigned int &w);
	friend istream & operator << (istream in, FileManager & aFileManager);
	friend ostream & operator >> (ostream out, const FileManager & aFileManager);

};