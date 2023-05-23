#include "RecruitInfo.h"
#include <iostream>

using namespace std;

RecruitInfo::RecruitInfo(string& work, int numPeople, string& deadline)
    : work(work), numPeople(numPeople), deadline(deadline), numAppliers(0) {}

//Getter
string RecruitInfo::getWork() const {
    return work;
}

int RecruitInfo::getNumPeople() const {
    return numPeople;
}

string RecruitInfo::getDeadline() const {
    return deadline;
}

int RecruitInfo::getNumAppliers() const {
    return numAppliers;
}

//Setter
void RecruitInfo::setWork(string& work) {
    this->work = work;
}

void RecruitInfo::setNumPeople(int numPeople) {
    this->numPeople = numPeople;
}

void RecruitInfo::setDeadline(string& deadline) {
    this->deadline = deadline;
}

void RecruitInfo::setNumAppliers(int numAppliers) {
    this->numAppliers = numAppliers;
}