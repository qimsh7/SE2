#include "AddRecruitInfo.h"

AddRecruitInfo::AddRecruitInfo(AddRecruitInfoUI& ui, Company& comp) : ui(ui), company(comp) {}

void AddRecruitInfo::startInterface() {
	ui.startInterface();
}

void AddRecruitInfo::addNewRecruitInfo(string& work, int numPeople, string& deadline) {
	company.addNewRecruitInfo(work, numPeople, deadline);
}