#include <stdio.h>
#include<stdlib.h>

typedef struct node{
	void* data_ptr;
	struct node* link;
} STACK_NODE;


typedef struct stack{

	int count;
	STACK_NODE* top;
} STACK;

STACK* create_stack();

int push(STACK* stack, void* in);
void* pop(STACK* stack);
void* stackBottom(STACK* stack);

int main(){

	STACK* s1 = create_stack();
	
	int a = 10;
	int b = 12;
	int c = 500;
	int d = 300;

	push(s1, &a);
	push(s1, &b);
	push(s1, &c);
	push(s1, &d);
	
	printf("count is : %d\n",s1 -> count);

	int* temp;
	temp = stackBottom(s1);

	printf("count is : %d\n",s1 -> count);
	printf("%d",*temp);


}

STACK* create_stack() {
	printf("creating a stack ...\n");
	STACK* stack = (STACK*)malloc(sizeof(STACK));
	if ( !stack )
		return 0;
	
	stack -> count = 0;
	stack -> top = 0;
	return stack;
}


int push(STACK* stack, void* in) {
	printf("pushing a data into stack...\n");
	STACK_NODE* node = (STACK_NODE*)malloc(sizeof(STACK_NODE));
	if(!node)
		return 0;

	node -> data_ptr = in;
	node -> link = stack -> top; // my next become old boss
	stack -> top = node; // I an a new boss
	stack -> count++;

	return 1;

}

void* pop(STACK* stack) {
	printf("poping a data from stack...\n");
	if(stack -> count == 0)
		return NULL;

	else{
		STACK_NODE* temp = stack -> top ; 
		void* data_out = stack -> top -> data_ptr;
		stack -> top = stack -> top -> link;
		free(temp);
		(stack -> count)--;
		
		return data_out;}

}

void* stackBottom(STACK* stack) {

	if(stack -> count == 0)
		return NULL;

	while(stack->count >= 2){
		STACK_NODE* temp = stack -> top;
		stack -> top = stack -> top -> link;
		free(temp);
		(stack -> count)--;
	}
		
		void* data_out = stack -> top -> data_ptr;
		return data_out;
}



	
