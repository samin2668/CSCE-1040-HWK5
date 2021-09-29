#include "Flight.h"

class Flights
{
	private:
		map <string, Flight> Flight_List;
	public:
		Flights();
		~Flights();
		void addFlight(string plane, string pilot, string copilot, string crew1, string crew2, string crew3, int p);
		void deleteFlight(string key);
		void editFlight(string key);
		string findFlight();
		void printFlight(string key);
		void printFlights();
		void load();
		void store();
};

