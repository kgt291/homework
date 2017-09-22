#include "List.h"
#include <time.h>
#include <windows.h>
extern string curSession;

//Function : void CList::match()
//Description: 아이디와 비밀번호를 체크한다.
//parameter : string id, string password
//return value : 
//created: 2017.06.20. 14:00
//author : 노대민

string CList::match(string id, string password) // 로그인시 Double Linked List를 이용하여 ID를 탐색하여 못찾을 시에는 
//로그인을 거부하고 찾을 시에는 로그인이 적용된다.
{
	CNode* find;
	find = pHead;

	if (find == NULL) {
		cout << "아이디를 찾을 수 없습니다." << endl;
	}
	else{
		while (find->Next != NULL){
			if (find->member.id == id && find->member.pw == password){
				curSession = id;
				cout << id << "님 로그인 되었습니다." << endl;
				return id;
			}
		}
		if (find->member.id == id && find->member.pw == password){
			curSession = id;
			cout << id << "님 로그인 되었습니다." << endl;
			return id;
		}
		else cout << "다시 확인해주세요." << endl;
	}
}

//Function : void CList::out()
//Description: 로그아웃 한다.
//created: 2017.06.20. 14:00
//author : 노대민

void CList::out() // Session를 nonmember로 바꿔주므로써 로그아웃을 시켜버린다.
{
	curSession = "nonmember";
	cout << "로그아웃 되었습니다." << endl;
}

//Function : void CList::addNewMember
//Description: 회원정보 추가하는 함수
//parameter : Member data
//return value : 
//created: 2017.06.20. 14:00
//author : 노대민

void CList::addNewMember(Member data) // Double Linked List를 이용하여 처음 회원 가입을 할 시에는 Member Object를 가지고 있는 Node를 생성하여서 회원가입이 되게끔 되어있고, 처음 회원가입이 아닐 시에는 원래 가지고 있는 Node에 next부분과 새로 생긴 prev부분과 연결한다.
{
	CNode* head;
	CNode* temp;
	head = pHead;
	if (head == NULL)
	{
		pHead = new CNode(0, 0, data);
	}
	else
	{
		while (head->Next != NULL)
		{
			head = head->Next;
		}
		temp = new CNode(0, head, data);
		head->Next = temp;
	}
}

//Function : void CList::deleteMember
//Description: 회원정보를 삭제하는 함수
//parameter : string id, string password
//return value : 
//created: 2017.06.20. 14:00
//author : 노대민


void CList::deleteMember(string id, string password) //회원 탈퇴 시 Double Linked List를 이용하여 ID, PassWord 탐색하여
//같을 시에는 회원탈퇴의 여부를 묻는다. 만약 ID, PassWord가 다를 경우에는 회원탈퇴의 여부 묻지않고 그 전 화면으로 돌린다.
{
	char ch;
	CNode* a;
	CNode* b;


	a = pHead;
	b = a->Next;

	if (a == NULL){
		cout << "찾으시는 정보가 없습니다." << endl;
		Sleep(1000);
		return;
	}

	while (a->Next != NULL)
	{
		if (a->member.id == id && a->member.pw == password)
		{
			cout << "* 탈퇴 하시겠습니까? (Y/N)" << endl;
			cin >> ch;
			if (ch == 'y' || ch == 'Y')
			{
				if (a->Prev == NULL)
				{
					b->Prev = NULL;
					pHead = b;
				}
				else{
					a->Prev->Next = b;
					b->Prev = a->Prev;
				}

				cout << "** 회원탈퇴를 완료하였습니다." << endl;
				curSession = "nonmember";
				Sleep(1000);
				return;
			}
			else return;
		}
		a = a->Next;
		b = b->Next;
	}

	if (a->Next == NULL&&a->member.id == id && a->member.pw == password)
	{
		cout << "탈퇴하시겠습니까? (Y/N)" << endl;
		cin >> ch;
		if (ch == 'y' || ch == 'Y')
		{
			if (a->Prev == NULL)
				pHead = NULL;
			else
				a->Prev->Next = NULL;
			cout << "** 회원탈퇴를 완료하였습니다." << endl;
			curSession = "nonmember";
			Sleep(1000);

			return;
		}
		else return;
	}


}
