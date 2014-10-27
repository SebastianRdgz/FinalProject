#pragma once
#include <iostream>
#include "MyMenu.h"
#include <string>
#include "Editor.h"
#include "FileReader.h"


class FileManager
{

public:
	FileManager();
	int openFile();
	void createFile();
	void menu();
	~FileManager();
	void loading();
	void copyFile();
	void openreadme();
	void RecentFiles();
};

