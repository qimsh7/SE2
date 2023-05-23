#ifndef RecruitInfoSystem_h
#define RecruitInfoSystem_h

#include <string>
#include <vector>
using namespace std;




/*
 ApplyInfo Entity Classes
 작성자: 김상혁
 */
class ApplyInfo{
private:
    string companyName;  // 회사이름
    string work;  // 업무
    int numPeople;  // 인원수
    string deadline;  // 신청 마감일
    string entrepreneurNumber;  // 사업자 번호
public:
    void getApplyInfoDetail();
    
    string getCompanyName();
    string getWork();
    int getNumPeople();
    string getDeadline();
    string getEntrepreneurNumber();
};




/*
 Applicant Entity Classes
 작성자: 김상혁
 */
class Applicant{
private:
    vector <ApplyInfo*> applyInfoList;  // 지원목록
public:
    void getApplyInfo();
    void deleteApplyInfo(string entrepreneurNumber);
    void getApplyNumsPerWork();
    
    vector <ApplyInfo*> getApplyInfoList();
};




/*
 지원정보조회 Control Class
 작성자: 김상혁
 */
class CheckApplyInfo{
private:
    
public:
    CheckApplyInfo();
    void showApplyInfo();
};


/*
 지원정보조회 Boundary Class
 작성자: 김상혁
 */
class CheckApplyInfoUI{
private:
    
public:
    void checkApplyInfoButton(CheckApplyInfo* checkApplyInfo);
};




/*
 지원취소 Control Class
 작성자: 김상혁
 */
class CancelApply{
private:
    
public:
    CancelApply();
    void sendCancelApplyData(string entrepreneurNumber);
};


/*
 지원취소 Boundary Class
 작성자: 김상혁
 */
class CancelApplyUI{
private:
    
public:
    void inputCancelApplyData(CancelApply* cancelApply);
};




/*
 지원정보통계 Control Class
 작성자: 김상혁
 */
class ApplyInfoStatistic{
private:
    
public:
    ApplyInfoStatistic();
    void showStatistic();
};



/*
 지원정보통계 Boundary Class
 작성자: 김상혁
 */
class ApplyInfoStatisticUI{
private:
    
public:
    void applyInfoStatisticButton(ApplyInfoStatistic* applyInfoStatistic);
};




#endif /* RecruitInfoSystem_h */
