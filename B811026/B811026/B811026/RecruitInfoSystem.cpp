#include "RecruitInfoSystem.h"
#include <iostream>
#include <vector>
using namespace std;




// 현재 로그인 한 applicant
Applicant* curLoginApplicant;




/*
 사용되는 곳: 지원정보조회, 지원삭제, 지원정보통계
 작성자: 김상혁
 */
vector <ApplyInfo*> Applicant::getApplyInfoList()
{
    return this->applyInfoList;
}


/*
 사용되는 곳: 지원정보조회
 작성자: 김상혁
 */
void Applicant::getApplyInfo()
{
    // 현재 로그인한 applicant의 지원목록리스트
    vector <ApplyInfo*> applyInfoList = curLoginApplicant->getApplyInfoList();
    
    //applyInfoList 회사명 기준 오름차순으로 한번 정렬해줘야함
    
    for (int i = 0 ; i < applyInfoList.size(); i++)
        applyInfoList[i]->getApplyInfoDetail();
}


/*
 사용되는 곳: 지원삭제
 작성자: 김상혁
 */
void Applicant::deleteApplyInfo(string entrepreneurNumber)
{
    // 현재 로그인한 applicant의 지원목록리스트
    vector <ApplyInfo*> applyInfoList = curLoginApplicant->getApplyInfoList();
    int j = -1;
    
    
    // loop 돌면서 (사업자 번호 == entreprenerNumber)인 applyInfo 발견, 인덱스 저장 및 break
    for (int i = 0 ; i < applyInfoList.size(); i++)
    {
        if (applyInfoList[i]->getEntrepreneurNumber() == entrepreneurNumber)
        {
            j = i;
            break;
        }
    }
    
    // 출력 양식
    cout << applyInfoList[j]->getCompanyName() << ' ' << applyInfoList[j]->getEntrepreneurNumber() << ' ' << applyInfoList[j]->getWork() << endl;
    
    // 해당 applyInfo 삭제
    if (j != -1)
        applyInfoList.erase(applyInfoList.begin() + j);
}


/*
 사용되는 곳: 지원정보통계
 작성자: 김상혁
 */
void Applicant::getApplyNumsPerWork()
{
    // 현재 로그인한 applicant의 지원목록리스트
    vector <ApplyInfo*> applyInfoList = curLoginApplicant->getApplyInfoList();
    
    // 업무별로 지원횟수 출력해야함
    // 업무들을 뽑아서 리스트를 만든다?
    
}




/*
 사용되는 곳: 지원정보조회
 작성자: 김상혁
 */
void ApplyInfo::getApplyInfoDetail()
{
    // 출력 양식
    cout << getCompanyName() << " " << getWork() << " " << getNumPeople() << " " << getDeadline() << endl;
}


/*
 사용되는 곳: 지원삭제
 작성자: 김상혁
 */
string ApplyInfo::getEntrepreneurNumber()
{
    return this->entrepreneurNumber;
}




/*
 사용되는 곳: 지원정보조회
 작성자: 김상혁
 */
void CheckApplyInfoUI::checkApplyInfoButton(CheckApplyInfo* checkApplyInfo)
{
    checkApplyInfo->showApplyInfo();
}


/*
 사용되는 곳: 지원정보조회
 작성자: 김상혁
 */
CheckApplyInfo::CheckApplyInfo()  // 생성자
{
        CheckApplyInfoUI* checkApplyInfoUI = new CheckApplyInfoUI;
        checkApplyInfoUI->checkApplyInfoButton(this);
}


/*
 사용되는 곳: 지원정보조회
 작성자: 김상혁
 */
void CheckApplyInfo::showApplyInfo()
{
    // 현재 로그인한 applicant
    curLoginApplicant->getApplyInfo();
}




/*
 사용되는 곳: 지원삭제
 작성자: 김상혁
 */
void CancelApplyUI::inputCancelApplyData(CancelApply* cancelApply)
{
    string entrepreneurNumber;  // 사업자 번호
    // 입력 받음
    cin >> entrepreneurNumber;
    
    cancelApply->sendCancelApplyData(entrepreneurNumber);
}


/*
 사용되는 곳: 지원삭제
 작성자: 김상혁
 */
CancelApply::CancelApply()  // 생성자
{
        CancelApplyUI* cancelApplyUI = new CancelApplyUI;
        cancelApplyUI->inputCancelApplyData(this);
}


/*
 사용되는 곳: 지원삭제
 작성자: 김상혁
 */
void CancelApply::sendCancelApplyData(string entrepreneurNumber)
{
    curLoginApplicant->deleteApplyInfo(entrepreneurNumber);
}




/*
 사용되는 곳: 지원정보통계
 작성자: 김상혁
 */
void ApplyInfoStatisticUI::applyInfoStatisticButton(ApplyInfoStatistic *applyInfoStatistic)
{
    applyInfoStatistic->showStatistic();
}


/*
 사용되는 곳: 지원정보통계
 작성자: 김상혁
 */
ApplyInfoStatistic::ApplyInfoStatistic()  // 생성자
{
    ApplyInfoStatisticUI* applyInfoStatisticUI = new ApplyInfoStatisticUI;
    applyInfoStatisticUI->applyInfoStatisticButton(this);
}


/*
 사용되는 곳: 지원정보통계
 작성자: 김상혁
 */
void ApplyInfoStatistic::showStatistic()
{
    curLoginApplicant->getApplyNumsPerWork();
}
