#include <iostream>
#include "List.h"
#include "CurrentTime.h"
#include "Session.h"
extern string curSession;

using namespace std;

// class : Login
// Description : �α��ο� ���� Ŭ�����̴�.
// Created : 2017.06.20 14:00
// Author : ����

class Login{ //�α��ΰ� �α׾ƿ��� ȭ��(UI)�� ������ �ִ� class�̴�.
public:
	int status;
public:
	Login(){ status = 0; }
	string login(CList* list); //�α����� �� ���ִ� ȭ������ �̵������ִ� �Լ�, id ����
	void logout(CList* list); //�α׾ƿ��� �� ���ִ� ȭ������ �̵������ִ� �Լ�

};

string RLinLout(CList* MList); //�α��ΰ� �α׾ƿ��� �Ҽ��ִ� ȭ��(UI)�� �����ִ� �Լ�


