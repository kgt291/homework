#include <iostream>
#include "vote.h"
#include "List.h"
#include "CurrentTime.h"
#include "LoginLogout.h"
#include "Session.h"
#include "Member.h"
#include "group.h"

using namespace std;

CList * MList = new CList;
GroupControl control;
string currentUser;
string curSession = "nonmember";
VoteList vlist;

void ShowMenu();  // 메인 메뉴 보여주기
void JoinMemberMenu();  // 회원가입 및 탈퇴 메뉴 보여주기
void LoginMenu();  // 로그인 및 로그아웃 메뉴 보여주기
void VoteManagementMenu();  // 투표관리 메뉴 보여주기
void GroupManagementMenu();  // 그룹관리 메뉴 보여주기

int main()
{
	LoginMenu();

	return 0;
}

void LoginMenu(){
	while (1)
	{
		int num;
		currentTime(); currentSession();
				//회원 리스트

		cout << "- 메인메뉴" << endl;
		cout << "1. Login/Logout" << endl;
		cout << "2. 회원가입/탈퇴" << endl;
		cout << "3. 서브메뉴" << endl;
		cout << "0. 종료" << endl;
		cout << "*  입력선택  : ";

		cin >> num;

		switch (num) {
		case 1:{
			currentUser = RLinLout(MList); break;
		}
		case 2:{
			JoinMemberUI(MList); break;
		}
		case 3:{
			ShowMenu();   // 메인 메뉴 띄우기
		}
		case 0: {
			cout << "종료됩니다." << endl;
			Sleep(500);
			return;
		}
		default: {
			cout << "다시입력해주세요." << endl;
			break;
		}
				 system("cls");
		}
	}
}


void ShowMenu()
{
	while (1) {
		int menu;

		cout << "1.메인 메뉴" << endl;
		cout << "2.그룹관리" << endl;
		cout << "3.투표관리" << endl;
		cout << "*입력 선택 : ";
		cin >> menu;

		switch (menu)
		{
		case 1:
			LoginMenu();  // 회원가입 및 탈퇴 메뉴 띄우기
			break;
		case 2:
			GroupManagementMenu();  // 그룹관리 메뉴 띄우기
			break;
		case 3:
			VoteManagementMenu();  // 투표관리 메뉴 띄우기			
			break;

		default:
			cout << "잘못 입력 하셨습니다." << endl;
		}
	}
	
}


void VoteManagementMenu()
{
	int menuChoice;
	while (1){
		cout << "======================================" << endl;
		cout << "1. 투표 제안" << endl;
		cout << "2. 진행 중인 투표 리스트 조회" << endl;
		cout << "3. 투표" << endl;
		cout << "4. 진행 예정인 투표 리스트 조회" << endl;
		cout << "5. 종료된 투표 리스트 조회" << endl;
		cout << "6. 나가기" << endl;
		cout << "======================================" << endl;
		cout << endl;
		cout << "*입력 선택 : ";
		cin >> menuChoice;
		fflush(stdin);
		if (menuChoice == 6) ShowMenu();
		switch (menuChoice){
		case 1:
			vlist.proposeVote();
			break;
		case 2:
			vlist.browseOngoingVote();
			break;
		case 3:
			vlist.selectVote();
			break;
		case 4:
			vlist.browseScheduledVote();
			break;
		case 5:
			vlist.browseClosedVote();
			break;
		}
	}
}

void GroupManagementMenu()
{
	int groupNum;

	cout << "1.전체 그룹 조회" << endl;
	cout << "2.그룹 가입" << endl;
	cout << "3.그룹 생성" << endl;
	cout << "4.그룹 탈퇴" << endl;
	cout << "0.메인 메뉴로 돌아가기" << endl;
	cout << "*입력 선택 : ";
	cin >> groupNum;

	switch (groupNum)
	{
	case 1:
	    control.getGrouplist();  // 전체 그룹 조회 함수 불러오기
		break;
	case 2:
		control.joinGroup(currentUser);  // 그룹 가입 함수 불러오기
		break;
	case 3:
		control.constructGroup(currentUser);  // 그룹 생성 함수 불러오기
		break;
	case 4:
		control.quitGroup(currentUser);  // 가입 탈퇴 함수 불러오기
		break;
	case 0:
		ShowMenu();  // 메인 메뉴 불러오기
		break;
	default:
		cout << "잘못 입력 하셨습니다." << endl;
	}
}
