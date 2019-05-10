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
void FW(int D[Vertexnum + 1][Vertexnum + 1], int P[Vertexnum + 1][Vertexnum + 1]);				//������ʼ���ڽӾ���D�����·���ĳ���Ϊ�ھ���D�У�ǰ������ΪP
int InputGraph(int W[Vertexnum + 1][Vertexnum + 1]);
void InitGraph(int W[Vertexnum + 1][Vertexnum + 1], Chainhead G[Vertexnum+1]);								//�������ݲ������ڽӾ�����ڽ�����
void FWshowall(int P[Vertexnum + 1][Vertexnum + 1], int W[Vertexnum + 1][Vertexnum + 1]);		//����ǰ����������·�����Ⱦ����������i��j�����·��Ϊ��i->a->b->��->j������Ϊx��
void showweightmatrix(int W[Vertexnum + 1][Vertexnum + 1]);		//��ӡ���·�������ǰ������
void showpathmatrix(int P[Vertexnum + 1][Vertexnum + 1]);
void RandomArray(int M[Vertexnum + 1][Vertexnum + 1]);	//������Vertexnum�����㡢Edgenum���ߵ�ͼ��д�뵽randomgraph.txt

int Bellmanford(int W[Vertexnum + 1][Vertexnum + 1], Chainhead G[]);		//��G[i].d�д����0�ڵ㵽i�ڵ�����·�����ȣ���G[i].Pi�д������·����ǰ���ڵ㡣����1��û�и�Ȩֵ��·������1���и�Ȩֵ��·
void Dijkstra(int W[Vertexnum + 1][Vertexnum + 1], Chainhead G[], int i);
int Johnson(int W[Vertexnum + 1][Vertexnum + 1], int Z[Vertexnum + 1][Vertexnum + 1], Chainhead G[]);