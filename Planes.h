#include "Plane.h"
#include <map>
#include <algorithm>
using namespace std;
class Planes
{
	private:
		map <string, Plane> Plane_List;
	public:
		Planes();
		~Planes();
		void addPlane();
		void deletePlane(string key);
		void editPlane(string key);
		string findPlane();
		void printPlane(string key);
		void printPlanes();
		void AddToFlight(string& id,  int& num);
		void store();
		void load();
};

