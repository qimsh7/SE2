#include "AddRecruitInfo.h"
#include "CheckRecruitInfo.h"
#include "RecruitInfoStatistic.h"

int main() {

    /* ä������ ��� �׽�Ʈ*/
    // Company ��ü ����
    Company company;

    // AddRecruitInfoUI ��ü ����
    AddRecruitInfoUI a_ui;

    // AddRecruitInfo ��ü ����
    AddRecruitInfo addRecruitInfo(a_ui, company);

    // AddRecruitInfoUI�� AddRecruitInfo ����
    a_ui.setAddRecruitInfo(addRecruitInfo);

    // AddRecruitInfo�� startInterface() ȣ��
    addRecruitInfo.startInterface();
    addRecruitInfo.startInterface();
    

    /*ä������ ��ȸ �׽�Ʈ*/
    CheckRecruitInfoUI c_ui;
    CheckRecruitInfo checkRecruitInfo(c_ui, company);
    c_ui.setCheckRecruitInfo(checkRecruitInfo);
    checkRecruitInfo.startInterface();
    

    /*�������� ��� �׽�Ʈ*/
    RecruitInfoStatisticUI r_ui;
    RecruitInfoStatistic recruitInfoStatistic(r_ui, company);
    r_ui.setRecruitInfoStatistic(recruitInfoStatistic);
    recruitInfoStatistic.startInterface();
    

	return 0;
}