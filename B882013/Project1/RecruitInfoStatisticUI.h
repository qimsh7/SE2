#pragma once
#include <iostream>
#include <string>
#include "RecruitInfoStatistic.h"

using namespace std;

class RecruitInfoStatistic;

class RecruitInfoStatisticUI
{
private:
	RecruitInfoStatistic* recruitInfoStatistic;

public:
	RecruitInfoStatisticUI();

	void setRecruitInfoStatistic(RecruitInfoStatistic recruitInfoStatistic);

	void startInterface();

	void selectStatistic() const;
};