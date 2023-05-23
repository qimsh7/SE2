#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>

#include "Class.h"

#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

using namespace std;

// ���� �Լ�
int main()
{
	inputFile.open(INPUT_FILE_NAME);    // �Է� ������ ���ϴ�
    outputFile.open(OUTPUT_FILE_NAME);  // ��� ������ ���ϴ�

    if (inputFile.is_open()) {  // ������ ���������� ���ȴ��� Ȯ���մϴ�
        doTask();
    }

    inputFile.close();          // ������ �ݽ��ϴ�
    outputFile.close();         // ������ �ݽ��ϴ�

	return 0;
}
