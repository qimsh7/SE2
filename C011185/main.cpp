#include <iostream>
#include <string>
#include <vector>
#include "recruit_info.h"

int main() {
    std::vector<RecruitInfo> recruitInfos = {
        RecruitInfo("삼성", 12, "회계", 2, "2023/05/26"),
        RecruitInfo("대우", 34, "영업", 3, "2023/05/26"),
        RecruitInfo("현대", 56, "판매", 4, "2023/05/26"),
        RecruitInfo("엘지", 78, "마케팅", 5, "2023/05/26"),
        RecruitInfo("네이버", 90, "제조", 6, "2023/05/26")
    };

    std::string input;
    std::getline(std::cin, input);

    size_t pos = input.find(' ');
    std::string menuStr = input.substr(0, pos);
    int menu_level_1 = std::stoi(menuStr);

    while (menu_level_1 != 0) {
        switch (menu_level_1) {
        case 4: {
            std::string restInput = input.substr(pos + 1);
            pos = restInput.find(' ');
            std::string menuStr2 = restInput.substr(0, pos);
            int menu_level_2 = std::stoi(menuStr2);

            switch (menu_level_2) {
            case 1: {
                std::string searchName = restInput.substr(pos + 1);
                RecruitInfo::searchByCompanyName(recruitInfos, searchName);
                break;
            }
            case 2: {
                std::string searchNumberStr = restInput.substr(pos + 1);
                int searchNumber = std::stoi(searchNumberStr);
                RecruitInfo::searchByEntrepreneurNumber(recruitInfos, searchNumber);
                break;
            }
            default:
                std::cout << "Invalid Menu Level 2" << std::endl;
                break;
            }
            break;
        }
        default:
            std::cout << "Invalid Menu Level 1" << std::endl;
            break;
        }

        std::getline(std::cin, input);

        pos = input.find(' ');
        menuStr = input.substr(0, pos);
        menu_level_1 = std::stoi(menuStr);
    }

    return 0;
}
