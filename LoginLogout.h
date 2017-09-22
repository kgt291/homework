#include <iostream>
#include "List.h"
#include "CurrentTime.h"
#include "Session.h"
extern string curSession;

using namespace std;

// class : Login
// Description : 로그인에 관한 클래스이다.
// Created : 2017.06.20 14:00
// Author : 노대민

class Login{ //로그인과 로그아웃의 화면(UI)을 가지고 있는 class이다.
public:
	int status;
public:
	Login(){ status = 0; }
	string login(CList* list); //로그인을 할 수있는 화면으로 이동시켜주는 함수, id 리턴
	void logout(CList* list); //로그아웃을 할 수있는 화면으로 이동시켜주는 함수

};

string RLinLout(CList* MList); //로그인과 로그아웃을 할수있는 화면(UI)를 보여주는 함수


