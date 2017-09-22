#include "group.h"

//Function : void joinGroup(string groupUser)
//description : 그룹에 가입시키는 함수입니다.
//parameter : string groupUser
//return value : 없음
//created: 2017.06.20. 14:00
//author : 김규태

void GroupControl::joinGroup(string groupUser) 
{
	int num; 
	getGrouplist(); // 그룹리스트출력해서 확인
	cout << "원하는 그룹번호를 입력하시오";
	cin  >> num;
	cout << endl;

	for (int j = 0; j < 100; j++) {  // 그룹회원 id 개수만큼
		if (group[num-1].groupUserId[j] == "\0") { // 해당그룹회원ID정보에 빈 공간을 발견하면
			group[num-1].groupUserId[j] = groupUser; // 해당그룹회원ID정보공간에 그룹회원ID 저장 
			break;
		}
	}
	cout << group[num - 1].groupName << "의 회원" << endl;
	cout << "****************************" << endl;
	for (int k = 0; k < 100 ;k++) {  
		if (group[num - 1].groupUserId[k] == "\0") break; // 해당그룹회원 id가 더이상 없으면 작업 종료
		cout<< k+1 << ". " << group[num - 1].groupUserId[k] << endl ; // 해당그룹회원ID정보에서 그룹회원ID 리스트 출력

	}
	cout << endl;
	
}

//Function : void constructGroup(string constructor)
//description : 그룹을 생성하는 함수입니다.
//parameter : string constructor
//return value : 없음
//created: 2017.06.20. 14:00
//author : 김규태

void GroupControl::constructGroup(string constructor)
{
	int k = 0; int i;
	string gname;
	cout << "그룹명을 입력하세요.\n";
	cin >> gname;
	for (i = 0; i < 200; i++) {
		if (group[i].groupName == "\0") break; // 그룹저장하는 공간 중에 빈 공간 찾기
		if (group[i].groupName == gname) k = 1; // 그룹에 이미 같은 이름의 그룹 있는지 확인
	}
	if (k != 1) { // 같은 이름의 그룹이 없으면 그룹 생성
		group[i].groupName = gname; // 그룹 정보에 그룹명 저장
		group[i].constructorId = constructor; // 그룹 정보에 그룹생성자ID로 저장
		group[i].groupUserId[0] = constructor; // 그룹 정보에 회원ID로 저장
	}
	else cout << "같은명을 가진 그룹이 존재합니다. 다른 그룹명을 입력하세요."<<endl; // 같은 그룹 존재 알려줌
}

//Function : void getGrouplist()
//description : 그룹리스트를 출력하는 함수입니다.
//parameter : 없음
//return value : 없음
//created: 2017.06.20. 14:00
//author : 김규태

void GroupControl::getGrouplist()
{
	for (int i = 0; i < 200; i++) {
		if (group[i].groupName == "\0") break; //그룹이 더이상 없으면 끝
		cout << i + 1 << ". " << group[i].groupName << endl; // 그룹 명 출력
	}

}

//Function : void quitGroup(string groupUser)
//description : 그룹에 탈퇴하게 하는 함수입니다.
//parameter : string groupUser
//return value : 없음
//created: 2017.06.20. 14:00
//author : 김규태

void GroupControl::quitGroup(string groupUser)
{
	string grname;
	int i;
	cout << "탈퇴할 그룹을 입력하세요. ";
	cin  >> grname;
	cout << endl;
	for (i = 0; i < 200; i++) {
		if (group[i].groupName == grname) break; // 탈퇴할 그룹 있는지 확인 
	}
	for (int j = 0; j < 100; j++) {
		if (group[i].groupUserId[j] == groupUser) { //해당그룹 내 남아있는 회원 정보 찾기  
			group[i].groupUserId[j] = "\0"; // 찾으면 해당그룹내 회원 정보 제거
			break;
		}
	}
	cout << group[i].groupName << "의 회원" << endl;
	cout << "****************************" << endl;
	for (int k = 0; k < 100; k++) { 
		if (group[i].groupUserId[k] == "\0") break; // 해당그룹회원 id가 더이상 없으면 작업 종료
		cout << k+1 << ". " << group[i].groupUserId[k] << endl; // 해당그룹회원ID정보에서 그룹회원ID리스트 출력
	}
	cout << endl;

}

