#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <string>

using namespace std;
//Struct: Member
//Description: 회원을 구성하는 object이다. 이 object에는 ID, PassWord, Name(회원이름), Address(회원주소), E-Mail(회원 이메일), Jumin(회원 주민번호)를 포함하고있다. 구조체는 회원의 정보를 담고 있다.
//Author: 노대민

typedef struct Member Member;
struct Member
{
	string id, pw, name, address, email, jumin;

};

class CNode// CNODE는 Double Linkded List를 구성하는 Node이다. Double Linked List 자료구조에는 Prev와 Next를 기본적으로 가지고 있으며, 
	//Member를 추가하거나 삭제 할 시 이 Node에 포함시켜서 시행한다.
{
public:

	Member member;

	CNode* Next;
	CNode* Prev;
	CNode() {}
	CNode(CNode* next, CNode* prev, Member _member) :Next(next), Prev(prev), member(_member) {}

};

// class : CList
// Description : // CNode를 포함함으로써 Double Linked List가 형성되며, Double Linkde List를 이용한 함수는 로그인시 
//ID, PassWord를 매칭시켜주는 함수, 로그아웃함수, 회원가입시 Member를 추가시키거나 삭제하는 클래스 이다.
// Created : 2017.06.20 14:00
// Author : 노대민
class CList
{
private:
	CNode* pHead;
	CNode* qHead;
public:
	CList() :pHead(NULL) {	};

	//----1login--------------
	string match(string id, string password); //로그인시 ID, Password가 있는지 없는지와 같은지 다른지를 확인하는 함수, 아이디 리턴
	void out(); // 로그아웃을 하는 함수

	//-----2 Member-------------------------
	void addNewMember(Member member); // 회원가입시 Member Object의 Double Linked List의 Node를 생성시키는 함수
	void deleteMember(string id, string password); // 회원탈퇴시 Member Object의 Double Linked List의 Node를 삭제시키는 함수

};
#endif