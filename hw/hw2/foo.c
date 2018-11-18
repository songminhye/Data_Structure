#include<stdio.h>
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


int main(){
	STACK* stack1 = create_stack();
	STACK* stack2 = create_stack();
	STACK* stack3 = create_stack();
	STACK* stack4 = create_stack();
	STACK* stack5 = create_stack();

	int a[5] = {0, 1, 2, 3, 4}; //data stack 1 
	int b[5] = {5, 6, 7, 8, 9}; //data stack 2
	int i;

	for(i=0; i<5; i++){
		push(stack1, &a[i]);
		push(stack2, &b[i]);
	}

	printf("---pushing stack1, stack2----\n");
	
	printf("stack1 count is : %d\n", stack1 -> count);
	printf("stack2 count is : %d\n", stack2 -> count);
	printf("stack3 count is : %d\n", stack3 -> count);
	printf("stack4 count is : %d\n", stack4 -> count);
	printf("stack5 count is : %d\n", stack5 -> count);
	printf("\n");

	for(i=0; i<5; i++){

	int* t1 = 0;
	t1 = (int*)pop(stack1);			
	push(stack3, t1);

	} // pop stack 1 -> push stack 3

	
	for(i=0; i<5; i++){

	int* t2 = 0;
	t2 = (int*)pop(stack2);			
	push(stack4, t2);
	} // pop stack 2 -> push stack 4
	
	printf("----poping stack 1-> stack3, stack 2-> stack4-----\n");
	printf("stack1 count is : %d\n", stack1 -> count);
	printf("stack2 count is : %d\n", stack2 -> count);
	printf("stack3 count is : %d\n", stack3 -> count);
	printf("stack4 count is : %d\n", stack4 -> count);
	printf("stack5 count is : %d\n", stack5 -> count);
	printf("\n");

	printf("---poping and pushing to stack5-----\n");

	for(i=0; i<5; i++){

	int* t3 = 0;
	int* t4 = 0;
	t3 = (int*)pop(stack3);
	t4 = (int*)pop(stack4);			
	push(stack5, t3);
	push(stack5, t4);
	printf("%d \n",*t3);
	printf("%d \n",*t4);

	}  // pop stack 3, pop stack 4 -> push stack 5
	

	printf("stack1 count is : %d\n", stack1 -> count);
	printf("stack2 count is : %d\n", stack2 -> count);
	printf("stack3 count is : %d\n", stack3 -> count);
	printf("stack4 count is : %d\n", stack4 -> count);
	printf("stack5 count is : %d\n", stack5 -> count);


}



STACK* create_stack(){

	STACK* stack = (STACK*)malloc(sizeof(STACK));
	stack -> count =0;
	stack -> top = 0;
	return stack;
}

int push(STACK* stack, void* in) {

	STACK_NODE* node = (STACK_NODE*)malloc(sizeof(STACK_NODE));
	if(!node)
		return 0;

	node -> data_ptr = in;
	node -> link = stack -> top;
	stack -> top = node;
	stack -> count++;
	
	return 1; 
}


void* pop(STACK* stack) {
	if(stack -> count == 0)
		return 0;
	else{
		STACK_NODE* temp = stack -> top;
		void* data_out = stack -> top -> data_ptr;
		stack -> top = stack -> top -> link;
		free(temp);
		(stack -> count)--;
		return data_out;
	}
}
