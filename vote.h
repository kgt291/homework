#ifndef VOTE_H
#define VOTE_H

#include <list>
#include <string>
#include <iostream>
#include <time.h>
#include <Windows.h>

using namespace std;

class Vote;
class Choice;
class VoteList;

// Class : VoteList
// Description: This is VoteList class. It contains vote list.
// Created: 2017/06/19 17:00 pm
// Author: Seho Kim
// mail: helios473@gmail.com
class VoteList{
private:
	list<Vote> voteList;	//투표 리스트
	int listSize = 0;	//리스트 사이즈 인덱스
public:
	void proposeVote();	//투표 제안
	void browseOngoingVote();	//진행중 투표 조회
	void browseScheduledVote();	//예정 투표 조회
	void browseClosedVote();	//종료 투표 조회
	void selectVote();	//투표 실행을 위한 해당 투표 선택
	
};

// Class : Vote
// Description: This is Vote class. It includes attributes and operations concerning vote.
// Created: 2017/06/19 17:00 pm
// Author: Seho Kim
// mail: helios473@gmail.com
class Vote{
private:
	string title;	//투표 제목	
	tm startTime;	//투표시작시간
	tm endTime;	//투표종료시간
	int voteState;	//투표 상태 0: 투표 예정, 1: 투표 진행중, 2: 투표 종료
	int voteNum;	//투표 번호
	bool alive = true;	//유효한 투표인지(4주 경과시 false로 변경)
public:
	list<Choice> choiceList;	//선택지 리스트
	void setTitle(string s);	//제목 설정
	string getTitle();	//제목 리턴	
	void addChoice(Choice c);	//선택지 추가
	void setStartTime(tm s);	//시작시간 설정
	tm getStartTime();		//시작시간 리턴
	void setEndTime(tm s);		//종료시간 설정
	tm getEndTime();		//종료시간 리턴
	void printChoiceList();		//선택지 출력
	void printVoteInfo();	//투표 정보출력
	int getVoteState();	//투표상태 리턴
	void setVoteState(int n);	//투표상태 설정
	void setVoteNum(int n);	//투표번호 설정
	int getVoteNum();	//투표번호 리턴
	bool getBAlive();	//유효한 투표인지 조회
	void setBAlive(bool v);	//유효한지 입력
};

// Class : Choice
// Description: This is Choice class. It includes choice title and number of votes. 
// Created: 2017/06/19 17:00 pm
// Author: Seho Kim
// mail: helios473@gmail.com
class Choice{
private:
	
public:
	string choiceTitle;	//선택지 제목
	int voteNumbers = 0;	//선택지의 투표수
	int choiceNumber = 0;	//선택지 번호
};


#endif