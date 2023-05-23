#pragma once
#include <iostream>
#include "AddRecruitInfoUI.h"
#include "Company.h"

using namespace std;

class AddRecruitInfoUI;
class Company;

class AddRecruitInfo
{
	private:
		AddRecruitInfoUI& ui;
		Company& company;

	public:
		AddRecruitInfo(AddRecruitInfoUI& ui, Company& comp);
		void startInterface();
		void addNewRecruitInfo(string& work, int numPeople, string& deadline);
};
