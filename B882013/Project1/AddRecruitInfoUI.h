#pragma once
#include <iostream>
#include <string>
#include "AddRecruitInfo.h"

using namespace std;

class AddRecruitInfo;

class AddRecruitInfoUI 
{
	private:
		AddRecruitInfo* addRecruitInfo;

	public:
		AddRecruitInfoUI();

		void setAddRecruitInfo(AddRecruitInfo& addRecruitInfo);

		void startInterface();

		//���� : (����, �ο���, ��û������)
		void createNewRecruitInfo(string& work, int numPeople, string& deadline);
};