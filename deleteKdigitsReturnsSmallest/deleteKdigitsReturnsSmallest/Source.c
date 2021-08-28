/*
#include<stdio.h>
#define MAX 100
void push(char n);
char pop();
int tos = -1;
char a[MAX];
void main() {
	char data[MAX];
	int m = 0;
	int i = 1;
	int k = 0;
	printf("please enter the string data:\n");
	scanf("%s", data);
	while (data[m] != '\0')
		m++;
	printf("The total numbers of string digits are: %d\n", m);
	printf("please enter the No. of items to be deleted\n");
	int K;
	scanf("%d", &K);
	if (K == m) {
		printf("%d", 0);
	}
	else {
		push(data[0]);
		while (k < K && i < m) {
			if (data[i] >= a[tos])
				push(data[i++]);
			else {
				pop();
				k++;
				push(data[i++]);
			}
		}
		if (k < K) {
			int j = K - k;
			while (j--)
				pop();
		}
		if (i < m) {
			int j = m - i;
			while (j--)
				push(data[i++]);
		}

		int s = 0;
		int r = 0;
		int j = 0;

		while (!r) {
			int d = a[j] - '0';
			j++;
			r = r || d;
		}
		s = j - 1;

		for (; s <m - K; s++) //or s<=tos;
			printf("%c", a[s]);
	}
}

void push(char n) {
	tos++;
	if (tos == MAX - 1)
		printf("stack is full\n");
	else 
		a[tos] = n;
}

char pop() {
	tos--;
	if (tos == -1) {
		printf("stack is empty\n");
	}
}
*/
/*
#include<stdio.h>
#define MAX 100
void push(char n);
void pop();
int tos = -1;
char a[MAX];
char* removeKdigits(char*, int);
void main() {
	char *num = "10";
	//char* num = "1432219";
	char*t=removeKdigits(num, 2);
}
char* removeKdigits(char* num, int k) {
	char tempChar[MAX];
	char data[MAX];
	char* temp;
	temp = num;
	int m = 0;
	int i = 1;
	int kn = 0;
	while (*num++ != '\0')
		m++;
	for (int i = 0; i < m; i++)
		data[i] = *temp++;
	data[m] = '\0';
	int K = k;
	if (K == m) {
		printf("%d", 0);
		tempChar[0] = "0";
	}
	else {
		push(data[0]);
		while (kn < K && i < m) {
			if (data[i] >= a[tos])
				push(data[i++]);
			else {
				pop();
				kn++;
				push(data[i++]);
			}
		}
		if (kn < K) {
			int j = K - kn;
			while (j--)
				pop();
		}
		if (i < m) {
			int j = m - i;
			while (j--)
				push(data[i++]);
		}

		int s = 0;
		int r = 0;
		int j = 0;

		while (!r&&j<m-K) {
			int d = a[j] - '0';
			r = r || d;
			j++;
		}
		s = j - 1;
		int t = s;
		for (; s < m - K; s++) {
			printf("%c", a[s]);
			tempChar[s-t] = a[s];
		}
	}
	return tempChar;
}

	void push(char n) {
		tos++;
		if (tos == MAX - 1)
			return;
		else
			a[tos] = n;
	}

	void pop() {
		tos--;
		if (tos == -1)
			return;
	}
*/

/*Leetcode
#define MAX 100000
	int tos = -1;
	int a[MAX];
	char tempChar[MAX];
	char data[MAX];
	char* temp;
	int m = 0;
	int i = 1;
	int kn = 0;

	char* removeKdigits(char* num, int k) {
		temp = num;
		while (*num++ != '\0')
			m++;
		for (int i = 0; i < m; i++)
			data[i] = *temp++;
		int K = k;
		if (K == m) {
			tempChar[0] = '0';
		}
		else {
			push(data[0]);
			while (kn < K && i < m) {
				if (data[i] >= a[tos])
					push(data[i++]);
				else {
					pop();
					kn++;
					push(data[i++]);
				}
			}
			if (kn < K) {
				int j = K - kn;
				while (j--)
					pop();
			}
			if (i < m) {
				int j = m - i;
				while (j--)
					push(data[i++]);
			}

			int s = 0;
			int r = 0;
			int j = 0;

			while (!r && j < m - K) {
				int d = a[j] - '0';
				r = r || d;
				j++;
			}
			s = j - 1;
			int t = s;
			for (; s < m - K; s++) {
				printf("%c", a[s]);
				tempChar[s - t] = a[s];
			}
		}
		return tempChar;
	}

	void push(char n) {
		tos++;
		if (tos == MAX - 1)
			return;
		else
			a[tos] = n;
	}

	void pop() {
		tos--;
		if (tos == -1)
			return;
	}
	*/
#include <stdio.h>
#include <string.h>

char* removeKdigits(char* num, int k) {
	for (int i = 0, j; i < k; ++i) {
		/* find j, the index of the end of the nondecreasing sequence */
		for (j = 0; num[j + 1]; ++j)
			if (num[j] > num[j + 1])
				break;

		/* remove the digit at j, handling leading zeros if necessary */
		if (j == 0)
			while (*++num == '0');
		else {
			memmove(num + 1, num, j);
			++num;
		}

		/* return "0" early if all digits were removed */
		if (!num[0])
			return num[-1] = '0', num - 1;
	}
	return num;
}
void main() {
	char* num = "1432219";
	char *t=removeKdigits(num, 3);
}