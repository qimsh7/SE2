#include "AddRecruitInfoUI.h"
#include "AddRecruitInfo.h"
#include <iostream>
#include<sstream>

using namespace std;

AddRecruitInfoUI::AddRecruitInfoUI() : addRecruitInfo(nullptr) {}

void AddRecruitInfoUI::setAddRecruitInfo(AddRecruitInfo& addRecruitInfo) {
	this->addRecruitInfo = &addRecruitInfo;
}

void AddRecruitInfoUI::startInterface() {
	string input;

	cout << ">";
	getline(cin, input);

	istringstream iss(input);
	string work;
	int numPeople;
	string deadline;

	iss >> work >> numPeople >> deadline;

	createNewRecruitInfo(work, numPeople, deadline);
}

void AddRecruitInfoUI::createNewRecruitInfo(string& work, int numPeople, string& deadline) {
	addRecruitInfo->addNewRecruitInfo(work, numPeople, deadline);
}