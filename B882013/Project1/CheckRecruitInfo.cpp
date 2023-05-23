#include "CheckRecruitInfo.h"
#include <iostream>
#include <vector>

using namespace std;

CheckRecruitInfo::CheckRecruitInfo(CheckRecruitInfoUI& ui, Company& comp) : ui(ui), company(comp) {}

void CheckRecruitInfo::startInterface() {
	ui.startInterface();
}

vector<RecruitInfo*> CheckRecruitInfo::showRecruitInfo() const {
	return company.getAllRecruitInfo();
}