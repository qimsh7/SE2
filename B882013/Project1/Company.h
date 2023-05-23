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
		//����Ʈ ���ڿ�
		Company(const string& name = "");
		~Company();
		void addNewRecruitInfo(string& work, int numPeople, string& deadline);
		vector<RecruitInfo*> getAllRecruitInfo() const;
};