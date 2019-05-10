#include "head.h"
#include "Fibheap.h"
#include "USTimer.h"

int main() {
	
	//打印出结果
	/*
	int Weight1[Vertexnum + 1][Vertexnum + 1];
	int Weight2[Vertexnum + 1][Vertexnum + 1];
	int P1[Vertexnum + 1][Vertexnum + 1];
	int P2[Vertexnum + 1][Vertexnum + 1];
	Chainhead G[Vertexnum+1];

	int result = InputGraph(Weight1);
	if (result == 0) {
		cout << "输入错误" << endl;
		return(0);
	}
	InitGraph(Weight1, G);
	for (int i = 0; i <= Vertexnum; i++) {
		for (int j = 0; j <= Vertexnum; j++) {
			Weight2[i][j] = Weight1[i][j];
		}
	}
	
	//Johnson
	if (Johnson(Weight1, P1, G) != 0) {
		showweightmatrix(Weight1);
		showpathmatrix(P1);
	}
	
	//FloydWarshall
	FW(Weight2, P2);
	showweightmatrix(Weight2);
	showpathmatrix(P2);
	FWshowall(P2, Weight2);
	
	*/

	//随机产生一个图，输出结果
	
	/*
	Chainhead G1[Vertexnum + 1];
	int W1[Vertexnum + 1][Vertexnum + 1];
	int W2[Vertexnum + 1][Vertexnum + 1];
	int P11[Vertexnum + 1][Vertexnum + 1];
	int P12[Vertexnum + 1][Vertexnum + 1];
	RandomArray(W1);
	cout << "权值矩阵" << endl;
	for (int i = 0; i <= Vertexnum; i++) {
		for (int j = 0; j <= Vertexnum; j++) {
			cout << W1[i][j] << "\t";
			W2[i][j] = W1[i][j];
		}
			
		cout << endl;
	}
	InitGraph(W1,G1);
	int nonegetiveweight = Johnson(W1, P11, G1);
	if (nonegetiveweight) {
		showweightmatrix(W1);
		showpathmatrix(P11);
	}

	//FloydWarshall

	FW(W2, P12);
	if (nonegetiveweight) {
		showweightmatrix(W2);
		showpathmatrix(P12);
		FWshowall(P12, W2);
	}
	*/
	
	/*随机产生graphnum个数组，运行repeate次*/
	
	int Weight1[Vertexnum + 1][Vertexnum + 1];
	int Weight2[Vertexnum + 1][Vertexnum + 1];
	int P1[Vertexnum + 1][Vertexnum + 1];
	int P2[Vertexnum + 1][Vertexnum + 1];
	Chainhead G[Vertexnum + 1];
	USTimer usT;
	double duringUS[3];

	time_t beginTime[3], endTime[3], duration[3];
	time_t totaldu1[3], maxdu[3];
	ofstream foutputT;
	foutputT.open(TimeF, 0);
	for (int t = 1; t <= Graphnum; t++)
	{
		RandomArray(Weight1);
		for (int i = 0; i <= Vertexnum; i++)
			for (int j = 0; j <= Vertexnum; j++)
				Weight2[i][j] = Weight1[i][j];


		beginTime[0] = clock();
		usT.start();
		InitGraph(Weight1, G);
		usT.end();
		endTime[0] = clock();
		duringUS[0] = usT.costTime;
		usT.reset();


		beginTime[1] = clock();
		usT.start();
		int nonegetiveweight = Johnson(Weight1, P1, G);
		usT.end();
		endTime[1] = clock();
		duringUS[1] = usT.costTime;
		usT.reset();

		beginTime[2] = clock();
		usT.start();
		FW(Weight2, P2);
		usT.end();
		endTime[2] = clock();
		duringUS[2] = usT.costTime;
		usT.reset();


		for (int i = 0; i < 3; i++) {
			duration[i] = endTime[i] - beginTime[i];
			foutputT << duration[i];
			foutputT << ',';
			cout << duration[i] << "\t";
			cout << "UStime: " << duringUS[i] << '\t';
		}
		foutputT << endl;
		cout << endl;
	}
	foutputT.close();
	
	return(1);
}