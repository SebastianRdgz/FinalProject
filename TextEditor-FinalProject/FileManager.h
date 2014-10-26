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
	FileManager(string FileName[MAX_FILES]);
	FileManager(const FileManager & aFileManager);
	~FileManager();
	string fixName(string FileName[], int &g); //A~ade .txt al nombre del file
	void setName(const FileManager & aFileManager);
	string getName() const;
	void openFile();
	void createFile();
	void copyDocument(string FileName);
	bool operator == (const FileManager & aFileManager) const;
	bool operator == (string FileName) const;
	void showMenu();
	int nameCount(int &g); //Busca un indice vacio para colocar el nombre en el array.
	void RecentDocumentsSave();
};