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
	Member curLoginMember;
    
    if (inputFile.is_open())    //파일이 열려있는지 확인
    {
        while (!inputFile.eof())    //파일의 끝까지 읽는것을 반복
        {
            string str;

            while (1)
            {
                int menu1, menu2;
                inputFile >> menu1 >> menu2;    // 파일로부터 메뉴2개 를 입력받음

                if (menu1 == 1 && menu2 == 1)
                {
                   join(members);
                }
                else if (menu1 == 1 && menu2 == 2)
                {
                   withdrawal(members, curLoginMember);
                }
                else if (menu1 == 2 && menu2 == 1)
                {
                    login(members, curLoginMember);
                }
                else if (menu1 == 2 && menu2 == 2)
                {
                    logout(members, curLoginMember);
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

                    // ** 필요함수 호출**

                    outputFile << endl;
                }
                else if (menu1 == 4 && menu2 == 3)
                {
                    outputFile << "4.3. 지원 정보 조회" << endl;

                    // ** 필요함수 호출**

                    outputFile << endl;
                }
                else if (menu1 == 4 && menu2 == 4)
                {
                    outputFile << "4.4. 지원 취소" << endl;

                    // ** 필요함수 호출**

                    outputFile << endl;
                }
                else if (menu1 == 5 && menu2 == 1)
                {
                    outputFile << "5.1. 지원 정보 통계" << endl;

                    // ** 필요함수 호출**
                    //회사회원인 경우
                    void recruitInfoStatistic();

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
                    cin >> str;
                }
            }
        }
    }
}

// 메인 함수
int main()
{
    inputFile.open(INPUT_FILE_NAME);    // 입력 파일을 엽니다
    outputFile.open(OUTPUT_FILE_NAME);  // 출력 파일을 엽니다

    doTask();

    inputFile.close();          // 파일을 닫습니다
    outputFile.close();         // 파일을 닫습니다

    return 0;
}
