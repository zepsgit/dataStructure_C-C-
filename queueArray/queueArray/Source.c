/*
#include<stdio.h>
#define MAX 20
void enqueue(int val);
int dequeue();
int isEmpty();
void display();
void exit();
struct queue
{
	int data[MAX];
	int front;
	int rear;
};
typedef struct queue que;
que q;

void main() {
	int ch, val, x;
	q.rear = -1;
	q.front = 0;
	do {
		printf("\n\t\t\tQUEUE USING ARRAYS");
		printf("\n\t\t\t--------------\n");
		printf("\n\t1.ENQUEUE");
		printf("\n\t2DEQUEUE");
		printf("\n\t3DISPLAY");
		printf("\n\t4EXIT\n");
		printf("\nEnter your choice:\t");
		scanf("%d", &ch);
		switch (ch) {
		case 1:
			printf("enter value");
			scanf("%d", &val);
			enqueue(val);
			display();
			break;
		case 2:
			x = dequeue();
			if (x != -1)
				printf("dequed value=%d\n", x);
			display();
			break;
		case 3:
			display();
			break;
		case 4:
			exit(0);
		default:
			printf("INVALID CHOICE\n");
			break;
		}
	} while (ch != 4);
}

void enqueue(int val) {
	q.rear++;
	q.data[q.rear] = val;
}

int dequeue() {
	int k, ans;
	k = isEmpty();
	if (k == 0) {
		ans = q.data[q.front];
		q.front++;
	}
	else {
		printf("Queue is empty\n");
		ans = -1;
	}
	return ans;
}

int isEmpty() {
	int ans;
	if (q.rear < q.front)
		ans = 1;
	else
		ans = 0;
	return ans;
}

void display() {
	int ans, i;
	printf("data elements in queue\n");
	ans = isEmpty();
	if (ans == 0) {
		for (i = q.front; i <= q.rear; i++)
			printf("%d  ", q.data[i]);
	}
	else
		printf("queue is empty\n");
}
*/

#include<stdio.h>
#include<stdlib.h>

struct queue {
	int data;
	struct queue* next;
};
typedef struct queue que;

que* front = NULL;
que* rear = NULL;

void enqueue(int val);
int dequeue();
void display();

void main(){
	int choice, val,x;
	do {
		printf("\t 1.Enqueue\n");
		printf("\t 2.Dequeue\n");
		printf("\t 3.Exit\n");
		printf("please enter your choice:\n");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			printf("please enter the value \n");
			scanf("%d", &val);
			enqueue(val);
			display();
			break;
		case 2:
			x=dequeue();
			if (x != -1)
				printf("Dequeued value is:%d\n", x);
			display();
			break;
		case 3:
			exit(0);
		}
	} while (choice != 3);
}

void enqueue(int val) {
	que* node;
	node = (que*)malloc(sizeof(que));
	node->data = val;
	node->next = NULL;
	if (front == NULL)
		front = node;
	else
		rear->next = node;
	rear = node;
}

int dequeue() {
	int val;
	que* q;
	if (front == NULL) {
		printf("List is empty\n");
		val = -1;
	}
	else {
		q = front;
		val = q->data;
		front = front->next;
		if (front == NULL)
			rear = NULL;
		free(q);
	}
	return val;
}

void display() {
	que* temp;
	temp = front;
	if (temp == NULL)
		printf("empty queue\n");
	else {
		while (temp->next) {
			printf("%d ", temp->data);
			temp = temp->next;
		}
		printf("%d\n", temp->data);
	}
}