#include<stdio.h>
#include<stdlib.h>
typedef struct Tree {
	int data;
	struct Tree* lptr;
	struct Tree* rptr;
}node;
node* createTree(node* root);
node* insert(int n, node* root);
node* delete(int n, node* root);
void search(int n, node* root);
int isLeft(node* parent, node* p);
int isRight(node* parent, node* p);

void main() {
	node* root = NULL;
	int n, n1, ch;
	while (1) {
		printf("\n\n\t\tMENU");
		printf("\n\t1.CREATE\n\t2.INSERTION\n\t3.DELETION\n\t4.SEARCH");
		printf("\n\t5.EXIT");
		printf("\n\n\tEnter your choice\t");
		scanf("%d", &ch);
		switch (ch) {
		case 1:
			root = NULL;
			root = createTree(root);
			break;
		case 2:
			printf("\nEnter Number");
			scanf("%d", &n);
			root = insert(n, root);
			break;
		case 3:
			printf("\n Enter number to be deleted");
			scanf("%d", &n1);
			root = delete(n1, root);
			break;
		case 4:
			printf("\nEnter value to be searched");
			scanf("%d", &n);
			search(n, root);
			break;
		case 5:
			exit(0);
			break;
		default:
			printf("\nInvalid choice");

		}
	}
}

node* createTree(node* root) {
	int n;
	do {
		printf("\nEnter number<0 to stop>");
		scanf("%d", &n);
		if (n)
			root = insert(n, root);
	} while (n);
	return root;
}

node* insert(int n, node* root) {
	node* temp1 = NULL;
	node* temp2 = NULL;
	node* p = NULL;
	p = (node*)malloc(sizeof(node));
	p->data = n;
	p->lptr = NULL;
	p->rptr = NULL;

	if (root == NULL)
		root = p;
	else
	{
		temp1 = root;//temp1 for traversal of tree
		while (temp1) {
			temp2 = temp1;//temp2 for storing parent
			if (p->data < temp1->data)
				temp1 = temp1->lptr;
			else if (p->data > temp1->data)
				temp1 = temp1->rptr;
			else {
				printf("\n\tDUPLICATE VALUE");
				free(p);
				break;	
			}
		}
		if (temp1 == NULL) {
			if (p->data < temp2->data)
				temp2->lptr = p;
			else
				temp2->rptr = p;
		}
		
	}
	printf("\n successful insertion\n");
	return root;
}

void search(int n, node* root) {
	node* p;
	p = root;
	while (n != p->data) {
		if (n < p->data)
			p = p->lptr;
		else
			p = p->rptr;
		if (p == NULL) {
			printf("value is not present in the tree\n");
			break;
		}
	}
	printf("\nvalue found");
}

node* delete(int n, node* root) {
	node* temp1 = NULL;
	node* temp2 = NULL;
	node* p = NULL;//p to store the deleted node
	int val;
	int ans;
	temp1 = root;
	while (n != temp1->data) {
		temp2 = temp1;
		if (n < temp1->data)
			temp1 = temp1->lptr;
		else
			temp1 = temp1->rptr;
		if (temp1 == NULL)
			break;
	}
	/*after while loop, the specific data will be found or not exist in the tree*/
	if (temp1 == NULL)
		printf("\n Value not present in the tree");
	else {
		p = temp1;
		if (p->lptr == NULL && p->rptr == NULL) {
			printf("deleteing terminal node with value:%d", p->data);
			if (temp2 == NULL)
				printf("\nDelete root which is a leaf node");
			else {
				ans = isLeft(temp2, p);
				if (ans == 0)//p is the left son
					temp2->lptr = NULL;
				ans = isRight(temp2, p);
				if (ans == 0)//p is right son
					temp2->rptr = NULL;
			}
			free(p);
		}
		else if (p->lptr == NULL || p->rptr == NULL) {
			printf("\n Delete node with one child with value %d", p->data);
			if (p->lptr != NULL) {
				if (temp2 == 0) {
					printf("\nDelete root with only left subtree");
					root = p->lptr;
				}
				else {
					ans = isLeft(temp2, p);
					if (ans == 0)//p is left son
						temp2->lptr = p->lptr;
					ans = isRight(temp2, p);
					if (ans == 0)
						temp2->rptr = p->lptr;
				}
				free(p);
			}
			else if (p->rptr != NULL) {
				if (temp2 == NULL) {
					printf("\nDelete root with only right subtree");
					root = p->rptr;
				}
				else {
					ans = isLeft(temp2, p);
					if (ans == 0);
					temp2->lptr = p->rptr;
					ans = isRight(temp2, p);
					if (ans == 0)
						temp2->rptr = p->rptr;
				}
				free(p);
			}
		}
		else if (p->lptr != NULL && p->data != NULL)
		{
			printf("\n Delete node with two children with value=%d", p->data);
			printf("\nFind minimun value in right subtree\n");
			temp1 = p->rptr;
			while (temp1->lptr)
				temp1 = temp1->lptr;
			printf("\n min value is %d", temp1->data);
			printf("\n Delete and re-adjust");
			val = temp1->data;
			delete(val, root);
			p->data = val;
		}
		printf("\n successful deletion");
	}
	return root;
}

int isLeft(node* parent, node* p) {
	int ans;
	if (parent->lptr == p)
		ans = 0;
	else
		ans = 1;
	return ans;
}

int isRight(node* parent, node* p) {
	int ans;
	if (parent->rptr == p)
		ans = 0;
	else
		ans = 1;
	return ans;
}