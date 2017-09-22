#include "vote.h"

//Function : void Vote::setTitle(string s)
//parameter : string s
//return value : void
// Description: title값 입력
//created: 2017.06.20. 14:00
// Author: Seho Kim
// mail: helios473@gmail.com
void Vote::setTitle(string s){
	title = s;
}
//Function : string Vote::getTitle()
//parameter : void
//return value : string
// Description: title값 출력
//created: 2017.06.20. 14:00
// Author: Seho Kim
// mail: helios473@gmail.com
string Vote::getTitle(){
	return title;
}
//Function : void Vote::addChoice(Choice c)
//parameter : Choice c
//return value : void
// Description: Vote 클래스의 choiceList에 Choice 클래스 추가
//created: 2017.06.20. 14:00
// Author: Seho Kim
// mail: helios473@gmail.com
void Vote::addChoice(Choice c){
	choiceList.push_back(c);
}
//Function : void Vote::setStartTime(tm s)
//parameter : tm s
//return value : void
// Description: startTime값 입력
//created: 2017.06.20. 14:00
// Author: Seho Kim
// mail: helios473@gmail.com
void Vote::setStartTime(tm s) {
	startTime = s;
}
//Function : tm Vote::getStartTime()
//parameter : void
//return value : tm
// Description: startTime값 출력
//created: 2017.06.20. 14:00
// Author: Seho Kim
// mail: helios473@gmail.com
tm Vote::getStartTime(){
	return startTime;
}
//Function : void Vote::setEndTime(tm s)
//parameter : tm s
//return value : void
// Description: endTime값 입력
//created: 2017.06.20. 14:00
// Author: Seho Kim
// mail: helios473@gmail.com
void Vote::setEndTime(tm s){
	endTime = s;
}
//Function : tm Vote::getEndTime()
//parameter : void
//return value : tm
// Description: endTime값 출력
//created: 2017.06.20. 14:00
// Author: Seho Kim
// mail: helios473@gmail.com
tm Vote::getEndTime(){
	return endTime;
}
//Function : void Vote::printChoiceList()
//parameter : void
//return value : void
// Description: Vote클래스의 Choice리스트 순서대로 출력
//created: 2017.06.20. 14:00
// Author: Seho Kim
// mail: helios473@gmail.com
void Vote::printChoiceList(){
	list<Choice>::iterator itor;
	string resultString;
	int resultVotes = 0;
	for (itor = choiceList.begin(); itor != choiceList.end(); itor++){
		if (itor == choiceList.begin()){
			resultString = (*itor).choiceTitle; resultVotes = (*itor).voteNumbers;
		}
		else{
			if ((*itor).voteNumbers > resultVotes){
				resultString = (*itor).choiceTitle; resultVotes = (*itor).voteNumbers;
			}
		}
		cout << (*itor).choiceNumber << "번 - " << (*itor).choiceTitle << ": " << (*itor).voteNumbers << "표" << endl;
	}
	if (resultVotes > 0){
		cout << "*최다 득표 선택지: " << resultString << " - " << "득표수 : " << resultVotes << endl;
	}
}
//Function : void Vote::printVoteInfo()
//parameter : void
//return value : void
// Description: Vote 클래스 정보 출력
//created: 2017.06.20. 14:00
// Author: Seho Kim
// mail: helios473@gmail.com
void Vote::printVoteInfo(){
	cout << "========================================" << endl;
	cout << "*투표 번호: " << getVoteNum() << endl;
	cout << "*투표 제목: " << getTitle() << endl;
	cout << "*투표 항목: " << endl;
	printChoiceList();
	cout << "*투표 시작 시간: " << getStartTime().tm_year << "년" << getStartTime().tm_mon << "월" << getStartTime().tm_mday << "일" << getStartTime().tm_hour << "시" << getStartTime().tm_min << "분" << endl;
	cout << "*투표 종료 시간: " << getEndTime().tm_year << "년" << getEndTime().tm_mon << "월" << getEndTime().tm_mday << "일" << getEndTime().tm_hour << "시" << getEndTime().tm_min << "분" << endl;
	cout << "========================================" << endl;
}
//Function : int Vote::getVoteState()
//parameter : void
//return value : int
// Description: voteState값 출력
//created: 2017.06.20. 14:00
// Author: Seho Kim
// mail: helios473@gmail.com
int Vote::getVoteState(){
	return voteState;
}
//Function : void Vote::setVoteState(int n)
//parameter : int n
//return value : void
// Description: voteState값 입력
//created: 2017.06.20. 14:00
// Author: Seho Kim
// mail: helios473@gmail.com
void Vote::setVoteState(int n) {
	voteState = n;
}
//Function : void Vote::setVoteNum(int n)
//parameter : int n
//return value : void
// Description: voteNum값 입력
//created: 2017.06.20. 14:00
// Author: Seho Kim
// mail: helios473@gmail.com
void Vote::setVoteNum(int n){
	voteNum = n;
}
//Function : int Vote::getVoteNum()
//parameter : void
//return value : int
// Description: voteNum값 출력
//created: 2017.06.20. 14:00
// Author: Seho Kim
// mail: helios473@gmail.com
int Vote::getVoteNum(){
	return voteNum;
}
//Function : bool Vote::getBAlive()
//parameter : void
//return value : bool
// Description: 유효한 투표인지 출력(종료 후 5주 경과시 조회되지않음)
//created: 2017.06.20. 14:00
// Author: Seho Kim
// mail: helios473@gmail.com
bool Vote::getBAlive() {
	return alive;
}
//Function : void Vote::setBAlive()
//parameter : bool v
//return value : void
// Description: 유효한 투표인지 값 설정(종료 후 5주 경과시 조회되지않음)
//created: 2017.06.20. 14:00
// Author: Seho Kim
// mail: helios473@gmail.com
void Vote::setBAlive(bool v) {
	alive = v;
}

//Function : closedValidity(SYSTEMTIME tNow, tm eTime)
//parameter : SYSTEMTIME tNow, tm eTime
//return value : bool
// Description: 종료일 이후 5주 이상 지났는지 확인
//created: 2017.06.20. 14:00
// Author: Seho Kim
// mail: helios473@gmail.com
bool closedValidity(SYSTEMTIME tNow, tm eTime) {
	int i, dDays = 0, pDays = 0;

	for (i = 1; i < tNow.wYear; i++) {
		dDays += 365;
	}
	for (i = 1; i < tNow.wMonth; i++) {
		dDays += 30;
	}
	dDays += tNow.wDay;

	for (i = 1; i < eTime.tm_year; i++) {
		pDays += 365;
	}
	for (i = 1; i < eTime.tm_mon; i++) {
		pDays += 30;
	}
	pDays += eTime.tm_mday;

	if (dDays - pDays > 35) return false;
	else return true;
}
//Function : compareTime(SYSTEMTIME tNow, tm sTime, tm eTime)
//parameter : SYSTEMTIME tNow, tm sTime, tm eTime
//return value : int
// Description: 현재시간, 시작시간, 종료시간 비교하여 값 리턴
//created: 2017.06.20. 14:00
// Author: Seho Kim
// mail: helios473@gmail.com
int compareTime(SYSTEMTIME tNow, tm sTime, tm eTime) {
	if (tNow.wYear < sTime.tm_year) {
		return 0;
	}
	else if ((tNow.wYear == sTime.tm_year) && (tNow.wMonth < sTime.tm_mon)) {
		return 0;
	}
	else if ((tNow.wYear == sTime.tm_year) && (tNow.wMonth == sTime.tm_mon) && (tNow.wDay < sTime.tm_mday)) {
		return 0;
	}
	else if ((tNow.wYear == sTime.tm_year) && (tNow.wMonth == sTime.tm_mon) && (tNow.wDay == sTime.tm_mday) && (tNow.wHour < sTime.tm_hour)) {
		return 0;
	}
	else if ((tNow.wYear == sTime.tm_year) && (tNow.wMonth == sTime.tm_mon) && (tNow.wDay == sTime.tm_mday) && (tNow.wHour == sTime.tm_hour) && (tNow.wMinute < sTime.tm_min)) {
		return 0;
	}

	else if (tNow.wYear > eTime.tm_year) {
		return 2;
	}
	else if ((tNow.wYear == eTime.tm_year) && (tNow.wMonth > eTime.tm_mon)) {
		return 2;
	}
	else if ((tNow.wYear == eTime.tm_year) && (tNow.wMonth == eTime.tm_mon) && (tNow.wDay > eTime.tm_mday)) {
		return 2;
	}
	else if ((tNow.wYear == eTime.tm_year) && (tNow.wMonth == eTime.tm_mon) && (tNow.wDay == eTime.tm_mday) && (tNow.wHour > eTime.tm_hour)) {
		return 2;
	}
	else if ((tNow.wYear == eTime.tm_year) && (tNow.wMonth == eTime.tm_mon) && (tNow.wDay == eTime.tm_mday) && (tNow.wHour == eTime.tm_hour) && (tNow.wMinute > eTime.tm_min)) {
		return 2;
	}

	else
		return 1;
}
//Function :checkTmValidity(tm t)
//parameter : tm t
//return value : bool
// Description: 날짜 유효성 검증
//created: 2017.06.20. 14:00
// Author: Seho Kim
// mail: helios473@gmail.com
bool checkTmValidity(tm t) {
	if ((t.tm_year < 2010 || t.tm_year > 2100) || (t.tm_mon > 12 || t.tm_mon < 1) || (t.tm_mday > 31 || t.tm_mday < 0) || (t.tm_hour < 0 || t.tm_hour > 24) || (t.tm_min < 0 || t.tm_min > 60)) {
		cout << "유효한 날짜와 시간을 입력하세요." << endl;
		return false;
	}
	return true;
}
//Function :checkDurationValidity(tm t)
//parameter : tm sTime, tmeTime
//return value : bool
// Description: 날짜간 기간 유효성 검증
//created: 2017.06.20. 14:00
// Author: Seho Kim
// mail: helios473@gmail.com
bool checkDurationValidity(tm sTime, tm eTime) {
	if (eTime.tm_year < sTime.tm_year) {
		return false;
	}
	else if ((eTime.tm_year == sTime.tm_year) && (eTime.tm_mon < sTime.tm_mon)) {
		return false;
	}
	else if ((eTime.tm_year == sTime.tm_year) && (eTime.tm_mon == sTime.tm_mon) && (eTime.tm_mday < sTime.tm_mday)) {
		return false;
	}
	else if ((eTime.tm_year == sTime.tm_year) && (eTime.tm_mon == sTime.tm_mon) && (eTime.tm_mday == sTime.tm_mday) && (eTime.tm_hour < sTime.tm_hour)) {
		return false;
	}
	else if ((eTime.tm_year == sTime.tm_year) && (eTime.tm_mon == sTime.tm_mon) && (eTime.tm_mday == sTime.tm_mday) && (eTime.tm_hour == sTime.tm_hour) && (eTime.tm_min < sTime.tm_min)) {
		return false;
	}
	return true;
}

//Function : proposeVote()
//parameter : void
//return value : void
// Description: 투표 제안
//created: 2017.06.20. 14:00
// Author: Seho Kim
// mail: helios473@gmail.com
void VoteList::proposeVote() {
	Vote tempVote;
	cout << endl;
	while (1) {
		cout << "========== 투표 제안 ==========" << endl;
		cout << "투표 주제를 입력하세요: " << endl;
		string tempString;
		getline(cin, tempString);
		tempVote.setTitle(tempString);
		cout << "투표 항목의 갯수를 입력하세요: " << endl;
		int choiceNumber;
		cin >> choiceNumber;
		if (choiceNumber < 1) {
			cout << "유효한 값을 입력해주세요.(1 이상)" << endl;
			continue;
		}
		fflush(stdin);
		for (int i = 0; i < choiceNumber; i++) {
			Choice tempChoice;
			cout << i + 1 << "번째 투표 항목을 입력하세요: ";
			getline(cin, tempChoice.choiceTitle);
			fflush(stdin);
			tempChoice.choiceNumber = i + 1;
			tempVote.addChoice(tempChoice);
		}
		tm tmpStartTime;
		memset(&tmpStartTime, 0, sizeof(tm));
		cout << "투표 시작 시간을 입력합니다---- " << endl;
		cout << "시작 년도를 입력하세요(최대 2100) : ";
		cin >> tmpStartTime.tm_year;
		fflush(stdin);
		cout << "시작 월을 입력하세요(1~12) : ";
		cin >> tmpStartTime.tm_mon;
		fflush(stdin);
		cout << "시작 일을 입력하세요(1~31) : ";
		cin >> tmpStartTime.tm_mday;
		fflush(stdin);
		cout << "시작 시각을 입력하세요(0~23) : ";
		cin >> tmpStartTime.tm_hour;
		fflush(stdin);
		cout << "시작 분을 입력하세요(0~60) : ";
		cin >> tmpStartTime.tm_min;
		fflush(stdin);
		tempVote.setStartTime(tmpStartTime);
		if (!checkTmValidity(tmpStartTime)) continue;
		tm tmpEndTime;
		memset(&tmpEndTime, 0, sizeof(tm));
		cout << "투표 종료 시간을 입력합니다---- " << endl;
		cout << "종료 년도를 입력하세요: ";
		cin >> tmpEndTime.tm_year;
		cout << "종료 월을 입력하세요: ";
		cin >> tmpEndTime.tm_mon;
		fflush(stdin);
		cout << "종료 일을 입력하세요: ";
		cin >> tmpEndTime.tm_mday;
		fflush(stdin);
		cout << "종료 시각을 입력하세요: ";
		cin >> tmpEndTime.tm_hour;
		fflush(stdin);
		cout << "종료 분을 입력하세요: ";
		cin >> tmpEndTime.tm_min;
		fflush(stdin);
		tempVote.setEndTime(tmpEndTime);
		if (!checkTmValidity(tmpEndTime)) continue;
		if (!checkDurationValidity(tmpStartTime, tmpEndTime)) {
			cout << "종료시간은 시작시간보다 뒤여야 합니다. 정확한 날짜를 입력해주세요." << endl;
			continue;
		}

		tempVote.setVoteNum(++listSize);

		cout << endl << "제안된 투표는 다음과 같습니다." << endl;
		tempVote.printVoteInfo();

		voteList.push_back(tempVote);
		break;
	}

}
//Function : browseScheduledVote()
//parameter : void
//return value : void
// Description: 예정 투표 리스트 출력
//created: 2017.06.20. 14:00
// Author: Seho Kim
// mail: helios473@gmail.com
void VoteList::browseScheduledVote() {
	list<Vote>::iterator itor;
	for (itor = voteList.begin(); itor != voteList.end(); itor++) {
		SYSTEMTIME tNow;
		GetLocalTime(&tNow);
		tm sTime = (*itor).getStartTime();
		tm eTime = (*itor).getEndTime();

		(*itor).setVoteState(compareTime(tNow, sTime, eTime));

		if ((*itor).getVoteState() == 0) {
			(*itor).printVoteInfo();
		}
	}
}
//Function : browseOngoingVote()
//parameter : void
//return value : void
// Description: 진행중 투표 리스트 출력
//created: 2017.06.20. 14:00
// Author: Seho Kim
// mail: helios473@gmail.com
void VoteList::browseOngoingVote() {
	list<Vote>::iterator itor;
	for (itor = voteList.begin(); itor != voteList.end(); itor++) {
		SYSTEMTIME tNow;
		GetLocalTime(&tNow);
		tm sTime = (*itor).getStartTime();
		tm eTime = (*itor).getEndTime();

		(*itor).setVoteState(compareTime(tNow, sTime, eTime));

		if ((*itor).getVoteState() == 1) {
			(*itor).printVoteInfo();
		}
	}
}
//Function : browseClosedVote()
//parameter : void
//return value : void
// Description: 종료된 투표 출력
//created: 2017.06.20. 14:00
// Author: Seho Kim
// mail: helios473@gmail.com
void VoteList::browseClosedVote() {
	list<Vote>::iterator itor;
	for (itor = voteList.begin(); itor != voteList.end(); itor++) {
		SYSTEMTIME tNow;
		GetLocalTime(&tNow);
		tm sTime = (*itor).getStartTime();
		tm eTime = (*itor).getEndTime();
		(*itor).setVoteState(compareTime(tNow, sTime, eTime));

		if ((*itor).getVoteState() == 2) {
			if (!closedValidity(tNow, eTime)) {
				(*itor).setBAlive(false);
			}
			if ((*itor).getBAlive()) {
				(*itor).printVoteInfo();
			}
		}
	}
}
//Function : selectVote()
//parameter : void
//return value : void
// Description: 투표 실행
//created: 2017.06.20. 14:00
// Author: Seho Kim
// mail: helios473@gmail.com
void VoteList::selectVote() {
	int voteChoice;
	cout << "투표하고자 하는 투표 번호를 입력해주세요: ";
	cin >> voteChoice;
	fflush(stdin);
	list<Vote>::iterator itor;
	for (itor = voteList.begin(); itor != voteList.end(); itor++) {
		if ((*itor).getVoteNum() == voteChoice) {
			(*itor).printVoteInfo();
			if ((*itor).getVoteState() != 1) {
				cout << "현재 진행중인 투표만 투표 행사가 가능합니다" << endl;
				break;
			}
			int castChoice;
			cout << "투표하고자 하는 선택지 번호를 입력해주세요: ";
			cin >> castChoice;
			fflush(stdin);
			list<Choice>::iterator citor;
			for (citor = (*itor).choiceList.begin(); citor != (*itor).choiceList.end(); citor++) {
				if ((*citor).choiceNumber == castChoice) {
					(*citor).voteNumbers++;
				}
			}
			(*itor).printVoteInfo();
		}
	}
}