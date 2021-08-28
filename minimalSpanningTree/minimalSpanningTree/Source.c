/*
#include<stdio.h>
#define INF 9999999
#define V 6
void main() {
	int G[V][V] = {
		{0,7,0,8,0,0},
		{7,0,6,3,0,0},
		{0,6,0,4,2,5},
		{8,3,4,0,3,0},
		{0,0,2,3,0,2},
		{0,0,5,0,2,0}
	};
	int visited[V];
	memset(visited, 0, sizeof(visited));
	visited[0]= 1;
	int numEdge = 0;
	while (numEdge < V - 1) {
		int x = 0;
		int y = 0;
		int min = INF;
		for (int i = 0; i < V; i++) {
			if (visited[i]) {
				for (int j = 0; j < V; j++) {
					if (!visited[j] && G[i][j]) {
						if (min > G[i][j]) {
							min = G[i][j];
							x = i;
							y = j;
						}
					}
				}
			}
		}
		numEdge++;
		visited[y] = 1;
		printf("%d--%d(%d)\n", x, y,G[x][y]);
	}
}
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define V 6
#define H 99999
int i, j, k, a, b, u, v, n, ne = 0;
int min, mincost = 0, cost[V][V], parent[V];
int find(int);
int uni(int, int);
void main()
{
	//clrscr();
	printf("\n\tImplementation of Kruskal's algorithm\n");
	int cost[V][V] = {
		{H,7,H,8,H,H},
		{7,H,6,3,H,H},
		{H,6,H,4,2,5},
		{8,3,4,H,3,H},
		{H,H,2,3,H,2},
		{H,H,5,H,2,H}
	};
	//printf("\nEnter the no. of vertices:");
	//scanf("%d", &n);
	//printf("\nEnter the cost adjacency matrix:\n");
	/*
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			scanf("%d", &cost[i][j]);
			if (cost[i][j] == 0)
				cost[i][j] = 999;
		}
	}
	*/
	//printf("The edges of Minimum Cost Spanning Tree are\n");
	while (ne < V-1)
	{
		for (i = 0, min = 999; i < V; i++)
		{
			for (j = 0; j < V; j++)
			{
				if (cost[i][j] < min)
				{
					min = cost[i][j];
					a = u = i;
					b = v = j;
				}
			}
		}
		u = find(u);
		v = find(v);
		printf("\tu %d, v %d\n", u, v);
		if (uni(u, v))
		{
			printf("%d edge (%d,%d) =%d\n", ne++, a, b, min);
			mincost += min;
		}
		cost[a][b] = cost[b][a] = 999;
	}
	printf("\n\tMinimum cost = %d\n", mincost);
	//getch();
}
int find(int i)
{
	while (parent[i])
		i = parent[i];
	return i;
}
int uni(int i, int j)
{
	if (i != j)
	{
		parent[j] = i;
		return 1;
	}
	return 0;
}