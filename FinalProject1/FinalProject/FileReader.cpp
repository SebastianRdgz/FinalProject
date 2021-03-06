#include "FileReader.h"
#include <ctype.h>
using namespace std;
FileReader::FileReader(string name) : f_name(name)
{

}
FileReader::~FileReader()
{

}


//Replace Methots --------------
void FileReader::lineReplace(int l_number)
{
	fstream file;
	file.open(this->f_name, ios::in);
	string line, bfr_Line, aft_Line;
	if (l_number > this->lineCount() || l_number <= 0)
	{
		cout << "The line entered does not match the number of lines displayed on the file." << endl;
	}
	else
	{

		int i = 1, j = 1;
		while (getline(file, line, '\n'))
		{
			if (i < l_number)
			{
				bfr_Line.append(line);
				bfr_Line.append("\n");
				i++;
			}

			if (j > l_number)
			{
				aft_Line.append(line);
				aft_Line.append("\n");

			}
			j++;
		}
		file.close();
		string newline;
		cout << "Enter the new sentence to replace with :" << endl;
		getline(cin, newline, '~');
		if (newline[0] == '\n')
		newline = newline.substr(1, newline.length());
		newline.append(aft_Line);
		bfr_Line.append(newline);

		file.open(this->f_name, ios::out);
		file << bfr_Line;
		file.close();
	}
	
}
void FileReader::paragraphReplace(int p_number)
	{
	fstream file;
	file.open(this->f_name, ios::in);
	string  pgraph, bfr_pgraph, aft_pgraph;
	if (p_number > this->paragraphCount()|| p_number <=0)
	{
		cout << "The paragraph number entered does not match the number of paragraph displayed on the file." << endl;
	}
	else
	{

		int i = 1, j = 1;
		while (getline(file, pgraph, '`'))
		{
			if (i < p_number)
			{
				bfr_pgraph.append(pgraph);
				bfr_pgraph.append("`");
				i++;
			}

			if (j > p_number)
			{
				aft_pgraph.append(pgraph);
				aft_pgraph.append("`");

			}
			j++;
		}
	file.close();
	while (aft_pgraph[0] == '\n')
	{
		aft_pgraph = aft_pgraph.substr(1, aft_pgraph.length());
	}
		string newline;
		cout << "Enter the new paragraph to replace with" << endl;
		getline(cin, newline, '~');
			newline = newline.substr(1, newline.length());
		newline.append("\n");
		newline.append(aft_pgraph);
		bfr_pgraph.append("\n");
		bfr_pgraph.append(newline);
		file.open(this->f_name, ios::out);
		file << bfr_pgraph;
		file.close();
	}
}
void FileReader::sentenceReplace(int s_number)
{
	fstream file;
	file.open(this->f_name, ios::in);
	string  sntnc, bfr_sntnc, aft_sntnc;
	if (s_number > this->sentenceCount()|| s_number  <= 0)
	{
		cout << "The sentence number entered does not match the number of sentences displayed on the file." << endl;
	}
	else
	{

		int i = 1, j = 1;
		while (getline(file, sntnc, '_'))
		{
			if (i < s_number)
			{
				bfr_sntnc.append(sntnc);
				bfr_sntnc.append("_");
				i++;
			}

			if (j > s_number)
			{
				aft_sntnc.append(sntnc);
				aft_sntnc.append("_");

			}
			j++;
		}
		file.close();
		string newline;
		cout << "Enter the new sentece to replace with: " << endl;
		getline(cin, newline, '~');
		newline = newline.substr(1, newline.length());
		newline.append(aft_sntnc);
		bfr_sntnc.append(newline);
		file.open(this->f_name, ios::out);
		file << bfr_sntnc;
		file.close();
	}
}
//------------------------------

//Delete Methots---------------
void FileReader::deleteLine(int l_number)
{
	fstream file;
	file.open(this->f_name, ios::in);
	string  line, bfr_Line, aft_Line;
	if (l_number > this->lineCount()|| l_number <= 0)
	{
		cout << "The line entered does not match the number of lines displayed on the file." << endl;
	}
	else
	{
	
		int i = 1, j = 1;
		while (getline(file, line, '\n'))
		{
			if (i < l_number)
			{
				bfr_Line.append(line);
				bfr_Line.append("\n");
				i++;
			}
	
			if (j > l_number)
			{
				aft_Line.append(line);
				aft_Line.append("\n");
	
			}
			j++;
		}
		file.close();
		file.open(this->f_name, ios::out);
		bfr_Line.append(aft_Line);
		file << bfr_Line;
		file.close();
	}
	
}
void FileReader::deleteParagraph(int p_number)
{
	fstream file;
	file.open(this->f_name, ios::in);
	string  pgraph, bfr_pgraph, aft_pgraph;
	if (p_number > this->paragraphCount() || p_number <= 0)
	{
		cout << "The paragraph number entered does not match the number of paragraph displayed on the file." << endl;
	}
	else
	{

		int i = 1, j = 1;
		while (getline(file, pgraph, '`'))
		{
			if (i < p_number)
			{
				bfr_pgraph.append(pgraph);
				bfr_pgraph.append("`");
				i++;
			}

			if (j > p_number)
			{
				aft_pgraph.append(pgraph);
				aft_pgraph.append("`");

			}
			j++;
		}
		file.close();
		bfr_pgraph.append(aft_pgraph);
		file.open(this->f_name, ios::out);
		file << bfr_pgraph;
		file.close();
	}
}
void FileReader::deleteSentence(int s_number)
{
	fstream file;
	file.open(this->f_name, ios::in);
	string  sntnc, bfr_sntnc, aft_sntnc;
	if (s_number > this->sentenceCount() || s_number <= 0)
	{
		cout << "The paragraph number entered does not match the number of paragraph displayed on the file." << endl;
	}
	else
	{

		int i = 1, j = 1;
		while (getline(file, sntnc, '_'))
		{
			if (i < s_number)
			{
				bfr_sntnc.append(sntnc);
				bfr_sntnc.append("_");
				i++;
			}

			if (j > s_number)
			{
				aft_sntnc.append(sntnc);
				aft_sntnc.append("_");

			}
			j++;
		}
		file.close();
		bfr_sntnc.append(aft_sntnc);
		file.open(this->f_name, ios::out);
		file << bfr_sntnc;
		file.close();
	}
}
//------------------------------

//Count Methots-----------------
int FileReader:: lineCount()
{
	char ch;
	int count =0;
	this->file.open(this->f_name, ios::in);
	this->file.get(ch);
	while (!file.eof()) //algorith for counting lines in a file
	{
		if (ch == '\n')
			count++;
		file.get(ch);
	}
	this->file.close();
	return count;
}
int FileReader::paragraphCount()
{
	char ch;
	int count = 0;
	this->file.open(this->f_name, ios::in);
	this->file.get(ch);
	while (!file.eof()) //algorith for counting lines in a file
	{
		if (ch == '`')
			count++;
		file.get(ch);
	}
		this->file.close();
	return count;
}
int FileReader::sentenceCount()
{
	char ch;
	int count = 0;
	this->file.open(this->f_name, ios::in);
	this->file.get(ch);
	while (!file.eof()) //algorith for counting sentences in a file
	{
		if (ch == '_')
			count++;
		file.get(ch);
	}
	this->file.close();
	return count;
}
void FileReader::wordPosCount(size_t remote_variable, string word_to_find, string file_content_holder)
{
	int i = 0;
	cout << "We found " << word_to_find << " on: " << endl;
	if (remote_variable != string::npos)
	{
		cout << '\t' << i + 1 << ')' << remote_variable << endl;
		i++;
	}
	int z = 0;
	for (unsigned int g = remote_variable; g == remote_variable; z = 1)
	{
		g = remote_variable;
		int m = 1;
		remote_variable = file_content_holder.find(word_to_find, remote_variable + z);
		if (remote_variable > g && remote_variable < 40000)
		{
			cout << '\t' << i + 1 << ')' << remote_variable << endl;
			i++;
			g = remote_variable;
		}
		else
		{
			g = 0;
		}
	}
}
//------------------------------

//Utility-----------------------
bool FileReader::is_empty(string f_name)
{
	ifstream file(f_name);
	return(file.peek() == ifstream::traits_type::eof());
}
//------------------------------

void FileReader::editByLine(int l_number)
{
	fstream file;
	file.open(this->f_name, ios::in);
	string line, str, temp;
	if (l_number > this->lineCount() || l_number <= 0)
	{
		cout << "The line entered does not match the number of lines displayed on the file." << endl;
	}
	else
	{
		while (getline(file, line, '\n'))
		{
			str.append(line);
			str.append("\n");
		}
		file.close();
		string temp;
		int j = 0;
		int i = 0;
		while (i < l_number - 1)
		{
			if (str[j] == '\n')
			{
				i++;
			}
			j++;
		}
		temp = str.substr(0, j);
		temp.append("\n");
		temp.append(str.substr(j, str.length()));
		ofstream file(this->f_name);
		file << temp;
		file.close();
		this->lineReplace(l_number);
		
	}

}
void FileReader::fileRead()
{
	cout << "\tV--------------------------File Content-------------------------V"<<endl << endl;
	this->file.open(this->f_name,ios::in);	
	char ch;
	this->file.get(ch);
	while (!file.fail())
	{
		cout.put(ch);
		this->file.get(ch);
	}
	cout << endl;
	this->file.close();

}