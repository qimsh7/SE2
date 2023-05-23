#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>

#include "Class.h"

#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

using namespace std;

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
