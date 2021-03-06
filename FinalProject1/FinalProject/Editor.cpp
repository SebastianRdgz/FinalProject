#include "Editor.h"
#include<iostream>
#include "FileManager.h"


Editor::Editor(string name) :f_name(name), reader(name)
{
	
}
Editor::~Editor()
{
	
}
//Edit Methots -----------------
void Editor::editFile()
{
	FileReader emp(f_name);
	//this methods needs to validate if the file 
	//has is new or has something written in it
	if (emp.is_empty(f_name))
	{
		cout << "File is empty." << endl;
	}
	else
	{
		cout << "This is what the file has currently written" << endl << endl;
	}

	this->reader.fileRead();
	file.open(this->f_name,ios::app);

	cout << "You can now start writing into the file." << endl;
	string n_text,text;
	getline(cin, n_text, '~');
	cin.ignore();
	text  = n_text.substr(1, n_text.length());
	file << text;

	file.close();
}
void Editor::editLine()
{
	
	int l_number;
	if (this->reader.is_empty(this->f_name))
	{
		cout << "Nothing to edit. File is emtpty." << endl;
	}
	else
	{ 
		cout << "There are " << this->reader.lineCount() << " lines on file. " << endl
			 << "Enter the number of the line you want to replace: " << endl;
		cin >> l_number;
		this->reader.lineReplace(l_number);
	}
	
}
void Editor::editParagraph()
{
	int p_number;
	if (reader.paragraphCount() != 0)
	{
		cout << "Enter the number of the paragraph: " << endl;
		cin >> p_number;
		this->reader.paragraphReplace(p_number);
	}
	else
	{
		cout << "\n\aWhoops! There are no pragraphs pointers on this file. \nRead the manual for more info. \n";
		this->menu();
	
	}
}
void Editor::editWord()
{
	string word, content, word2, word3;
	unsigned int c = 1, pos = 0;
	cout << "Type in the word you want to edit. Please type as it is in the file : ";
	cin >> word;
	ifstream emp(f_name);
	while (!emp.eof())
	{
		getline(emp, content, '~');
		bool g = true;
		do
		{
			if (content.find(word, 0) != string::npos)
				g = true;
			else
			{
				cout << "\nWord was not found on the file. Try Again. \n\nEnter word: ";
				cin >> word;
				g = false;
			}
		}while (g != true);

		emp.close();
	}
	cout << "\nEnter the replacement word :";
	cin >> word2;
	fstream emp2(f_name);
	size_t Found = content.find(word);
	reader.wordPosCount(Found, word, content);
	cout << "Enter the position of the word: ";
	cin >> pos;
	int a = word.length();
	if (word.length() > word2.length())
	{
		a = word.length() - word2.length();
	}
	if (word.length() < word2.length())
	{
		a = word2.length() - word.length();
	}

	if (word.length() <= word2.length())
		content.replace(pos, word.length() + a - 1, word2);
	if (word.length() > word2.length())
	{
		for (unsigned int q = 0; q < (word.length() - word2.length());q++)
			content.append("\b\b");
		content.replace(pos, word.length() - a + (word.length() - word2.length()), word2);
	}


	emp2 << content;
	emp2.close();
}
void Editor::editSentence()
{
	
	int s_number;
	if (this->reader.is_empty(this->f_name)|| this->reader.sentenceCount() <= 0)
	{
		cout << "Nothing to edit. File has no sentences or is empty." << endl;
	}
	else
	{
		cout << "There are " << this->reader.sentenceCount() << " sentences on file. " << endl
			<< "Enter the number of the sentence you want to replace." << endl;
	cin >> s_number;
	this->reader.sentenceReplace(s_number);
}
	
}
//------------------------------
//Delete Methots ---------------
void Editor::deleteLine()
{
	int l_number;
	if (this->reader.is_empty(this->f_name)|| this->reader.lineCount() <= 0)
	{
		cout << "Nothing to edit. File is empty." << endl;
	}
	else
	{
		cout << "There are " << this->reader.lineCount() << " lines on file. " << endl
			<< "Enter the number of the line you want to delete" << endl;
	cin >> l_number;
	this->reader.deleteLine(l_number);
}

}
void Editor::deleteParagraph()
{
	int p_number;
	if (reader.paragraphCount() != 0)
	{
		cout << "Enter the number of the paragraph: " << endl;
		cin >> p_number;
		this->reader.deleteParagraph(p_number);
	}
	else
	{
		cout << "\n\aWhoops! There are no pragraphs pointers on this file. \nRead the manual for more info. \n";
		this->menu();

	}
}
void Editor::deleteWord()
{
	string word, content, word2;
	unsigned int c = 1, i = 0, pos = 0;
	cout << "Type in the word you want to delete. Please type as it is in the file : ";
	cin >> word;
	ifstream emp(f_name);
	while (!emp.eof())
	{
		bool g;
		getline(emp, content, '~');
		do
		{
			if (content.find(word, 0) != string::npos)
				g = true;
			else
			{
				cout << "\nWord was not found on the file. Try Again. \n\nEnter word: ";
				cin >> word;
				g = false;
			}
		} while (g != true);
		emp.close();
	}
	fstream emp2(f_name);
	size_t Found = content.find(word);
	reader.wordPosCount(Found, word, content);
	cout << "Enter the position of the word: ";
	cin >> pos;
	for (unsigned int q = 0; q < word.length(); q++)
	{
		content.append("\b");
	}
	content.erase(pos, word.length());

	emp2 << content;
	emp2.close();
}
void Editor::deleteSentence()
{
	int s_number;
	if (this->reader.is_empty(this->f_name) || this->reader.sentenceCount() <= 0)
	{
		cout << "Nothing to edit. File has no sentences or is empty." << endl;
	}
	else
	{
		cout << "There are " << this->reader.sentenceCount() << "sentences on file. " << endl
			<< "Enter the number of the sentence you want to delete." << endl;
	cin >> s_number;
	this->reader.deleteSentence(s_number);
}
	
}
void Editor::clearFile()
{
	string yn;
	cout << "Are you sure you want to delete the file. After is done you cant undo. Y/N: ";
	cin >> yn;
	do
	{
		if (yn == "Y" || yn == "y")
		{
			FileManager::loading();
			this->file.open(this->f_name, ios::out | ios::trunc);
			file.close();
			cout << "File cleared" << endl;
			return;
		}
		else if (yn == "n" || yn == "N")
		{
			cout << "File wasn't deleted. Returning to main menu." << endl;
			return;
		}
		else
		{
			cout << "\aDidn't get that. Try again. \n Yes or No? ";
			cin >> yn;
		}
	} while (yn != "y" || yn != "Y" || yn != "n" || yn != "N");
}
void Editor::replaceLine()
{
	int l_number;
	if (this->reader.is_empty(this->f_name))
	{
		cout << "Nothing to edit. File is emtpty." << endl;
	}
	else
	{
		cout << "There are " << this->reader.lineCount() << " lines on file. " << endl
			<< "Enter the number of the line you want to replace: " << endl;
		cin >> l_number;
		this->reader.lineReplace(l_number);
	}

}
void Editor::addLine()
{
	int l_number;
	if (this->reader.is_empty(this->f_name))
	{
		cout << "Nothing to edit. File is emtpty." << endl;
	}
	else
	{
		cout << "There are " << this->reader.lineCount() << " lines on file. " << endl
			<< "Enter the number of the line where you want to edit: " << endl;
		cin >> l_number;
		this->reader.editByLine(l_number);
	}
}
void Editor::menu()
{
	MyMenu menu;
	string option;
	FileReader men(this->f_name);
	menu.cambiarTitulo("Welcome to the text editing tool            I");
	menu.agregarOpcion("Start writing into the file.     I");
	menu.agregarOpcion("View file content.               I");
	if (!men.is_empty(this->f_name))
	{
		menu.agregarOpcion("Edit a word.                     I");
		menu.agregarOpcion("Delete a word.                   I");
		menu.agregarOpcion("Edit a line.                     I");
		menu.agregarOpcion("Add new line                     I");
		menu.agregarOpcion("Delete a line.                   I");
		menu.agregarOpcion("Edit a paragraph.                I");
		menu.agregarOpcion("Delete a paragraph.              I");
		menu.agregarOpcion("Edit a sentence.                 I");
		menu.agregarOpcion("Delete a sentence.               I");
		menu.agregarOpcion("Clear file.                      I");
	}
		menu.agregarOpcion("Return to previous menu.         I");
		menu.cambiarPregunta("Please choose one of the option shown above.I");

	cout << "____________________________________________" << endl;
	cout << menu << endl;
	cout << "____________________________________________" << endl;

	cin >> option;

	if (option == "1")
	{
		this->editFile();
		this->menu();
	}
	else if (option == "2")
	{
		this->reader.fileRead();
		cout << endl;
		this->menu();
	}
	if (!men.is_empty(this->f_name))
	{
		if (option == "3")
		{
			this->editWord();
			this->menu();
		}
		else if (option == "4")
		{
			this->deleteWord();
			this->menu();
		}
		else if (option == "5")
		{
			this->editLine();
			this->menu();
		}
		else if (option == "6")
		{
			this->addLine();
			this->menu();
		}
		else if (option == "7")
		{
			this->deleteLine();
			this->menu();
		}
		else if (option == "8")
		{
			this->editParagraph();
			this->menu();
		}
		else if (option == "9")
		{
			this->deleteParagraph();
			this->menu();
		}
		else if (option == "10")
		{
			this->editSentence();
			this->menu();
		}
		else if (option == "11")
		{
			this->deleteSentence();
			this->menu();
		}
		else if (option == "12")
		{
			this->clearFile();
			this->menu();
		}
		else if (option == "13")
		{
			cout << "Saving document..." << endl
				<< "Now going back to previous menu." << endl;
			return;
		}
		else
		{
			cout << "\aInvalid input, please try again" << endl;
			this->menu();
		}
	}
		else if (men.is_empty(this->f_name))
	{
		if (option == "3")
		{
			cout << "Saving document..." << endl
				<< "Now going back to previous menu." << endl;
			return;
		}
		else
		{
			cout << "\aInvalid input, please try again." << endl;
			this->menu();
		}
	}
}