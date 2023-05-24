#include "RecruitInfoSystem.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <tuple>

#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

using namespace std;

/*
doTask() 실행함수 선언
작성자 : 최은서
*/
void join()
{
	AddMemberUI addmemberui;
	addmemberui.joinNewMember(members);
}

void login()
{
	LoginUI loginui;
	loginui.login(members);
}

void withdrawal()
{
	WithdrawalUI withdrawalui;
	withdrawalui.requestWithdrawal(members);
}

void logout()
{
	LogoutUI logoutui;
	logoutui.requestLogout(members);
}

//기능: 회원가입
void AddMemberUI::joinNewMember(vector<Member>& members)
{
    AddMember addMember;
    addMember.createNewMember(members);
}

void AddMember::createNewMember(vector<Member>& members)
{
    Member member;
    member.addNewMember(members);
}

void Member::addNewMember(vector<Member>& members)
{
    string name, number, ID, PW;

    int memberCategory = 0;                //일반회원인지 회사회원인지 구분

    // 입력 형식 : 이름, 주민번호, ID, Password를 파일로부터 읽음
    inputFile >> memberCategory;

    if (memberCategory == 1)            // 회사회원 회원가입
    {
        inputFile >> name >> number >> ID >> PW;

        CompanyMember companyMember(name, number);    // 생성자를 통해 companyName과 entrepreneurNumber 설정
        companyMember.ID = ID;
        companyMember.PW = PW;
        companyMember.loggedIn = 0; // 로그아웃 상태로 초기화

        members.push_back(companyMember);

    }

    else if (memberCategory == 2)        // 일반회원 회원가입
    {
        inputFile >> name >> number >> ID >> PW;

        NormalMember normalMember(name, number);    // 생성자를 통해 name과 residentNumber 설정
        normalMember.ID = ID;
        normalMember.PW = PW;
        normalMember.loggedIn = 0; // 로그아웃 상태로 초기화

        members.push_back(normalMember);

    }

    outputFile << "1.1. 회원가입" << endl;
    outputFile << "> " << memberCategory << " " << name << " " << number << " " << ID << " " << PW << endl;

}


//기능 : 회원탈퇴
void WithdrawalUI::requestWithdrawal(vector<Member>& members)
{
    Withdrawal withdrawal;
    withdrawal.withdrawal(members);
}

void Withdrawal::withdrawal(vector<Member>& members)
{
    Member member;
    member.deleteMember(members);
}

void Member::deleteMember(vector<Member>& members)
{
    string targetID;
    inputFile >> targetID;

    for (auto it = members.begin(); it != members.end(); ++it)
    {
        if (it->getID() == targetID)
        {
            members.erase(it);
            break;
        }
    }

    outputFile << "1.2. 회원탈퇴" << endl;
    outputFile << "> " << targetID << endl;

}


//기능 : 로그인
void LoginUI::login(vector<Member>& members)
{
    Login login;
    login.getLoginInformation(members);
}

void Login::getLoginInformation(vector<Member>& members)
{
    Member member;
    member.checkMember(members);
}

void Member::checkMember(vector<Member>& members)
{
    string targetID;
    string targetPW;

    inputFile >> targetID >> targetPW;

    for (Member& member : members) {
        if (member.getID() == targetID && member.getPW() == targetPW) {
            // 로그인 성공
            member.setLoggedIn(1);

            outputFile << "2.1. 로그인" << endl;
            outputFile << "> " << targetID << " " << targetPW << endl;

            return;
        }
    }
    
}


//기능 : 로그아웃
void LogoutUI::requestLogout(vector<Member>& members)
{
    Logout logout;
    logout.logout(members);
}

void Logout::logout(vector<Member>& members)
{
    string targetID;

    for (Member& member : members) {
        if (member.getID() == targetID) {
            // 로그아웃 처리
            member.setLoggedIn(0);

            outputFile << "2.2. 로그아웃" << endl;
            outputFile << "> " << targetID << endl;
        }
    }
}


/*
doTask() 실행함수 구현
작성자 : 남석현
*/
void addRecruitInfo() {
    Company company;
    AddRecruitInfoUI addRecruitInfoui;

    AddRecruitInfo addRecruitInfo(addRecruitInfoui, company);

    a_ui.setAddRecruitInfo(addRecruitInfo);

    addRecruitInfo.startInterface();
}

void checkRecruitInfo() {
    CheckRecruitInfoUI checkRecruitInfoui;
    CheckRecruitInfo checkRecruitInfo(checkRecruitInfoui, company);
    c_ui.setCheckRecruitInfo(checkRecruitInfo);
    checkRecruitInfo.startInterface();
}

/*
채용정보
RecruitInfo : Entity Class
작성자 : 남석현
*/
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

/*
회사
Company : Entity Class
작성자 : 남석현
*/
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

//생성된 모든 RecruitInfo 인스턴스 리턴
vector<RecruitInfo*> Company::getAllRecruitInfo() const {
    return recruitInfos;
}

/*
지원정보 통계 sudo code
1. Company.getAllRecruitInfo()로 vector불러오기
2. for(recruitInfo : recruitinfos) 돌면서
3. recruitInfo->setNumAppliers(recruitInfo->getNumAppliers()+1)
*/

/*
채용정보등록
AddRecruitInfoUI : Boundary Class
작성자 : 남석현
*/
AddRecruitInfoUI::AddRecruitInfoUI() : addRecruitInfo(nullptr) {}

void AddRecruitInfoUI::setAddRecruitInfo(AddRecruitInfo& addRecruitInfo) {
    this->addRecruitInfo = &addRecruitInfo;
}

void AddRecruitInfoUI::startInterface() {
    string input;

    getline(inputFile, input);

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

/*
채용정보등록
AddRecruitInfo : Control Class
작성자 : 남석현
*/
AddRecruitInfo::AddRecruitInfo(AddRecruitInfoUI& ui, Company& comp) : ui(ui), company(comp) {}

void AddRecruitInfo::startInterface() {
    ui.startInterface();
}

void AddRecruitInfo::addNewRecruitInfo(string& work, int numPeople, string& deadline) {
    company.addNewRecruitInfo(work, numPeople, deadline);
}

/*
채용정보조회
CheckRecruitInfoUI : Boundary Class
작성자 : 남석현
*/
CheckRecruitInfoUI::CheckRecruitInfoUI() : checkRecruitInfo(nullptr) {}

void CheckRecruitInfoUI::setCheckRecruitInfo(CheckRecruitInfo& checkRecruitInfo) {
    this->checkRecruitInfo = &checkRecruitInfo;
}

void CheckRecruitInfoUI::startInterface() {
    selectCheck();
}

void CheckRecruitInfoUI::selectCheck() const {
    vector<RecruitInfo*> recruitInfos = checkRecruitInfo->showRecruitInfo();

    for (const auto& recruitInfo : recruitInfos) {
        outputFile << "> " << recruitInfo->getWork() << " " << recruitInfo->getNumPeople() << " " << recruitInfo->getDeadline() << endl;
    }
}

/*
채용정보조회
CheckRecruitInfo : Control Class
작성자 : 남석현
*/
CheckRecruitInfo::CheckRecruitInfo(CheckRecruitInfoUI& ui, Company& comp) : ui(ui), company(comp) {}

void CheckRecruitInfo::startInterface() {
    ui.startInterface();
}

vector<RecruitInfo*> CheckRecruitInfo::showRecruitInfo() const {
    return company.getAllRecruitInfo();
}

/*
지원정보통계
RecruitInfoStaticUI : Boundary Class
작성자 : 남석현
*/
RecruitInfoStatisticUI::RecruitInfoStatisticUI() : recruitInfoStatistic(nullptr) {}

void RecruitInfoStatisticUI::setRecruitInfoStatistic(RecruitInfoStatistic recruitInfoStatistic) {
    this->recruitInfoStatistic = &recruitInfoStatistic;
}

void RecruitInfoStatisticUI::startInterface() {
    selectStatistic();
}

void RecruitInfoStatisticUI::selectStatistic() const {
    unordered_map<string, int> statistics = recruitInfoStatistic->showStatistic();

    for (const auto& pair : statistics) {
        const string& work = pair.first;
        int numAppliers = pair.second;
        outputFile << "> " << work << " " << numAppliers << endl;
    }
}

/*
지원정보통계
RecruitInfoStatic : Control Class
작성자 : 남석현
*/
RecruitInfoStatistic::RecruitInfoStatistic(RecruitInfoStatisticUI& ui, Company& comp) : ui(ui), company(comp) {}

void RecruitInfoStatistic::startInterface() {
    ui.startInterface();
}

unordered_map<string, int> RecruitInfoStatistic::showStatistic() const {
    unordered_map<string, int> statistics;

    vector<RecruitInfo*> recruitInfos = company.getAllRecruitInfo();
    for (const auto& recruitInfo : recruitInfos) {
        const string& work = recruitInfo->getWork();
        int numAppliers = recruitInfo->getNumAppliers();
        statistics[work] += numAppliers;
    }
    return statistics;
}



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
    return companyName;
}


/*
 RecruitInfo::getWork()
 사용되는 곳: 채용 정보 검색, 채용 지원
 작성자: 임준혁
 */
string RecruitInfo::getWork() // 업무 받아오기
{
    return work;
}


/*
 RecruitInfo::getNumPeople()
 사용되는 곳: 채용 정보 검색, 채용 지원
 작성자: 임준혁
 */
int RecruitInfo::getNumPeople() // 인원수 받아오기
{
    return numPeople;
}


/*
 RecruitInfo::getDeadline()
 사용되는 곳: 채용 지원 검색, 채용 지원
 작성자: 임준혁
 */
string RecruitInfo::getDeadline() // 마감일 받아오기
{
    return deadline;
}


/*
 RecruitInfo::getEntrepreneurNumber()
 사용되는 곳: 채용 정보 검색, 채용 지원
 작성자: 임준혁
 */
string RecruitInfo::getEntrepreneurNumber() // 사업자번호 받아오기
{
    return entrepreneurNumber;
}




// 현재 로그인 한 applicant -> 수정예정
Applicant* curLoginApplicant;


/*
 Applicant::getApplyInfoList()
 사용되는 곳: 지원정보조회, 지원삭제, 지원정보통계
 작성자: 김상혁
 */
vector <ApplyInfo*> Applicant::getApplyInfoList()
{
    return this->applyInfoList;
}


/*
 Applicant::getApplyInfo()
 사용되는 곳: 지원정보조회
 작성자: 김상혁
 */
void Applicant::getApplyInfo()
{
    // 현재 로그인한 applicant의 지원목록리스트
    vector <ApplyInfo*> applyInfoList = curLoginApplicant->getApplyInfoList();
    
    // 출력을 위한 vector v
    vector <tuple <string, string, int, string, string> > v;
    
    // loop 돌면서 applyInfo마다 세부정보 불러오기
    for (int i = 0 ; i < applyInfoList.size() ; i++)
        v.push_back(applyInfoList[i]->getApplyInfoDetail());
    
    // v 오름차순 정렬
    sort(v.begin(), v.end());
    
    // 출력 양식
    outputFile << "4.3. 지원 정보 조회" << endl;
    
    // loop 돌면서 지원정보 출력
    for (int i = 0 ; i < v.size ; i++)
    {
        // 출력 양식
        outputFile << get<0>(v[i]) << ' ' << get<1>(v[i]) << ' ' << get<2>(v[i]) << ' ' << get<3>(v[i]) << endl;
    }
}


/*
 Applicant::deleteApplyInfo(string entrepreneurNumber)
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
    outputFile << "4.4. 지원 취소" << endl;
    outputFile  << "> "<< applyInfoList[j]->getCompanyName() << ' ' << applyInfoList[j]->getEntrepreneurNumber() << ' ' << applyInfoList[j]->getWork() << endl;
    
    // 해당 applyInfo 삭제
    if (j != -1)
        applyInfoList.erase(applyInfoList.begin() + j);
}


/*
 Applicant::getApplyNumsPerWork()
 사용되는 곳: 지원정보통계
 작성자: 김상혁
 */
void Applicant::getApplyNumsPerWork()
{
    // 현재 로그인한 applicant의 지원목록리스트
    vector <ApplyInfo*> applyInfoList = curLoginApplicant->getApplyInfoList();
    
    // 업무들을 모아놓은 리스트
    vector <string> workList;
    
    // 업무들을 모아놓은 리스트에서 중복 제거한 리스트
    vector <string> workListUnique;
    
    // loop 돌면서 업무들을 workList와 workListUnique에 push
    for (int i = 0 ; i < applyInfoList.size(); i++)
    {
        string work = applyInfoList[i]->getWork();
        workList.push_back(work);
        workListUnique.push_back(work);
    }
    
    // workListUnique에서 중복 제거
    sort(workListUnique.begin(), workListUnique.end());
    workListUnique.erase(unique(workListUnique.begin(), workListUnique.end(), workListUnique.end()));
    
    // 출력 양식
    outputFile << "5.1. 지원 정보 통계" << endl;
    
    // loop 돌면서 업무와 지원횟수 출력
    for (int i = 0 ; i < workListUnique.size() ; i++)
    {
        string targetWork = workListUnique[i];
        int cnt = count(workList.begin(), workList.end(), targetWork);
        
        // 출력 양식
        outputFile << "> " << targetWork << ' ' << cnt << endl;
    }
}


/*
 ApplyInfo::getApplyInfoDetail()
 사용되는 곳: 지원정보조회
 작성자: 김상혁
 */
tuple<string, string, int, string, string> ApplyInfo::getApplyInfoDetail()
{
    return make_tuple(getCompanyName(), getWork(), getNumPeople(), getDeadline(), getEntrepreneurNumber());
}


/*
 ApplyInfo::getCompanyName()
 사용되는 곳:
 작성자: 김상혁
 */
string ApplyInfo::getCompanyName()
{
    return this->companyName;
}


/*
 ApplyInfo::getWork()
 사용되는 곳:
 작성자: 김상혁
 */
string ApplyInfo::getWork()
{
    return this->work;
}


/*
 ApplyInfo::getNumPeople()
 사용되는 곳:
 작성자: 김상혁
 */
int ApplyInfo::getNumPeople()
{
    return this->numPeople;
}


/*
 ApplyInfo::getDeadline()
 사용되는 곳:
 작성자: 김상혁
 */
string ApplyInfo::getDeadline()
{
    return this->deadline;
}


/*
 ApplyInfo::getEntrepreneurNumber()
 사용되는 곳: 지원삭제
 작성자: 김상혁
 */
string ApplyInfo::getEntrepreneurNumber()
{
    return this->entrepreneurNumber;
}


/*
 CheckApplyInfoUI::checkApplyInfoButton(CheckApplyInfo* checkApplyInfo)
 사용되는 곳: 지원정보조회
 작성자: 김상혁
 */
void CheckApplyInfoUI::checkApplyInfoButton(CheckApplyInfo* checkApplyInfo)
{
    checkApplyInfo->showApplyInfo();
}


/*
 CheckApplyInfo::CheckApplyInfo()  // 생성자
 사용되는 곳: 지원정보조회
 작성자: 김상혁
 */
CheckApplyInfo::CheckApplyInfo()
{
        CheckApplyInfoUI* checkApplyInfoUI = new CheckApplyInfoUI;
        checkApplyInfoUI->checkApplyInfoButton(this);
}


/*
 CheckApplyInfo::showApplyInfo()
 사용되는 곳: 지원정보조회
 작성자: 김상혁
 */
void CheckApplyInfo::showApplyInfo()
{
    // 현재 로그인한 applicant
    curLoginApplicant->getApplyInfo();
}


/*
 CancelApplyUI::inputCancelApplyData(CancelApply* cancelApply)
 사용되는 곳: 지원삭제
 작성자: 김상혁
 */
void CancelApplyUI::inputCancelApplyData(CancelApply* cancelApply)
{
    string entrepreneurNumber;  // 사업자 번호
    // 입력 받음
    inputFile >> entrepreneurNumber;
    
    cancelApply->sendCancelApplyData(entrepreneurNumber);
}


/*
 CancelApply::CancelApply()  // 생성자
 사용되는 곳: 지원삭제
 작성자: 김상혁
 */
CancelApply::CancelApply()
{
        CancelApplyUI* cancelApplyUI = new CancelApplyUI;
        cancelApplyUI->inputCancelApplyData(this);
}


/*
 CancelApply::sendCancelApplyData(string entrepreneurNumber)
 사용되는 곳: 지원삭제
 작성자: 김상혁
 */
void CancelApply::sendCancelApplyData(string entrepreneurNumber)
{
    curLoginApplicant->deleteApplyInfo(entrepreneurNumber);
}


/*
 ApplyInfoStatisticUI::applyInfoStatisticButton(ApplyInfoStatistic *applyInfoStatistic)
 사용되는 곳: 지원정보통계
 작성자: 김상혁
 */
void ApplyInfoStatisticUI::applyInfoStatisticButton(ApplyInfoStatistic *applyInfoStatistic)
{
    applyInfoStatistic->showStatistic();
}


/*
 ApplyInfoStatistic::ApplyInfoStatistic()  // 생성자
 사용되는 곳: 지원정보통계
 작성자: 김상혁
 */
ApplyInfoStatistic::ApplyInfoStatistic()
{
    ApplyInfoStatisticUI* applyInfoStatisticUI = new ApplyInfoStatisticUI;
    applyInfoStatisticUI->applyInfoStatisticButton(this);
}


/*
 ApplyInfoStatistic::showStatistic()
 사용되는 곳: 지원정보통계
 작성자: 김상혁
 */
void ApplyInfoStatistic::showStatistic()
{
    curLoginApplicant->getApplyNumsPerWork();
}
