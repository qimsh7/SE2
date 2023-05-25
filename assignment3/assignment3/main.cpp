#include "RecruitInfoSystem.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

using namespace std;


// doTask()
void doTask()
{
	vector<Member> members;

	int menu_level_1 = 0, menu_level_2 = 0;
	int is_program_exit = 0;

	while (!is_program_exit) {
		inputFile >> menu_level_1 >> menu_level_2;

		switch (menu_level_1) {
		case 1: {
			switch (menu_level_2) {
			case 1:
				join(members);
				break;
			case 2:
				withdrawal(members);
				break;
			}
			break;
		}
		case 2: {
			switch (menu_level_2) {
			case 1:
				login(members);
				break;
			case 2:
				logout(members);
				break;
			}
			break;
		}

		case 3: {
			switch (menu_level_2) {
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

			}
		}

		case 4: { 
			switch (menu_level_2) {
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

			}
		}

		case 5: { 
			switch (menu_level_2) {
			case 1: // "5.1. 지원 정보 통계" 메뉴 부분
			{	// () 함수에서 해당 기능 수행 
				();
				break;
			}

			}
		}
		
                
		case 6: {
			switch (menu_level_2) {
			case 1:
				is_program_exit = 1;
				break;
			}
			break;
		}
		}
	}
}



// 메인 함수
int main()
{
    inputFile.open(INPUT_FILE_NAME);    // 입력 파일을 엽니다
    outputFile.open(OUTPUT_FILE_NAME);  // 출력 파일을 엽니다

    if (inputFile.is_open()) {  // 파일이 정상적으로 열렸는지 확인합니다
        doTask();
    }

    inputFile.close();          // 파일을 닫습니다
    outputFile.close();         // 파일을 닫습니다

    return 0;
}
