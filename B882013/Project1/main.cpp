#include "AddRecruitInfo.h"
#include "CheckRecruitInfo.h"
#include "RecruitInfoStatistic.h"

int main() {

    /* 채용정보 등록 테스트*/
    // Company 객체 생성
    Company company;

    // AddRecruitInfoUI 객체 생성
    AddRecruitInfoUI a_ui;

    // AddRecruitInfo 객체 생성
    AddRecruitInfo addRecruitInfo(a_ui, company);

    // AddRecruitInfoUI와 AddRecruitInfo 연결
    a_ui.setAddRecruitInfo(addRecruitInfo);

    // AddRecruitInfo의 startInterface() 호출
    addRecruitInfo.startInterface();
    addRecruitInfo.startInterface();
    

    /*채용정보 조회 테스트*/
    CheckRecruitInfoUI c_ui;
    CheckRecruitInfo checkRecruitInfo(c_ui, company);
    c_ui.setCheckRecruitInfo(checkRecruitInfo);
    checkRecruitInfo.startInterface();
    

    /*지원정보 통계 테스트*/
    RecruitInfoStatisticUI r_ui;
    RecruitInfoStatistic recruitInfoStatistic(r_ui, company);
    r_ui.setRecruitInfoStatistic(recruitInfoStatistic);
    recruitInfoStatistic.startInterface();
    

	return 0;
}