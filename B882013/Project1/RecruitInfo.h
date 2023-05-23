#pragma once
#include <string>

using namespace std;

class RecruitInfo {
	private:
		string work;
		int numPeople;
		string deadline;
		int numAppliers;
	
	public:
		RecruitInfo(string& work, int numPeople, string& deadline);

		//Getter
		string getWork() const;
		int getNumPeople() const;
		string getDeadline() const;
		int getNumAppliers() const;

		//Setter
		void setWork(string& work);
		void setNumPeople(int numPeople);
		void setDeadline(string& deadline);
		void setNumAppliers(int numPeople);

};