#include<stdio.h>
#include<stdlib.h>

#define MAX 5

typedef struct Queue{
	int arr[MAX];
	int front, rear;
} Queue;

void initialQueue(Queue* queue){
	queue->front = -1;
	queue->rear = -1;
}

int isEmpty(Queue* queue){
	if(queue->front == -1){
		return 1;
	}
	return 0;
}

int isFull(Queue* queue){
	if(queue->rear == MAX - 1){
		return 1;
	}
	return 0;
}

void enqueue(Queue* queue, int value){
	if(isFull(queue) == 1){
		printf("Hang doi da day");
		return;
	}
	
	if(isEmpty(queue) == 1){
		queue->front = 0;
	}
	queue->rear++;
	queue->arr[queue->rear] = value;
}

void dequeue(Queue* queue){
	if(isEmpty(queue) == 1){
		printf("Hang doi rong!");
		return;
	}
	queue->arr[queue->front];
	queue->front++;
	
	if(queue->front > queue->rear){
		initialQueue(queue);
	}
}

int peekQueue(Queue* queue){
	if(isEmpty(queue) == 1){
		printf("Hang doi rong");
		return 1;
	}
	return queue->arr[queue->front];
}

void printQueue(Queue* queue){
	for(int i=queue->front; i<=queue->rear; i++){
		printf("%d\t", queue->arr[i]);
	}
}

int main(){
	Queue queue;
	initialQueue(&queue);
	int value;
	
	do{
		printf("\n---------------------MENU-------------------\n");
		printf("1. Them phan tu vao hang doi\n");
		printf("2. In ra hang doi\n");
		printf("3. Xoa phan tu dau cua hang doi\n");
		printf("4. Lay gia tri dau tien ma k xoa\n");
		printf("0. Thoat\n");
		printf("Moi ban chon: ");
		
		int choice;
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
				printf("Nhap gia tri can them: ");
				scanf("%d", &value);
				enqueue(&queue, value);
				break;
			case 2:
				printQueue(&queue);
				break;
			case 3:
				dequeue(&queue);
				break;
			case 4:
				printf("Phan tu dau tien trong mang la: %d", peekQueue(&queue));
				break;
			case 0:
				exit(0);
			default:
				printf("Vui long chon lai tu 1 den 4");
		}
	}while(1==1);
	return 0;
}
