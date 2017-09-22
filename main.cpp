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

void ShowMenu();  // ���� �޴� �����ֱ�
void JoinMemberMenu();  // ȸ������ �� Ż�� �޴� �����ֱ�
void LoginMenu();  // �α��� �� �α׾ƿ� �޴� �����ֱ�
void VoteManagementMenu();  // ��ǥ���� �޴� �����ֱ�
void GroupManagementMenu();  // �׷���� �޴� �����ֱ�

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
				//ȸ�� ����Ʈ

		cout << "- ���θ޴�" << endl;
		cout << "1. Login/Logout" << endl;
		cout << "2. ȸ������/Ż��" << endl;
		cout << "3. ����޴�" << endl;
		cout << "0. ����" << endl;
		cout << "*  �Է¼���  : ";

		cin >> num;

		switch (num) {
		case 1:{
			currentUser = RLinLout(MList); break;
		}
		case 2:{
			JoinMemberUI(MList); break;
		}
		case 3:{
			ShowMenu();   // ���� �޴� ����
		}
		case 0: {
			cout << "����˴ϴ�." << endl;
			Sleep(500);
			return;
		}
		default: {
			cout << "�ٽ��Է����ּ���." << endl;
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

		cout << "1.���� �޴�" << endl;
		cout << "2.�׷����" << endl;
		cout << "3.��ǥ����" << endl;
		cout << "*�Է� ���� : ";
		cin >> menu;

		switch (menu)
		{
		case 1:
			LoginMenu();  // ȸ������ �� Ż�� �޴� ����
			break;
		case 2:
			GroupManagementMenu();  // �׷���� �޴� ����
			break;
		case 3:
			VoteManagementMenu();  // ��ǥ���� �޴� ����			
			break;

		default:
			cout << "�߸� �Է� �ϼ̽��ϴ�." << endl;
		}
	}
	
}


void VoteManagementMenu()
{
	int menuChoice;
	while (1){
		cout << "======================================" << endl;
		cout << "1. ��ǥ ����" << endl;
		cout << "2. ���� ���� ��ǥ ����Ʈ ��ȸ" << endl;
		cout << "3. ��ǥ" << endl;
		cout << "4. ���� ������ ��ǥ ����Ʈ ��ȸ" << endl;
		cout << "5. ����� ��ǥ ����Ʈ ��ȸ" << endl;
		cout << "6. ������" << endl;
		cout << "======================================" << endl;
		cout << endl;
		cout << "*�Է� ���� : ";
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

	cout << "1.��ü �׷� ��ȸ" << endl;
	cout << "2.�׷� ����" << endl;
	cout << "3.�׷� ����" << endl;
	cout << "4.�׷� Ż��" << endl;
	cout << "0.���� �޴��� ���ư���" << endl;
	cout << "*�Է� ���� : ";
	cin >> groupNum;

	switch (groupNum)
	{
	case 1:
	    control.getGrouplist();  // ��ü �׷� ��ȸ �Լ� �ҷ�����
		break;
	case 2:
		control.joinGroup(currentUser);  // �׷� ���� �Լ� �ҷ�����
		break;
	case 3:
		control.constructGroup(currentUser);  // �׷� ���� �Լ� �ҷ�����
		break;
	case 4:
		control.quitGroup(currentUser);  // ���� Ż�� �Լ� �ҷ�����
		break;
	case 0:
		ShowMenu();  // ���� �޴� �ҷ�����
		break;
	default:
		cout << "�߸� �Է� �ϼ̽��ϴ�." << endl;
	}
}
