#include "RecruitInfoSystem.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <sstream>

#define MAX_STRING 32

using namespace std;

/*
 전역변수
 */
Member curLoginMember = Member();
CompanyMember* curLoginCompanyMember = new CompanyMember;
NormalMember* curLoginNormalMember = new NormalMember;
vector <RecruitInfo*> recruitInfoList;

/*
doTask() 실행함수 구현
작성자 : 최은서, 남석현, 임준혁, 김상혁
*/

// 작성자: 최은서
void join(vector<Member>& members)
{
    AddMemberUI addmemberui;
    addmemberui.joinNewMember(members);
}

void login(vector<Member>& members, Member& curLoginMember)
{
    LoginUI loginui;
    loginui.login(members, curLoginMember);
}

void withdrawal(vector<Member>& members, Member& curLoginMember)
{
    WithdrawalUI withdrawalui;
    withdrawalui.requestWithdrawal(members, curLoginMember);
}

void logout(vector<Member>& members, Member& curLoginMember)
{
    LogoutUI logoutui;
    logoutui.requestLogout(members, curLoginMember);
}

// 작성자: 남석현
void addRecruitInfo()
{
    AddRecruitInfoUI addRecruitInfoui;

    AddRecruitInfo addRecruitInfo(addRecruitInfoui, curLoginCompanyMember);

    addRecruitInfoui.setAddRecruitInfo(addRecruitInfo);

    addRecruitInfo.startInterface();
}

void checkRecruitInfo()
{
    CheckRecruitInfoUI checkRecruitInfoui;
    CheckRecruitInfo checkRecruitInfo(checkRecruitInfoui, curLoginCompanyMember);
    checkRecruitInfoui.setCheckRecruitInfo(checkRecruitInfo);
    checkRecruitInfo.startInterface();
}

void recruitInfoStatistic()
{
    RecruitInfoStatisticUI recruitInfoStatisticui;
    RecruitInfoStatistic recruitInfoStatistic(recruitInfoStatisticui, curLoginCompanyMember);
    recruitInfoStatisticui.setRecruitInfoStatistic(recruitInfoStatistic);
    recruitInfoStatistic.startInterface();

}

// 작성자: 임준혁
void searchRecruitInfo()
{
    SearchRecruitInfoUI searchRecruitInfoui;
    SearchRecruitInfo searchRecruitInfo(searchRecruitInfoui, curLoginCompanyMember);
    searchRecruitInfoui.setSearchRecruitInfo(searchRecruitInfo);
    searchRecruitInfo.startInterface();
}

void doApply()
{
    DoApply* doApply = new DoApply;
}

// 작성자: 김상혁
void checkApplyInfo()
{
    CheckApplyInfo* checkApplyInfo = new CheckApplyInfo;
}

void cancelApply()
{
    CancelApply* cancelApply = new CancelApply;
}

void applyInfoStatistic()
{
    ApplyInfoStatistic* applyInfoStatistic = new ApplyInfoStatistic;
}




/*
회원가입
작성자 : 최은서
*/

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

        companyMember.setCategory(1);

        members.push_back(companyMember);

    }

    else if (memberCategory == 2)        // 일반회원 회원가입
    {
        inputFile >> name >> number >> ID >> PW;

        NormalMember normalMember(name, number);    // 생성자를 통해 name과 residentNumber 설정
        normalMember.ID = ID;
        normalMember.PW = PW;

        normalMember.setCategory(2);

        members.push_back(normalMember);

    }

    outputFile << "> " << memberCategory << " " << name << " " << number << " " << ID << " " << PW << endl;

}


/*
회원탈퇴
작성자 : 최은서
*/
void WithdrawalUI::requestWithdrawal(vector<Member>& members, Member& curLoginMember)
{
    Withdrawal withdrawal;
    withdrawal.withdrawal(members, curLoginMember);
}

void Withdrawal::withdrawal(vector<Member>& members, Member& curLoginMember)
{
    Member member;
    member.deleteMember(members, curLoginMember);
}

void Member::deleteMember(vector<Member>& members, Member& curLoginMember)
{
    for (auto it = members.begin(); it != members.end(); ++it)
    {
        if (it->getID() == curLoginMember.getID())
        {
            members.erase(it);
            break;
        }
    }

    outputFile << "> " << curLoginMember.getID() << endl;

}


/*
로그인
작성자 : 최은서
*/
void LoginUI::login(vector<Member>& members, Member& curLoginMember)
{
    Login login;
    login.getLoginInformation(members, curLoginMember);
}

void Login::getLoginInformation(vector<Member>& members, Member& curLoginMember)
{
    Member member;
    member.checkMember(members, curLoginMember);
}

void Member::checkMember(vector<Member>& members, Member& curLoginMember)
{
    string targetID;
    string targetPW;

    inputFile >> targetID >> targetPW;

    for (Member& member : members)
    {
        if (member.getID() == targetID && member.getPW() == targetPW)
        {
            curLoginMember = member;  // 현재 로그인 중인 멤버 업데이트
            if (member.category == 1)
            {
                curLoginCompanyMember = (CompanyMember*)&member;
            }
            else
            {
                curLoginNormalMember = (NormalMember*)&member;
            }
            outputFile << "> " << targetID << " " << targetPW << endl;

            return;
        }
    }
}


/*
로그아웃
작성자 : 최은서
*/
void LogoutUI::requestLogout(vector<Member>& members, Member& curLoginMember)
{
    Logout logout;
    logout.logout(members, curLoginMember);
}

void Logout::logout(vector<Member>& members, Member& curLoginMember)
{
    for (Member& member : members)
    {
        if (member.getID() == curLoginMember.getID())
        {
            outputFile << "> " << member.getID() << endl;
            curLoginMember = Member();  // 현재 로그인 중인 멤버를 기본생성자로 초기화
            curLoginCompanyMember = new CompanyMember;
            curLoginNormalMember = new NormalMember;
            break;
        }
    }
}




/*
채용정보
RecruitInfo : Entity Class
작성자 : 남석현
*/
RecruitInfo::RecruitInfo(string& work, int numPeople, string& deadline)
    : work(work), numPeople(numPeople), deadline(deadline), numAppliers(0) {}

// getter
string RecruitInfo::getWork() const
{
    return work;
}

int RecruitInfo::getNumPeople() const
{
    return numPeople;
}

string RecruitInfo::getDeadline() const
{
    return deadline;
}

int RecruitInfo::getNumAppliers() const
{
    return numAppliers;
}

//Setter
void RecruitInfo::setWork(string& work)
{
    this->work = work;
}

void RecruitInfo::setNumPeople(int numPeople)
{
    this->numPeople = numPeople;
}

void RecruitInfo::setDeadline(string& deadline)
{
    this->deadline = deadline;
}

void RecruitInfo::setNumAppliers(int numAppliers)
{
    this->numAppliers = numAppliers;
}

/*
회사
CompanyMember : Entity Class
작성자 : 남석현
*/

vector<RecruitInfo*> allRecruitInfos;

void CompanyMember::addNewRecruitInfo(string& work, int numPeople, string& deadline)
{
    RecruitInfo* newRecruitInfo = new RecruitInfo(work, numPeople, deadline);
    curLoginCompanyMember->recruitInfos.push_back(newRecruitInfo);
    allRecruitInfos.push_back(newRecruitInfo);
}

//생성된 모든 RecruitInfo 인스턴스 리턴
vector<RecruitInfo*> CompanyMember::getAllRecruitInfo() const
{
    return this->recruitInfos;
}

/*
지원정보 통계 sudo code
1. CompanyMember.getAllRecruitInfo()로 vector불러오기
2. for(recruitInfo : recruitinfos) 돌면서
3. recruitInfo->setNumAppliers(recruitInfo->getNumAppliers()+1)
*/

/*
채용정보등록
AddRecruitInfoUI : Boundary Class
작성자 : 남석현
*/
AddRecruitInfoUI::AddRecruitInfoUI() : addRecruitInfo(nullptr) {}

void AddRecruitInfoUI::setAddRecruitInfo(AddRecruitInfo& addRecruitInfo)
{
    this->addRecruitInfo = &addRecruitInfo;
}

void AddRecruitInfoUI::startInterface()
{
    string input;

    getline(inputFile, input);

    istringstream iss(input);
    string work;
    int numPeople;
    string deadline;

    iss >> work >> numPeople >> deadline;

    createNewRecruitInfo(work, numPeople, deadline);
}

void AddRecruitInfoUI::createNewRecruitInfo(string& work, int numPeople, string& deadline)
{
    addRecruitInfo->addNewRecruitInfo(work, numPeople, deadline);
}


/*
채용정보등록
AddRecruitInfo : Control Class
작성자 : 남석현
*/
AddRecruitInfo::AddRecruitInfo(AddRecruitInfoUI& ui, CompanyMember* comp) : ui(ui), companyMember() {}

void AddRecruitInfo::startInterface()
{
    ui.startInterface();
}

void AddRecruitInfo::addNewRecruitInfo(string& work, int numPeople, string& deadline)
{
    curLoginCompanyMember->addNewRecruitInfo(work, numPeople, deadline);
    
    outputFile << "> " << work << ' ' << numPeople << ' ' << deadline << endl;
}

/*
채용정보조회
CheckRecruitInfoUI : Boundary Class
작성자 : 남석현
*/
CheckRecruitInfoUI::CheckRecruitInfoUI() : checkRecruitInfo(nullptr) {}

void CheckRecruitInfoUI::setCheckRecruitInfo(CheckRecruitInfo& checkRecruitInfo)
{
    this->checkRecruitInfo = &checkRecruitInfo;
}

void CheckRecruitInfoUI::startInterface()
{
    selectCheck();
}

void CheckRecruitInfoUI::selectCheck() const
{
    vector<RecruitInfo*> recruitInfos = checkRecruitInfo->showRecruitInfo();

    for (const auto& recruitInfo : recruitInfos)
    {
        outputFile << "> " << recruitInfo->getWork() << " " << recruitInfo->getNumPeople() << " " << recruitInfo->getDeadline() << endl;
    }
}

/*
채용정보조회
CheckRecruitInfo : Control Class
작성자 : 남석현
*/
CheckRecruitInfo::CheckRecruitInfo(CheckRecruitInfoUI& ui, CompanyMember* comp) : ui(ui), companyMember() {}

void CheckRecruitInfo::startInterface()
{
    ui.startInterface();
}

vector<RecruitInfo*> CheckRecruitInfo::showRecruitInfo() const
{
    return curLoginCompanyMember->getAllRecruitInfo();
}

/*
지원정보통계
RecruitInfoStaticUI : Boundary Class
작성자 : 남석현
*/
RecruitInfoStatisticUI::RecruitInfoStatisticUI() : recruitInfoStatistic(nullptr) {}

void RecruitInfoStatisticUI::setRecruitInfoStatistic(RecruitInfoStatistic recruitInfoStatistic)
{
    this->recruitInfoStatistic = &recruitInfoStatistic;
}

void RecruitInfoStatisticUI::startInterface()
{
    selectStatistic();
}

void RecruitInfoStatisticUI::selectStatistic() const
{
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
RecruitInfoStatistic::RecruitInfoStatistic(RecruitInfoStatisticUI& ui, CompanyMember* comp) : ui(ui), companyMember() {}

void RecruitInfoStatistic::startInterface()
{
    ui.startInterface();
}

unordered_map<string, int> RecruitInfoStatistic::showStatistic() const
{
    unordered_map<string, int> statistics;

    vector<RecruitInfo*> recruitInfos = curLoginCompanyMember->getAllRecruitInfo();
    for (const auto& recruitInfo : recruitInfos) {
        const string& work = recruitInfo->getWork();
        int numAppliers = recruitInfo->getNumAppliers();
        statistics[work] += numAppliers;
    }
    return statistics;
}




/*
 SearchRecruitInfoUI : Boundary Class
 사용되는 곳: 채용 정보 검색
 작성자: 임준혁
 */
SearchRecruitInfoUI::SearchRecruitInfoUI() : searchRecruitInfo(nullptr) {}

void SearchRecruitInfoUI::setSearchRecruitInfo(SearchRecruitInfo& searchRecruitInfo)
{
    this->searchRecruitInfo = &searchRecruitInfo;
}

void SearchRecruitInfoUI::startInterface()
{
    string companyName;
    inputFile >> companyName;

    selectSearch(companyName);
}

void SearchRecruitInfoUI::selectSearch(string companyName) const
{
    vector<RecruitInfo*> recruitInfos = searchRecruitInfo->searchRecruitInfo(companyName);

    for (const auto& recruitInfo : recruitInfos)
    {
        outputFile << "> " << recruitInfo->getCompanyName() << " " << recruitInfo->getEntrepreneurNumber() << " " << recruitInfo->getWork() << " " << recruitInfo->getNumPeople() << " " << recruitInfo->getDeadline() << endl;
    }
}

/*
 SearchRecruitInfo : Control Class
 사용되는 곳: 채용 정보 검색
 작성자: 임준혁
 */
SearchRecruitInfo::SearchRecruitInfo(SearchRecruitInfoUI& ui, CompanyMember* comp) : ui(ui), companyMember() {}

void SearchRecruitInfo::startInterface()
{
    ui.startInterface();
}

vector<RecruitInfo*> SearchRecruitInfo::searchRecruitInfo(string companyName) const
{
    vector<RecruitInfo*> searchedRecruitInfos;

    //companyName과 일치하는 recruitInfos 찾기
    for (RecruitInfo* recruitInfo : allRecruitInfos)
    {
        if (recruitInfo->getCompanyName() == companyName)
        {
            searchedRecruitInfos.push_back(recruitInfo);
        }
    }
    return searchedRecruitInfos;
}


/*
 DoApplyUI::inputDoApplyData(CancelApply* cancelApply)
 작성자: 임준혁
 */
void DoApplyUI::inputDoApplyData(DoApply* doApply)
{
    string entrepreneurNumber;  // 사업자 번호
    // 입력 받음
    inputFile >> entrepreneurNumber;

    doApply->sendDoApplyData(entrepreneurNumber);
}


/*
 DoApply::DoApply()  // 생성자
 작성자: 임준혁
 */
DoApply::DoApply()
{
    DoApplyUI* doApplyUI = new DoApplyUI;
    doApplyUI->inputDoApplyData(this);
}


/*
 DoApply::sendDoApplyData(string entrepreneurNumber)
 작성자: 임준혁
 */
void DoApply::sendDoApplyData(string entrepreneurNumber)
{
    int j = -1;
    for (int i = 0 ; i < recruitInfoList.size() ; i++){
        if (recruitInfoList[i]->getEntrepreneurNumber() == entrepreneurNumber)
        {
            j = i;
            break;
        }
    }
    if (j != -1)
    {
        string companyName = recruitInfoList[j]->getCompanyName();
        string work = recruitInfoList[j]->getWork();
        int numPeople = recruitInfoList[j]->getNumPeople();
        string deadline = recruitInfoList[j]->getDeadline();
        
        // 여기 담아서 보냄 curLoginNormalMember->addApplyInfoList()
    }
    
}



/*
 NormalMember::getApplyInfo()
 작성자: 김상혁
 */
void NormalMember::getApplyInfo()
{
    // 현재 로그인한 NormalMember의 지원목록리스트
    vector <RecruitInfo*> applyInfoList = curLoginNormalMember->getApplyInfoList();

    // 출력을 위한 vector v
    vector <tuple<string, string, string, int, string>> v;

    // loop 돌면서 applyInfo마다 세부정보 불러오기
    for (int i = 0 ; i < applyInfoList.size() ; i++)
        v.push_back(applyInfoList[i]->getApplyInfoDetail());

    // v 오름차순 정렬
    sort(v.begin(), v.end());

    // loop 돌면서 지원정보 출력
    for (int i = 0 ; i < v.size() ; i++)
    {
        // 출력 양식
        outputFile << "> " << get<0>(v[i]) << ' ' << get<1>(v[i]) << ' ' << get<2>(v[i]) << ' ' << get<3>(v[i]) << ' ' << get<4>(v[i]) << endl;
    }
}


/*
 NormalMember::deleteApplyInfo(string entrepreneurNumber)
 작성자: 김상혁
 */
void NormalMember::deleteApplyInfo(string entrepreneurNumber)
{
    // 현재 로그인한 NormalMember의 지원목록리스트
    vector <RecruitInfo*> applyInfoList = curLoginNormalMember->getApplyInfoList();
    int j = -1;

    // loop 돌면서 (사업자 번호 == entreprenerNumber)인 RecruitInfo 발견, 인덱스 저장 및 break
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

    // 해당 RecruitInfo 삭제
    if (j != -1){
        applyInfoList.erase(applyInfoList.begin() + j);
        this->setApplyInfoList(applyInfoList);
    }
}


/*
 NormalMember::getApplyNumsPerWork()
 작성자: 김상혁
 */
void NormalMember::getApplyNumsPerWork()
{
    // 현재 로그인한 NormalMember의 지원목록리스트
    vector <RecruitInfo*> applyInfoList = curLoginNormalMember->getApplyInfoList();

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
    workListUnique.erase(unique(workListUnique.begin(), workListUnique.end()), workListUnique.end());

    // loop 돌면서 업무와 지원횟수 출력
    for (int i = 0 ; i < workListUnique.size() ; i++)
    {
        string targetWork = workListUnique[i];
        long cnt = count(workList.begin(), workList.end(), targetWork);

        // 출력 양식
        outputFile << "> " << targetWork << ' ' << cnt << endl;
    }
}


/*
 RecruitInfo::getApplyInfoDetail()
 작성자: 김상혁
 */
tuple<string, string,string, int, string> RecruitInfo::getApplyInfoDetail()
{
    return make_tuple(this->getCompanyName(), this->getEntrepreneurNumber(), this->getWork(), this->getNumPeople(), this->getDeadline());
}


/*
 CheckApplyInfoUI::checkApplyInfoButton(CheckApplyInfo* checkApplyInfo)
 작성자: 김상혁
 */
void CheckApplyInfoUI::checkApplyInfoButton(CheckApplyInfo* checkApplyInfo)
{
    checkApplyInfo->showApplyInfo();
}


/*
 CheckApplyInfo::CheckApplyInfo()  // 생성자
 작성자: 김상혁
 */
CheckApplyInfo::CheckApplyInfo()
{
        CheckApplyInfoUI* checkApplyInfoUI = new CheckApplyInfoUI;
        checkApplyInfoUI->checkApplyInfoButton(this);
}


/*
 CheckApplyInfo::showApplyInfo()
 작성자: 김상혁
 */
void CheckApplyInfo::showApplyInfo()
{
    // 현재 로그인한 NormalMember
    curLoginNormalMember->getApplyInfo();
}


/*
 CancelApplyUI::inputCancelApplyData(CancelApply* cancelApply)
 작성자: 김상혁
 */
void CancelApplyUI::inputCancelApplyData(CancelApply* cancelApply)
{
    string entrepreneurNumber;  // 사업자 번호
    // 입력 받음
    inputFile >> entrepreneurNumber;
    cin >> entrepreneurNumber;

    cancelApply->sendCancelApplyData(entrepreneurNumber);
}


/*
 CancelApply::CancelApply()  // 생성자
 작성자: 김상혁
 */
CancelApply::CancelApply()
{
        CancelApplyUI* cancelApplyUI = new CancelApplyUI;
        cancelApplyUI->inputCancelApplyData(this);
}


/*
 CancelApply::sendCancelApplyData(string entrepreneurNumber)
 작성자: 김상혁
 */
void CancelApply::sendCancelApplyData(string entrepreneurNumber)
{
    curLoginNormalMember->deleteApplyInfo(entrepreneurNumber);
}


/*
 ApplyInfoStatisticUI::applyInfoStatisticButton(ApplyInfoStatistic *applyInfoStatistic)
 작성자: 김상혁
 */
void ApplyInfoStatisticUI::applyInfoStatisticButton(ApplyInfoStatistic *applyInfoStatistic)
{
    applyInfoStatistic->showStatistic();
}


/*
 ApplyInfoStatistic::ApplyInfoStatistic()  // 생성자
 작성자: 김상혁
 */
ApplyInfoStatistic::ApplyInfoStatistic()
{
    ApplyInfoStatisticUI* applyInfoStatisticUI = new ApplyInfoStatisticUI;
    applyInfoStatisticUI->applyInfoStatisticButton(this);
}


/*
 ApplyInfoStatistic::showStatistic()
 작성자: 김상혁
 */
void ApplyInfoStatistic::showStatistic()
{
    curLoginNormalMember->getApplyNumsPerWork();
}


// doTask()
void doTask()
{
    vector<Member> members;
    
    if (inputFile.is_open())  //파일이 열려있는지 확인
    {
        while (!inputFile.eof())  //파일의 끝까지 읽는것을 반복
        {
            string str;

            while (1)
            {
                int menu1, menu2;
                
                // 파일에서 메뉴 숫자 2개 입력받기
                inputFile >> menu1 >> menu2;

                if (menu1 == 1 && menu2 == 1)
                {
                    outputFile << "1.1. 회원가입" << endl;
                    
                    join(members);
                    
                    outputFile << endl;
                }
                else if (menu1 == 1 && menu2 == 2)
                {
                    outputFile << "1.2. 회원탈퇴" << endl;

                    withdrawal(members, curLoginMember);
                    
                    outputFile << endl;
                }
                else if (menu1 == 2 && menu2 == 1)
                {
                    outputFile << "2.1. 로그인" << endl;
                    
                    login(members, curLoginMember);
                    
                    outputFile << endl;
                }
                else if (menu1 == 2 && menu2 == 2)
                {
                    outputFile << "2.2. 로그아웃" << endl;
                    
                    logout(members, curLoginMember);
                    
                    outputFile << endl;
                }
                else if (menu1 == 3 && menu2 == 1)
                {
                    outputFile << "3.1. 채용 정보 등록" << endl;

                    addRecruitInfo();

                    outputFile << endl;
                }
                else if (menu1 == 3 && menu2 == 2)
                {
                    outputFile << "3.2. 등록된 채용 정보 조회" << endl;

                    checkRecruitInfo();

                    outputFile << endl;
                }
                else if (menu1 == 4 && menu2 == 1)
                {
                    outputFile << "4.1. 채용 정보 검색" << endl;

                    searchRecruitInfo();

                    outputFile << endl;
                }
                else if (menu1 == 4 && menu2 == 2)
                {
                    outputFile << "4.2. 채용 지원" << endl;

                    doApply();

                    outputFile << endl;
                }
                else if (menu1 == 4 && menu2 == 3)
                {
                    outputFile << "4.3. 지원 정보 조회" << endl;

                    checkApplyInfo();

                    outputFile << endl;
                }
                else if (menu1 == 4 && menu2 == 4)
                {
                    outputFile << "4.4. 지원 취소" << endl;

                    cancelApply();

                    outputFile << endl;
                }
                else if (menu1 == 5 && menu2 == 1)
                {
                    outputFile << "5.1. 지원 정보 통계" << endl;

                    /*
                     두 기능 합칠 예정
                     */
                    if (curLoginMember.getCategory() == 1)
                    {
                        recruitInfoStatistic();
                    }
                    else
                    {
                        applyInfoStatistic();
                    }
    
                    outputFile << endl;
                }
                else if (menu1 == 6 && menu2 == 1)
                {
                    outputFile << "6.1. 종료" << endl;
                    return; //doTask 함수종료
                }
                else
                {
                    getline(inputFile, str);
                }
            }  // while문 종료
        }  // while문 종료
    }  // if문 종료
}  // doTask() 종료


// main 함수
int main()
{
    // 파일 열기: 헤더 파일에서 실행
    
    // doTask() 함수 호출
    doTask();

    // 파일 닫기
    inputFile.close();
    outputFile.close();

    return 0;
}  // main() 종료
