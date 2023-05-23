#include "RecruitInfoStatistic.h"

RecruitInfoStatistic::RecruitInfoStatistic(RecruitInfoStatisticUI& ui, Company& comp) : ui(ui), company(comp) {}

void RecruitInfoStatistic::startInterface() {
	ui.startInterface();
}

unordered_map<string, int> RecruitInfoStatistic::showStatistic() const {
	unordered_map<string, int> statistics;

	vector<RecruitInfo*> recruitInfos = company.getAllRecruitInfo();
	for (const auto& recruitInfo : recruitInfos) {
		const string& work = recruitInfo->getWork();
		int numAppliers = recruitInfo->getNumAppliers();
		statistics[work] += numAppliers;
	}
	return statistics;
}