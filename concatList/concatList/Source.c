
#include<stdio.h>
#include<stdlib.h>
struct linkedList {
	int data;
	struct linkedList* next;
};
typedef struct linkedList node;
node* head;
node* createList(node* front);
node* concatList(node* front1, node* front2);
void sortList();
void printList(node* front);
void main() {
	node* front1 = NULL;
	node* front2 = NULL;
	node* front3 = NULL;
	printf("create first list......\n");
	front1 = createList(front1);
	printList(front1);
	printf("\ncreate the second list......\n");
	front2 = createList(front2);
	printList(front2);
	printf("\nconcat list:\n");
	front1 = concatList(front1, front2);
	printList(front1);
	printf("\nafter sorting:\n");
	head = createList(head);
	sortList();
	//printf("\nafter sorting:\n");
	printList(head);
}
node* createList(node* front) {
	node* temp, * p;
	int dat;
	printf("\nenter data<0 to stop>");
	scanf("%d", &dat);
	while (dat) {
		if (front == NULL) {
			front = (node*)malloc(sizeof(node));
			front->data = dat;
			front->next = NULL;
		}
		else {
			temp = front;
			while (temp->next)
				temp = temp->next;
			p = (node*)malloc(sizeof(node));
			p->data = dat;
			p->next = NULL;
			temp->next = p;
		}
		printf("\nenter data<0 to stop>");
		scanf("%d", &dat);
	}
	return front;
}

node* concatList(node* front1, node* front2) {
	node* temp = front1;
	while (temp->next)
		temp = temp->next;
	temp->next = front2;
	return front1;
}

void printList(node* front) {
	node* temp = front;
	while (temp) {
		printf("%d-->", temp->data);
		temp = temp->next;
	}
}


void sortList() {
    //Node current will point to head  
    struct node* current = head, * index = NULL;
    int temp;

    if (head == NULL) {
        return;
    }
    else {
        while (current != NULL) {
            //Node index will point to node next to current  
            index = current->next;

            while (index != NULL) {
                //If current node's data is greater than index's node data, swap the data between them  
                if (current->data > index->data) {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}

/*
void sortList(node* front) {
	//selection sort
	node* cur;
	node* index;
	cur = front;
	index = NULL;
	int temp;
	if (front == NULL)
		return;
	else {
		while (cur!=NULL) {
			index = cur->next;
			while (index!=NULL) {
				if (cur->data > index->data) {
					temp = cur->data;
					cur->data = index->data;
					index->data = temp;
				}
				index = cur->next;
			}
			cur = cur->next;
		}
	}
}
*/

/*
#include <stdio.h>  
#include <stdlib.h>
//Represent a node of the singly linked list  
struct node{
	int data;
    struct node* next;
};

//Represent the head and tail of the singly linked list  
struct node* head, * tail = NULL;

//addNode() will add a new node to the list  
void addNode(int data) {
    //Create a new node  
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    //Checks if the list is empty  
    if (head == NULL) {
        //If list is empty, both head and tail will point to new node  
        head = newNode;
        tail = newNode;
    }
    else {
        //newNode will be added after tail such that tail's next will point to newNode  
        tail->next = newNode;
        //newNode will become new tail of the list  
        tail = newNode;
    }
}

//sortList() will sort nodes of the list in ascending order  
void sortList() {
    //Node current will point to head  
    struct node* current = head, * index = NULL;
    int temp;

    if (head == NULL) {
        return;
    }
    else {
        while (current != NULL) {
            //Node index will point to node next to current  
            index = current->next;

            while (index != NULL) {
                //If current node's data is greater than index's node data, swap the data between them  
                if (current->data > index->data) {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}

//display() will display all the nodes present in the list  
void display() {
    //Node current will point to head  
    struct node* current = head;
    if (head == NULL) {
        printf("List is empty \n");
        return;
    }
    while (current != NULL) {
        //Prints each node by incrementing pointer  
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    //Adds data to the list  
    addNode(9);
    addNode(7);
    addNode(2);
    addNode(5);
    addNode(4);

    //Displaying original list  
    printf("Original list: \n");
    display();

    //Sorting list  
    sortList();

    //Displaying sorted list  
    printf("Sorted list: \n");
    display();

    return 0;
}
*/