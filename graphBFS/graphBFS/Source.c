/*
#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
typedef struct queue {
	int array[SIZE];
	int f;
	int r;
}que;
typedef struct newNode {
	int v;
	struct newNode *next;
}node;

typedef struct newGraph {
	int numV;
	node** adjList;
	int* visited;
}graph;

void enQue(int v);
int deQue();
graph* createGraph(int numV);
void addEdge(graph* g, int s, int d);
void bfsDisp(graph* g, int v);
que* createQue();
int isEmpty(que* q);

void main() {
	graph* g = createGraph(5);
	addEdge(g,1,2);
	addEdge(g, 1, 4);
	addEdge(g, 1, 5);
	addEdge(g, 2, 3);
	addEdge(g, 2, 4);
	addEdge(g, 2, 5);
	addEdge(g, 3, 4);
	bfsDisp(g, 1);
}

que* createQue() {
	que* q = malloc(sizeof(que));
	q->f = -1;
	q->r = -1;
	return q;
}
void enQue(que*q,int v) {
	if (q->r == SIZE - 1)
		printf("Queue is full\n");
	else {
		if(q->f == -1)
			q->f = 0;
		q->r++;
		q->array[q->r] = v;
	}

}

int deQue(que*q) {
	int val;
	if (isEmpty(q))
		printf("Que is empty\n");
	else
	{
		val = q->array[q->f];
		q->f++;
		if (q->f > q->r) {
			printf("reset que\n");
			q->f = q->r = -1;
		}
	}
	return val;

}

int isEmpty(que* q) {
	if (q->r == -1)
		return 1;
	else
		return 0;
}

graph* createGraph(int numV) {
	graph* newGraph = malloc(sizeof(graph));
	newGraph->numV = numV;
	newGraph->visited = malloc(numV*sizeof(int));
	newGraph->adjList = malloc(numV * sizeof(node));
	for (int i = 0; i < numV; i++) {
		newGraph->adjList[i] = NULL;
		newGraph->visited[i] = 0;
	}
	return newGraph;
}

void addEdge(graph* g, int s, int d) {
	//add edge from s to d;
	node* newNodeD = malloc(sizeof(node));
	newNodeD->v = d;
	newNodeD->next = g->adjList[s];
	g->adjList[s] = newNodeD;

	//add edge from d to s;
	node* newNodeS = malloc(sizeof(node));
	newNodeS->v = s;
	newNodeS->next = g->adjList[d];
	g->adjList[d] = newNodeS;
}

void bfsDisp(graph* g, int v) {
	que* q = createQue();
	g->visited[v] = 1;
	enQue(q,v);
	while (!isEmpty(q)) {
		printf("%d", v);
		int curV = deQue(q);
		printf("%d-->", curV);
		node* temp = g->adjList[curV];
		
		while (temp) {
			int adjV = temp->v;
			int visitAdj = g->visited[adjV];
			if (visitAdj == 0) {
				enQue(q,adjV);
				visitAdj = 1;
			}
			temp = temp->next;
		}
	}
}
*/

// BFS algorithm in C

#include <stdio.h>
#include <stdlib.h>
#define SIZE 40

struct queue {
	int items[SIZE];
	int front;
	int rear;
};

struct queue* createQueue();
void enqueue(struct queue* q, int);
int dequeue(struct queue* q);
void display(struct queue* q);
int isEmpty(struct queue* q);
void printQueue(struct queue* q);

struct node {
	int vertex;
	struct node* next;
};

struct node* createNode(int);

struct Graph {
	int numVertices;
	struct node** adjLists;
	int* visited;
};

// BFS algorithm
void bfs(struct Graph* graph, int startVertex) {
	struct queue* q = createQueue();

	graph->visited[startVertex] = 1;
	enqueue(q, startVertex);

	while (!isEmpty(q)) {
		//printQueue(q);
		int currentVertex = dequeue(q);
		printf("%d-->", currentVertex);

		struct node* temp = graph->adjLists[currentVertex];

		while (temp) {
			int adjVertex = temp->vertex;

			if (graph->visited[adjVertex] == 0) {
				graph->visited[adjVertex] = 1;
				enqueue(q, adjVertex);
			}
			temp = temp->next;
		}
	}
}

// Creating a node
struct node* createNode(int v) {
	struct node* newNode = malloc(sizeof(struct node));
	newNode->vertex = v;
	newNode->next = NULL;
	return newNode;
}

// Creating a graph
struct Graph* createGraph(int vertices) {
	struct Graph* graph = malloc(sizeof(struct Graph));
	graph->numVertices = vertices;

	graph->adjLists = malloc(vertices * sizeof(struct node*));
	graph->visited = malloc(vertices * sizeof(int));

	int i;
	for (i = 0; i < vertices; i++) {
		graph->adjLists[i] = NULL;
		graph->visited[i] = 0;
	}

	return graph;
}

// Add edge
void addEdge(struct Graph* graph, int src, int dest) {
	// Add edge from src to dest
	struct node* newNode = createNode(dest);
	newNode->next = graph->adjLists[src];
	graph->adjLists[src] = newNode;

	// Add edge from dest to src
	newNode = createNode(src);
	newNode->next = graph->adjLists[dest];
	graph->adjLists[dest] = newNode;
}

// Create a queue
struct queue* createQueue() {
	struct queue* q = malloc(sizeof(struct queue));
	q->front = -1;
	q->rear = -1;
	return q;
}

// Check if the queue is empty
int isEmpty(struct queue* q) {
	if (q->rear == -1)
		return 1;
	else
		return 0;
}

// Adding elements into queue
void enqueue(struct queue* q, int value) {
	if (q->rear == SIZE - 1)
		printf("\nQueue is Full!!");
	else {
		if (q->front == -1)
			q->front = 0;
		q->rear++;
		q->items[q->rear] = value;
	}
}

// Removing elements from queue
int dequeue(struct queue* q) {
	int item;
	if (isEmpty(q)) {
		printf("Queue is empty");
		item = -1;
	}
	else {
		item = q->items[q->front];
		q->front++;
		if (q->front > q->rear) {
			printf("Resetting queue ");
			q->front = q->rear = -1;
		}
	}
	return item;
}

// Print the queue
void printQueue(struct queue* q) {
	int i = q->front;

	if (isEmpty(q)) {
		printf("Queue is empty");
	}
	else {
		printf("\nQueue contains \n");
		for (i = q->front; i < q->rear + 1; i++) {
			printf("%d ", q->items[i]);
		}
	}
}

void printEdge(struct Graph* g) {
	int n = g->numVertices;
	for (int i = 0; i < n; i++)
	{
		struct node* temp = g->adjLists[i];
		while (temp) {
			printf("%d-->", temp->vertex);
			temp = temp->next;
		}
		printf("\n");
	}
}

int main() {
	struct Graph* graph = createGraph(6);
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 2);
	addEdge(graph, 1, 2);
	addEdge(graph, 1, 4);
	addEdge(graph, 1, 3);
	addEdge(graph, 2, 4);
	addEdge(graph, 3, 4);
	printEdge(graph);

	bfs(graph, 0);
	return 0;
}