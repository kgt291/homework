#include "member.h"



//Function : MemberInfo::JoinMember()
//Description: 회원가입을 위한 정보를 입력받는다.
//parameter : CList* List
//return value :
//created: 2017.06.20. 14:00
//author : 노대민
void MemberInfo::JoinMember(CList* List) { //Member Object에 회원가입시 입력한 Member정보를 넣어주며
	//Double Linked List 를 이용한 Node를 생성시켜준다.
	Member mem;

	system("cls");
	currentTime(); currentSession();
	cout << "-2.1. 회원가입" << endl;
	cout << "# ID : "; cin >> mem.id;
	cout << "# PW : "; cin >> mem.pw;
	cout << "# 이름 : "; cin >> mem.name;
	cout << "# 주민번호 : "; cin >> mem.jumin;
	cout << "# 주소 : "; cin >> mem.address;
	cout << "# 이메일 : "; cin >> mem.email;
	List->addNewMember(mem);
	cout << "회원가입이 완료되었습니다." << endl;
}


//Function:void MemberInfo::LeaveMember()
//Description: 이 함수는 회원탈퇴하는 함수이다.
//parameter : CList* List
//return value :
//created: 2017.06.20. 14:00
//author : 노대민

void MemberInfo::LeaveMember(CList* List) { //회원탈퇴시 입력한 Member정보가 포함된 Member Object를
	//Double Linked List 를 이용한 Node를 삭제시켜준다.
	string id, pw, yn;


	system("cls");
	currentTime(); currentSession();
	cout << "-2.2. 회원탈퇴" << endl;
	cout << "# ID : "; cin >> id;
	cout << "# PW : "; cin >> pw;

	List->deleteMember(id, pw);


}

//Function:void JoinMemberUI
//Description: 회원가입과 회원탈퇴를 선택할 수 있는 화면(UI)로 이동시켜주는 함수
//parameter : CList* MList
//return value :
//created: 2017.06.20. 14:00
//author : 노대민

void JoinMemberUI(CList* MList) {

	int num;
	MemberInfo object;


	while (1){
		system("cls");
		currentTime(); currentSession();
		cout << "- 2.회원가입/탈퇴" << endl;
		cout << "1. 회원가입" << endl;
		cout << "2. 회원탈퇴" << endl;
		cout << "0. 메인 메뉴로 돌아가기" << endl;
		cout << "* 입력선택 : ";
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
			cout << "다시입력해주세요." << endl;
		}
	}
}