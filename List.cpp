#include "List.h"
#include <time.h>
#include <windows.h>
extern string curSession;

//Function : void CList::match()
//Description: ���̵�� ��й�ȣ�� üũ�Ѵ�.
//parameter : string id, string password
//return value : 
//created: 2017.06.20. 14:00
//author : ����

string CList::match(string id, string password) // �α��ν� Double Linked List�� �̿��Ͽ� ID�� Ž���Ͽ� ��ã�� �ÿ��� 
//�α����� �ź��ϰ� ã�� �ÿ��� �α����� ����ȴ�.
{
	CNode* find;
	find = pHead;

	if (find == NULL) {
		cout << "���̵� ã�� �� �����ϴ�." << endl;
	}
	else{
		while (find->Next != NULL){
			if (find->member.id == id && find->member.pw == password){
				curSession = id;
				cout << id << "�� �α��� �Ǿ����ϴ�." << endl;
				return id;
			}
		}
		if (find->member.id == id && find->member.pw == password){
			curSession = id;
			cout << id << "�� �α��� �Ǿ����ϴ�." << endl;
			return id;
		}
		else cout << "�ٽ� Ȯ�����ּ���." << endl;
	}
}

//Function : void CList::out()
//Description: �α׾ƿ� �Ѵ�.
//created: 2017.06.20. 14:00
//author : ����

void CList::out() // Session�� nonmember�� �ٲ��ֹǷν� �α׾ƿ��� ���ѹ�����.
{
	curSession = "nonmember";
	cout << "�α׾ƿ� �Ǿ����ϴ�." << endl;
}

//Function : void CList::addNewMember
//Description: ȸ������ �߰��ϴ� �Լ�
//parameter : Member data
//return value : 
//created: 2017.06.20. 14:00
//author : ����

void CList::addNewMember(Member data) // Double Linked List�� �̿��Ͽ� ó�� ȸ�� ������ �� �ÿ��� Member Object�� ������ �ִ� Node�� �����Ͽ��� ȸ�������� �ǰԲ� �Ǿ��ְ�, ó�� ȸ�������� �ƴ� �ÿ��� ���� ������ �ִ� Node�� next�κа� ���� ���� prev�κа� �����Ѵ�.
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
//Description: ȸ�������� �����ϴ� �Լ�
//parameter : string id, string password
//return value : 
//created: 2017.06.20. 14:00
//author : ����


void CList::deleteMember(string id, string password) //ȸ�� Ż�� �� Double Linked List�� �̿��Ͽ� ID, PassWord Ž���Ͽ�
//���� �ÿ��� ȸ��Ż���� ���θ� ���´�. ���� ID, PassWord�� �ٸ� ��쿡�� ȸ��Ż���� ���� �����ʰ� �� �� ȭ������ ������.
{
	char ch;
	CNode* a;
	CNode* b;


	a = pHead;
	b = a->Next;

	if (a == NULL){
		cout << "ã���ô� ������ �����ϴ�." << endl;
		Sleep(1000);
		return;
	}

	while (a->Next != NULL)
	{
		if (a->member.id == id && a->member.pw == password)
		{
			cout << "* Ż�� �Ͻðڽ��ϱ�? (Y/N)" << endl;
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

				cout << "** ȸ��Ż�� �Ϸ��Ͽ����ϴ�." << endl;
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
		cout << "Ż���Ͻðڽ��ϱ�? (Y/N)" << endl;
		cin >> ch;
		if (ch == 'y' || ch == 'Y')
		{
			if (a->Prev == NULL)
				pHead = NULL;
			else
				a->Prev->Next = NULL;
			cout << "** ȸ��Ż�� �Ϸ��Ͽ����ϴ�." << endl;
			curSession = "nonmember";
			Sleep(1000);

			return;
		}
		else return;
	}


}
