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
