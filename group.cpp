#include "group.h"

//Function : void joinGroup(string groupUser)
//description : �׷쿡 ���Խ�Ű�� �Լ��Դϴ�.
//parameter : string groupUser
//return value : ����
//created: 2017.06.20. 14:00
//author : �����

void GroupControl::joinGroup(string groupUser) 
{
	int num; 
	getGrouplist(); // �׷츮��Ʈ����ؼ� Ȯ��
	cout << "���ϴ� �׷��ȣ�� �Է��Ͻÿ�";
	cin  >> num;
	cout << endl;

	for (int j = 0; j < 100; j++) {  // �׷�ȸ�� id ������ŭ
		if (group[num-1].groupUserId[j] == "\0") { // �ش�׷�ȸ��ID������ �� ������ �߰��ϸ�
			group[num-1].groupUserId[j] = groupUser; // �ش�׷�ȸ��ID���������� �׷�ȸ��ID ���� 
			break;
		}
	}
	cout << group[num - 1].groupName << "�� ȸ��" << endl;
	cout << "****************************" << endl;
	for (int k = 0; k < 100 ;k++) {  
		if (group[num - 1].groupUserId[k] == "\0") break; // �ش�׷�ȸ�� id�� ���̻� ������ �۾� ����
		cout<< k+1 << ". " << group[num - 1].groupUserId[k] << endl ; // �ش�׷�ȸ��ID�������� �׷�ȸ��ID ����Ʈ ���

	}
	cout << endl;
	
}

//Function : void constructGroup(string constructor)
//description : �׷��� �����ϴ� �Լ��Դϴ�.
//parameter : string constructor
//return value : ����
//created: 2017.06.20. 14:00
//author : �����

void GroupControl::constructGroup(string constructor)
{
	int k = 0; int i;
	string gname;
	cout << "�׷���� �Է��ϼ���.\n";
	cin >> gname;
	for (i = 0; i < 200; i++) {
		if (group[i].groupName == "\0") break; // �׷������ϴ� ���� �߿� �� ���� ã��
		if (group[i].groupName == gname) k = 1; // �׷쿡 �̹� ���� �̸��� �׷� �ִ��� Ȯ��
	}
	if (k != 1) { // ���� �̸��� �׷��� ������ �׷� ����
		group[i].groupName = gname; // �׷� ������ �׷�� ����
		group[i].constructorId = constructor; // �׷� ������ �׷������ID�� ����
		group[i].groupUserId[0] = constructor; // �׷� ������ ȸ��ID�� ����
	}
	else cout << "�������� ���� �׷��� �����մϴ�. �ٸ� �׷���� �Է��ϼ���."<<endl; // ���� �׷� ���� �˷���
}

//Function : void getGrouplist()
//description : �׷츮��Ʈ�� ����ϴ� �Լ��Դϴ�.
//parameter : ����
//return value : ����
//created: 2017.06.20. 14:00
//author : �����

void GroupControl::getGrouplist()
{
	for (int i = 0; i < 200; i++) {
		if (group[i].groupName == "\0") break; //�׷��� ���̻� ������ ��
		cout << i + 1 << ". " << group[i].groupName << endl; // �׷� �� ���
	}

}

//Function : void quitGroup(string groupUser)
//description : �׷쿡 Ż���ϰ� �ϴ� �Լ��Դϴ�.
//parameter : string groupUser
//return value : ����
//created: 2017.06.20. 14:00
//author : �����

void GroupControl::quitGroup(string groupUser)
{
	string grname;
	int i;
	cout << "Ż���� �׷��� �Է��ϼ���. ";
	cin  >> grname;
	cout << endl;
	for (i = 0; i < 200; i++) {
		if (group[i].groupName == grname) break; // Ż���� �׷� �ִ��� Ȯ�� 
	}
	for (int j = 0; j < 100; j++) {
		if (group[i].groupUserId[j] == groupUser) { //�ش�׷� �� �����ִ� ȸ�� ���� ã��  
			group[i].groupUserId[j] = "\0"; // ã���� �ش�׷쳻 ȸ�� ���� ����
			break;
		}
	}
	cout << group[i].groupName << "�� ȸ��" << endl;
	cout << "****************************" << endl;
	for (int k = 0; k < 100; k++) { 
		if (group[i].groupUserId[k] == "\0") break; // �ش�׷�ȸ�� id�� ���̻� ������ �۾� ����
		cout << k+1 << ". " << group[i].groupUserId[k] << endl; // �ش�׷�ȸ��ID�������� �׷�ȸ��ID����Ʈ ���
	}
	cout << endl;

}

