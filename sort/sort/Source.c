
/*
#include<stdio.h>

void quickSort(int lo, int hi, int list[30]) {
	int i;
	int pivot = hi;
	int j = lo - 1;//the index of smaller elements
	while (lo < hi)
	{
		for (i = lo; i < hi; i++) {
			if (list[i] <= list[pivot]) {
				j++;
				//swap(list[i], list[j]);
				int temp = list[i];
				list[i] = list[pivot];
				list[pivot] = temp;
			}

		}
		//swap(list[i + 1], list[pivot]);
		int temp = list[i + 1];
		list[i + 1] = list[pivot];
		list[pivot] = temp;

		quickSort(lo, i, list);
		quickSort(i + 2, hi, list);
	}
}


int main() {
	printf("Please enter the number of elements:\n");
	int count;
	int list[30];
	scanf("%d",&count);
	printf("Please enter the elements:\n");
	for (int counter = 0; counter < count; counter++) 
		scanf("%d",&list[counter]);
	
	for (int i = 0; i < count; i++)
		printf("%d ",list[i]);

	quickSort(0, count-1, list);
	printf("the sorted elements are:\n");
	for (int i = 0; i < count; i++)
		printf("%d ", list[i]);

}

*/
/*
#include<stdio.h>

swap(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}

int partition(int arr[30], int low, int high)
{
	// pivot (Element to be placed at right position)
	int pivot = arr[high];

	int i = (low - 1);  // Index of smaller element and indicates the 
				   // right position of pivot found so far

		for (int j = low; j <= high - 1; j++)
		{
			// If current element is smaller than the pivot
			if (arr[j] < pivot)
			{
				i++;    // increment index of smaller element
				swap(arr[i], arr[j]);
			}
		}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

quickSort(int arr[30], int low, int high)
{
	if (low < high)
	{
		//pi is partitioning index, arr[pi] is now
		   //at right place 
		int pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);  // Before pi
		quickSort(arr, pi + 1, high); // After pi
	}
}

int main() {
	printf("Please enter the number of elements:\n");
	int count;
	int list[30];
	scanf("%d", &count);
	printf("Please enter the elements:\n");
	for (int counter = 0; counter < count; counter++)
		scanf("%d", &list[counter]);

	for (int i = 0; i < count; i++)
		printf("%d ", list[i]);

	quickSort(list, 0, count - 1);
	printf("the sorted elements are:\n");
	for (int i = 0; i < count; i++)
		printf("%d ", list[i]);
}
*/

//quick sort another way


/*
#include<stdio.h>
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void quickSort(int arr[], int low, int high) {
	int value1 = low;
	int value2 = high;
	if(low < high) {

		while (value1 < value2) {
			
			while (arr[value1] <= arr[low] && value1 <= high) {
				value1++;
			}

			while (arr[value2] > arr[low] && value2 >= low) {
				value2--;
			}

			if (value1 < value2)
				swap(&arr[value1], &arr[value2]);
		}
		printf("\nvalue1:\n");
		printf("%d ", value1);
		printf("value2:\n");
		printf("%d ", value2);

		swap(&arr[value2], &arr[low]);
		int pivot = value2;
		quickSort(arr, low, pivot - 1);
		quickSort(arr, pivot + 1, high);

	}
}

int main() {

	printf("Please enter the number of elements:\n");
	int count;
	int list[30];
	scanf("%d", &count);
	printf("Please enter the elements:\n");
	for (int counter = 0; counter < count; counter++)
		scanf("%d", &list[counter]);

	for (int i = 0; i < count; i++)
		printf("%d ", list[i]);

	quickSort(list, 0, count - 1);
	
	printf("\nthe sorted elements are:\n");
	for (int i = 0; i < count; i++)
		printf("%d ", list[i]);
}



/*
#include<stdio.h>
#define MAXLEN 100
int getLen(char Line[]);
void copyLine(char to[], char from[]);

int main() {
	int max = 0;
	int len;
	char line[MAXLEN];
	char longest[MAXLEN];
	while (len=getLen(line) > 0) {
		if (len > max)
			max = len;
			copyLine(longest, line);
	}
	printf("getlen is:%d\n", max);

	printf("the longest line is:%s", longest);
}
int getLen(char Line[MAXLEN]) {
	int ch;
	int i;
	for (i = 0; i < MAXLEN && (ch = getchar()) != '\n' && ch!=EOF; i++) {
		Line[i] = ch;
	}
	if (ch == '\n') {
		Line[i] = ch;
		Line[i + 1] = '\0';
		return i;
	}
	if (ch == EOF)
		return EOF;
	
}

void copyLine(char to[MAXLEN], char from[MAXLEN]) {
	for (int i = 0; from[i]!='\0'; i++)
		to[i] = from[i];
}
*/

/*
#include<stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
void copy(char to[], char from[]);

main() {
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;
	while ((len = getline(line, MAXLINE)) > 0) {
		if (len > max)
			max = len;
		copy(longest, line);
		len = getline(line, MAXLINE);
	}
	if (max > 0)
		printf("%s", longest);
	return 0;
}

int getline(char s[], int lim) {
	char c;
	int i;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (s == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

void copy(char to[], char from[]) {
	int i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
*/
/*
#include<stdio.h>
#define MAXLEN 50
int getLine(char line[]);
int searchIndex(char line[], char pattern[]);
void copy(char to[], char[]);
int main() {
	int found = 0;
	char pattern[] = "ould";
	char line[MAXLEN];
	int max = 0;
	char longest[MAXLEN];
	
	while (getLine(line)>0) {
		if (searchIndex(line, pattern) >= 0) {
			printf("%s\n", line);
			found++;
			printf("found:%d\n", found);
		}
		if (getLine(line) > max) {
			max = getLine(line);
			copy(longest, line);
			printf("%s", longest);
		}
	}
	return found;
}

int getLine(char line[]) {
	int i = MAXLEN;
	int j = 0;
	int ch;
	while (i-- >0 && (ch = getchar()) != EOF && ch != '\n')
		line[j++] = ch;
	if (ch == '\n')
		line[j++] = ch;
	line[j] = '\0';
	return j;
}

int searchIndex(char line[], char pattern[]) {
	int i, j, k;
	for (i = 0; line[i] != '\0'; i++) {
		for (j = i, k = 0; pattern[k] != '\0' && pattern[k] == line[j]; j++, k++);
		if (k > 0 && pattern[k] == '\0')
			return j;
	}
	return -1;
}

void copy(char to[], char from[]) {
	int i = 0;
	while ((to[i] = from[i]) != '\0')
		i++;
		//to[i] = '\0';
}
*/

/*
#include <stdio.h>

int main(int argc, char* argv[]) {

	if (argc == 2) {
		printf("The argument supplied is %s\n", argv[1]);
	}
	else if (argc > 2) {
		printf("Too many arguments supplied.\n");
	}
	else {
		printf("One argument expected.\n");
	}
}
*/

#include<stdio.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* dailyTemperatures(int* T, int TSize, int* returnSize) {
	
	for (int i = 0; i < TSize; i++) {
		int j = i+1;
		while (*(T + i) >= *(T + j) && j < TSize) {
			j++;
		}
		if (j == TSize)
			*(returnSize++) = 0;
		else
			*(returnSize++) = j-i;

	}
	return returnSize;
}

int main() {
	int num;
	int* listP;
	int list[] = {0};
	printf("Please enter the number of days:\n");
	scanf("%d",&num);
	printf("Please enter the daily temperature between 30 to 100:\n");
	for (int i = 0; i < num; i++)
		scanf("%d", &list[i]);
	
	int returnSize[] = {0};
	int* r = returnSize;
	dailyTemperatures(list, num, r);
	for(int i=0; i<num; i++)
	printf("%d ", *(r++));
}

struct {
	int a;
	int b;
} Boook;

struct Boook book;