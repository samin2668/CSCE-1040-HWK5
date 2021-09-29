#include "Functions.h"

Planes PL;
Crews CW;
Flights FL;

void myinfo()
{
	cout << "Samin Yasar" << endl << "saminyasar@my.unt.edu" << endl
		<< "CSCE 1040 Computer Science II Sec. 001" << endl
		<< "Homework 4 - Mean Grean Airlines" << endl << endl;
}
void addMenu()
{
	int i = -1;
	cout << "Select a collection from below to add an entity to\n";
	cout << "\n1.\tPLANE\n2.\tCREW MEMBER\n3.\tFLIGHT\n";
	cout << "\nENTER 0 TO GO BACK\n";
	cin >> i;
	switch (i)
	{
		case 0: cout << endl; mainMenu();	break;
		case 1:	PL.addPlane();	addMenu();	break;
		case 2:	CW.addCrew();	addMenu();	break;
		case 3:
		{
			string plID;
			string pID;
			string cpID;
			string c1;
			string c2;
			string c3;
			int ps;
			cin.ignore();
			PL.AddToFlight(plID, ps);
			CW.AddToFlight(pID, cpID, c1, c2, c3);
			FL.addFlight(plID, pID, cpID, c1, c2, c3, ps);	
			addMenu();	
			break; 
		}
		default:	cout << "INVALID CHOICE, ";	addMenu();	break;
	}


}
void editMenu()
{
	string temp;
	int i = -1;
	cout << "Select a collection from below to edit an entity from\n";
	cout << "\n1.\tPLANE\n2.\tCREW MEMBER\n3.\tFLIGHT\n";
	cout << "\nENTER 0 TO GO BACK\n";
	cin >> i;
	switch (i)
	{
		case 0: cout << endl; mainMenu();	break;
		case 1:	PL.editPlane(PL.findPlane());	editMenu();	break;
		case 2:	CW.editCrew(CW.findCrew());	editMenu();	break;
		case 3:	
		{
			FL.editFlight(FL.findFlight());
			string plID;
			string pID;
			string cpID;
			string c1;
			string c2;
			string c3;
			int ps;
			cin.ignore();
			PL.AddToFlight(plID, ps);
			CW.AddToFlight(pID, cpID, c1, c2, c3);
			FL.addFlight(plID, pID, cpID, c1, c2, c3, ps);
			editMenu();	
			break; }
		default:	cout << "INVALID CHOICE, ";	editMenu();	break;
	}
}
void deleteMenu()
{
	string temp;
	int i = -1;
	cout << "Select a collection from below to delete an entity from\n";
	cout << "\n1.\tPLANE\n2.\tCREW MEMBER\n3.\tFLIGHT\n";
	cout << "\nENTER 0 TO GO BACK\n";
	cin >> i;
	cout << endl;
	switch (i)
	{
		case 0: cout << endl; mainMenu();	break;
		case 1:	PL.deletePlane(PL.findPlane());	deleteMenu();	break;
		case 2:	CW.deleteCrew(CW.findCrew());	deleteMenu();	break;
		case 3:	FL.deleteFlight(FL.findFlight());	deleteMenu();	break;
		default:	cout << "INVALID CHOICE, ";	deleteMenu();	break;
	}
}
void printALL()
{
	string temp;
	int i = -1;
	cout << "Select a collection from below to print\n";
	cout << "\n1.\tPLANE\n2.\tCREW MEMBER\n3.\tFLIGHT\n";
	cout << "\nENTER 0 TO GO BACK\n";
	cin >> i;
	switch (i)
	{
		case 0: cout << endl; mainMenu();	break;
		case 1: cout << endl; PL.printPlanes();	 printALL();	break;
		case 2:	cout << endl; CW.printCrews();	 printALL();	break;
		case 3:	cout << endl; FL.printFlights();	printALL();	break;
		default:	cout << "INVALID CHOICE, ";	printALL();	break;
	}
}
void printSingle()
{
	string temp;
	int i = -1;
	cout << "Select a collection from below to print an entity from\n";
	cout << "\n1.\tPLANE\n2.\tCREW MEMBER\n3.\tFLIGHT\n";
	cout << "\nENTER 0 TO GO BACK\n";
	cin >> i;
	switch (i)
	{
		case 0: cout << endl; mainMenu();	break;
		case 1:	PL.printPlane(PL.findPlane());	printSingle();	break;
		case 2:	CW.printCrew(CW.findCrew());	printSingle();	break;
		case 3:	FL.printFlight(FL.findFlight());	printSingle();	break;
		default:	cout << "INVALID CHOICE, ";	printSingle();	break;
	}
}
void mainMenu()
{
	PL.load();
	CW.load();
	FL.load();
	cout << "Select an option below..." << endl;
	cout << "\n1.\tADD\n2.\tEDIT\n3.\tDELETE\n4.\tPRINT ENTIRE COLLECTION\n5.\tPRINT SINGLE ENTITY\n";
	cout << "\nENTER 0 TO QUIT..." << endl;
	int i = -1;
	cin >> i;
	switch (i)
	{
		case 0:	PL.store(); CW.store(); FL.store(); EXIT_SUCCESS;	break;
		case 1: cout << "ADD SELECTED\n" << endl; addMenu(); break;
		case 2: cout << "EDIT SELECTED\n" << endl; editMenu(); break;
		case 3:	cout << "DELETE SELECTED\n" << endl; deleteMenu(); break;
		case 4: cout << "PRINT ALL SELECTED\n" << endl; printALL();	break;
		case 5:	cout << "PRINT SINGLE SELECTED\n" << endl; printSingle();	break;
		default: cout << "INVALID CHOICE, ";	mainMenu();	break;
	} 
}