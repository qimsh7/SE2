#include "CheckRecruitInfoUI.h"
#include <iostream>
#include <vector>

using namespace std;

CheckRecruitInfoUI::CheckRecruitInfoUI() : checkRecruitInfo(nullptr) {}

void CheckRecruitInfoUI::setCheckRecruitInfo(CheckRecruitInfo& checkRecruitInfo) {
	this->checkRecruitInfo = &checkRecruitInfo;
}

void CheckRecruitInfoUI::startInterface() {
	selectCheck();
}

void CheckRecruitInfoUI::selectCheck() const {
	vector<RecruitInfo*> recruitInfos = checkRecruitInfo->showRecruitInfo();

	for (const auto& recruitInfo : recruitInfos) {
		cout << "> " << recruitInfo->getWork() << " " << recruitInfo->getNumPeople() << " " << recruitInfo->getDeadline() << endl;
	}
}