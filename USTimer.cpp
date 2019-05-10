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
{            // 开始计时
	QueryPerformanceCounter(&beginTime);
}
void USTimer::end()
{                // 结束计时beginTime
	QueryPerformanceCounter(&endTime);
	costTime = (long)((endTime.QuadPart - beginTime.QuadPart) * 1000000 / freq);
}
void USTimer::reset()
{            // 计时清0
	costTime = 0;
}

/*------使用说明：
1. 生成一个 USTimer 类型的实例											（如：	USTimer usT;			)
2. 在算法开始前使用实例的成员方法：start()								（如：	usT.start();			)
3. 算法结束后使用成员方法：end()										（如：	usT.end();				)
4. 一次计时结束后调用类成员：costTime 获取间隔时间，单位为us			（如：	during = usT.costTime	)
5. 下次调用计时功能前将计时器清零，使用成员方法：reset()				（如：		usT.reset()			)
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