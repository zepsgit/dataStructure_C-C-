/*
#include<stdio.h>
#define MAX 10
int isEmpty();
int isFull();
int pop();
int push(int val);
int disp();

struct stack {
	int data[MAX];
	int sp;
};
typedef struct stack stk;
stk st;

int main() {
	int choice, item;
	st.sp = -1;

	do {
		printf("\n\n");
		printf("\n menu");
		printf("\n 1:push");
		printf("\n 2:pop");
		printf("\n 3:display");
		printf("\n 4:exit\t\t");
		printf("\n Enter your choice:");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			printf("\nEnter an element to push");
			scanf("%d", &item);
			push(item);
			disp();
			break;
		case 2:
			pop();
			disp();
			break;
		case 3:
			disp();
			break;
		}
	} while (choice!=4);
	return 0;
}

int isEmpty() {
	if (st.sp == -1) {
		//printf("Stack is empty");
		return 1;
	}
	else
		return 0;
}

int isFull() {
	if (st.sp == MAX - 1) {
		//printf("Stack overflows");
		return 1;
	}
	else
		return 0;
}

int push(int val) {
	int ans;//stand for "answer"
	ans = isFull();
	if (ans == 0) {
		st.sp++;
		st.data[st.sp] = val;
	}
	else {
		printf("Stack overflow");
	}
	return 0;
}

int pop() {
	int ans;
	ans = isEmpty();
	if (ans == 0) {
		printf("\nThe pop element is\t%d", st.data[st.sp]);
		st.sp--;
	}
	else {
		//printf("\n Stack is empty");
	}
	return 0;
}

int disp() {
	int i;
	printf("\n");

	if (isEmpty() == 0) {
		printf("\n***elements of stack***");
		for (i = st.sp; i >= 0; i--)
			printf("\n%d\t", st.data[i]);
	}
	else
		printf("\nStack is empty");
	return 0;
}
*/

/*Implementation of stack data structure using liked list*/
#include<stdio.h>
#include<stdlib.h>
#define size 10
struct stack {
	int data;
	struct stack* next;
};

typedef struct stack stk;
stk* tos = NULL;
void push();
int pop();
void display();
void main() {
	int choice = 0;
	int val;
	do {
		printf("\n Menu.....");
		printf("\n 1. Push data");
		printf("\n 2. Pop data");
		printf("\n 3. Display");
		printf("\n 4. Exit");
		printf("\n Enter your choice");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			push();
			display();
			break;
		case 2:
			val = pop();
			printf("\n Pop up value=%d", val);
			printf("\n stack after pop up");
			display();
			break;
		case 3:
			display();
			break;
		case 4:
			printf("exit");
			break;
		default:
			printf("\nwrong choice");
		}
	} while (choice != 4);
}

	void push() {
		stk* node;
		node = (stk*)malloc(sizeof(stk));
		printf("\nenter data to be pushed\n");
		scanf("%d", &node->data);
		node->next = tos;
		tos = node;
	}

	int pop() {
		int val;
		stk* temp;
		temp = tos;
		if (tos == NULL) {
			printf("\n stack is empty");
			exit(0);
		}
		else {
			val = tos->data;
			tos = tos->next;
			free(temp);
		}
		return val;
}
	void display() {
		stk* temp;
		temp = tos;
		printf("\nstack elements are:\n");
		if (temp == NULL)
			printf("\nstack is empty");
		else {
			while (temp->next != NULL) {
				printf("%d\n", temp->data);
				temp = temp->next;
			}
			printf("%d", temp->data);
		}
	}

