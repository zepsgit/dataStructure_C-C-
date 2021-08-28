/*
#include<stdio.h>
#include<string.h>
#define MAX 10
typedef struct stack {
	char s[MAX];
	int top;
}stk;
stk stk1;
void push(char item) {
	if (stk1.top == MAX - 1)
		printf("Stack is full\n");
	else {
		stk1.top++;
		stk1.s[stk1.top] = item;
	}

}

void pop() {
	if (stk1.top == -1)
		printf("Stack is empty\n");
	else{
		
		stk1.top--;
	}
}

int main() {
	char exp[MAX];
	int i = 0;
	stk1.top=-1;
	printf("Please enter the expression\n");
	scanf("%s", exp);
	for (i = 0; i < strlen(exp); i++) {
		if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
			push(exp[i]);
			continue;
		}
		else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
			if (exp[i] == ')') {
				if (stk1.s[stk1.top] == '(') {
					pop();
				}
				else 
					printf("Unbalanced expression\n");
				break;
				
			}

			if (exp[i] == ']') {
				if (stk1.s[stk1.top] == '[') {
					pop();
				}
				else
					printf("Unbalanced expression\n");
				break;

			}

			if (exp[i] == '}') {
				if (stk1.s[stk1.top] == '{') {
					pop();
				}
				else
					printf("Unbalanced expression\n");
				break;

			}
				
		}
		if (stk1.top == -1)
			printf("unbalanced expression\n");
	}
}
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20

struct stack
{
	char stk[MAX];
	int top;
}s;

void push(char item)
{
	if (s.top == (MAX - 1))
		printf("Stack is Full\n");
	else
	{
		s.top = s.top + 1; // Push the char and increment top
		s.stk[s.top] = item;
	}
}

void pop()
{
	if (s.top == -1)
	{
		printf("Stack is Empty\n");
	}
	else
	{
		s.top = s.top - 1; // Pop the char and decrement top
	}
}

int main()
{
	
	char exp[MAX];
	int i = 0;
	s.top = -1;
	printf("\nINPUT THE EXPRESSION : ");
	scanf("%s", exp);
	for (i = 0; i < strlen(exp); i++)
	{
		if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
		{
			push(exp[i]); // Push the open bracket
			continue;
		}
		else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') // If a closed bracket is encountered
		{
			if (exp[i] == ')')
			{
				if (s.stk[s.top] == '(')
				{
					pop(); // Pop the stack until closed bracket is found
				}
				else
				{
					printf("\nUNBALANCED EXPRESSION\n");
					break;
				}
			}
			if (exp[i] == ']')
			{
				if (s.stk[s.top] == '[')
				{
					pop(); // Pop the stack until closed bracket is found
				}
				else
				{
					printf("\nUNBALANCED EXPRESSION\n");
					break;
				}
			}
			if (exp[i] == '}')
			{
				if (s.stk[s.top] == '{')
				{
					pop(); // Pop the stack until closed bracket is found
				}
				else
				{
					printf("\nUNBALANCED EXPRESSION\n");
					break;
				}
			}
		}
	}
	if (s.top == -1)
	{
		printf("\nBALANCED EXPRESSION\n"); // Finally if the stack is empty, display that the expression is balanced
	}
}

