#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Class.h"

#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

using namespace std;


void doTask()
{	
	vector<Member> members;
	
	// 메뉴 파싱을 위한 level 구분을 위한 변수
	int menu_level_1 = 0, menu_level_2 = 0; int is_program_exit = 0;
	
	while (!is_program_exit) { 
		// 입력파일에서 메뉴 숫자 2개를 읽기
		inputFile >> menu_level_1 >> menu_level_2;

		// 메뉴 구분 및 해당 연산 수행
		switch (menu_level_1) {
			case 1: { switch (menu_level_2) {
				case 1: // "1.1. 회원가입" 메뉴 부분
				{	// join() 함수에서 해당 기능 수행 
					AddMemberUI addmemberui;
					addmemberui.joinNewMember(members);
					break; 
				} 
				case 2:	// "1.2. 회원탈퇴" 메뉴 부분
				{	// withdrawal() 함수에서 해당 기능 수행
					WithdrawalUI withdrawalui;
					withdrawalui.requestWithdrawal(members);
					break; 
				}

			}}

			case 2: { switch (menu_level_2) {
				case 1: // "2.1. 로그인" 메뉴 부분
				{	// login() 함수에서 해당 기능 수행
					LoginUI loginui;
					loginui.login(members);
					break;
				}
				case 2: // "2.2. 로그아웃" 메뉴 부분
				{	// logout() 함수에서 해당 기능 수행
					LogoutUI logoutui;
					logoutui.requestLogout(members);
					break;
				}

			}}

			case 3: { switch (menu_level_2) {
				case 1: // "3.1. 채용 정보 등록" 메뉴 부분
				{	// () 함수에서 해당 기능 수행 
					();
					break;
				}
				case 2:	// "3.2. 등록된 채용 정보 조회" 메뉴 부분
				{	// () 함수에서 해당 기능 수행
					();
					break;
				}

			}}
			
			case 4: { switch (menu_level_2) {
				case 1: // "4.1. 채용 정보 검색" 메뉴 부분
				{	// () 함수에서 해당 기능 수행 
					();
					break;
				}
				case 2:	// "4.2. 채용 지원" 메뉴 부분
				{	// () 함수에서 해당 기능 수행
					();
					break;
				}
				case 3:	// "4.3. 지원 정보 조회" 메뉴 부분
				{	// () 함수에서 해당 기능 수행
					();
					break;
				}
				case 4:	// "4.4. 지원 취소" 메뉴 부분
				{	// () 함수에서 해당 기능 수행
					();
					break;
				}

			}}

			case 5: { switch (menu_level_2) {
				case 1: // "5.1. 지원 정보 통계" 메뉴 부분
				{	// () 함수에서 해당 기능 수행 
					();
					break;
				}

			}}

			case 6: { switch (menu_level_2) {
				case 1: // "6.1. 종료“ 메뉴 부분
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

	int memberCategory = 0;				//일반회원인지 회사회원인지 구분

	// 입력 형식 : 이름, 주민번호, ID, Password를 파일로부터 읽음
	inputFile >> memberCategory;

	if (memberCategory == 1)			// 회사회원 회원가입
	{
		inputFile >> name >> number >> ID >> PW;

		CompanyMember companyMember(name, number);	// 생성자를 통해 companyName과 entrepreneurNumber 설정
		companyMember.ID = ID;
		companyMember.PW = PW;
		companyMember.loggedIn = 0; // 로그아웃 상태로 초기화

		members.push_back(companyMember);

	}

	else if (memberCategory == 2)		// 일반회원 회원가입
	{
		inputFile >> name >> number >> ID >> PW; 

		NormalMember normalMember(name, number);	// 생성자를 통해 name과 residentNumber 설정
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
