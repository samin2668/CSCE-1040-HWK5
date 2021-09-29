#include <string>
#include <iostream>
using namespace std;
class Plane
{
	private:
		string Make;
		string Model;
		int NumberOfSeats;
		string Range;
		string Status;
	public:
		Plane();
		Plane(string mk, string mdl, int seats, string rng, string stat);
		~Plane();

		void setMake(string mk);
		void setModel(string md);
		void setNumSeats(int numSeats);
		void setRange(string rng);
		void setStatus(string stat);

		string getMake();
		string getModel();
		int getNumSeats();
		string getRange();
		string getStatus();
		void print();
};

