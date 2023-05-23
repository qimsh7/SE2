#include "Company.h"
#include <iostream>
#include <vector>

using namespace std;

Company::Company(const string& name /* = "" */) : companyName(name) {}

Company::~Company() {
	for (RecruitInfo* info : recruitInfos) {
		delete info;
	}
}

void Company::addNewRecruitInfo(string& work, int numPeople, string& deadline) {
	RecruitInfo* newRecruitInfo = new RecruitInfo(work, numPeople, deadline);
	recruitInfos.push_back(newRecruitInfo);
}

//������ ��� RecruitInfo �ν��Ͻ� ����
vector<RecruitInfo*> Company::getAllRecruitInfo() const {
	return recruitInfos;
}
