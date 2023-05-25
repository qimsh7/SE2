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


// doTask()
void doTask()
{
    vector<Member> members;
    Member curLoginMember;
    
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

                    void addRecruitInfo();

                    outputFile << endl;
                }
                else if (menu1 == 3 && menu2 == 2)
                {
                    outputFile << "3.2. 등록된 채용 정보 조회" << endl;

                    void checkRecruitInfo();

                    outputFile << endl;
                }
                else if (menu1 == 4 && menu2 == 1)
                {
                    outputFile << "4.1. 채용 정보 검색" << endl;

                    void searchRecruitInfo();

                    outputFile << endl;
                }
                else if (menu1 == 4 && menu2 == 2)
                {
                    outputFile << "4.2. 채용 지원" << endl;

                    // 작성 예정 by 김상혁

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
                    // 회사회원인 경우
                    recruitInfoStatistic();
//                  // 일반회원인 경우
//                  applyInfoStatistic();

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
