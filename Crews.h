#include "Crew.h"
#include <map>
#include <algorithm>
class Crews
{
	private:
		map <string, Crew> Crew_List;
	public:
		Crews();
		~Crews();
		void addCrew();
		void deleteCrew(string key);
		void editCrew(string key);
		string findCrew();
		void printCrew(string key);
		void printCrews();
		void AddToFlight(string& Pilot, string& CoPilot, string& crew1, string& crew2, string& crew3);
		void store();
		void load();
};

