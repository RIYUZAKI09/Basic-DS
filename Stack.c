#include<stdio.h>
#define size 20

struct Stack{
	int stack[size];
	int top;
};

void push(struct Stack* st,int num){
		if(st->top< size-1){
			st->top = st->top+1;
			st->stack[st->top]=num;
			return;
		}
		else {
			printf("Stack overflow\n");
			return;
		}
	}
	
int pop(struct Stack* st){
		if(st->top>-1){
			int x;
			x = st->stack[st->top];
			st->top = st->top-1;
			return x;
		}
		else {
			printf("Stack underflow\n");
			return -1;
		}
	}
	
void displayStack(struct Stack st){
	if(st.top >= 0){
		int m=st.top;
		while(m>= 0){
			printf("%d\n",st.stack[m]);
			m--;
		}
		return;
	}
	else {
		printf("Stack underflow\n");
		return;
	}
}

int main(){
	struct Stack sta;
	sta.top=-1;
	while(1){
		printf("\n1. Push\n");
		printf("2. Pop\n");
		printf("3. Display\n");
		printf("4. Exit\n");
		printf("Enter your choice: ");
		int choice;
		scanf("%d",&choice);
		switch(choice){
			case 1: {
				printf("Enter the element to be inserted: ");
				int element;
				scanf("%d",&element);
				push(&sta,element);
				break;
			}
			case 2: {
				pop(&sta);
				break;
			}
			case 3:{
				displayStack(sta);
				break;
			}
			case 4: {
				return(0);
				break;
			}
			default: {
				printf("Wrong input! Try again");
			}
		}		
	}
}
