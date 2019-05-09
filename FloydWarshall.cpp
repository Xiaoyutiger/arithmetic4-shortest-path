#include "head.h"

void FW(int D[Vertexnum+1][Vertexnum+1] , int P[Vertexnum+1][Vertexnum+1]) {	//给定初始的邻接矩阵D，最短路径的长度为在矩阵D中，前驱矩阵为P
	for (int i = 1; i <= Vertexnum; i++) {
		for (int j = 1; j <= Vertexnum; j++) {
			if (i == j)
				P[i][j] = Maxint;
			else{
				if (D[i][j] == Maxint)
					P[i][j] = -1;

				else
					P[i][j] = i;
			}
		}
	}
	for (int k = 1; k <= Vertexnum; k++) {
		for (int i = 1; i <= Vertexnum; i++) {
			for (int j = 1; j <= Vertexnum; j++) {
				if ((D[i][k] == Maxint) || (D[k][j] == Maxint))
					continue;
				int temp = D[i][k] + D[k][j];
				if (D[i][j] > temp) {
					D[i][j] = temp;
					P[i][j] = P[k][j];
				}
			}
		}
	}
}



void FWpath(int P[Vertexnum + 1][Vertexnum + 1], int i, int j) {
	if (j == -1) {
		cout << "没有路" << endl;
		return;
	}
	if (i == j)
		cout << j;
	else
	{
		FWpath(P, i, P[i][j]);
		cout << "->";
		cout << j;
	}
}


void FWshowall(int P[Vertexnum + 1][Vertexnum + 1], int W[Vertexnum + 1][Vertexnum + 1]) {		//根据前驱矩阵和最短路径长度矩阵，输出“从i到j的最短路径为：i->a->b->…->j，长度为x”
	for (int i = 1; i <= Vertexnum; i++) {
		for (int j = 1; j <= Vertexnum; j++) {
			cout << "从" << i << "到" << j << "的最短路径为：\t";
			FWpath(P, i, j);
			cout << endl << "长度为" << W[i][j] << endl;
		}
	}
}
