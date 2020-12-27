#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "LabApp.h"
using namespace std;

vector<string> vec_names;
vector<int> vec_year;
vector<string> vec_address;

void load_file()
{
	fstream file;
	file.open("names.txt", ios::in); // ios:in = odczyt pliku 
	string line;
	int line_number = 1;

	if (file.good() == false)
	{
		cout << "file cant open";
	}
	
	int year_Temp;
	string name_Temp;
	string adres_Temp;
	string control;

	while (getline(file, line))
	{
		switch (line_number)
		{
		case 1: name_Temp = line;
			vec_names.push_back(name_Temp);
			break;

		case 2:
			for (int i = 0; i <= line.length; i++)
			{
				while (isdigit(line.c_str()[i] == true))
				{
					control = control + line[i];
				}
			}
			year_Temp = atoi(control.c_str());
			vec_year.push_back(year_Temp);
			break;

		case 3: adres_Temp = line;
			vec_address.push_back(adres_Temp);
			break;


		default:
			break;
		}

		line_number++;
	}

	file.close();
}

void save_file(vector<string> names, vector<string> address)
{
	fstream file;
	file.open("names.txt", ios::out); //ios:out =zapis do pliku 

	int line_number = 1;
	string line, name_Temp, adres_Temp;

	//finns filen redan?
	if (file.good() == false)
	{
		cout << "file cant open";
	}

	change_name(names);
	string temp;
	for (int i = 0; (i <= names.size()) & (i <= address.size()); i++)
	{
		name_Temp = names[i];
		adres_Temp = address[i];
		is_man(vec_year[i]);

		if (is_man(vec_year[i]) == true)
		{
			file << name_Temp << endl << adres_Temp << endl << "Man" << endl;
		}

		if (is_man(vec_year[i]) == true)
		{
			file << name_Temp << endl << adres_Temp << endl << "Kvinna" << endl;
		}
		else
		{
			cout << "Save_File Error";
		}
	}

	switch (line_number)
	{
	case 1:
		file << name_Temp << " " << endl;
		break;

	case 2:
		file << adres_Temp << endl;
		break;


	default:
		break;
	}


	file.close();
}

void change_name(vector<string> names)
{
	vector<string> name_first, name_second;
	string temp;

	//dela efternamn och namn i två
	for (int i = 0; i <= names.size(); i++)
	{
		for (int nameletter = 0; nameletter < names[i].length; nameletter++)
		{
			while (isalpha(names[i][nameletter]) == true)
			{
				temp = temp + ((names[i])[nameletter]);
			}
			name_first.push_back(temp);
			temp = "";
			nameletter++; // Kommer orsaka problem om det finns mer än 1 space mellan namn och effternamn

			while (isalpha(names[i][nameletter]) == true)
			{
				temp = temp + ((names[i])[nameletter]);
			}
			name_second.push_back(temp);
			temp = "";
		}
	}


	//Organisera om till namn och efternamn
	for (int i = 0; i <= name_second.size(); i++)
	{
		temp = temp + name_second[i] + " ";
		for (int i2 = 0; i2 <= name_first.size(); i2++)
		{
			temp = temp + name_first[i2];
		}
	}
}

bool is_man(int Y) //2,4,6=man 3,5,7=kvinna
{
	string control;
	if (atoi(control.c_str) % 2 == 0)
	{
		return true; //male
	}
	else
	{
		return false; //kobieta
	}

	//for (int i = 0; i <Y.size(); i++)
	//{
	//	if (atoi(control.c_str)%2 ==1)
	//	{
	//		return false;//kvinna
	//	}
	//	else
	//	{
	//		return true;//man
	//	}*/
	//}
}

int main()
{
	load_file();
	change_name(vec_names);
	save_file(vec_names, vec_address);
}
