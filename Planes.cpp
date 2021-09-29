#include "Planes.h"
#include <fstream>

Planes::Planes()
{
}
Planes::~Planes()
{
}
void Planes::addPlane()
{
	string mk;
	string md;
	string tn;
	int sts;
	string rg;
	string stat = "none";
	int choice;
	cin.ignore();
	cout << "Enter the make: ";
	getline(cin, mk);
	cout << "Enter model: ";
	getline(cin, md);
	cout << "Enter the tail-number: ";
	getline(cin, tn);
	cout << "Enter the number of seats: ";
	cin >> sts;
	cin.ignore();
	cout << "Enter the expected range (with units): ";
	getline(cin, rg);
	cout << "Enter the current status of plane: \n1.\tout\n2.\tin\n3.\trepair\n";
	while (stat == "none")
	{
		cin >> choice;
		switch (choice)
		{
		case 1: {stat = "out";	break; }
		case 2: {stat = "in";	break; }
		case 3: {stat = "repair";	break; }
		default: {cout << "Invalid choice" << endl; break; }
		}
	}

	Plane tmp(mk, md, sts, rg, stat);
	Plane_List[tn] = tmp;
}
void Planes::deletePlane(string key)
{
	if (key != "ERROR")
	{
		map <string, Plane>::iterator it;
		it = Plane_List.find(key);
		Plane_List.erase(it);
		cout << "Plane \"" << key << "\" has been deleted...\n";
	}
	else
	{
		cout << key << " PLANE NOT FOUND..." << endl;
	}
}
void Planes::editPlane(string key)
{
	if (key != "ERROR")
	{
		int dateType;
		string tmp;
		int num;
		Plane_List[key].print();
		cout << "1.\tMake\n2.\tModel\n3.\tTail Number\n4.\tNumber of Seats\n5.\tRange\n6.\tStatus\n"
			<< "Select a data type from above you wish to change: ";
		cin >> dateType;
		cout << "Enter the new value: ";
		cin.ignore();
		switch (dateType)
		{
			case 1: {getline(cin, tmp);	Plane_List[key].setMake(tmp);	break; }
			case 2: {getline(cin, tmp);	Plane_List[key].setModel(tmp);	break; }
			case 3:
			{
				getline(cin, tmp);
				Plane_List[tmp] = Plane_List[key];
				Plane_List.erase(key);
				break;
			}
			case 4: {cin >> num; Plane_List[key].setNumSeats(num);	break; }
			case 5: {getline(cin, tmp);	Plane_List[key].setRange(tmp);	break; }
			case 6: {getline(cin, tmp);	Plane_List[key].setStatus(tmp);	break; }
		}
	}
	else
	{
		cout << key << " PLANE NOT FOUND..." << endl;
	}
}
string Planes::findPlane()
{
	string tn;
	string key;
	cout << "Enter plane's Tail-Nunmber: ";
	cin.ignore();
	getline(cin, tn);
	map <string, Plane>::iterator it = Plane_List.find(tn);
	if (it != Plane_List.end())
	{
		key = it->first;
		return key;
	}
	else
	{
		return("ERROR");
		
	}
}
void Planes::printPlane(string key)
{
	if (key != "ERROR")
	{
		Plane_List[key].print();
		cout << "Press enter to continue...\n";
		cin.ignore();
	}
	else
	{
		cout << key << " PLANE NOT FOUND..." << endl;
	}
}
void Planes::printPlanes()
{
	string i;
	for (map <string, Plane>::iterator it = Plane_List.begin(); it != Plane_List.end(); it++)
	{
		cout << "TailNumber: " << it->first << endl;
		it->second.print();
		cout << endl;
	}
	cout << "Press enter to continue...\n";
	getline(cin, i);
	cin.ignore();
}
void Planes::AddToFlight(string& id, int& num)
{
	string tmp;
	for (map <string, Plane>::iterator it = Plane_List.begin(); it != Plane_List.end(); it++)
	{
		cout << "TailNumber: " << it->first << "	Status: " << it->second.getStatus() << endl;
	}
	cout << "Enter the tail number of the plane you wish to use for the flight: ";
	getline(cin, tmp);
	map <string, Plane>::iterator it = Plane_List.find(tmp);
	if (it != Plane_List.end() && it->second.getStatus() == "in")
	{
			id = tmp;
			num = it->second.getNumSeats();
			cout << endl;
	}
	else
	{
		cout << "Plane selected either does not exist or is unavailable please choose another" << endl;
		AddToFlight(id, num);
	}
}
void Planes::store()
{
	map <string, Plane>::iterator it;
	ofstream myFile;
	myFile.open("Planes.txt");
	for (it = Plane_List.begin(); it != Plane_List.end(); it++)
	{
		myFile << it->first << endl
			<< it->second.getMake() << endl
			<< it->second.getModel() << endl
			<< it->second.getNumSeats() << endl
			<< it->second.getRange() << endl
			<< it->second.getStatus() << endl;
	}
}
void Planes::load()
{
	string key;
	string make;
	string model;
	int num;
	string range;
	string status;
	map <string, Plane>::iterator it;
	ifstream myFile;
	myFile.open("Planes.txt");
	if (myFile.is_open())
	{
		while (!myFile.eof())
		{
			myFile >> key
				>> make
				>> model
				>> num;
			myFile.ignore();
			getline(myFile, range);
			myFile >> status;
			Plane tmp(make, model, num, range, status);
			Plane_List[key] = tmp;
		}
	}
	else
	{
		cout << "Plane List was not found..." << endl;
	}
}

