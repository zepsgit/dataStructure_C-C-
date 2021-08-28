#include<stdio.h>
#include<math.h>
#define MAX 5
int insertNum = 0;
int deleteNum = 0;
int insert();
int disp();
struct queue {
	int q[MAX];
	int f, r;
};
struct queue qu;
int main() {
	int ch = 0;
	qu.f = 0;
	qu.r = 0;
	while (ch != 4)//menu display
	{
		printf("\n\n\t\tMENU");
		printf("\n\n\t1: INSERTION");
		printf("\n\t2: DELETION"); 
		printf("\n\t3: DISPLAY");
		printf("\n\t4: EXIT");
		printf("\n\n\tEnter your choice\t");
		scanf("%d", &ch);//scan your choice
		switch (ch)
		{
		case 1: insert();
			break;
		case 2: delete();
			break;
		case 3:
			disp();
			break;
		}//end switch
	}//end while
	return 0;
}

int insert() {
	int item;
	printf("Please enter the item to insert\n");
	scanf("%d", &item);
	qu.q[qu.r] = item;
	qu.r++;
	insertNum++;
	if (qu.r == MAX)
		qu.r = 0;
	if (insertNum == deleteNum)
		printf("\nEMPTY\n");
	if (insertNum - deleteNum == MAX)
		printf("\nFULL\n");
}

int delete() {
	int item;
	item = qu.q[qu.f];
	qu.f++;
	deleteNum++;
	printf("\n The deleted item is %d", item);
	if (qu.f == MAX)
		qu.f = 0;
	if (insertNum == deleteNum)
		printf("\nEMPTY\n");
	if (insertNum - deleteNum == MAX)
		printf("\nFULL\n");
	return 0;
}

int disp() {
	int i;
	if (insertNum==deleteNum) {
		printf("\nThe queue is empty\n");
		return 0;
	}
	printf("\nThe elements in the queue are\n");
	if (qu.f < qu.r) {
		for (i = qu.f; i<qu.r; i++)
			printf("%d  ", qu.q[i]);
	}
	else {
		for (i = qu.f; i < MAX; i++)
			printf("%d  ", qu.q[i]);
		for(i=0;i<qu.r;i++)
			printf("%d  ", qu.q[i]);
	}
		
}