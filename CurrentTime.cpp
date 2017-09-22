#include <iostream>
#include "CurrentTime.h"
#pragma warning(disable: 4996) 

using namespace std;

//Function : currentTime()
//Description: 현재 시간을 상단에 보여주는 함수 (연,월,일,시간)
//parameter : 
//return value : 
//created: 2017.06.20. 14:00
//author : 노대민

void currentTime() { //현재 시간을 가져오는 함수인데 현재시각을 yyyy/mm/dd hh:mm 형식으로 출력한다.
	time_t curr_time;
	struct tm *curr_tm;

	curr_time = time(NULL);
	curr_tm = localtime(&curr_time);

	cout << curr_tm->tm_year + 1900 << "/" << curr_tm->tm_mon + 1 << "/" << curr_tm->tm_mday << " ";
	cout << curr_tm->tm_hour << ":" << curr_tm->tm_min;
}