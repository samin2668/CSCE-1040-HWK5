#include "Crews.h"
#include <fstream>

Crews::Crews()
{
}
Crews::~Crews()
{
}
void Crews::addCrew()
{
	string nm;
	string id;
	string tp = "none";
	string sts = "none";
	int choice;
	cin.ignore();
	cout << "Enter name: ";
	getline(cin, nm);
	cout << "Enter ID: ";
	getline(cin, id);
	cout << "Enter type: \n1.\tPilot\n2.\tCoPilot\n3.\tCabin\n";
	while (tp == "none")
	{
		cin >> choice;
		switch (choice)
		{
		case 1: {tp = "pilot";	break; }
		case 2: {tp = "copilot";	break; }
		case 3: {tp = "cabin";	break; }
		default: {cout << "Invalid choice" << endl;	break; }
		}
	}
	cout << "Enter status: \n1.\tAvailable\n2.\tOn Leave\n3.\tSick\n";
	cin >> choice;
	while (sts == "none")
	{
		switch (choice)
		{
		case 1: {sts = "available";	break; }
		case 2: {sts = "on leave";	break; }
		case 3: {sts = "sick";	break; }
		default: {cout << "Invalid choice" << endl;	break; }
		}
	}
	Crew tmp(nm, tp, sts);
	Crew_List[id] = tmp;
}
void Crews::deleteCrew(string key) 
{
	if (key != "ERROR")
	{
		map <string, Crew>::iterator it;
		it = Crew_List.find(key);
		Crew_List.erase(it);
		cout << "Crew \"" << key << "\" has been deleted...\n";
	}
	else
	{
		cout << key << " PLANE NOT FOUND..." << endl;
	}
}
void Crews::editCrew(string key)
{
	if (key != "ERROR")
	{
		string tmp;
		int dataType;
		Crew_List[key].Print();
		cout << "1.\tName\n2.\tID\n3.\tType\n4.\tStatus\n"
			<< "Select a data type you wish to change: ";
		cin >> dataType;
		cout << "Enter the new value: ";
		cin.ignore();
		switch (dataType)
		{
			case 1: {getline(cin, tmp);	Crew_List[key].setName(tmp);	break; }
			case 2:
			{
				getline(cin, tmp);
				Crew_List[tmp] = Crew_List[key];
				Crew_List.erase(key);
				break;
			}
			case 3: {getline(cin, tmp);	Crew_List[key].setType(tmp);	break; }
			case 4: {getline(cin, tmp);	Crew_List[key].setStatus(tmp);	break; }
		}
	}
	else
	{
		cout << key << " CREW NOT FOUND..." << endl;
	}
}
string Crews::findCrew() 
{
	string id;
	string key;
	cout << "Enter crew member's ID number: ";
	cin.ignore();
	getline(cin, id);
	map <string, Crew>::iterator it = Crew_List.find(id);
	if (it != Crew_List.end())
	{
		key = it->first;
		return key;
	}
	else
	{
		return("ERROR");
	}
}
void Crews::printCrew(string key)
{
	if(key != "ERROR")
	{
		Crew_List[key].Print();
		cout << "Press enter to continue...\n";
		cin.ignore(); 
	}
	else
	{
		cout << key << " CREW MEMBER NOT FOUND..." << endl;
	}
}
void Crews::printCrews() 
{
	string i;
	for (map <string, Crew>::iterator it = Crew_List.begin(); it != Crew_List.end(); it++)
	{
		cout << "ID: " << it->first << endl;
		it->second.Print();
		cout << endl;
	}
	cout << "Press enter to continue...\n";
	getline(cin, i);
	cin.ignore();
}
void Crews::AddToFlight(string& Pilot, string& CoPilot, string& crew1, string& crew2, string& crew3)
{
	string p;
	string cp;
	string c1;
	string c2;
	string c3;
	map<string, Crew>::iterator it;
	for(int i = 0; i < 1;)
	{
		for (it = Crew_List.begin(); it != Crew_List.end(); it++)
		{
			if (it->second.getType() == "pilot")
			{
				cout << "Pilot ID: " << it->first << "	Availability: " << it->second.getStatus() << endl;
			}
		}
		cout << "Enter ID of an available pilot from above: ";
		getline(cin, p);
		it = Crew_List.find(p);
		if ((it != Crew_List.end()) && (it->second.getType() == "pilot") && (it->second.getStatus() == "available"))
		{
			Pilot = p;
			i++;
		}
		else
		{
			cout << "Pilot is either unavailable, or does not exist please choose another" << endl;
		}
	}
	
	for (int i = 0; i < 1;)
	{
		for (it = Crew_List.begin(); it != Crew_List.end(); it++)
		{
			if (it->second.getType() == "copilot")
			{
				cout << "Crew ID: " << it->first << "	Availability: " << it->second.getStatus() << endl;
			}
		}
		cout << "Enter ID of an available copilot from above: ";
		getline(cin, p);
		it = Crew_List.find(p);
		if ((it != Crew_List.end()) && (it->second.getType() == "copilot") && (it->second.getStatus() == "available"))
		{
			CoPilot = p;
			i++;
		}
		else
		{
			cout << "CoPilot is either unavailable, or does not exist please choose another" << endl;
		}
	}

	for (int i = 0; i < 1;)
	{
		for (it = Crew_List.begin(); it != Crew_List.end(); it++)
		{
			if (it->second.getType() == "cabin")
			{
				cout << "Crew ID: " << it->first << "	Availability: " << it->second.getStatus() << endl;
			}
		}
		cout << "Enter ID of an available cabin member from above: ";
		getline(cin, p);

		it = Crew_List.find(p);
		if ((it != Crew_List.end()) && (it->second.getType() == "cabin") && (it->second.getStatus() == "available"))
		{
			crew1 = p;
			i++;
		}
		else
		{
			cout << "cabin member is either unavailable, or does not exist please choose another" << endl;
		}
	}

	for (int i = 0; i < 1;)
	{
		for (it = Crew_List.begin(); it != Crew_List.end(); it++)
		{
			if (it->second.getType() == "cabin")
			{
				cout << "Crew ID: " << it->first << "	Availability: " << it->second.getStatus() << endl;
			}
		}
		cout << "Enter ID of an available cabin member from above: ";
		getline(cin, p);
		it = Crew_List.find(p);
		if ((it != Crew_List.end()) && (it->second.getType() == "cabin") && (it->second.getStatus() == "available"))
		{
			crew2 = p;
			i++;
		}
		else
		{
			cout << "cabin member is either unavailable, or does not exist please choose another" << endl;
		}
	}

	for (int i = 0; i < 1;)
	{
		for (it = Crew_List.begin(); it != Crew_List.end(); it++)
		{
			if (it->second.getType() == "cabin")
			{
				cout << "Crew ID: " << it->first << "	Availability: " << it->second.getStatus() << endl;
			}
		}
		cout << "Enter ID of an available cabin member from above: ";
		getline(cin, p);
		it = Crew_List.find(p);
		if ((it != Crew_List.end()) && (it->second.getType() == "cabin") && (it->second.getStatus() == "available"))
		{
			crew3 = p;
			i++;
		}
		else
		{
			cout << "cabin member is either unavailable, or does not exist please choose another" << endl;
		}
	}



}

void Crews::store()
{
	map <string, Crew>::iterator it;
	ofstream myFile;
	myFile.open("Crews.txt");
	for (it = Crew_List.begin(); it != Crew_List.end(); it++)
	{
		myFile << it->first << endl
			<< it->second.getName() << endl
			<< it->second.getType() << endl
			<< it->second.getStatus() << endl;
	}
}
void Crews::load()
{
	string key;
	string name;
	string type;
	string status;
	map <string, Crew>::iterator it;
	ifstream myFile;
	myFile.open("Crews.txt");
	if (myFile.is_open())
	{
		while (!myFile.eof())
		{
			myFile >> key;
			myFile.ignore();
			getline(myFile, name);
			myFile >> type;
			myFile.ignore();
			getline(myFile, status);
			Crew tmp(name, type, status);
			Crew_List[key] = tmp;
		}
	}
	else
	{
		cout << "Crew List was not found..." << endl;
	}
}