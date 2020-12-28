#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "LabApp.h"

#include <sstream>

using namespace std;
vector<string> vec_names;
vector<string> vec_national_id_nr;
vector<string> vec_address;

void load_file(const string& path)
{
	fstream file;
	string line;
	string name_temp;
	string address_temp;
	string national_id_nr_temp;
	int line_number = 1;
	
	file.open(path, ios::in);
	
	if (file.is_open() && file.good() == true)
	{	
		cout << "File loaded correctly." << endl;
	}
	else
	{
		cout << "File load failed!" << endl;
		exit(0);
	}

	while (getline(file, line))
	{		
		switch (line_number)
		{
		case 1:
			name_temp = line;
			vec_names.push_back(name_temp);
			break;
		case 2:
			national_id_nr_temp = line;
			vec_national_id_nr.push_back(national_id_nr_temp);
			break;
		case 3:
			address_temp = line;
			vec_address.push_back(address_temp);
			break;
		default:
			break;
		}		
		line_number++;
		if (line_number == 4)
		{
			line_number = 1;
		}
	}
}

void temp_file()
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

	//test
	//while (getline(file, line))
	//{
	//	switch (line_number)
	//	{
	//	case 1: name_Temp = line;
	//		vec_names.push_back(name_Temp);
	//		break;

	//	case 2:
	//		for (int i = 0; i <= line.length; i++)
	//		{
	//			while (isdigit(line.c_str()[i] == true))
	//			{
	//				control = control + line[i];
	//			}
	//		}
	//		year_Temp = atoi(control.c_str());
	//		vec_year.push_back(year_Temp);
	//		break;

	//	case 3: adres_Temp = line;
	//		vec_address.push_back(adres_Temp);
	//		break;


	//	default:
	//		break;
	//	}

	//	line_number++;
	//}

	file.close();
}

void save_file(vector<string> names, vector<string> address, vector<string> genders)
{
	fstream file;
	string line;	
	file.open("outNames.txt", ios::out);
	
	for (auto i = 0; (i < names.size()) && (i < address.size()); i++)
	{
		auto name_temp = names[i];
		auto address_temp = address[i];
		auto gender = genders[i];
		file << name_temp << gender << endl;
		file << address_temp << endl;
	}

	file.close();
}

void change_name(vector<string> names)
{
	//vector<string> name_first, name_second;
	//string temp;

	////dela efternamn och namn i två
	//for (int i = 0; i <= names.size(); i++)
	//{
	//	for (int nameletter = 0; nameletter < names[i].length; nameletter++)
	//	{
	//		while (isalpha(names[i][nameletter]) == true)
	//		{
	//			temp = temp + ((names[i])[nameletter]);
	//		}
	//		name_first.push_back(temp);
	//		temp = "";
	//		nameletter++; // Kommer orsaka problem om det finns mer än 1 space mellan namn och effternamn

	//		while (isalpha(names[i][nameletter]) == true)
	//		{
	//			temp = temp + ((names[i])[nameletter]);
	//		}
	//		name_second.push_back(temp);
	//		temp = "";
	//	}
	//}


	////Organisera om till namn och efternamn
	//for (int i = 0; i <= name_second.size(); i++)
	//{
	//	temp = temp + name_second[i] + " ";
	//	for (int i2 = 0; i2 <= name_first.size(); i2++)
	//	{
	//		temp = temp + name_first[i2];
	//	}
	//}
}

bool is_man(int Y) //2,4,6=man 3,5,7=kvinna
{
	//string control;
	//if (atoi(control.c_str) % 2 == 0)
	//{
	//	return true; //male
	//}
	//return false; //kobieta

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
	return false;
}

vector<string> swap_names(vector<string> names)
{
	vector<string> name_first, name_second;
	string temp;	

	for (int i = 0; i < names.size(); i++)
	{
		string line = names[i];
		std::string delimiter = " ";

		size_t pos = 0;
		std::string first_name;
		std::string last_name;
		while ((pos = line.find(delimiter)) != std::string::npos)
		{
			first_name = line.substr(0, pos);
			std::cout << first_name << std::endl;
			last_name = line.erase(0, pos + delimiter.length());
			std::cout << last_name << std::endl;
		}

		names[i] = last_name + delimiter + first_name;
	}
	
	return names;
};

vector<string> define_gender(vector<string> ids)
{
	// change NationalId to gender char
	
	return ids;
};

int main()
{
	load_file("names.txt");
	vec_names = swap_names(vec_names);
	vector<string> vec_gender_national_id_nr = define_gender(vec_national_id_nr);
	
	save_file(vec_names, vec_address, vec_gender_national_id_nr);

	//change_name(vec_names);
	//save_file(vec_names, vec_address);
}
