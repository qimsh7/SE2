#ifndef RECRUIT_INFO_H
#define RECRUIT_INFO_H

#include <string>
#include <vector>
#include <iostream>

class RecruitInfo {
public:
    std::string companyName;
    int entrepreneurNumber;
    std::string work;
    int numPeople;
    std::string deadline;

    RecruitInfo(const std::string& name, int number, const std::string& job, int people, const std::string& dueDate);

    static void searchByCompanyName(const std::vector<RecruitInfo>& recruitInfos, const std::string& searchName);
    static void searchByEntrepreneurNumber(const std::vector<RecruitInfo>& recruitInfos, int searchNumber);
};

#endif // RECRUIT_INFO_H#pragma once
