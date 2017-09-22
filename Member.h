#include <iostream>
#include "List.h"
#include "CurrentTime.h"
#include "Session.h"
#include "group.h"

using namespace std;

//Class: MemberInfo
//Description: �� Ŭ������ ȸ�������� ������ �ִ� �Լ��̴�.
//Author:����

class MemberInfo{  //Member Object�� �����ϴ� �����ڿ� �Ҹ��ϴ� �Ҹ��ڸ� ������ ������, ȸ������/Ż�� ȭ������ �̵���Ű�� �Լ��� �����ϰ��ִ�.
private:
	string id, pw, name, address, email, jumin;
public:
	MemberInfo(){}
	~MemberInfo(void){}
	Group group;
public:

	void JoinMember(CList* List); //ȸ������ ȭ������ �̵������ִ� �Լ�
	void LeaveMember(CList* List);//ȸ��Ż�� ȭ������ �̵������ִ� �Լ�
	string GetID();
};
void JoinMemberUI(CList* MList);  //ȸ�����԰� ȸ��Ż�� ������ �� �ִ� ȭ��(UI)�� �̵������ִ� �Լ�