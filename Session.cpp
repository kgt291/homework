#include "Session.h"
#include "CurrentTime.h"

//Function:void currentSession()
//Description: 현재 세션을 불러오는 함수
//parameter : 
//return value :
//created: 2017.06.20. 14:00
//author : 노대민

void currentSession(){ //현재 세션을 불러오는 함수이며 회원가입을 하면 ID로 Session이 정해지며 로그인을 하면 Session이 ID로 바뀐다.
	//처음 Session은 nonmember로 정해지게끔 해놓았다.
	cout << " / " << curSession << endl;
}
