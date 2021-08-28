/*
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node* next;
}Node, *nodePtr;

nodePtr head;
void initialize() {
	head = NULL;
}

void insertAtFront(int num) {
	nodePtr newNode = (nodePtr)malloc(sizeof(Node));
	newNode->data = num;
	newNode->next = head;
	head = newNode;
	printf("\nInsert element:%d\n", num);
}

// The variable in this function won't be changed because the arguments passed by value in C such that
// head still point to the front node

void insertAtEnd(nodePtr node, int num) {
	nodePtr newNode = (nodePtr)malloc(sizeof(Node));
	newNode->data = num;

	if (node == NULL) {
		printf("Invalid list\n");
	}
	while (node->next != NULL) {
		node = node->next;
	}
	node->next = newNode;
	newNode->next = NULL;
}


//The variable 'head' in this function will be changed from the point where it starts to be evaluated
// so that the 'head' points to the last address of the node
// All of this outcome happened because 'head' is a global variable
/*
void insertAtEnd(int num) {
	nodePtr newNode = (nodePtr)malloc(sizeof(Node));
	newNode->data = num;

	if (head == NULL) {
		printf("Invalid list\n");
	}
	while (head->next != NULL) {
		head = head->next;
	}
	head->next = newNode;
	newNode->next = NULL;
}


void deleteNode(nodePtr head, int key) {
	nodePtr prev, temp;
	temp = head;
	prev = head;
	while (temp != NULL && temp->data != key) {
		prev = temp;
		temp = temp->next;
	}
	prev->next = temp->next;
	free(temp);
}

void deletePos(nodePtr head, int item) {
	nodePtr prev, temp;
	int i = 1;
	prev = head;
	temp = head;
	while(temp != NULL && i!=item){
		i++;
		prev = temp;
		temp = temp->next;
	}
	if (i == item) {
		prev->next = temp->next;
		free(temp);
	}
}

void deleteHead(nodePtr node) {
	if (node != NULL) {
		nodePtr temp = node;
		node = node->next;
		free (temp);
	}
	
}

void printList(nodePtr node) {
	printf("\nThe whole list as below:\n");
	while (node != NULL && node!= 0xdddddddd) {
		printf("%d", node->data);
		node = node->next;
		if (node != NULL) {
			printf("-->");
		}
	}
}

int main() {
	initialize();
	insertAtFront(2);
	insertAtFront(7);
	insertAtFront(9);
	insertAtFront(6);
	printList(head);
	insertAtEnd(head,3);
	printf("\n\nAfter insertion at end:\n");
	printList(head);
	insertAtFront(4);
	printList(head);
	insertAtEnd(head,18);
	printList(head);
	deleteNode(head,2);
	printList(head);
	deletePos(head, 3);
	printList(head);
	deleteHead(head);
	printList(head);

}
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct LinkedList {
	int data;
	struct LinkedList* next;
};
typedef struct LinkedList node;
//declarations of function prototype
void AddFront(node **front, node *newnode);
int DeletePos(node **front, int pos);
int DeleteElm(node** front, int data);
void EraseList(node** front);
void ReverseList(node *front);
void AddEnd(node *front);
node* CreateList(node *front);
int GetData();
int GetChoice();
void DisplayList(node* front);

int main() {
	int start = clock();
	node* front = NULL;
	node* newnode;
	int data, pos;
	while (1) {
		switch (GetChoice()) {
		case 1: {
			data = GetData();
			newnode = (node*)malloc(sizeof(node));
			newnode->data = data;
			AddFront(&front, newnode);
			DisplayList(front);
			break;
		}
		case 2: {
			printf("\n Enter the position:");
			fflush(NULL);
			scanf("%d", &pos);
			if (DeletePos(front, pos) == 0)
				printf("\n There is no element to delete\n");
			else {
				printf("\n The Linked List after deletion is....\n");
				DisplayList(front);
			}
			break;
		}
		case 3: {
			data = GetData();
			if (DeleteElm(&front, data) == 0)
				printf("no element whose value is %d\n", data);
			else {
				printf("The Linked List after deletion is:\n");
				DisplayList(front);
			}
			break;
		}
		case 4: {
			ReverseList(&front);
			DisplayList(front);
			break;
		}
		case 5: {
			DisplayList(front);
			break;
		}
		case 6: {
			EraseList(front);
			break;
		}
		case 7: {
			node* front1 = (node*)malloc(sizeof(node));
			AddEnd(front1);
			DisplayList(front1);
		}
			  break;
		case 8: {
			node* front1=NULL;
			node *front = CreateList(front1);
			DisplayList(front);
		}
			  break;
		case 9: {
			exit(0);
		}
			  break;
		}

	}
	
}

void AddFront(node ** front, node* newnode) {
	//make new node as first node.
	newnode->next = *front;
	*front = newnode;
}

void AddEnd(node *front1) {
	int data;
	int n = 4;
	node* prev;
	prev = front1;
	node* temp = NULL;
	while (n--) {
		data = GetData();
		prev->data = data;
		temp = (node*)malloc(sizeof(node));
		prev->next = temp;
		prev = prev->next;
	}
	prev->next = NULL;
}

node* CreateList(node* front) {
	node* temp, * p;
	int data;
	printf("\nEnter data<9999 to stop>:");
	scanf("%d", &data);
	while (data != 9999) {
		//check if list is empty
		if (front == NULL) {
			front = (node*)malloc(sizeof(node));
			front->data = data;
			front->next = NULL;
		}
		else {
			temp = front;
			while (temp->next)
			temp = temp->next;

			p = (node*)malloc(sizeof(node));
			p->data = data;
			p->next = NULL;
			temp->next = p;
		}
		printf("\nEnter data<9999 to stop>:");
		scanf("%d", &data);
	}
	return front;
}
/*delete at pos. first element is 0. fn returns 0 if no element at given pos*/

int DeletePos(node* front, int pos) {
	node* cur, * prev;
	prev = front;
	//check if the node to be deleted is the fist node

	if (pos == 0) {
		cur = front;//store first node in cur for deletion later
		front = front->next;
	}
	else {
		int i = 0;
		cur = front;//store in cur which will be used for traversal
		while (i < pos && cur) {//cur!=NULL

			prev = cur;
			cur = cur->next;
			i++;
		}
		/*check if element at given pos exists*/
		if (cur) {
			prev->next = cur->next;
			free(cur);
			return 1;
		}
		else
			return 0;
	}
}
	/*DeleteElm deletes a node whose data field is given
	return 0 if no data found*/

	int DeleteElm(node **front, int data) {
		node *cur, * prev;
		cur = *front;
		prev = *front;
		while (cur && cur->data != data) {
			prev = cur;//save cur in prev
			cur = cur->next;
		}
		if (cur) {
			//check if deleted data is the first
			if (cur == *front) 
				*front = (*front)->next;
			else
				prev->next = cur->next;
			free(cur);
			return 1;
		}
		else return 0;
}

	void ReverseList(node **front) {
		node* prev, * cur, * next;
		prev = NULL;
		next = NULL;
		cur = *front;
		while (cur) {
			next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
		}
		*front = prev;
	}
	int GetChoice() {
		int choice;
		do {
			printf("\n1 Insert at beginning of the Linked List\n");
			printf("2 Delete an element at given position \n");
			printf("3 Delete an element of given data\n");
			printf("4 Display the Reversed List\n");
			printf("5 Display the Linked List\n");
			printf("6 Erase the Linked List\n");
			printf("7 Add new node at the end\n");
			printf("8 Create List\n");
			printf("9 Quit\n");

			printf("\n Enter your choice...:");
			scanf("%d", &choice);
		} while (choice<1||choice>9);
		return choice;
	}

	int GetData() {
		int data;
		printf("\n Enter data for the node: ");
		//fflush(NULL);
		scanf("%d", &data);
		return data;
}

	void DisplayList(node* front) {
		node* cur;
		cur = front;//cur for traversal
		if (!cur) 
			printf("\n the list is empty\n");
		else {
			printf("\n the list is.....\n");
			while (cur) {
				printf("%d", cur->data);
				if (cur->next)
				printf("-->");
				cur = cur->next;
			}
		}
	}

	void EraseList(node* front) {
		node* cur;
		cur = front;
		while (front) {
			front = front->next;
			free(cur);
			cur = front;
			DisplayList(front);
		}
		return;
	}
