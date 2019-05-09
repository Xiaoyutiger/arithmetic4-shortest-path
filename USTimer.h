#include<iostream>
#include <windows.h>

using namespace std;

class USTimer
{
private:
	int freq;
	LARGE_INTEGER beginTime;
	LARGE_INTEGER endTime;

public:
	long costTime;

public:
	USTimer();
	void start();
	void end();
	void reset();
};

