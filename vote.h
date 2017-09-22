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
	list<Vote> voteList;	//��ǥ ����Ʈ
	int listSize = 0;	//����Ʈ ������ �ε���
public:
	void proposeVote();	//��ǥ ����
	void browseOngoingVote();	//������ ��ǥ ��ȸ
	void browseScheduledVote();	//���� ��ǥ ��ȸ
	void browseClosedVote();	//���� ��ǥ ��ȸ
	void selectVote();	//��ǥ ������ ���� �ش� ��ǥ ����
	
};

// Class : Vote
// Description: This is Vote class. It includes attributes and operations concerning vote.
// Created: 2017/06/19 17:00 pm
// Author: Seho Kim
// mail: helios473@gmail.com
class Vote{
private:
	string title;	//��ǥ ����	
	tm startTime;	//��ǥ���۽ð�
	tm endTime;	//��ǥ����ð�
	int voteState;	//��ǥ ���� 0: ��ǥ ����, 1: ��ǥ ������, 2: ��ǥ ����
	int voteNum;	//��ǥ ��ȣ
	bool alive = true;	//��ȿ�� ��ǥ����(4�� ����� false�� ����)
public:
	list<Choice> choiceList;	//������ ����Ʈ
	void setTitle(string s);	//���� ����
	string getTitle();	//���� ����	
	void addChoice(Choice c);	//������ �߰�
	void setStartTime(tm s);	//���۽ð� ����
	tm getStartTime();		//���۽ð� ����
	void setEndTime(tm s);		//����ð� ����
	tm getEndTime();		//����ð� ����
	void printChoiceList();		//������ ���
	void printVoteInfo();	//��ǥ �������
	int getVoteState();	//��ǥ���� ����
	void setVoteState(int n);	//��ǥ���� ����
	void setVoteNum(int n);	//��ǥ��ȣ ����
	int getVoteNum();	//��ǥ��ȣ ����
	bool getBAlive();	//��ȿ�� ��ǥ���� ��ȸ
	void setBAlive(bool v);	//��ȿ���� �Է�
};

// Class : Choice
// Description: This is Choice class. It includes choice title and number of votes. 
// Created: 2017/06/19 17:00 pm
// Author: Seho Kim
// mail: helios473@gmail.com
class Choice{
private:
	
public:
	string choiceTitle;	//������ ����
	int voteNumbers = 0;	//�������� ��ǥ��
	int choiceNumber = 0;	//������ ��ȣ
};


#endif