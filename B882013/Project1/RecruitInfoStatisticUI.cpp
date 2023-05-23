#include "RecruitInfoStatisticUI.h"

using namespace std;

RecruitInfoStatisticUI::RecruitInfoStatisticUI() : recruitInfoStatistic(nullptr) {}

void RecruitInfoStatisticUI::setRecruitInfoStatistic(RecruitInfoStatistic recruitInfoStatistic) {
	this->recruitInfoStatistic = &recruitInfoStatistic;
}

void RecruitInfoStatisticUI::startInterface() {
	selectStatistic();
}

void RecruitInfoStatisticUI::selectStatistic() const {
	unordered_map<string, int> statistics = recruitInfoStatistic->showStatistic();

	for (const auto& pair : statistics) {
		const string& work = pair.first;
		int numAppliers = pair.second;
		cout << "> " << work << " " << numAppliers << endl;
	}
}