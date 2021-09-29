#include "Flight.h"

Flight::Flight()
{
}
Flight::Flight(string plID, string pID, string cID, string c1, string c2, string c3, string SD, string ED, int ST, int ET, string SC, string EC, int pass, string stat)
{
	PlaneID = plID;
	PilotID = pID;
	CoPilotID = cID;
	cwID1 = c1;
	cwID2 = c2;
	cwID3 = c3;
	sDate = SD;
	eDate = ED;
	sTime = ST;
	eTime = ET;
	sCode = SC;
	eCode = EC;
	NumberOfPassengers = pass;
	Status = stat;
}
Flight::~Flight()
{
}

void Flight::setPlaneID(string tmp)
{
	PlaneID = tmp;
}
void Flight::setPilotID(string tmp) 
{
	PilotID = tmp;
}
void Flight::setCoPilotID(string tmp)
{
	CoPilotID = tmp;
}
void Flight::setCrew1(string tmp)
{
	cwID1 = tmp;
}
void Flight::setCrew2(string tmp)
{
	cwID2 = tmp;
}
void Flight::setCrew3(string tmp)
{
	cwID3 = tmp;
}
void Flight::setSdate(string tmp)
{
	sDate = tmp;
}
void Flight::setEdate(string tmp)
{
	eDate = tmp;
}
void Flight::setStime(int num)
{
	sTime = num;
}
void Flight::setEtime(int num)
{
	eTime = num;
}
void Flight::setScode(string tmp)
{
	sCode = tmp;
}
void Flight::setEcode(string tmp)
{
	eCode = tmp;
}
void Flight::setPass(int num) 
{ 
	NumberOfPassengers = num; 
}
void Flight::setStatus(string tmp) 
{ 
	Status = tmp; 

}

string Flight::getPlaneID()
{
	return PlaneID;
}
string Flight::getCoPilotID()
{
	return CoPilotID;
}
string Flight::getPilotID()
{
	return PilotID;
}
string Flight::getCrew1()
{
	return cwID1;
}
string Flight::getCrew2()
{
	return cwID2;
}
string Flight::getCrew3()
{
	return cwID3;
}
string Flight::getSdate()
{
	return sDate;
}
string Flight::getEdate()
{
	return eDate;
}
int Flight::getStime()
{
	return sTime;
}
int Flight::getEtime()
{
	return eTime;
}
string Flight::getScode()
{
	return sCode;
}
string Flight::getEcode()
{
	return eCode;
}
int Flight::getPass()
{
	return NumberOfPassengers;
}
string Flight::getStatus() 
{
	return Status;
}
void Flight::Print()
{
	cout << "Plane ID: " << PlaneID << endl
		<< "CoPilot ID: " << CoPilotID << endl
		<< "Cabin members: " << cwID1 << endl
		<< "               " << cwID2 << endl
		<< "               " << cwID3 << endl
		<< "Start date and time: " << sDate << " " << sTime << endl
		<< "End date and time: " << eDate << " " << eTime << endl
		<< "To " << eCode << " From " << sCode << endl
		<< "Number of Passengers: " << NumberOfPassengers << endl
		<< "Current Status: " << Status << endl;
}