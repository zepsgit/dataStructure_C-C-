/*
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 7
//void quicksort_method(int[], int, int);
int main() {
	/*
	//find the highest common factor

	int x, y;
	printf("please enter {x, y}:\n");
	scanf_s("%d %d", &x, &y);
	while (x * y) {
		if (x >= y) {
			x -= y;
		}
		else if (x < y) {
			y -= x;
		}
	}
	printf("The highest common factor is: %d\n", x > y ? x:y);
	return(0);

#define INPUT_NUM 4
	float num;
	int n = INPUT_NUM;
	float min = 0;
	float sum = 0;
	printf("please enter a number:\n");
	while (n--) {
		scanf_s("%f", &num);
		min = num;
		if (num < min)
			min = num;
		sum = sum + num;
	}
	printf("The min number is %lf\n The sum of all the input is:%lf", min, sum);
	return(0);
	*/

	/**
	int n = 0, sum = 0, num;
	FILE* in = fopen("D:\\TestData\\text.txt", "r");
	FILE* out = fopen("D:\\TestData\\output.txt", "w");
	fprintf(out, "The number copied from text.txt are:\n");
	fscanf(in, "%d", &num);
	while (num != 0) {

		fprintf(out, "%d ",num);

		n += 1;
		sum = sum + num;
		fscanf(in, "%d", &num);
	}
	if (n == 0) {
	printf("None number is supplied");
	fclose(in);
	fclose(out);
}
	else {
		printf("%d numbers has been supplied\n", n);
		printf("The average of these numbers is:%f\n", (float)sum / n);
		fclose(in);
		fclose(out);
	}

	*/

	/*
	FILE* in = fopen("D:\\TestData\\paydata.txt","r");
	FILE* out = fopen("D:\\TestData\\payroll.txt","w");
	char firstName[20];
	char lastName[20];
	char highestPaymentWinner[20];
	int hours;
	int n = 0;
	float highestPayment = 0;
	float rate;
	float payment;
	float grossPayment = 0;
	fprintf(out, "%-21s %s   %s     %s\n", "NAME", "HOURS", "RATE", "PAYMENT\n-------------------------------------------------------------------\n");

	fscanf(in,"%s",firstName);
	while (strcmp(firstName,"END") != 0) {
		n++;
		fscanf(in,"%s %d %f",lastName,&hours,&rate);
		payment = hours * rate;
		grossPayment = grossPayment + payment;
		if (highestPayment <= payment) {
			highestPayment = payment;
			strcpy(highestPaymentWinner,lastName);
		}
		fprintf(out, "%-10s %-10s %d      %4.2f   %7.2f\n", firstName, lastName, hours, rate, payment);
		fscanf(in, "%s", firstName);
	}
	fprintf(out,"\n-------------------------------------------------------------------\n");
	fprintf(out, "The number of employee is:%d\nThe highest payment winner is:%s\nThe gross payment is:%f",n,highestPaymentWinner,grossPayment);

	fclose(out);
	fclose(in);

	int numChar = 0;
	char ch;
	int numBlank = 0;
	printf("Please type some data and then press Enter\n");
	while ((ch = getchar()) != '\n') {
		numChar++;
		if(ch==' ')
			numBlank++;
	}

	printf("The number of characters on a line is:%d\n The number of blanks is:%d\n",numChar,numBlank);


char ch;
FILE* out = fopen("D:\\TestData\\output.txt","w");
FILE* in = fopen("D:\\TestData\\text.txt","r");
while ((ch = getc(in)) != EOF) {
	putchar(ch);
	putc(ch, out);
}
putchar('\n');

*/
/*
	printf("please type some numbers ending up with 0 \n");
	int n, i=0, k = 0;
	int num[10];

	scanf("%d", &n);
	while (n != 0) {
		num[i++] = n;
		scanf("%d", &n);
	}
	*/
	/*
	//selection sort
	for (int i = 0; i <= 5; i++) {
		for (int j = i + 1; j <= 5; j++) {
			if (num[j] < num[i])
			{
				int temp = num[i];
				num[i] = num[j];
				num[j] = temp;
			}
		}
		printf("%d ", num[i]);

	*/

	//bubble sort
/*
	int lenOf= sizeof(num) / sizeof(num[0]);
	for (int i = 0; i < lenOf; i++) {
		for (int j = 0; j < lenOf - 1; j++) {
			if (num[j] > num[j + 1]) {
				int temp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = temp;
			}
		}
	}
	while(k<lenOf)
	printf("%d ",num[k++]);
	*/

	//void quicksort_method(int[], int, int);
	/*
		int element_list[50], count, counter;
		printf("Please enter the total count of the elements that you want to sort: ");
		scanf("%d", &count);
		printf("Please input the elements that has to be sorted:\n");
		for (counter = 0; counter < count; counter++)
		{
			scanf("%d", &element_list[counter]);
		}
		quicksort_method(element_list, 0, count - 1);
		printf("Output generated after using quick sort\n");
		for (counter = 0; counter < count; counter++)
		{
			printf("%d ", element_list[counter]);
		}
		printf("\n");
		return 0;
	}
	void quicksort_method(int element_list[], int low, int high)
	{
		int pivot, value1, value2, temp;
		if (low < high)
		{
			pivot = low;
			value1 = low;
			value2 = high;
			while (value1 < value2)
			{
				while (element_list[value1] <= element_list[pivot] && value1 <= high)
				{
					value1++;
				}
				while (element_list[value2] > element_list[pivot] && value2 >= low)
				{
					value2--;
				}
				if (value1 < value2)
				{
					temp = element_list[value1];
					element_list[value1] = element_list[value2];
					element_list[value2] = temp;
				}
			}
			temp = element_list[value2];
			element_list[value2] = element_list[pivot];
			element_list[pivot] = temp;
			quicksort_method(element_list, low, value2 - 1);
			quicksort_method(element_list, value2 + 1, high);
		}
	*/

	/*
		int count=0;
		int arr[50];
		int swap(int, int);

		printf("please enter the number of elements:\n");
		scanf("%d",&count);
		printf("Please enter the elements:\n");
		for (int n = 0; n < count; n++) {
			scanf("%d", &arr[n]);
		}

		for (int i = 1; i < count; i++) {

			while (i && (arr[i - 1] > arr[i]))
			{
				int temp = arr[i-1];
				arr[i - 1] = arr[i];
				arr[i] = temp;


				i--;
			}
		}
		for(int k=0;k<count;k++)
		printf("%d ", arr[k]);
		*/
		/*
			void insertSortForString(int lo, int hi, char list[][30]);
			int lo = 3, hi = 6;
			char list[8][30] = {
				"Samlal, Rawle",
				"Williams, Mark",
				"Delwin, Mac",
				"Taylor, Victor",
				"Mohamed, Abu",
				"Singh, Krishna",
				"Tawari, Tau",
				"Abdool, Zaid"
			};

			int id[] = {
				1,
				2,
				3,
				4,
				5,
				6,
				7,
				8
			};
			insertSortForString(0, 7, list,id);
			insertSortForString(lo, hi, list,id);
		}
		void insertSortForString(int lo, int hi, char list[][30], int id[10]) {

			for (int h = lo + 1; h <= hi; h++) {
				while ((h - 1 >= lo) && strcmp(list[h - 1], list[h]) > 0) {
					char temp[30];

					strcpy(temp, list[h - 1]);
					strcpy(list[h - 1], list[h]);
					strcpy(list[h], temp);

					int t = id[h-1];
					id[h - 1] = id[h];
					id[h] = t;

					h--;
				}
			}
			for (int i = lo; i <= hi; i++) {
				printf("%-18s   %d\n", list[i],id[i]);

			}
			printf("\n\n");
		}
		*/

		/*
				//quicksort
		printf("please enter the number of elements:\n");
		int count;
		scanf("%d",&count);
		printf("please enter the elements:\n");
		int _list[20];
		for (int counter = 0; counter < count; counter++) {
			scanf("%d",&_list[counter]);
		}

		void quickSort(int,int,int list[]);
		quickSort(0,count-1,_list[20]);
		for (int counter = 0; counter < count; counter++) {
			printf("%d",_list[counter]);
		}
		}
		void quickSort(int low, int high, int list[20]) {
			int value1, value2, pivot;
			if (low < high) {

				value1 = low;
				value2 = high;
				pivot = high;
				void swap(int, int);
				while (value1 < value2) {
					while (list[value1] <= list[pivot] && value1 <= high) {
						value1++;
					}
					while (list[value2] >= list[pivot] && value2 >= low) {
						value2--;
					}
					if (value1 < value2)
						swap(list[value1], list[value2]);
				}
			}
			swap(list[value2],list[pivot]);
			quickSort(low,value2-1,list[20]);
			quickSort(value2+1,high,list[20]);
		}

		void swap(int a, int b) {
			int temp = a;
			a = b;
			b = temp;
		}
		
void quicksort_method(int, int, int list[]);
	printf("please enter the number of elements:\n");
	int count;
	scanf("%d", &count);
	printf("please enter the elements:\n");
	int _list[20];
	for (int counter = 0; counter < count; counter++) {
		scanf("%d", &_list[counter]);
	}

	
	quicksort_method(_list[20],0, count - 1);
	for (int counter = 0; counter < count; counter++) {
		printf("%d", _list[counter]);
	}
}
	void quicksort_method(int element_list[], int low, int high)
	{
		int pivot, value1, value2, temp;
		if (low < high)
		{
			pivot = low;
			value1 = low;
			value2 = high;
			while (value1 < value2)
			{
				while (element_list[value1] <= element_list[pivot] && value1 <= high)
				{
					value1++;
				}
				while (element_list[value2] > element_list[pivot] && value2 >= low)
				{
					value2--;
				}
				if (value1 < value2)
				{
					temp = element_list[value1];
					element_list[value1] = element_list[value2];
					element_list[value2] = temp;
				}
			}
			temp = element_list[value2];
			element_list[value2] = element_list[pivot];
			element_list[pivot] = temp;
			quicksort_method(element_list, low, value2 - 1);
			quicksort_method(element_list, value2 + 1, high);
		}
	}

*/

/*
#include <stdio.h>
void quicksort_method(int[], int, int);
int main()
{
	int element_list[50], count, counter;
	printf("Please enter the total count of the elements that you want to sort: ");
	scanf("%d", &count);
	printf("Please input the elements that has to be sorted:\n");
	for (counter = 0; counter < count; counter++)
	{
		scanf("%d", &element_list[counter]);
	}
	quicksort_method(element_list, 0, count - 1);
	printf("Output generated after using quick sort\n");
	for (counter = 0; counter < count; counter++)
	{
		printf("%d ", element_list[counter]);
	}
	printf("\n");
	return 0;
}
void quicksort_method(int element_list[], int low, int high)
{
	int pivot, value1, value2, temp;
	if (low < high)
	{
		pivot = low;
		value1 = low;
		value2 = high;
		while (value1 < value2)
		{
			while (element_list[value1] <= element_list[pivot] /*&& value1 <= high)
			{
				value1++;
			}
			while (element_list[value2] > element_list[pivot] /*&& value2 >= low)
			{
				value2--;
			}
			if (value1 < value2)
			{
				temp = element_list[value1];
				element_list[value1] = element_list[value2];
				element_list[value2] = temp;
			}
		}
		temp = element_list[value2];
		element_list[value2] = element_list[pivot];
		element_list[pivot] = temp;
		quicksort_method(element_list, low, value2 - 1);
		quicksort_method(element_list, value2 + 1, high);
	}
}
*/

//quicksort
/*
#include <stdio.h>
void quickSort(int, int, int list[]);
void main(){
		printf("please enter the number of elements:\n");
		int count;
		scanf("%d", &count);
		printf("please enter the elements:\n");
		int _list[30];
		for (int counter = 0; counter < count; counter++) {
			scanf("%d", &_list[counter]);
		}

		
		quickSort(0, count - 1, _list);
		for (int counter = 0; counter < count; counter++) {
			printf("%d", _list[counter]);
		}

}
	void quickSort(int low, int high, int list[]) {
					int value1, value2, pivot;
					if (low < high) {

						value1 = low;
						value2 = high;
						pivot = high;
						while (value1 < value2) {
							while (list[value1] <= list[pivot] && value1 <= high) {
								value1++;
							}
							while (list[value2] >= list[pivot] && value2 >= low) {
								value2--;
							}
							if (value1 < value2)
							{
								int temp = list[value1];
								value1 = value2;
								value2 = temp;
							}
						}
						
						int temp = list[value2];
						list[value2] = list[pivot];
						list[pivot] = temp;
						quickSort(low, value2 - 1, list);
						quickSort(value2 + 1, high, list);
					}
					
				}

	*/
#include <stdio.h>
	// 函数声明
long factorial(int n);  //也可以写作 long factorial(int);
long sum(long n);  //也可以写作 long sum(long);
int main() {
	printf("1!+2!+...+9!+10! = %ld\n", sum(10));
	return 0;
}
//求阶乘
long factorial(int n) {
	int i;
	long result = 1;
	for (i = 1; i <= n; i++) {
		result *= i;
	}
	return result;
}
// 求累加的和
long sum(long n) {
	int i;
	long result = 0;
	for (i = 1; i <= n; i++) {
		//嵌套调用
		result += factorial(i);
	}
	return result;
}