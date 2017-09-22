#include "member.h"



//Function : MemberInfo::JoinMember()
//Description: ȸ�������� ���� ������ �Է¹޴´�.
//parameter : CList* List
//return value :
//created: 2017.06.20. 14:00
//author : ����
void MemberInfo::JoinMember(CList* List) { //Member Object�� ȸ�����Խ� �Է��� Member������ �־��ָ�
	//Double Linked List �� �̿��� Node�� ���������ش�.
	Member mem;

	system("cls");
	currentTime(); currentSession();
	cout << "-2.1. ȸ������" << endl;
	cout << "# ID : "; cin >> mem.id;
	cout << "# PW : "; cin >> mem.pw;
	cout << "# �̸� : "; cin >> mem.name;
	cout << "# �ֹι�ȣ : "; cin >> mem.jumin;
	cout << "# �ּ� : "; cin >> mem.address;
	cout << "# �̸��� : "; cin >> mem.email;
	List->addNewMember(mem);
	cout << "ȸ�������� �Ϸ�Ǿ����ϴ�." << endl;
}


//Function:void MemberInfo::LeaveMember()
//Description: �� �Լ��� ȸ��Ż���ϴ� �Լ��̴�.
//parameter : CList* List
//return value :
//created: 2017.06.20. 14:00
//author : ����

void MemberInfo::LeaveMember(CList* List) { //ȸ��Ż��� �Է��� Member������ ���Ե� Member Object��
	//Double Linked List �� �̿��� Node�� ���������ش�.
	string id, pw, yn;


	system("cls");
	currentTime(); currentSession();
	cout << "-2.2. ȸ��Ż��" << endl;
	cout << "# ID : "; cin >> id;
	cout << "# PW : "; cin >> pw;

	List->deleteMember(id, pw);


}

//Function:void JoinMemberUI
//Description: ȸ�����԰� ȸ��Ż�� ������ �� �ִ� ȭ��(UI)�� �̵������ִ� �Լ�
//parameter : CList* MList
//return value :
//created: 2017.06.20. 14:00
//author : ����

void JoinMemberUI(CList* MList) {

	int num;
	MemberInfo object;


	while (1){
		system("cls");
		currentTime(); currentSession();
		cout << "- 2.ȸ������/Ż��" << endl;
		cout << "1. ȸ������" << endl;
		cout << "2. ȸ��Ż��" << endl;
		cout << "0. ���� �޴��� ���ư���" << endl;
		cout << "* �Է¼��� : ";
		cin >> num;

		switch (num) {
		case 1: {
			object.JoinMember(MList); break;
		}

		case 2: {
			object.LeaveMember(MList); break;
		}
		case 0: {
			return;
		}
		default:
			cout << "�ٽ��Է����ּ���." << endl;
		}
	}
}