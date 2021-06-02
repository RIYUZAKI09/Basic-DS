#include<stdio.h>
#define size 6

struct queue{
	int a[size];
	int front;
	int rear;
};

int isEmpty(struct queue q){
	if(q.rear == q.front ){
		return 1;
	}
	return 0;
}


void display(struct queue q){
	if(isEmpty(q)){
		printf(" Queue is Empty\n\n");
		return;
	}
	printf("\n Displaying Queue : ");
	if(q.front<q.rear){
		int i;
		for(i=q.front;i<q.rear;i++){
			printf("%d ",q.a[i]);
		}
	}
	else{
		int i;
		for(i=q.front;i<size;i++){
			printf("%d ",q.a[i]);
		}
		for(i=0;i<q.rear;i++){
			printf("%d ",q.a[i]);
		}
	}
	printf("\n\n");
}



int isFULL(struct queue q){
	if((q.rear+1)%size == q.front){
		return 1;
	}
	return 0;
}




void insert(struct queue *q){
	int x;
	if(isFULL(*q)){
		printf(" Queue is full.\n");
		display(*q);
		return;
	}
	printf(" Enter the number you want to insert into the queue : ");
	scanf("%d",&x);
	q->a[q->rear] = x;
	q->rear = (q->rear + 1)%size;
	printf(" %d is inserted into the queue\n",x);
	display(*q);
}

int Delete(struct queue *q){
	int x = -1;
	if(isEmpty(*q)){
		return x;
	}
	x = q->a[q->front];
	q->front = (q->front + 1)%size;
	return x;
}


int main(){
	struct queue q;
	q.front = 0;
	q.rear = 0;
	int choice,num;
	while(1){
		printf(" 1. Insert\n");
		printf(" 2. Delete \n");
		printf(" 3. Display\n");
		printf(" 4. Exit\n");
		printf(" ENTER YOUR CHOICE : ");
		scanf("%d",&choice);
		printf("\n");
		switch(choice){
			case 1:
					insert(&q);
					break;
			case 2:
				 	num = Delete(&q);
				 	if(num==-1){
				 		printf(" Queue is Empty\n");
					 }
					else{
						printf(" %d is deleted from the queue\n",num);	
					}
					break;
			case 3:
					display(q);
					break;
			case 4:
					return 0;
			default : 
					printf(" Enter a valid option!!!\n\n");
		}
		printf("*******************************************************\n");
	}
	return 0;
}