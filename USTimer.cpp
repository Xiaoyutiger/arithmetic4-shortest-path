#include "usTimer.h"
#include "HEAD.h"



USTimer::USTimer()
{
	LARGE_INTEGER tmp;
	QueryPerformanceFrequency(&tmp);
	freq = tmp.QuadPart;
	costTime = 0;
}
void USTimer::start()
{            // ��ʼ��ʱ
	QueryPerformanceCounter(&beginTime);
}
void USTimer::end()
{                // ������ʱbeginTime
	QueryPerformanceCounter(&endTime);
	costTime = (long)((endTime.QuadPart - beginTime.QuadPart) * 1000000 / freq);
}
void USTimer::reset()
{            // ��ʱ��0
	costTime = 0;
}

/*------ʹ��˵����
1. ����һ�� USTimer ���͵�ʵ��											���磺	USTimer usT;			)
2. ���㷨��ʼǰʹ��ʵ���ĳ�Ա������start()								���磺	usT.start();			)
3. �㷨������ʹ�ó�Ա������end()										���磺	usT.end();				)
4. һ�μ�ʱ������������Ա��costTime ��ȡ���ʱ�䣬��λΪus			���磺	during = usT.costTime	)
5. �´ε��ü�ʱ����ǰ����ʱ�����㣬ʹ�ó�Ա������reset()				���磺		usT.reset()			)
*/

//#endif 
/////////////////
/*
int main() {
	MyTimer mt;
	mt.Start();
	int i;
	int sum = 0;
	for (i = 0; i < 9999999; i++) {
		sum = sum + i;
	}
	mt.End();
	cout << "Total cost time:" << mt.costTime << " us" << endl;
	return 0;
}
*/