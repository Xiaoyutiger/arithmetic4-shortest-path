#include "head.h"
#include "FibHeap.h"

void Relax(int i, int j, int W[Vertexnum + 1][Vertexnum + 1], Chainhead G[]) {		//松弛边（i，j）f
	int temp = G[i].d + W[i][j];
	if ((temp < G[j].d)) {
		G[j].d = temp;
		G[j].Pi = i;
	}
}

int Bellmanford(int W[Vertexnum + 1][Vertexnum + 1], Chainhead G[]) {		//在G[i].d中储存从0节点到i节点的最短路径长度，在G[i].Pi中储存最短路径的前驱节点。返回1则没有负权值环路，返回1则有负权值环路
	for (int i = 1; i <= Vertexnum; i++) {
		for (int j = 1; j <= Vertexnum; j++) {
			Chain* pointer = G[j].next;
			while (pointer != NULL) {
				Relax(j, pointer->node, W, G);
				pointer = pointer->next;
			}
		}
	}
	for (int i = 0; i <= Vertexnum; i++) {
		Chain* pointer = G[i].next;
		while (pointer != NULL) {
			int j = pointer->node;
			if (G[j].d > G[i].d + W[i][j])
				return(0);
			pointer = pointer->next;
		}
	}
	return(1);
}

void Dijkstra(int W[Vertexnum + 1][Vertexnum + 1], Chainhead G[], int i) {
	FibHeap<int>* hb = new FibHeap<int>();
	FibNode<int>* position[Vertexnum+1];

	for (int j = 1; j <= Vertexnum; j++)
		position[j] = hb->insert(G[j].d, j);
	for(int j=1;j<=Vertexnum;j++){
		FibNode<int>* min= hb->min;
		int to = min->to;
		hb->removeMin();
		if (G[to].d == Maxint)
			continue;
		Chain* pointer = G[to].next;
		while (pointer != NULL) {
			int k = pointer->node;
			int temp = G[to].d + W[to][k];
			if (temp < G[k].d){
				hb->decrease(position[k],temp);
				G[k].Pi = to;
				G[k].d = temp;
			}
			pointer = pointer->next;
		}
	}

}

int Johnson(int W[Vertexnum + 1][Vertexnum + 1], int P[Vertexnum + 1][Vertexnum + 1], Chainhead G[]) {
	int Z[Vertexnum + 1][Vertexnum + 1];
	int h[Vertexnum + 1];
	if (Bellmanford(W, G) == 0) {
		cout << "图中有负权值环路" << endl;
		return(0);
	}
	for (int i = 1; i <= Vertexnum; i++)
		h[i] = G[i].d;
	for (int i = 1; i <= Vertexnum; i++)
		for(int j=1;j<=Vertexnum;j++)
			Z[i][j] = W[i][j] + h[i] - h[j];
		
	for (int i = 1; i <= Vertexnum; i++) {
		for (int j = 1; j <= Vertexnum; j++) {
			G[j].d = Maxint;
			G[j].Pi = -1;
		}
		G[i].d = 0;
		Dijkstra(Z, G, i);
		for (int j = 1; j <= Vertexnum; j++) {
			W[i][j] = G[j].d + h[j] - h[i];
			P[i][j] = G[j].Pi;
		}
		P[i][i] = Maxint;
	}
	return(1);
}

