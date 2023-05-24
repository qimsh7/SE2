#include "RecruitInfoSystem.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

using namespace std;


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




// 현재 로그인 한 applicant -> 수정예정
Applicant* curLoginApplicant;


/*
 사용되는 곳: 지원정보조회, 지원삭제, 지원정보통계
 작성자: 김상혁
 */
vector <ApplyInfo*> Applicant::getApplyInfoList()
{
    return this->applyInfoList;
}


/*
 사용되는 곳: 지원정보조회
 작성자: 김상혁
 */
void Applicant::getApplyInfo()
{
    // 현재 로그인한 applicant의 지원목록리스트
    vector <ApplyInfo*> applyInfoList = curLoginApplicant->getApplyInfoList();
    
    //applyInfoList 회사명 기준 오름차순으로 한번 정렬해줘야함
    
    for (int i = 0 ; i < applyInfoList.size(); i++)
        applyInfoList[i]->getApplyInfoDetail();
}


/*
 사용되는 곳: 지원삭제
 작성자: 김상혁
 */
void Applicant::deleteApplyInfo(string entrepreneurNumber)
{
    // 현재 로그인한 applicant의 지원목록리스트
    vector <ApplyInfo*> applyInfoList = curLoginApplicant->getApplyInfoList();
    int j = -1;
    
    
    // loop 돌면서 (사업자 번호 == entreprenerNumber)인 applyInfo 발견, 인덱스 저장 및 break
    for (int i = 0 ; i < applyInfoList.size(); i++)
    {
        if (applyInfoList[i]->getEntrepreneurNumber() == entrepreneurNumber)
        {
            j = i;
            break;
        }
    }
    
    // 출력 양식
    cout << applyInfoList[j]->getCompanyName() << ' ' << applyInfoList[j]->getEntrepreneurNumber() << ' ' << applyInfoList[j]->getWork() << endl;
    
    // 해당 applyInfo 삭제
    if (j != -1)
        applyInfoList.erase(applyInfoList.begin() + j);
}


/*
 사용되는 곳: 지원정보통계
 작성자: 김상혁
 */
void Applicant::getApplyNumsPerWork()
{
    // 현재 로그인한 applicant의 지원목록리스트
    vector <ApplyInfo*> applyInfoList = curLoginApplicant->getApplyInfoList();
    
    // 업무들을 모아놓은 리스트
    vector <string> workList;
    
    // 업무들을 모아놓은 리스트에서 중복 제거한 리스트
    vector <string> workListUnique;
    
    // loop 돌면서 업무들을 workList와 workListUnique에 push
    for (int i = 0 ; i < applyInfoList.size(); i++)
    {
        string work = applyInfoList[i]->getWork();
        workList.push_back(work);
        workListUnique.push_back(work);
    }
    
    // workListUnique에서 중복 제거
    sort(workListUnique.begin(), workListUnique.end());
    workListUnique.erase(unique(workListUnique.begin(), workListUnique.end(), workListUnique.end()));
    
    // loop 돌면서 업무와 지원횟수 출력
    for (int i = 0 ; i < workListUnique.size() ; i++)
    {
        string targetWork = workListUnique[i];
        int cnt = count(workList.begin(), workList.end(), targetWork);
        // 출력 양식
        cout << targetWork << ' ' << cnt << endl;
    }
}




/*
 사용되는 곳: 지원정보조회
 작성자: 김상혁
 */
void ApplyInfo::getApplyInfoDetail()
{
    // 출력 양식
    cout << getCompanyName() << " " << getWork() << " " << getNumPeople() << " " << getDeadline() << endl;
}


/*
 사용되는 곳: 지원삭제
 작성자: 김상혁
 */
string ApplyInfo::getEntrepreneurNumber()
{
    return this->entrepreneurNumber;
}




/*
 사용되는 곳: 지원정보조회
 작성자: 김상혁
 */
void CheckApplyInfoUI::checkApplyInfoButton(CheckApplyInfo* checkApplyInfo)
{
    checkApplyInfo->showApplyInfo();
}


/*
 사용되는 곳: 지원정보조회
 작성자: 김상혁
 */
CheckApplyInfo::CheckApplyInfo()  // 생성자
{
        CheckApplyInfoUI* checkApplyInfoUI = new CheckApplyInfoUI;
        checkApplyInfoUI->checkApplyInfoButton(this);
}


/*
 사용되는 곳: 지원정보조회
 작성자: 김상혁
 */
void CheckApplyInfo::showApplyInfo()
{
    // 현재 로그인한 applicant
    curLoginApplicant->getApplyInfo();
}




/*
 사용되는 곳: 지원삭제
 작성자: 김상혁
 */
void CancelApplyUI::inputCancelApplyData(CancelApply* cancelApply)
{
    string entrepreneurNumber;  // 사업자 번호
    // 입력 받음
    cin >> entrepreneurNumber;
    
    cancelApply->sendCancelApplyData(entrepreneurNumber);
}


/*
 사용되는 곳: 지원삭제
 작성자: 김상혁
 */
CancelApply::CancelApply()  // 생성자
{
        CancelApplyUI* cancelApplyUI = new CancelApplyUI;
        cancelApplyUI->inputCancelApplyData(this);
}


/*
 사용되는 곳: 지원삭제
 작성자: 김상혁
 */
void CancelApply::sendCancelApplyData(string entrepreneurNumber)
{
    curLoginApplicant->deleteApplyInfo(entrepreneurNumber);
}




/*
 사용되는 곳: 지원정보통계
 작성자: 김상혁
 */
void ApplyInfoStatisticUI::applyInfoStatisticButton(ApplyInfoStatistic *applyInfoStatistic)
{
    applyInfoStatistic->showStatistic();
}


/*
 사용되는 곳: 지원정보통계
 작성자: 김상혁
 */
ApplyInfoStatistic::ApplyInfoStatistic()  // 생성자
{
    ApplyInfoStatisticUI* applyInfoStatisticUI = new ApplyInfoStatisticUI;
    applyInfoStatisticUI->applyInfoStatisticButton(this);
}


/*
 사용되는 곳: 지원정보통계
 작성자: 김상혁
 */
void ApplyInfoStatistic::showStatistic()
{
    curLoginApplicant->getApplyNumsPerWork();
}
