#include<stdio.h>
#include<stdlib.h>

struct doubleList
{
	int data;
	struct doubleList* left;
	struct doubleList* right;
};
typedef struct doubleList node;

node* createList(node* list);
node* insert(int n, int val, node* list);//insert node with data=val
node* delete(int n, node*list);
void printList(node*list);
void main() {
	int val, n;
	node* list = NULL;
	list = createList(list);
	printList(list);
	printf("\nEnter value to be inserted:");
	scanf("%d", &val);
	printf("Node after which value has to be inserted<0 for starting>");
	scanf("%d", &n);
	list = insert(n, val, list);
	printList(list);
	printf("\nEnter the value to be deleted");
	scanf("%d", &n);
	list = delete(n, list);
	printList(list);
}

node* createList(node* list) {
	int n;
	node* p, * temp;
	do {
		printf("Enter value<0 to stop>");
		scanf("%d", &n);
		if (n) {
			p = (node*)malloc(sizeof(node));
			p->data = n;
			if (list == NULL) {
				list = p;
				p->left = NULL;
				p->right = NULL;
			}
			else {
				temp = list;
				while (temp->left)
					temp = temp->left;
				temp->left = p;
				p->right = temp;
				p->left = NULL;
			}
		}
	} while (n);
	return list;
}

node* insert(int n, int val, node* list) {
	node* p, * temp;
	temp = list;
	p = (node*)malloc(sizeof(node));
	p->data = val;
	if (!n) {
		p->right = NULL;
		p->left = list;
		list->right = p;
		list = p;
	}
	else {
		while (temp->data != n && temp->left != NULL)
			temp = temp->left;
			if (temp->data != n) {
				printf("node does not exist in list\n");
				exit(1);
		}
			else {
				p->left = temp->left;
				temp->left = p;
				p->right = temp;
				if (p->left)
					(p->left)->right = p;
			}
	return list;
	}
}
node* delete(int n, node* list) {
	node* temp = list;
	while (temp->data != n && temp->left != NULL)
		temp = temp->left;
	if (temp->data != n) {
		printf("node does not exist in list\n");
		exit(1);
		}
	else {
		//case 1:delete the starting node
		if (temp->right == NULL) {
			list = list->left;//or list=temp->left
			list->right = NULL;
			free(temp);
		}
		//case 2: node is general node with left and right node
		else {
			(temp->right)->left = temp->left;
			if(temp->left)
				(temp->left)->right = temp->right;
			free(temp);
		}
	}
	return list;
}

void printList(node* list) {
	node* temp = list;
	printf("\nList:\n");
	if (list == NULL)
	{
		printf("Empty list\n");
		exit(1);
	}
	else
	{
		while (temp) {
			printf("%d<-->",temp->data);
			temp = temp->left;
		}
	}
}

