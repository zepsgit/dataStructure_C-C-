#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int data;
	struct node* left;
	struct node* right;
}node;

node* create(node* root);
void preOrder(node* root);
void inOrder(node* root);
void postOrder(node* root);

node* create(root) {
	int data;
	node* temp;
	node* parent=0;
	do {
	node* p = (node*)malloc(sizeof(node));
	

	printf("\nplease enter the data<0 to stop>:\n");
	
		scanf("%d", &data);
		if (data == 0)
			break;
		p->data = data;
		p->left = NULL;
		p->right = NULL;
		if (root == NULL) {
			root = p;
			printf("root ready\n");
			
		}
			
		else {
			temp = root;
			while (temp) {
				parent = temp;
				if (p->data < temp->data) {
					temp = temp->left;
					printf("%d ", p->data);
					printf("temp to left\n");
				}
				else if (p->data > temp->data) {
					temp = temp->right;
					printf("temp %d to right\n ", p->data);
				}
				else {
					printf("Duplicate value %d\n",temp->data);
					free(p);
					break;
				}

			}
			//jump out of while means temp==NULL
			if (temp == NULL) {
				if (p->data < parent->data) {
					parent->left = p;
					printf("new node to the left\n");
				}
				else if (p->data > parent->data) {
					parent->right = p;
					printf("newnode to the right\n");
				}
				else
					printf("Duplicate value2\n");
			}
		}	
	} while (1);
	return root;
}

void preOrder(node* root) {
	if (root == NULL)
		return;
	printf("%d ", root->data);
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(node* root) {
	if (root == NULL)
		return;
	inOrder(root->left);
	printf("%d ", root->data);
	inOrder(root->right);
}

void postOrder(node* root) {
	if (root == NULL)
		return;
	postOrder(root->left);
	postOrder(root->right);
	printf("%d ", root->data);
}

void main() {
	node* root = NULL;
	int ch;
	do {
		printf("\n1.CREATE\n");
		printf("2.PREORDER\n");
		printf("3.INORDER\n");
		printf("4.POSTORDER\n");
		printf("5.EXIT\n");
		printf("\nEnter your choice:\n");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			root = create(root);
			break;
		case 2:
			preOrder(root);
			break;
		case 3:
			inOrder(root);
			break;
		case 4:
			postOrder(root);
			break;
		case 5:
			exit(0);
		default:
			printf("wrong choice\n");
			break;
		}

	} while (ch != 5);
}