#ifndef RecruitInfoSystem_h
#define RecruitInfoSystem_h

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

using namespace std;

ifstream inputFile(INPUT_FILE_NAME);   // input.txt 를 읽기모드로 열기
ofstream outputFile(OUTPUT_FILE_NAME); // output.txt 를 쓰기모드로 열기

void doTask();

class RecruitInfo {
private:
	string entrepreneurNumber; //사업자번호
	string work; //업무
	int numPeople; //인원수
	string deadline; //신청마감일
public:
	RecruitInfo(string&  companyName, string& entrepreneurNumber, string& work, int numPeople, string& deadline); //뭔지 모르겠지만 정보를 갖는 놈 같다.

	//Getter
	int getEntrepreneurNumber() const;
	string getWork() const;
   	string getNumPeople() const;
    	string getDeadline() const;

}; //class RecruitInfo끝

class Company
{
private:
    string companyName;
    vector<RecruitInfo*> recruitInfos;

public:
    Company(const string& name = "");
    string getCompanyName() const; // 얘가 여기 들어가도 되나?
    ~Company();
    void addNewRecruitInfo(string& work, int numPeople, string& deadline); // 이부분에 해당하는 내꺼모르겠당
    vector<RecruitInfo*> getRecruitInfo() const;
}; //class Company끝, 내가 손댄것없음, 겹치지만 사용하는 곳이 다름

/*
채용정보검색
ResearchRecruitInfoUI : Boundary Class
작성자 : 임준혁
*/
class ResearchRecruitInfoUI
{
public :
	void selectentrepreneurNumber(ResearchRecruitInfo* researchrecruitinfo);
};


/*
채용정보검색
ResearchRecruitInfo : Control Class
작성자 : 임준혁
*/
class ResearchRecruitInfo
{
public :
	ResearchRecruitInfo();
	void showRecruitInfo();
};

/*
채용 지원
ApplyUI : Boundary Class
작성자 : 임준혁
*/
class ApplyUI
{
public :
	selectentrepreneur(Apply* apply); // 얘는 뭘까? actor에서 boundary로 이어지는 애
};

/*
채용 지원
Apply : Control Class
작성자 : 임준혁
*/
class Apply
{
public :
	Apply(); // 얘는 뭘까?
	void showapplyrecruit(string entrepreneurNumber); // 사업자번호주면 회사이름 사업자번호 업무보여주는 애
};
