#include "recruit_info.h"

RecruitInfo::RecruitInfo(const std::string& name, int number, const std::string& job, int people, const std::string& dueDate)
    : companyName(name), entrepreneurNumber(number), work(job), numPeople(people), deadline(dueDate) {}

void RecruitInfo::searchByCompanyName(const std::vector<RecruitInfo>& recruitInfos, const std::string& searchName) {
    for (const auto& recruitInfo : recruitInfos) {
        if (recruitInfo.companyName == searchName) {
            std::cout << recruitInfo.companyName << " "
                << recruitInfo.entrepreneurNumber << " "
                << recruitInfo.work << " "
                << recruitInfo.numPeople << " "
                << recruitInfo.deadline << std::endl;
            return;
        }
    }

    std::cout << "해당 회사 정보를 찾을 수 없습니다." << std::endl;
}

void RecruitInfo::searchByEntrepreneurNumber(const std::vector<RecruitInfo>& recruitInfos, int searchNumber) {
    for (const auto& recruitInfo : recruitInfos) {
        if (recruitInfo.entrepreneurNumber == searchNumber) {
            std::cout << recruitInfo.companyName << " "
                << recruitInfo.entrepreneurNumber << " "
                << recruitInfo.work << std::endl;
            return;
        }
    }

    std::cout << "해당 회사 정보를 찾을 수 없습니다." << std::endl;
}
