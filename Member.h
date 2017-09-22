#include <iostream>
#include "List.h"
#include "CurrentTime.h"
#include "Session.h"
#include "group.h"

using namespace std;

//Class: MemberInfo
//Description: 이 클래스는 회원정보를 가지고 있는 함수이다.
//Author:노대민

class MemberInfo{  //Member Object를 생성하는 생성자와 소멸하는 소멸자를 가지고 있으며, 회원가입/탈퇴 화면으로 이동시키는 함수를 포함하고있다.
private:
	string id, pw, name, address, email, jumin;
public:
	MemberInfo(){}
	~MemberInfo(void){}
	Group group;
public:

	void JoinMember(CList* List); //회원가입 화면으로 이동시켜주는 함수
	void LeaveMember(CList* List);//회원탈퇴 화면으로 이동시켜주는 함수
	string GetID();
};
void JoinMemberUI(CList* MList);  //회원가입과 회원탈퇴를 선택할 수 있는 화면(UI)로 이동시켜주는 함수