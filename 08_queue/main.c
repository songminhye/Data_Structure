#include<stdio.h>
#include<stdlib.h>
#include"queue.h"

int main(){

	QUEUE* q1;
	q1 = create_queue();
	
	int a[]={1,2,3,4,5};

	for(int i=0;i<5;i++){
//		enqueue(q1,&a[i]);
		if(enqueue(q1,&a[i])){
			printf("enqueue succes\n");
		}
	}
	
	int* data;
	data = (int*)dequeue(q1);
	printf("%d\n",*data);
}
