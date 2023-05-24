#include "RecruitInfoSystem.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

using namespace std;
 

/*
 ApplyUI::selectentrepreneur(Apply* apply)
 사용되는 곳: 채용 지원
 작성자: 임준혁
 */
void ApplyUI::selectentrepreneur(Apply* apply)
{
    apply->showapplyrcruit();
}


/*
 Apply::Apply()  // 생성자
 사용되는 곳: 채용지원
 작성자: 임준혁
 */
Apply::Apply()
{
        ApplyUI* applyUI = new ApplyUI;
        applyUI->selectentrepreneur(this); // this는 무엇일까? cpp에서 받아오나보다
}

/*
 Apply::showapplyrecruit()
 사용되는 곳: 채용지원
 작성자: 임준혁
 */
void Apply::showapplyrecruit()
{
    (뭐라고 써야하나)->listRecruitInfo();
}


/*
 ResearchRecruitInfoUI::selectCompany(ResearchRecruitInfo* researchrecruitinfo)
 사용되는 곳: 채용 정보 검색
 작성자: 임준혁
 */
void ResearchRecruitInfoUI::selectCompany(ResearchRecruitInfo* researchrecruitinfo)
{
    researchrecruitinfo->showRecruitInfo();
}

/*
 ResearchRecruitInfo::ResearchRecruitInfo()  // 생성자
 사용되는 곳: 채용 정보 검색
 작성자: 임준혁
 */
ResearchRecruitInfo::ResearchRecruitInfo()
{
        ResearchRecruitInfoUI* researchrecruitInfoUI = new ResearchRecruitInfoUI;
        researchrecruitInfoUI->selectCompany(this); //새로 만든 저 인스턴스(?)라는 애에서 selectCompany갖고 뭐하나봐..
}

/*
 Apply::showapplyrecruit()
 사용되는 곳: 채용지원
 작성자: 임준혁
 */
void Apply::showRecruitInfo()
{
    (뭐라고 써야하나)->getRecruitInfo();
}


//공통 Entity부분
<Entity : RecruitInfo 부분>
/*
 RecruitInfo::getRecruitInfo()
 사용되는 곳: 채용 정보 검색, 채용 지원
 작성자: 임준혁
 */
void RecruitInfo::getRecruitInfoDetail() // 정보들 5개 받아와서 출력하기
{
    // 출력 양식
    outputFile << getCompanyName() << " " << getEntrepreneurNumber() << “ ” < getWork() << " " << getNumPeople() << " " << getDeadline() << endl;
}


/*
 RecruitInfo::getCompanyName()
 사용되는 곳: 채용 정보 검색, 채용 지원
 작성자: 임준혁
 */
string RecruitInfo::getCompanyName() // 회사이름 받아오기
{
    return this->companyName;
}


/*
 RecruitInfo::getWork()
 사용되는 곳: 채용 정보 검색, 채용 지원
 작성자: 임준혁
 */
string RecruitInfo::getWork() // 업무 받아오기
{
    return this->work;
}


/*
 RecruitInfo::getNumPeople()
 사용되는 곳: 채용 정보 검색, 채용 지원
 작성자: 임준혁
 */
int RecruitInfo::getNumPeople() // 인원수 받아오기
{
    return this->numPeople;
}


/*
 RecruitInfo::getDeadline()
 사용되는 곳: 채용 지원 검색, 채용 지원
 작성자: 임준혁
 */
string RecruitInfo::getDeadline() // 마감일 받아오기
{
    return this->deadline;
}


/*
 RecruitInfo::getEntrepreneurNumber()
 사용되는 곳: 채용 정보 검색, 채용 지원
 작성자: 
 */
string RecruitInfo::getEntrepreneurNumber() // 사업자번호 받아오기
{
    return this->entrepreneurNumber;
