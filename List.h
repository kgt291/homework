#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <string>

using namespace std;
//Struct: Member
//Description: ȸ���� �����ϴ� object�̴�. �� object���� ID, PassWord, Name(ȸ���̸�), Address(ȸ���ּ�), E-Mail(ȸ�� �̸���), Jumin(ȸ�� �ֹι�ȣ)�� �����ϰ��ִ�. ����ü�� ȸ���� ������ ��� �ִ�.
//Author: ����

typedef struct Member Member;
struct Member
{
	string id, pw, name, address, email, jumin;

};

class CNode// CNODE�� Double Linkded List�� �����ϴ� Node�̴�. Double Linked List �ڷᱸ������ Prev�� Next�� �⺻������ ������ ������, 
	//Member�� �߰��ϰų� ���� �� �� �� Node�� ���Խ��Ѽ� �����Ѵ�.
{
public:

	Member member;

	CNode* Next;
	CNode* Prev;
	CNode() {}
	CNode(CNode* next, CNode* prev, Member _member) :Next(next), Prev(prev), member(_member) {}

};

// class : CList
// Description : // CNode�� ���������ν� Double Linked List�� �����Ǹ�, Double Linkde List�� �̿��� �Լ��� �α��ν� 
//ID, PassWord�� ��Ī�����ִ� �Լ�, �α׾ƿ��Լ�, ȸ�����Խ� Member�� �߰���Ű�ų� �����ϴ� Ŭ���� �̴�.
// Created : 2017.06.20 14:00
// Author : ����
class CList
{
private:
	CNode* pHead;
	CNode* qHead;
public:
	CList() :pHead(NULL) {	};

	//----1login--------------
	string match(string id, string password); //�α��ν� ID, Password�� �ִ��� �������� ������ �ٸ����� Ȯ���ϴ� �Լ�, ���̵� ����
	void out(); // �α׾ƿ��� �ϴ� �Լ�

	//-----2 Member-------------------------
	void addNewMember(Member member); // ȸ�����Խ� Member Object�� Double Linked List�� Node�� ������Ű�� �Լ�
	void deleteMember(string id, string password); // ȸ��Ż��� Member Object�� Double Linked List�� Node�� ������Ű�� �Լ�

};
#endif