#include "vote.h"

//Function : void Vote::setTitle(string s)
//parameter : string s
//return value : void
// Description: title�� �Է�
//created: 2017.06.20. 14:00
// Author: Seho Kim
// mail: helios473@gmail.com
void Vote::setTitle(string s){
	title = s;
}
//Function : string Vote::getTitle()
//parameter : void
//return value : string
// Description: title�� ���
//created: 2017.06.20. 14:00
// Author: Seho Kim
// mail: helios473@gmail.com
string Vote::getTitle(){
	return title;
}
//Function : void Vote::addChoice(Choice c)
//parameter : Choice c
//return value : void
// Description: Vote Ŭ������ choiceList�� Choice Ŭ���� �߰�
//created: 2017.06.20. 14:00
// Author: Seho Kim
// mail: helios473@gmail.com
void Vote::addChoice(Choice c){
	choiceList.push_back(c);
}
//Function : void Vote::setStartTime(tm s)
//parameter : tm s
//return value : void
// Description: startTime�� �Է�
//created: 2017.06.20. 14:00
// Author: Seho Kim
// mail: helios473@gmail.com
void Vote::setStartTime(tm s) {
	startTime = s;
}
//Function : tm Vote::getStartTime()
//parameter : void
//return value : tm
// Description: startTime�� ���
//created: 2017.06.20. 14:00
// Author: Seho Kim
// mail: helios473@gmail.com
tm Vote::getStartTime(){
	return startTime;
}
//Function : void Vote::setEndTime(tm s)
//parameter : tm s
//return value : void
// Description: endTime�� �Է�
//created: 2017.06.20. 14:00
// Author: Seho Kim
// mail: helios473@gmail.com
void Vote::setEndTime(tm s){
	endTime = s;
}
//Function : tm Vote::getEndTime()
//parameter : void
//return value : tm
// Description: endTime�� ���
//created: 2017.06.20. 14:00
// Author: Seho Kim
// mail: helios473@gmail.com
tm Vote::getEndTime(){
	return endTime;
}
//Function : void Vote::printChoiceList()
//parameter : void
//return value : void
// Description: VoteŬ������ Choice����Ʈ ������� ���
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
		cout << (*itor).choiceNumber << "�� - " << (*itor).choiceTitle << ": " << (*itor).voteNumbers << "ǥ" << endl;
	}
	if (resultVotes > 0){
		cout << "*�ִ� ��ǥ ������: " << resultString << " - " << "��ǥ�� : " << resultVotes << endl;
	}
}
//Function : void Vote::printVoteInfo()
//parameter : void
//return value : void
// Description: Vote Ŭ���� ���� ���
//created: 2017.06.20. 14:00
// Author: Seho Kim
// mail: helios473@gmail.com
void Vote::printVoteInfo(){
	cout << "========================================" << endl;
	cout << "*��ǥ ��ȣ: " << getVoteNum() << endl;
	cout << "*��ǥ ����: " << getTitle() << endl;
	cout << "*��ǥ �׸�: " << endl;
	printChoiceList();
	cout << "*��ǥ ���� �ð�: " << getStartTime().tm_year << "��" << getStartTime().tm_mon << "��" << getStartTime().tm_mday << "��" << getStartTime().tm_hour << "��" << getStartTime().tm_min << "��" << endl;
	cout << "*��ǥ ���� �ð�: " << getEndTime().tm_year << "��" << getEndTime().tm_mon << "��" << getEndTime().tm_mday << "��" << getEndTime().tm_hour << "��" << getEndTime().tm_min << "��" << endl;
	cout << "========================================" << endl;
}
//Function : int Vote::getVoteState()
//parameter : void
//return value : int
// Description: voteState�� ���
//created: 2017.06.20. 14:00
// Author: Seho Kim
// mail: helios473@gmail.com
int Vote::getVoteState(){
	return voteState;
}
//Function : void Vote::setVoteState(int n)
//parameter : int n
//return value : void
// Description: voteState�� �Է�
//created: 2017.06.20. 14:00
// Author: Seho Kim
// mail: helios473@gmail.com
void Vote::setVoteState(int n) {
	voteState = n;
}
//Function : void Vote::setVoteNum(int n)
//parameter : int n
//return value : void
// Description: voteNum�� �Է�
//created: 2017.06.20. 14:00
// Author: Seho Kim
// mail: helios473@gmail.com
void Vote::setVoteNum(int n){
	voteNum = n;
}
//Function : int Vote::getVoteNum()
//parameter : void
//return value : int
// Description: voteNum�� ���
//created: 2017.06.20. 14:00
// Author: Seho Kim
// mail: helios473@gmail.com
int Vote::getVoteNum(){
	return voteNum;
}
//Function : bool Vote::getBAlive()
//parameter : void
//return value : bool
// Description: ��ȿ�� ��ǥ���� ���(���� �� 5�� ����� ��ȸ��������)
//created: 2017.06.20. 14:00
// Author: Seho Kim
// mail: helios473@gmail.com
bool Vote::getBAlive() {
	return alive;
}
//Function : void Vote::setBAlive()
//parameter : bool v
//return value : void
// Description: ��ȿ�� ��ǥ���� �� ����(���� �� 5�� ����� ��ȸ��������)
//created: 2017.06.20. 14:00
// Author: Seho Kim
// mail: helios473@gmail.com
void Vote::setBAlive(bool v) {
	alive = v;
}

//Function : closedValidity(SYSTEMTIME tNow, tm eTime)
//parameter : SYSTEMTIME tNow, tm eTime
//return value : bool
// Description: ������ ���� 5�� �̻� �������� Ȯ��
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
// Description: ����ð�, ���۽ð�, ����ð� ���Ͽ� �� ����
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
// Description: ��¥ ��ȿ�� ����
//created: 2017.06.20. 14:00
// Author: Seho Kim
// mail: helios473@gmail.com
bool checkTmValidity(tm t) {
	if ((t.tm_year < 2010 || t.tm_year > 2100) || (t.tm_mon > 12 || t.tm_mon < 1) || (t.tm_mday > 31 || t.tm_mday < 0) || (t.tm_hour < 0 || t.tm_hour > 24) || (t.tm_min < 0 || t.tm_min > 60)) {
		cout << "��ȿ�� ��¥�� �ð��� �Է��ϼ���." << endl;
		return false;
	}
	return true;
}
//Function :checkDurationValidity(tm t)
//parameter : tm sTime, tmeTime
//return value : bool
// Description: ��¥�� �Ⱓ ��ȿ�� ����
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
// Description: ��ǥ ����
//created: 2017.06.20. 14:00
// Author: Seho Kim
// mail: helios473@gmail.com
void VoteList::proposeVote() {
	Vote tempVote;
	cout << endl;
	while (1) {
		cout << "========== ��ǥ ���� ==========" << endl;
		cout << "��ǥ ������ �Է��ϼ���: " << endl;
		string tempString;
		getline(cin, tempString);
		tempVote.setTitle(tempString);
		cout << "��ǥ �׸��� ������ �Է��ϼ���: " << endl;
		int choiceNumber;
		cin >> choiceNumber;
		if (choiceNumber < 1) {
			cout << "��ȿ�� ���� �Է����ּ���.(1 �̻�)" << endl;
			continue;
		}
		fflush(stdin);
		for (int i = 0; i < choiceNumber; i++) {
			Choice tempChoice;
			cout << i + 1 << "��° ��ǥ �׸��� �Է��ϼ���: ";
			getline(cin, tempChoice.choiceTitle);
			fflush(stdin);
			tempChoice.choiceNumber = i + 1;
			tempVote.addChoice(tempChoice);
		}
		tm tmpStartTime;
		memset(&tmpStartTime, 0, sizeof(tm));
		cout << "��ǥ ���� �ð��� �Է��մϴ�---- " << endl;
		cout << "���� �⵵�� �Է��ϼ���(�ִ� 2100) : ";
		cin >> tmpStartTime.tm_year;
		fflush(stdin);
		cout << "���� ���� �Է��ϼ���(1~12) : ";
		cin >> tmpStartTime.tm_mon;
		fflush(stdin);
		cout << "���� ���� �Է��ϼ���(1~31) : ";
		cin >> tmpStartTime.tm_mday;
		fflush(stdin);
		cout << "���� �ð��� �Է��ϼ���(0~23) : ";
		cin >> tmpStartTime.tm_hour;
		fflush(stdin);
		cout << "���� ���� �Է��ϼ���(0~60) : ";
		cin >> tmpStartTime.tm_min;
		fflush(stdin);
		tempVote.setStartTime(tmpStartTime);
		if (!checkTmValidity(tmpStartTime)) continue;
		tm tmpEndTime;
		memset(&tmpEndTime, 0, sizeof(tm));
		cout << "��ǥ ���� �ð��� �Է��մϴ�---- " << endl;
		cout << "���� �⵵�� �Է��ϼ���: ";
		cin >> tmpEndTime.tm_year;
		cout << "���� ���� �Է��ϼ���: ";
		cin >> tmpEndTime.tm_mon;
		fflush(stdin);
		cout << "���� ���� �Է��ϼ���: ";
		cin >> tmpEndTime.tm_mday;
		fflush(stdin);
		cout << "���� �ð��� �Է��ϼ���: ";
		cin >> tmpEndTime.tm_hour;
		fflush(stdin);
		cout << "���� ���� �Է��ϼ���: ";
		cin >> tmpEndTime.tm_min;
		fflush(stdin);
		tempVote.setEndTime(tmpEndTime);
		if (!checkTmValidity(tmpEndTime)) continue;
		if (!checkDurationValidity(tmpStartTime, tmpEndTime)) {
			cout << "����ð��� ���۽ð����� �ڿ��� �մϴ�. ��Ȯ�� ��¥�� �Է����ּ���." << endl;
			continue;
		}

		tempVote.setVoteNum(++listSize);

		cout << endl << "���ȵ� ��ǥ�� ������ �����ϴ�." << endl;
		tempVote.printVoteInfo();

		voteList.push_back(tempVote);
		break;
	}

}
//Function : browseScheduledVote()
//parameter : void
//return value : void
// Description: ���� ��ǥ ����Ʈ ���
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
// Description: ������ ��ǥ ����Ʈ ���
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
// Description: ����� ��ǥ ���
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
// Description: ��ǥ ����
//created: 2017.06.20. 14:00
// Author: Seho Kim
// mail: helios473@gmail.com
void VoteList::selectVote() {
	int voteChoice;
	cout << "��ǥ�ϰ��� �ϴ� ��ǥ ��ȣ�� �Է����ּ���: ";
	cin >> voteChoice;
	fflush(stdin);
	list<Vote>::iterator itor;
	for (itor = voteList.begin(); itor != voteList.end(); itor++) {
		if ((*itor).getVoteNum() == voteChoice) {
			(*itor).printVoteInfo();
			if ((*itor).getVoteState() != 1) {
				cout << "���� �������� ��ǥ�� ��ǥ ��簡 �����մϴ�" << endl;
				break;
			}
			int castChoice;
			cout << "��ǥ�ϰ��� �ϴ� ������ ��ȣ�� �Է����ּ���: ";
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