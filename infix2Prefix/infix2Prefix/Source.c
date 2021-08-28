#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char stk[30];
int tos=-1;

int precede(char c) {
	int n;
	if (c == '^')
		n = 3;
	else if (c == '*' || c == '/')
		n = 2;
	else if (c == '+' || c=='-')
		n = 1;
	else
		n = 0;
	return n;
}
void push(char c) {
	tos++;
	stk[tos] = c;
}
char pop() {
	char c;
	c = stk[tos];
	tos--;
	return c;
}

void rInfix(char* p) {
	char* frontAdd = p;
	while (*p != '\0')
		p++;
	char* endAdd = p - 1;
	while (endAdd > frontAdd) {
		char temp;
		temp = *frontAdd;
		*frontAdd = *endAdd;
		*endAdd = temp;
		endAdd--;
		frontAdd++;
	}
}
int main() {
	char infix[30];
	char prefix[30];
	printf("please enter the infix:\n");
	scanf("%s", infix);
	rInfix(infix);
	printf("Reverse infix:\n");
	printf("%s", infix);
	int i, j = 0, u, v;
	for (i = 0; i < strlen(infix); i++) {
		if ((infix[i]>='a'&&infix[i]<='z')||(infix[i]>='A'&&infix[i]<='Z')|| (infix[i] >= '0' && infix[i] <= '9')) {
			prefix[j] = infix[i];
			j++;
		}
		else if (infix[i]=='^'||infix[i]=='*'||infix[i]=='/'||infix[i]=='+'||infix[i]=='-') {
			u = precede(infix[i]);
			v = precede(stk[tos]);
			while (u < v) {
				prefix[j] = pop();
				j++;
				v = precede(stk[tos]);
			}
			push(infix[i]);
		}
		else if (infix[i] == ')')
			push(infix[i]);
		else if (infix[i] == '(') {
			char c = pop();
			while (c != ')') {
				prefix[j] = c;
				j++;
				c = pop();
			}
		}
		else {
			printf("\nERROR\n");
			exit(0);
		}
	}
	while (tos != -1) {
		prefix[j] = pop();
		j++;
	}
	prefix[j] = '\0';
	printf("\nPrefix before reverse:%s\n", prefix);
	rInfix(prefix);
	printf("\nThe PREFIX is:%s\n",prefix);
}