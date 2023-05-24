#ifndef RecruitInfoSystem_h
#define RecruitInfoSystem_h

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

using namespace std;

ifstream inputFile(INPUT_FILE_NAME);   // input.txt 를 읽기모드로 열기
ofstream outputFile(OUTPUT_FILE_NAME); // output.txt 를 쓰기모드로 열기


void doTask();

class Client
{

};


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
작성자 : 최은서
*/
class NormalMember : public Member    // 일반 회원
{
private:
    string name;            // 이름
    string residentNumber;    // 주민번호

public:
    NormalMember() : Member("", ""), name(""), residentNumber("") {}
    NormalMember(string str1, string str2) : name(str1), residentNumber(str2) {}
};

/*
회사회원
CompanyMember : Entity Class
작성자 : 최은서
*/
class CompanyMember : public Member    // 회사 회원
{
private:
    string companyName;            // 회사 이름
    string entrepreneurNumber;    // 사업자번호

public:
    CompanyMember() : Member("", ""), companyName(""), entrepreneurNumber("") {}
    CompanyMember(string str1, string str2) : companyName(str1), entrepreneurNumber(str2) {}
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
class RecruitInfo {
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
회사
Company : Entity Class
작성자 : 남석현
*/
class Company
{
private:
    string companyName;
    vector<RecruitInfo*> recruitInfos;

public:
    Company(const string& name = "");
    ~Company();
    void addNewRecruitInfo(string& work, int numPeople, string& deadline);
    vector<RecruitInfo*> getAllRecruitInfo() const;
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
class Company;

class AddRecruitInfo
{
private:
    AddRecruitInfoUI& ui;
    Company& company;

public:
    AddRecruitInfo(AddRecruitInfoUI& ui, Company& comp);
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
class Company;

class CheckRecruitInfo
{
private:
    CheckRecruitInfoUI& ui;
    Company& company;

public:
    CheckRecruitInfo(CheckRecruitInfoUI& ui, Company& comp);
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
class Company;

class RecruitInfoStatistic {
private:
    RecruitInfoStatisticUI& ui;
    Company& company;

public:
    RecruitInfoStatistic(RecruitInfoStatisticUI& ui, Company& company);
    void startInterface();
    unordered_map<string, int> showStatistic() const;
};



/*
채용정보
RecruitInfo : Entity Class
작성자 : 임준혁
*/

class RecruitInfo {
private:
	string entrepreneurNumber; //사업자번호
	string work; //업무
	int numPeople; //인원수
	string deadline; //신청마감일
public:
	RecruitInfo(string&  companyName, string& entrepreneurNumber, string& work, int numPeople, string& deadline); //뭔지 모르겠지만 정보를 갖는 놈 같다
	void getRecruitInfoDetail();
	
	//Getter
	int getEntrepreneurNumber() const;
	string getWork() const;
   	string getNumPeople() const;
    	string getDeadline() const;

}; 

/*회사
Company : Entity Class
작성자 : 임준혁
*/
class Company
{
private:
    string companyName;
    vector<RecruitInfo*> recruitInfos;

public:
    Company(const string& name = "");
    string getCompanyName() const; // 얘가 여기 들어가도 되나?
    ~Company();
    void getRecruitInfo();
    vector<RecruitInfo*> getRecruitInfo() const;
}; //class Company끝, 내가 손댄것없음, 겹치지만 사용하는 곳이 다름

/*
채용정보검색
ResearchRecruitInfoUI : Boundary Class
작성자 : 임준혁
*/
class ResearchRecruitInfoUI
{
public :
	void selectentrepreneurNumber(ResearchRecruitInfo* researchrecruitinfo);
};


/*
채용정보검색
ResearchRecruitInfo : Control Class
작성자 : 임준혁
*/
class ResearchRecruitInfo
{
public :
	ResearchRecruitInfo();
	void showRecruitInfo();
};

/*
채용 지원
ApplyUI : Boundary Class
작성자 : 임준혁
*/
class ApplyUI
{
public :
	selectentrepreneur(Apply* apply); // 얘는 뭘까? actor에서 boundary로 이어지는 애
};

/*
채용 지원
Apply : Control Class
작성자 : 임준혁
*/
class Apply
{
public :
	Apply(); // 얘는 뭘까?
	void showapplyrecruit(string entrepreneurNumber); // 사업자번호주면 회사이름 사업자번호 업무보여주는 애
};





/*
 ApplyInfo : Entity Classes
 작성자: 김상혁
 */
class ApplyInfo{
private:
    string companyName;  // 회사이름
    string work;  // 업무
    int numPeople;  // 인원수
    string deadline;  // 신청 마감일
    string entrepreneurNumber;  // 사업자 번호
public:
    void getApplyInfoDetail();
    
    // get 함수
    string getCompanyName();
    string getWork();
    int getNumPeople();
    string getDeadline();
    string getEntrepreneurNumber();
};


/*
 Applicant : Entity Classes
 작성자: 김상혁
 */
class Applicant
{
private:
    vector <ApplyInfo*> applyInfoList;  // 지원목록
public:
    void getApplyInfo();
    void deleteApplyInfo(string entrepreneurNumber);
    void getApplyNumsPerWork();
    
    // get 함수
    vector <ApplyInfo*> getApplyInfoList();
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
