#include "LoginLogout.h"
#include <windows.h>

//Function :void Login::login
//Description: ���̵�� �н����带 �Է¹޴� �Լ�
//parameter : CList* list
//return value : 
//created: 2017.06.20. 14:00
//author : ����

string Login::login(CList* list) { //�α��ν� ID, PassWord�� �Է��Ͽ� ID, PassWord�� Member Object�� ���Ե�
	//Double Linked List�� �ִ� ID, PassWord�� ���Ͽ� �α����� �����Ų��.
	string id, pw;
	system("cls");
	currentTime(); currentSession();
	cout << "-1.1 Login" << endl;
	cout << "# ID : ";
	cin >> id;

	cout << "# PW : ";
	cin >> pw;

	id = list->match(id, pw);
	return id;
}

//Function : void Login::logout
//Description: �α׾ƿ� �ϴ� �Լ�
//parameter : CList* list
//return value : 
//created: 2017.06.20. 14:00
//author : ����

void Login::logout(CList* list) { //���� �α��ο� ����� ID�� �α׾ƿ��� �Ҷ� ���θ� ����� �α׾ƿ���Ų��.
	char yn;
	system("cls");
	currentTime(); currentSession();
	cout << "-1.2 Logout" << endl;

	if (curSession == "nonmember"){
		cout << "�α����� ���� �ʾҽ��ϴ�. ���� �޴��� ���ư��ϴ�." << endl;
		Sleep(2000);
		return;
	}

	cout << "* ���� �α׾ƿ��Ͻðڽ��ϱ�?(Y/N)";
	cin >> yn;

	if (yn == 'Y' || yn == 'y') {
		list->out();
	}
	else if (yn == 'N' || yn == 'n') {
		return;
	}
	else cout << "�߸� �ԷµǾ����ϴ�." << endl;
}

//Function : void RLinLout
//Description: �α��ΰ� �α׾ƿ��� �����ϴ� �Լ�
//parameter : CList* MList
//return value : 
//created: 2017.06.20. 14:00
//author : ����

string RLinLout(CList* MList) { //�α��ΰ� �α׾ƿ��� �Ҽ��ִ� ȭ��(UI)�� �����ִ� �Լ�

	int num;
	Login object;
	string noID;

	while (1){
		system("cls");
		currentTime(); currentSession();
		cout << "- 1. Login / Logout" << endl;
		cout << "1. Login" << endl;
		cout << "2. Logout" << endl;
		cout << "0. ���� �޴��� ���ư���" << endl;
		cout << "* �Է¼��� : ";
		cin >> num;

		switch (num) {
		case 1:
		{
			return object.login(MList); break;
		}
		case 2:
		{
			object.logout(MList); break;
		}
		case 0:
		{
			return noID;
		}
		default:
			cout << "�ٽ��Է����ּ���." << endl;
		}
	}
	return noID;
}