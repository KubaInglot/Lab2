
//Uppgiftinstruktioner
/*
//Du ska skapa ett fristående program som utför uppgifterna nedan.
//Börja med att lösa uppgift ett och färdigställ den uppgiften innan du börjar på uppgift 2.
//Ditt program ska läsa filerna som omnämns ifrån ”current working directory”.

//Samtliga filer är i textformat med ”\n” som radslut.Du kan om du önskar
//använda pipes och redirects för att lösa filinläsningen och utskriften istället
//för std::ifstream och std::ofstream.Kommentera i sådant fall det i koden
//tillsammans med exempel på hur programmet används.


//1. Filen names.txt innehåller namn och personnummer på följande form.Filen
//innehåller flera personer.
//Förnamn Efternamn
//YYMMDDNNNN
//Adressrad

	//Din uppgift är att omvandla indatat till formen :
//Efternamn, Förnamn
//Adressrad
//Filen names.txt finner du på :
//http://w3.miun.se/dt028g/attach/164/names.txt.


//2. Utdatat ska indikera om personen är en man eller kvinna.Exempelvis för
//en man kan det stå :
//Efternamn, Förnamn[M]
//Adressrad
*/



#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

#include "names.txt"
#include "LabApp.h"
using namespace std;




vector<string> vec_Of_Names;
vector <int> vec_Of_Year;
vector<string> vec_Of_Adres;

void Load_file()
{
	fstream file;
	file.open("names.txt", ios::in);// ios:in = odczyt pliku 
	string line;
	int line_number = 1;

	if (file.good() == false)
	{
		cout << "file cant open";

	}

	//1
	int line_number = 1, year_Temp;
	string line, name_Temp, adres_Temp, control;

	while (getline(file, line))
	{
		switch (line_number)
		{
		case 1: name_Temp = line;
			vec_Of_Names.push_back(name_Temp);
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
			vec_Of_Year.push_back(year_Temp);
			break;

		case 3:adres_Temp = line;
			vec_Of_Adres.push_back(adres_Temp);
			break;


		default:
			break;
		}

		line_number++;

	}

	file.close();
}

void Save_file(vector<string> names, vector<string> adress)
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

	ByteNamn(names);
	string temp;
	for (int i = 0; (i <= names.size()) & (i <= adress.size()); i++)
	{
		name_Temp = names[i];
		adres_Temp = adress[i];
		Man_eller_kvinna(vec_Of_Year[i]);

		if (Man_eller_kvinna(vec_Of_Year[i]) == true)
		{
			file << name_Temp << endl << adres_Temp << endl << "Man" << endl;
		}

		if (Man_eller_kvinna(vec_Of_Year[i]) == true)
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
		file << name_Temp << " " << endl; break;

	case 2:
		file << adres_Temp << endl;  break;




	default:
		break;
	}



	file.close();
}

void ByteNamn(vector<string> names)
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
			nameletter++;// Kommer orsaka problem om det finns mer än 1 space mellan namn och effternamn

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

//2
bool Man_eller_kvinna(int Y) //2,4,6=man 3,5,7=kvinna
{
	string control;
	if (atoi(control.c_str) % 2 == 0)
	{
		return true;//male
	}
	else
	{
		return false;//kobieta
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
	Load_file();


	ByteNamn(vec_Of_Names);

	Save_file(vec_Of_Names, vec_Of_Adres);


}

