#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int preceed(char c);
void push(char c);
char pop();
char stk[30];
int tos = -1;

void main() {
	int i, j = 0, n, u, v;
	char infix[30], postfix[30];
	char c;
	printf("\n enter the infix expression:");
	scanf("%s", infix);
	n = strlen(infix);
	for (i = 0; i < n; i++) {
		if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z')) {
			postfix[j] = infix[i];
			j++;
		}
		else if (infix[i] == '^' || infix[i] == '*' || infix[i] == '/' || infix[i] == '+' || infix[i] == '-') {
			//before push the operator onto the stack, check the precedence first
			u = preceed(stk[tos]);
			v = preceed(infix[i]);
			while (u >= v) {
				postfix[j]=pop();
				j++;
				u = preceed(stk[tos]);
			}
			push(infix[i]);
		}
		else if (infix[i] == '(') {
			push(infix[i]);
		}
		else if (infix[i] == ')') {
			char c = pop();
			while (c != '(') {
				postfix[j] = c;
				j++;
				c = pop();
			}
		}
		else {
			printf("The expression has an ERROR\n");
			exit(0);
		}
	}
	while (tos != -1) {
		postfix[j] = pop();
		j++;
	}
	postfix[j] = '\0';
	printf("The infix is:%s\n", infix);
	printf("The POSTFIX is:%s\n", postfix);
}

int preceed(char c) {
	int v;
	switch (c) {
	case '^':
		v = 3;
		break;
	case'*':
	case'/':
		v = 2;
		break;
	case'+':
	case'-':
		v = 1;
		break;
	default:
		v = 0;
		break;
	}
	return v;
}

void push(char c) {
	tos++;
	stk[tos] = c;
}

char pop() {
	char val;
	val = stk[tos];
	tos--;
	return val;
}