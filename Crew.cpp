#include "Crew.h"

Crew::Crew()
{
}
Crew::Crew(string nm, string tp, string stat)
{
	Name = nm;
	Types = tp;
	Status = stat;
}
Crew::~Crew()
{
}
void Crew::setName(string nm)
{
	Name = nm;
}
void Crew::setType(string tp)
{
	Types = tp;
}
void Crew::setStatus(string stat)
{
	Status = stat;
}
string Crew::getName()
{
	return Name;
}
string Crew::getType()
{
	return Types;
}
string Crew::getStatus()
{
	return Status;
}
void Crew::Print()
{
	cout << "Name: " << Name << "\nType: " << Types << "\nStatus: " << Status << endl;
}


