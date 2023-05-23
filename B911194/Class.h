#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>

#define CLASS_H

#define MAX_STRING 32
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
	char ID[MAX_STRING];
	char PW[MAX_STRING];
	int loggedIn;		// 1은 로그인, 0은 로그아웃 상태

public:
	void addNewMember(vector<Member>& members);
	void checkMember(vector<Member>& members);
	void deleteMember(vector<Member>& members);
	
	Member() {
		// 기본 생성자: 멤버 변수를 초기화
		strncpy(ID, "", sizeof(ID));
		ID[sizeof(ID) - 1] = '\0';

		strncpy(PW, "", sizeof(PW));
		PW[sizeof(PW) - 1] = '\0';
	}

	Member(const char* str1, const char* str2) {
		strncpy(ID, str1, sizeof(ID));
		ID[sizeof(ID) - 1] = '\0';

		strncpy(PW, str2, sizeof(PW));
		PW[sizeof(PW) - 1] = '\0';
	}

	const char* getID() const {
		return ID;
	}
	const char* getPW() const {
		return PW;
	}
	void setLoggedIn(int value) {
		loggedIn = value;
	}

};

class NormalMember : public Member	// 일반 회원
{
private: 
	char name[MAX_STRING];				// 이름
	char residentNumber[MAX_STRING];	// 주민번호

public:
	NormalMember() {
		// 기본 생성자: 멤버 변수를 초기화
		strncpy(name, "", sizeof(name));
		name[sizeof(name) - 1] = '\0';

		strncpy(residentNumber, "", sizeof(residentNumber));
		residentNumber[sizeof(residentNumber) - 1] = '\0';
	}
	NormalMember(const char* str1, const char* str2, const char* str3, const char* str4) : Member(str1, str2)
	{
		strncpy(name, str3, sizeof(name));
		name[sizeof(name) - 1] = '\0';

		strncpy(residentNumber, str4, sizeof(residentNumber));
		residentNumber[sizeof(residentNumber) - 1] = '\0';
	}
};

class CompanyMember : public Member	// 회사 회원
{
private:
	char companyName[MAX_STRING];			// 회사 이름
	char entrepreneurNumber[MAX_STRING];	// 사업자번호

public:
	CompanyMember() {
		// 기본 생성자: 멤버 변수를 초기화
		strncpy(companyName, "", sizeof(companyName));
		companyName[sizeof(companyName) - 1] = '\0';

		strncpy(entrepreneurNumber, "", sizeof(entrepreneurNumber));
		entrepreneurNumber[sizeof(entrepreneurNumber) - 1] = '\0';
	}
	CompanyMember(const char* str1, const char* str2, const char* str3, const char* str4) : Member(str1, str2)
	{
		strncpy(companyName, str3, sizeof(companyName));
		companyName[sizeof(companyName) - 1] = '\0';

		strncpy(entrepreneurNumber, str4, sizeof(entrepreneurNumber));
		entrepreneurNumber[sizeof(entrepreneurNumber) - 1] = '\0';
	}
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

