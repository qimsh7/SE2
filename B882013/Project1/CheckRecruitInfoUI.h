#pragma once
#include <iostream>
#include <string>
#include "CheckRecruitInfo.h"

using namespace std;

class CheckRecruitInfo;

class CheckRecruitInfoUI
{
	private:
		CheckRecruitInfo* checkRecruitInfo;

	public:
		CheckRecruitInfoUI();

		void setCheckRecruitInfo(CheckRecruitInfo& checkRecruitInfo);

		void startInterface();

		void selectCheck() const;
};