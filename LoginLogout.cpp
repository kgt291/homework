#include "LoginLogout.h"
#include <windows.h>

//Function :void Login::login
//Description: 아이디와 패스워드를 입력받는 함수
//parameter : CList* list
//return value : 
//created: 2017.06.20. 14:00
//author : 노대민

string Login::login(CList* list) { //로그인시 ID, PassWord를 입력하여 ID, PassWord가 Member Object가 포함된
	//Double Linked List에 있는 ID, PassWord와 비교하여 로그인을 적용시킨다.
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
//Description: 로그아웃 하는 함수
//parameter : CList* list
//return value : 
//created: 2017.06.20. 14:00
//author : 노대민

void Login::logout(CList* list) { //현재 로그인에 적용된 ID를 로그아웃을 할때 여부를 물어보고 로그아웃시킨다.
	char yn;
	system("cls");
	currentTime(); currentSession();
	cout << "-1.2 Logout" << endl;

	if (curSession == "nonmember"){
		cout << "로그인을 하지 않았습니다. 이전 메뉴로 돌아갑니다." << endl;
		Sleep(2000);
		return;
	}

	cout << "* 정말 로그아웃하시겠습니까?(Y/N)";
	cin >> yn;

	if (yn == 'Y' || yn == 'y') {
		list->out();
	}
	else if (yn == 'N' || yn == 'n') {
		return;
	}
	else cout << "잘못 입력되었습니다." << endl;
}

//Function : void RLinLout
//Description: 로그인과 로그아웃을 선택하는 함수
//parameter : CList* MList
//return value : 
//created: 2017.06.20. 14:00
//author : 노대민

string RLinLout(CList* MList) { //로그인과 로그아웃을 할수있는 화면(UI)를 보여주는 함수

	int num;
	Login object;
	string noID;

	while (1){
		system("cls");
		currentTime(); currentSession();
		cout << "- 1. Login / Logout" << endl;
		cout << "1. Login" << endl;
		cout << "2. Logout" << endl;
		cout << "0. 메인 메뉴로 돌아가기" << endl;
		cout << "* 입력선택 : ";
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
			cout << "다시입력해주세요." << endl;
		}
	}
	return noID;
}