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

		//인자 : (업무, 인원수, 신청마감일)
		void createNewRecruitInfo(string& work, int numPeople, string& deadline);
};