#include <iostream>
#include "CurrentTime.h"
#pragma warning(disable: 4996) 

using namespace std;

//Function : currentTime()
//Description: ���� �ð��� ��ܿ� �����ִ� �Լ� (��,��,��,�ð�)
//parameter : 
//return value : 
//created: 2017.06.20. 14:00
//author : ����

void currentTime() { //���� �ð��� �������� �Լ��ε� ����ð��� yyyy/mm/dd hh:mm �������� ����Ѵ�.
	time_t curr_time;
	struct tm *curr_tm;

	curr_time = time(NULL);
	curr_tm = localtime(&curr_time);

	cout << curr_tm->tm_year + 1900 << "/" << curr_tm->tm_mon + 1 << "/" << curr_tm->tm_mday << " ";
	cout << curr_tm->tm_hour << ":" << curr_tm->tm_min;
}