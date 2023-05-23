#pragma once
#include <iostream>
#include <vector>
#include "CheckRecruitInfoUI.h"
#include "Company.h"

using namespace std;

class CheckRecruitInfoUI;
class Company;

class CheckRecruitInfo
{
	private:
		CheckRecruitInfoUI& ui;
		Company& company;

	public:
		CheckRecruitInfo(CheckRecruitInfoUI& ui, Company& comp);
		void startInterface();
		vector<RecruitInfo*> showRecruitInfo() const;
};