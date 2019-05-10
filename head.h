#define Vertexnum 5
#define Edgenum 3000
#define Maxint 1000
#define weightdif 20
#define Lweight -1
#define Graphnum 10

#define		INPUTF		"./graph.txt"
#define		OUTPUTF		"./graph.txt"
#define		TimeF		"./time.csv"

#include <iostream>
#include <fstream>
#include <time.h>
#include <string>
#include <cstring>
#include <sstream>
#include <malloc.h>

using namespace std;

struct Chain {
	int node;
	Chain* next;
};
struct Chainhead {
	Chain* next;
	Chain* last;
	int Pi;
	int d;
};
void FW(int D[Vertexnum + 1][Vertexnum + 1], int P[Vertexnum + 1][Vertexnum + 1]);				//给定初始的邻接矩阵D，最短路径的长度为在矩阵D中，前驱矩阵为P
int InputGraph(int W[Vertexnum + 1][Vertexnum + 1]);
void InitGraph(int W[Vertexnum + 1][Vertexnum + 1], Chainhead G[Vertexnum+1]);								//输入数据并建立邻接矩阵和邻接链表
void FWshowall(int P[Vertexnum + 1][Vertexnum + 1], int W[Vertexnum + 1][Vertexnum + 1]);		//根据前驱矩阵和最短路径长度矩阵，输出“从i到j的最短路径为：i->a->b->…->j，长度为x”
void showweightmatrix(int W[Vertexnum + 1][Vertexnum + 1]);		//打印最短路径矩阵和前驱矩阵
void showpathmatrix(int P[Vertexnum + 1][Vertexnum + 1]);
void RandomArray(int M[Vertexnum + 1][Vertexnum + 1]);	//产生有Vertexnum个顶点、Edgenum条边的图，写入到randomgraph.txt

int Bellmanford(int W[Vertexnum + 1][Vertexnum + 1], Chainhead G[]);		//在G[i].d中储存从0节点到i节点的最短路径长度，在G[i].Pi中储存最短路径的前驱节点。返回1则没有负权值环路，返回1则有负权值环路
void Dijkstra(int W[Vertexnum + 1][Vertexnum + 1], Chainhead G[], int i);
int Johnson(int W[Vertexnum + 1][Vertexnum + 1], int Z[Vertexnum + 1][Vertexnum + 1], Chainhead G[]);