#ifndef RecruitInfoSystem_h
#define RecruitInfoSystem_h

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <tuple>
#include <unordered_map>

#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

using namespace std;


ifstream inputFile(INPUT_FILE_NAME);   // input.txt 를 읽기모드로 열기
ofstream outputFile(OUTPUT_FILE_NAME); // output.txt 를 쓰기모드로 열기


/*
 전방선언
 */
void doTask();
class ApplyInfo;
class RecruitInfo;
class Member;


class Client
{

};


/*
doTask() 실행함수 선언
작성자 : 최은서
*/
void join(vector<Member>& members);
void withdrawal(vector<Member>& members);
void login(vector<Member>& members);
void logout(vector<Member>& members);


/*
회원
Member : Entity Class
작성자 : 최은서
*/
class Member
{
private:
    string ID;
    string PW;
    int loggedIn;        // 1은 로그인, 0은 로그아웃 상태

public:
    void addNewMember(vector<Member>& members);
    void checkMember(vector<Member>& members);
    void deleteMember(vector<Member>& members);
    
    Member() : ID(""), PW(""), loggedIn(0) {}
    Member(string str1, string str2) : ID(str1), PW(str2) {}

    string getID() {
        return ID;
    }
    string getPW() {
        return PW;
    }
    void setLoggedIn(int value) {
        loggedIn = value;
    }

};


/*
일반회원
NormalMember : Entity Class
작성자 : 최은서, 김상혁
*/
class NormalMember : public Member    // 일반 회원
{
private:
    string name;            // 이름
    string residentNumber;    // 주민번호
    
    vector <ApplyInfo*> applyInfoList;  // 지원목록

public:
    NormalMember() : Member("", ""), name(""), residentNumber("") {}
    NormalMember(string str1, string str2) : name(str1), residentNumber(str2) {}

    void getApplyInfo();
    void deleteApplyInfo(string entrepreneurNumber);
    void getApplyNumsPerWork();
    
    void pushBackApplyInfoList(ApplyInfo* ai){
        applyInfoList.push_back(ai);
    }
    
    // getter
    vector <ApplyInfo*> getApplyInfoList();
    
    // setter
    void setApplyInfoList(vector<ApplyInfo*> v){
        this->applyInfoList = v;
    }
};


/*
회사회원
CompanyMember : Entity Class
작성자 : 최은서, 남석현
*/
class CompanyMember : public Member    // 회사 회원
{
private:
    string companyName;            // 회사 이름
    string entrepreneurNumber;    // 사업자번호
    vector<RecruitInfo*> recruitInfos;


public:
    CompanyMember() : Member("", ""), companyName(""), entrepreneurNumber("") {}
    CompanyMember(string str1, string str2) : companyName(str1), entrepreneurNumber(str2) {}
    //Getter
    string getCompanyName() const;
    string getEntrepreneurNumber() const;
    void addNewRecruitInfo(string& work, int numPeople, string& deadline);
    vector<RecruitInfo*> getAllRecruitInfo() const;
};



/*
회원가입
AddMember : Control Class
작성자 : 최은서
*/
class AddMember
{
public:
    void createNewMember(vector<Member>& members);
};

/*
회원가입
AddMemberUI : Boundary Class
작성자 : 최은서
*/
class AddMemberUI
{
public:
    void joinNewMember(vector<Member>& members);
};

/*
회원탈퇴
Withdrawal : Control Class
작성자 : 최은서
*/
class Withdrawal
{
public:
    void withdrawal(vector<Member>& members);
};

/*
회원탈퇴
WithdrawalUI : Boundary Class
작성자 : 최은서
*/
class WithdrawalUI
{
public:
    void requestWithdrawal(vector<Member>& members);
};

/*
로그인
Login : Control Class
작성자 : 최은서
*/
class Login
{
public:
    void getLoginInformation(vector<Member>& members);
};

/*
로그인
LoginUI : Boundary Class
작성자 : 최은서
*/
class LoginUI
{
public:
    void login(vector<Member>& members);
};

/*
로그아웃
Logout : Control Class
작성자 : 최은서
*/
class Logout
{
public:
    void logout(vector<Member>& members);
};

/*
로그아웃
LogoutUI : Boudary Class
작성자 : 최은서
*/
class LogoutUI
{
public:
    void requestLogout(vector<Member>& members);
};

/*
doTask() 실행함수 선언
작성자 : 남석현
*/
void addRecruitInfo();
void checkRecruitInfo();

/*
채용정보
RecruitInfo : Entity Class
작성자 : 남석현
*/
class RecruitInfo : public CompanyMember
{
private:
    string work;
    int numPeople;
    string deadline;
    int numAppliers;

public:
    RecruitInfo(string& work, int numPeople, string& deadline);

    //Getter
    string getWork() const;
    int getNumPeople() const;
    string getDeadline() const;
    int getNumAppliers() const;

    //Setter
    void setWork(string& work);
    void setNumPeople(int numPeople);
    void setDeadline(string& deadline);
    void setNumAppliers(int numPeople);

};


/*
채용정보등록
AddRecruitInfoUI : Boundary Class
작성자 : 남석현
*/
class AddRecruitInfo;  //전방선언

class AddRecruitInfoUI
{
private:
    AddRecruitInfo* addRecruitInfo;

public:
    AddRecruitInfoUI();

    void setAddRecruitInfo(AddRecruitInfo& addRecruitInfo);

    void startInterface();

    //인자 : (업무, 인원수, 신청마감일)
    void createNewRecruitInfo(string& work, int numPeople, string& deadline);
};

/*
채용정보등록
AddRecruitInfo : Control Class
작성자 : 남석현
*/
class AddRecruitInfoUI; //전방선언
class CompanyMember;

class AddRecruitInfo
{
private:
    AddRecruitInfoUI& ui;
    CompanyMember& companyMember;

public:
    AddRecruitInfo(AddRecruitInfoUI& ui, CompanyMember& comp);
    void startInterface();
    void addNewRecruitInfo(string& work, int numPeople, string& deadline);
};


/*
채용정보조회
CheckRecruitInfoUI : Boundary Class
작성자 : 남석현
*/
class CheckRecruitInfo;

class CheckRecruitInfoUI
{
private:
    CheckRecruitInfo* checkRecruitInfo;

public:
    CheckRecruitInfoUI();

    void setCheckRecruitInfo(CheckRecruitInfo& checkRecruitInfo);

    void startInterface();

    void selectCheck() const;
};

/*
채용정보조회
CheckRecruitInfo : Control Class
작성자 : 남석현
*/
class CheckRecruitInfoUI;
class CompanyMember;

class CheckRecruitInfo
{
private:
    CheckRecruitInfoUI& ui;
    CompanyMember& companyMember;

public:
    CheckRecruitInfo(CheckRecruitInfoUI& ui, CompanyMember& comp);
    void startInterface();
    vector<RecruitInfo*> showRecruitInfo() const;
};

/*
지원정보통계
RecruitInfoStaticUI : Boundary Class
작성자 : 남석현
*/
class RecruitInfoStatistic;

class RecruitInfoStatisticUI
{
private:
    RecruitInfoStatistic* recruitInfoStatistic;

public:
    RecruitInfoStatisticUI();

    void setRecruitInfoStatistic(RecruitInfoStatistic recruitInfoStatistic);

    void startInterface();

    void selectStatistic() const;
};

/*
지원정보통계
RecruitInfoStatic : Control Class
작성자 : 남석현
*/
class RecruitInfoStatisticUI;
class CompanyMember;

class RecruitInfoStatistic {
private:
    RecruitInfoStatisticUI& ui;
    CompanyMember& companyMember;

public:
    RecruitInfoStatistic(RecruitInfoStatisticUI& ui, CompanyMember& company);
    void startInterface();
    unordered_map<string, int> showStatistic() const;
};


/*
채용정보검색
ResearchRecruitInfoUI : Boundary Class
작성자 : 임준혁
*/
class SearchRecruitInfo;

class SearchRecruitInfoUI
{
private:
    SearchRecruitInfo* searchRecruitInfo;

public:
    SearchRecruitInfoUI();

    void setSearchRecruitInfo(SearchRecruitInfo& searchRecruitInfo);

    void startInterface();

    void selectSearch(string companyName) const;
};


/*
채용정보검색
ResearchRecruitInfo : Control Class
작성자 : 임준혁
*/
class SearchRecruitInfoUI;
class CompanyMember;

class SearchRecruitInfo
{
private:
    SearchRecruitInfoUI& ui;
    CompanyMember& companyMember;

public:
    SearchRecruitInfo(SearchRecruitInfoUI& ui, CompanyMember& companyMember);
    void startInterface();
    vector<RecruitInfo*> searchRecruitInfo(string compayName) const;

};



/*
채용 지원
DoApply : Control Class
작성자 : 임준혁, 김상혁
*/
class DoApply
{
private:
    
public :
	DoApply(); // 얘는 뭘까?
	void showapplyrecruit(string entrepreneurNumber); // 사업자번호주면 회사이름 사업자번호 업무보여주는 애
};


/*
doTask() 실행함수 선언
작성자 : 김상혁
*/
void checkApplyInfo();
void cancelApplyInfo();
void applyInfoStatistic();


/*
 ApplyInfo : Entity Classes
 작성자: 김상혁
 */
class ApplyInfo
{
private:
    string companyName;  // 회사이름
    string entrepreneurNumber;  // 사업자 번호
    string work;  // 업무
    int numPeople;  // 인원수
    string deadline;  // 신청 마감일
    
public:
    tuple<string, string, string, int, string> getApplyInfoDetail();
    
    // setter 
    void setCompanyName(string str){
        this->companyName = str;
    }
    void setEntrepreneurNumber(string str){
        this->entrepreneurNumber = str;
    }
    void setWork(string str){
        this->work = str;
    }
    void setNumPeople(int num){
        this->numPeople = num;
    }
    void setDeadline(string str){
        this->deadline = str;
    }
    
    // getter
    string getCompanyName(){
        return this->companyName;
    }
    string getEntrepreneurNumber(){
        return this->entrepreneurNumber;
    }
    string getWork(){
        return this->work;
    }
    int getNumPeople(){
        return this->numPeople;
    }
    string getDeadline(){
        return this->deadline;
    }
    
};


/*
 지원정보조회
 CheckApplyInfo : Control Class
 작성자: 김상혁
 */
class CheckApplyInfo
{
private:
    
public:
    CheckApplyInfo();
    void showApplyInfo();
};


/*
 지원정보조회
 CheckApplyInfoUI : Boundary Class
 작성자: 김상혁
 */
class CheckApplyInfoUI
{
private:
    
public:
    void checkApplyInfoButton(CheckApplyInfo* checkApplyInfo);
};


/*
 지원취소
 CancelApply : Control Class
 작성자: 김상혁
 */
class CancelApply
{
private:
    
public:
    CancelApply();
    void sendCancelApplyData(string entrepreneurNumber);
};


/*
 지원취소
 CancelApplyUI : Boundary Class
 작성자: 김상혁
 */
class CancelApplyUI
{
private:
    
public:
    void inputCancelApplyData(CancelApply* cancelApply);
};


/*
 지원정보통계
 ApplyInfoStatistic : Control Class
 작성자: 김상혁
 */
class ApplyInfoStatistic
{
private:
    
public:
    ApplyInfoStatistic();
    void showStatistic();
};


/*
 지원정보통계
 ApplyInfoStatisticUI : Boundary Class
 작성자: 김상혁
 */
class ApplyInfoStatisticUI
{
private:
    
public:
    void applyInfoStatisticButton(ApplyInfoStatistic* applyInfoStatistic);
};


#endif /* RecruitInfoSystem_h */
