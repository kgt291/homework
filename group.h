#ifndef GROUP_H
#define GROUP_H
#include <iostream>
#include <string>



using namespace std;


// class : Group
// Description : This is a Group class
// Created : 2017.06.20 14:00
// Author : 김규태

class Group {
public:
	string groupName; // 그룹이름
	string constructorId; // 생성자의 ID
	string groupUserId[100]; // 그룹회원들의 ID들
};

//class : GroupControl
// Description : This is a GroupControl class
// Created : 2017.06.20 14:00
// Author : 김규태

class GroupControl {
public:
	Group group[200]; //Group 저장 공간
	void joinGroup(string groupUser); // 그룹 가입
	void constructGroup(string constructor); //그룹 생성
	void getGrouplist(); // 그룹 리스트 출력
	void quitGroup(string groupUser); // 그룹 탈퇴
};

#endif




