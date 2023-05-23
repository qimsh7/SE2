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
	int loggedIn;		// 1�� �α���, 0�� �α׾ƿ� ����

public:
	void addNewMember(vector<Member>& members);
	void checkMember(vector<Member>& members);
	void deleteMember(vector<Member>& members);
	
	Member() {
		// �⺻ ������: ��� ������ �ʱ�ȭ
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

class NormalMember : public Member	// �Ϲ� ȸ��
{
private: 
	char name[MAX_STRING];				// �̸�
	char residentNumber[MAX_STRING];	// �ֹι�ȣ

public:
	NormalMember() {
		// �⺻ ������: ��� ������ �ʱ�ȭ
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

class CompanyMember : public Member	// ȸ�� ȸ��
{
private:
	char companyName[MAX_STRING];			// ȸ�� �̸�
	char entrepreneurNumber[MAX_STRING];	// ����ڹ�ȣ

public:
	CompanyMember() {
		// �⺻ ������: ��� ������ �ʱ�ȭ
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

