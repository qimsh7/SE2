#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#define CLASS_H

#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

using namespace std;

ifstream inputFile;
ofstream outputFile;


void doTask();

class Client
{

};

class Member
{
private: 
	string ID;
	string PW;
	int loggedIn;		// 1은 로그인, 0은 로그아웃 상태

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

class NormalMember : public Member	// 일반 회원
{
private: 
	string name;			// 이름
	string residentNumber;	// 주민번호

public:
	NormalMember() : Member("", ""), name(""), residentNumber("") {}
	NormalMember(string str1, string str2) : name(str1), residentNumber(str2) {}
};

class CompanyMember : public Member	// 회사 회원
{
private:
	string companyName;			// 회사 이름
	string entrepreneurNumber;	// 사업자번호

public:
	CompanyMember() : Member("", ""), companyName(""), entrepreneurNumber("") {}
	CompanyMember(string str1, string str2) : companyName(str1), entrepreneurNumber(str2) {}
};

class AddMember
{
public:
	void createNewMember(vector<Member>& members);
};

class AddMemberUI
{
public:
	void joinNewMember(vector<Member>& members);
};

class Withdrawal
{
public:
	void withdrawal(vector<Member>& members);
};

class WithdrawalUI
{
public:
	void requestWithdrawal(vector<Member>& members);
};

class Login
{
public:
	void getLoginInformation(vector<Member>& members);
};

class LoginUI
{
public:
	void login(vector<Member>& members);
};

class Logout
{
public:
	void logout(vector<Member>& members);
};

class LogoutUI
{
public:
	void requestLogout(vector<Member>& members);
};


/*
채용정보
RecruitInfo : Entity Class
작성자 : 남석현
*/

/*
회사
Company : Entity Class
작성자 : 남석현
*/

/*
채용정보등록
AddRecruitInfoUI : Boundary Class
작성자 : 남석현
*/

/*
채용정보등록
AddRecruitInfo : Control Class
작성자 : 남석현
*/

/*
채용정보조회
CheckRecruitInfoUI : Boundary Class
작성자 : 남석현
*/

/*
채용정보조회
CheckRecruitInfo : Control Class
작성자 : 남석현
*/

/*
지원정보통계
RecruitInfoStaticUI : Boundary Class
작성자 : 남석현
*/

/*
지원정보통계
RecruitInfoStatic : Control Class
작성자 : 남석현
*/
