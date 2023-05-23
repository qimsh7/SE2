#include <iostream>
#include "RecruitInfoSystem.h"

#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"


void doTask(){
    // 은서님 구현
}


int main(int argc, const char * argv[]) {
    // 파일 입출력을 위한 초기화
    FILE* in_fp = fopen(INPUT_FILE_NAME, "r+");
    FILE* out_fp = fopen(OUTPUT_FILE_NAME, "w+");

    
    doTask();
    
    
    return 0;
}
