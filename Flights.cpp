#include "Flights.h"
#include <fstream>

Flights::Flights()
{
}
Flights::~Flights()
{
}
void Flights::addFlight(string plane, string pilot, string copilot, string crew1, string crew2, string crew3, int p)
{
	cin.ignore();
	string key;
	string planeID = plane;
	string pilotID = pilot;
	string copilotID = copilot;
	string c1 = crew1;
	string c2 = crew2;
	string c3 = crew3;
	string SD;
	string ED;
	int ST;
	int ET;
	string SC;
	string EC;
	int pass;
	int seats = p;
	string stat;

	cout << "Enter the ID for the flight: ";
	getline(cin, key);
	cout << "Enter the starting date(mm/dd/yy): ";
	getline(cin, SD);
	cout << "Enter the ending date(mm/dd/yy): ";
	getline(cin, ED);
	cout << "Enter the starting time in GMT: ";
	cin >> ST;
	cout << "Enter the ending time in GMT: ";
	cin >> ET;
	cout << "Enter the starting airport code: ";
	getline(cin, SC);
	cout << "Enter the ending airport code: ";
	getline(cin, EC);
	cout << "Enter the number of passengers: ";
	cin >> pass;
	while (pass > seats)
	{
		cout << "Plane does not have the capacity for that many passengers...\n"
			<< "Enter the number of passengers: ";
		cin >> pass;
	}
	cin.ignore();
	cout << "Enter the current status of flight: ";
	getline(cin, stat);
	Flight tmp(planeID, pilotID, copilotID, c1, c2, c3, SD, ED, ST, ET, SC, EC, pass, stat);
	Flight_List[key] = tmp;
}
void Flights::deleteFlight(string key)
{
	if (key != "ERROR")
	{
		map <string, Flight>::iterator it;
		it = Flight_List.find(key);
		Flight_List.erase(it);
		cout << "Flight# \"" << key << "\" has been deleted...\n";
	}
	else
	{
		cout << key << " FLIGHT NOT FOUND..." << endl;
	}
}
void Flights::editFlight(string key)
{
	printFlight(key);
	cout << "Re-enter the following information including any changes: \n";
	deleteFlight(key);
}
string Flights::findFlight()
{
	string id;
	string key;
	cout << "Enter flight ID: ";
	cin.ignore();
	getline(cin, id);
	map <string, Flight>::iterator it = Flight_List.find(id);
	if (it != Flight_List.end())
	{
		key = it->first;
		return key;
	}
	else
	{
		return("ERROR");
	}
}
void Flights::printFlight(string key)
{
	if (key != "ERROR")
	{
		Flight_List[key].Print();
		cout << "Press enter to continue...\n";
		cin.ignore();
	}
	else
	{
		cout << key << " CREW MEMBER NOT FOUND..." << endl;
	}
}
void Flights::printFlights()
{
	string i;
	for (map <string, Flight>::iterator it = Flight_List.begin(); it != Flight_List.end(); it++)
	{
		cout << "ID: " << it->first << endl;
		it->second.Print();
		cout << endl;
	}
	cout << "Press enter to continue...\n";
	getline(cin, i);
	cin.ignore();
}
void Flights::load()
{
	string key;
	string planeID;
	string pilotID;
	string copilotID;
	string cw1;
	string cw2;
	string cw3;
	string sd;
	string ed;
	int st;
	int et;
	string sc;
	string ec;
	int Pass;
	string status;
	map <string, Flight>::iterator it;
	ifstream myFile;
	myFile.open("Flights.txt");
	if (myFile.is_open())
	{
		while (!myFile.eof())
		{
			myFile >> key
				>> planeID
				>> pilotID
				>> copilotID
				>> cw1
				>> cw2
				>> cw3
				>> sd
				>> ed
				>> st
				>> et
				>> sc
				>> ec
				>> Pass
				>> status;
			Flight tmp(planeID, pilotID, copilotID, cw1, cw2, cw3, sd, ed, st, et, sc, ec, Pass, status);
			Flight_List[key] = tmp;
		}
	}
	else
	{
		cout << "Flight List was not found..." << endl;
	}
}
void Flights::store()
{
	map <string, Flight>::iterator it;
	ofstream myFile;
	myFile.open("Flights.txt");
	for (it = Flight_List.begin(); it != Flight_List.end(); it++)
	{
		myFile << it->first << endl
			<< it->second.getPlaneID() << endl
			<< it->second.getPilotID() << endl
			<< it->second.getCoPilotID() << endl
			<< it->second.getCrew1() << endl
			<< it->second.getCrew2() << endl
			<< it->second.getCrew3() << endl
			<< it->second.getSdate() << endl
			<< it->second.getEdate() << endl
			<< it->second.getStime() << endl
			<< it->second.getEtime() << endl
			<< it->second.getScode() << endl
			<< it->second.getEcode() << endl
			<< it->second.getPass() << endl
			<< it->second.getStatus() << endl;
	}
}
