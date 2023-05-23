#pragma once
#include <iostream>
#include "RecruitInfo.h"
#include <vector>

using namespace std;

class Company
{
	private:
		string companyName;
		vector<RecruitInfo*> recruitInfos;

	public:
		//디폴트 빈문자열
		Company(const string& name = "");
		~Company();
		void addNewRecruitInfo(string& work, int numPeople, string& deadline);
		vector<RecruitInfo*> getAllRecruitInfo() const;
};