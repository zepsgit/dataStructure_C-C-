#include<stdio.h>
#define H 9999
#define V 6


int rootOf[V];

int findRoot(int v);
int uni(int u, int v);

void main() {
	int G[V][V] = {
		{0,7,0,8,0,0},
		{7,0,6,3,0,0},
		{0,6,0,4,2,5},
		{8,3,4,0,3,0},
		{0,0,2,3,0,2},
		{0,0,5,0,2,0}
	};
	
	int numEdge = 0;
	int min;
	int a, u;
	int b, v;
	int cost = 0;

	while (numEdge < V - 1) {
		min = H;
		for (int i = 1; i < V; i++) {
			for (int j = 0; j < i; j++) {
				if (min > G[i][j]&&G[i][j]){
					min = G[i][j];
					a = u = i;
					b = v = j;
				}
			}
		}
		u = findRoot(u);
		v = findRoot(v);
		if (uni(u, v)) {
			printf("\tEdge%d: %d--%d  (%d)\n",numEdge, a, b, min);
			numEdge++;
			cost = cost + min;
		}
		G[a][b] = H;
	}
	printf("\tMinimal cost is:%d\n", cost);
}

int findRoot(int u) {
	while (rootOf[u])
		u = rootOf[u];
	return u;
}

int uni(int u, int v) {
	if (u != v) {
		//variable u and v is the root value of new node u' and v' respectively
		//if u!=v suggests u' and v' does not share the common root 
		//such that the edge u'--v' can be added without a cycle
		rootOf[u] = v;
		return 1;
	}
	//else
		return 0;
}