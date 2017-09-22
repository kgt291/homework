#ifndef GROUP_H
#define GROUP_H
#include <iostream>
#include <string>



using namespace std;


// class : Group
// Description : This is a Group class
// Created : 2017.06.20 14:00
// Author : �����

class Group {
public:
	string groupName; // �׷��̸�
	string constructorId; // �������� ID
	string groupUserId[100]; // �׷�ȸ������ ID��
};

//class : GroupControl
// Description : This is a GroupControl class
// Created : 2017.06.20 14:00
// Author : �����

class GroupControl {
public:
	Group group[200]; //Group ���� ����
	void joinGroup(string groupUser); // �׷� ����
	void constructGroup(string constructor); //�׷� ����
	void getGrouplist(); // �׷� ����Ʈ ���
	void quitGroup(string groupUser); // �׷� Ż��
};

#endif




