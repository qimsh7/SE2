#pragma once
#include "Company.h"
#include <unordered_map>
#include "RecruitInfoStatisticUI.h"

using namespace std;

class RecruitInfoStatisticUI;
class Company;

class RecruitInfoStatistic {
	private:
		RecruitInfoStatisticUI& ui;
		Company& company;

	public:
		RecruitInfoStatistic(RecruitInfoStatisticUI& ui,Company& company);
		void startInterface();
		unordered_map<string, int> showStatistic() const;
};