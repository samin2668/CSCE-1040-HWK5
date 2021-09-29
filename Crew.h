#include <string>
#include <iostream>
using namespace std;
class Crew
{
	private:
		string Name;
		string Types;
		string Status;
	public:
		Crew();
		Crew(string nm, string tp, string stat);
		~Crew();

		void setName(string nm);
		void setType(string tp);
		void setStatus(string stat);
		string getName();
		string getType();
		string getStatus();
		void Print();
};

