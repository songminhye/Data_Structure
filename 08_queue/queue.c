#include<stdio.h>
#include<stdlib.h>
#include "queue.h"

QUEUE* create_queue(){
	
	QUEUE* queue;
	queue = (QUEUE*)malloc(sizeof(QUEUE));
	
	if(queue){
		queue->front = NULL;
		queue->rear = NULL;
		queue->count = 0;

		return queue;
	}else{
		return NULL;
	}
}

bool enqueue(QUEUE* queue,void* in){
	QUEUE_NODE* new_node;
	new_node = (QUEUE_NODE*)malloc(sizeof(QUEUE_NODE));
	new_node->data_ptr = in;
	new_node->next = NULL;

	if(queue->count == 0){
		queue->front = new_node;
		(queue->count)++;
		queue->rear = new_node;
		printf("count : %d\n",queue->count);
		return true;
	}else{
		queue->rear->next = new_node;
		(queue->count)++;
		queue->rear = new_node;
		printf("count : %d\n",queue->count);
		return true;
	}
	
}

void* dequeue(QUEUE* queue){
	if(queue->count == 0) return NULL;
	
	QUEUE_NODE* deleted_node;
	deleted_node = queue->front;
	void* item_ptr = queue->front->data_ptr;

	if(queue->count==1){
	queue->front = NULL;
	queue->rear = NULL;
	}else{
	queue->front = queue->front->next;
	}
	(queue->count)--;

	free(deleted_node);

	printf("count : %d\n",queue->count);
	return item_ptr;
}
