#include <string>
#include <map>
#include <iostream>

using namespace std;
class Flight
{
	private:
		string PlaneID;
		string PilotID;
		string CoPilotID;
		string cwID1;
		string cwID2;
		string cwID3;
		string sDate;
		string eDate;
		int sTime;
		int eTime;
		string sCode;
		string eCode;
		int NumberOfPassengers;
		string Status;
	public:
		Flight();
		Flight(string plID, string pID, string cID, string c1, string c2, string c3, string SD, string ED, int ST, int ET, string SC, string EC, int pass, string stat);
		~Flight();
		
		void setPlaneID(string tmp);
		void setPilotID(string tmp);
		void setCoPilotID(string tmp);
		void setCrew1(string tmp);
		void setCrew2(string tmp);
		void setCrew3(string tmp);
		void setSdate(string tmp);
		void setEdate(string tmp);
		void setStime(int num);
		void setEtime(int num);
		void setScode(string tmp);
		void setEcode(string tmp);
		void setPass(int num);
		void setStatus(string tmp);
		
		string getPlaneID();
		string getCoPilotID();
		string getPilotID();
		string getCrew1();
		string getCrew2();
		string getCrew3();
		string getSdate();
		string getEdate();
		int getStime();
		int getEtime();
		string getScode();
		string getEcode();
		int getPass();
		string getStatus();

		void Print();
};

