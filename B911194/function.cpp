#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>

#include "Class.h"

#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

using namespace std;


void doTask()
{	// �޴� �Ľ��� ���� level ������ ���� ����
	int menu_level_1 = 0, menu_level_2 = 0; int is_program_exit = 0;
		
	while (!is_program_exit) { 
		// �Է����Ͽ��� �޴� ���� 2���� �б�
		inputFile >> menu_level_1 >> menu_level_2;

		// �޴� ���� �� �ش� ���� ����
		switch (menu_level_1) {
			case 1: { switch (menu_level_2) {
				case 1: // "1.1. ȸ������" �޴� �κ�
				{	// join() �Լ����� �ش� ��� ���� 
					join();
					break; 
				} 
				case 2:	// "1.2. ȸ��Ż��" �޴� �κ�
				{	// withdrawal() �Լ����� �ش� ��� ����
					withdrawal();
					break; 
				}

			}}

			case 2: { switch (menu_level_2) {
				case 1: // "2.1. �α���" �޴� �κ�
				{	// login() �Լ����� �ش� ��� ����
					login();
					break;
				}
				case 2: // "2.2. �α׾ƿ�" �޴� �κ�
				{	// logout() �Լ����� �ش� ��� ����
					logout();
					break;
				}

			}}

			case 3: { switch (menu_level_2) {
				case 1: // "3.1. ä�� ���� ���" �޴� �κ�
				{	// () �Լ����� �ش� ��� ���� 
					();
					break;
				}
				case 2:	// "3.2. ��ϵ� ä�� ���� ��ȸ" �޴� �κ�
				{	// () �Լ����� �ش� ��� ����
					();
					break;
				}

			}}
			
			case 4: { switch (menu_level_2) {
				case 1: // "4.1. ä�� ���� �˻�" �޴� �κ�
				{	// () �Լ����� �ش� ��� ���� 
					();
					break;
				}
				case 2:	// "4.2. ä�� ����" �޴� �κ�
				{	// () �Լ����� �ش� ��� ����
					();
					break;
				}
				case 3:	// "4.3. ���� ���� ��ȸ" �޴� �κ�
				{	// () �Լ����� �ش� ��� ����
					();
					break;
				}
				case 4:	// "4.4. ���� ���" �޴� �κ�
				{	// () �Լ����� �ش� ��� ����
					();
					break;
				}

			}}

			case 5: { switch (menu_level_2) {
				case 1: // "5.1. ���� ���� ���" �޴� �κ�
				{	// () �Լ����� �ش� ��� ���� 
					();
					break;
				}

			}}

			case 6: { switch (menu_level_2) {
				case 1: // "6.1. ���ᡰ �޴� �κ�
				{ 
					program_exit(); 
					is_program_exit = 1; 
					break;
				}
			}}
				
				  return;
		}
	}
}

//���: ȸ������
void join(vector<Member>& members)
{
	AddMemberUI addmemberui;
	addmemberui.joinNewMember(members);
}

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
	char name[MAX_STRING], number[MAX_STRING], ID[MAX_STRING], PW[MAX_STRING];

	int memberCategory = 0;				//�Ϲ�ȸ������ ȸ��ȸ������ ����

	// �Է� ���� : �̸�, �ֹι�ȣ, ID, Password�� ���Ϸκ��� ����
	inputFile >> memberCategory;

	if (memberCategory == 1)			// ȸ��ȸ�� ȸ������
	{
		vector <CompanyMember> member;	// CompanyMember ��ü�� �����ϴ� ���� ����
		CompanyMember m;
		inputFile >> name >> number >> ID >> PW;
		member.push_back(CompanyMember(name, number, ID, PW));
	}

	else if (memberCategory == 2)		// �Ϲ�ȸ�� ȸ������
	{
		vector <NormalMember> member;	// NormalMember ��ü�� �����ϴ� ���� ����
		NormalMember m;
		inputFile >> name >> number >> ID >> PW; 
		member.push_back(NormalMember(name, number, ID, PW));
		vector <Member> members;
		Member ms;
		members.push_back(Member(ID, PW));
	}

	outputFile << "1.1. ȸ������" << endl;
	outputFile << "> " << memberCategory << " " << name << " " << number << " " << ID << " " << PW << endl;

}


//��� : ȸ��Ż��
void withdrawal(vector<Member>& members)
{
	WithdrawalUI withdrawalui;
	withdrawalui.requestWithdrawal(members);
}

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
	char targetID[MAX_STRING];
	inputFile >> targetID;

	for (auto it = members.begin(); it != members.end(); ++it) {
		if (strcmp(it->getID(), targetID) == 0) {
			members.erase(it);
			break; // ��� ID�� �����ϴٰ� �����ϰ�, ��ġ�ϴ� �׸��� ã���� �˻��� �ߴ��մϴ�.
		}
	}

	outputFile << "1.2. ȸ��Ż��" << endl;
	outputFile << "> " << targetID << endl;

}


//��� : �α���
void login(vector<Member>& members)
{
	LoginUI loginui;
	loginui.login(members);
}

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
	char targetID[MAX_STRING];
	char targetPW[MAX_STRING];

	inputFile >> targetID >> targetPW;

	for (Member& member : members) {
		if (member.getID() == targetID && member.getPW() == targetPW) {
			// �α��� ����
			member.setLoggedIn(1);

			outputFile << "2.1. �α���" << endl;
			outputFile << "> " << targetID << " " << targetPW << endl;

			return;
		}
	}
	
}


//��� : �α׾ƿ�
void logout(vector<Member>& members)
{
	LogoutUI logoutui;
	logoutui.requestLogout(members);
}

void LogoutUI::requestLogout(vector<Member>& members)
{
	Logout logout;
	logout.logout(members);
}

void Logout::logout(vector<Member>& members)
{
	char targetID[MAX_STRING];

	for (Member& member : members) {
		if (member.getID() == targetID) {
			// �α׾ƿ� ó��
			member.setLoggedIn(0);

			outputFile << "2.2. �α׾ƿ�" << endl;
			outputFile << "> " << targetID << endl;
		}
	}
}


//��� : ���α׷� ����
void program_exit()
{

}