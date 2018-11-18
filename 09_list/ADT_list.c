#include<stdio.h>
#include<stdlib.h>
#include"ADT_list.h"


LLIST* create_list(){

	LLIST* list = (LLIST*)malloc(sizeof(LLIST*));
	if(list) {
	list -> count = 0;
	list -> front = NULL;
	list -> rear = NULL;
	list -> pos = NULL;

	return list;
	} else
		return NULL;
 	   
}


bool add_node_at(LLIST* list, unsigned int index, void* in){

	if(index > list->count)
		return false;

	NODE* new_node = (NODE*)malloc(sizeof(NODE*));
	if(!new_node) return false;
	
	new_node -> data_ptr = in;
	new_node -> next = NULL;

	if(list->count ==0) {
	list->front = new_node;
	list->rear = new_node;
	(list->count)++;
	return true;
	}

	int iter_i = 0;
	if(index = 0){
	new_node->next =  list->front;
	list->front = new_node;
	(list->count)++;
	return true;
	}
	
	iter_i++;
	list->pos = list->front;
	while(iter_i != index){
	list->pos = list->pos->next;
	iter_i++;
	}

	if(iter_i == list->count){
	list->pos->next = new_node;
	list->rear = new_node;
	(list->count)++;
	return true;
	} 

	else{
	new_node->next = list->pos->next;
	list->pos->next = new_node;
	(list->count)++;
	return true;
	} 
	

	}


bool del_node_at(LLIST* list, unsigned int index){

	if(list->count ==0)
		return false;
	else if(index >= list->count)
		return false;

	
	if(list->count == 1){
	free(list->front);
	list->front = NULL;
	list->rear = NULL;
	list->count = 0;
	return true;
	}

	int iter_i = 0;
	list->pos = list->front;
	NODE* back = NULL;
	while(iter_i != index){
	back = list->pos;
	list->pos = list->pos->next;
	iter_i++;
	}

	if(index == 0){
	list->front = list->front->next;
	free(list->pos);
	list->pos = NULL;
	(list->count)--;
	return true;
	}

	if(index == (list->count)-1){
	list -> rear = back;
	back -> next = NULL;
	free(list->pos);
	list->pos = NULL;
	(list->count)--;
	return true;
	}
	
	else{
	back->next = list->pos->next;
	free(list->pos);
	list->pos = NULL;
	(list->count)--;
	return true;
	}
}

	
	
