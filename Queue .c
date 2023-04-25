#include<stdio.h>
#include<stdlib.h>
 
struct queue
{
  int size;
  int f;
  int r;
  int* arr;
};

int isEmpty(struct queue *q);
int isFull(struct queue* q);
void enqueue(struct queue* q, int val);
int dequeue(struct queue*q);
 

 
int main(){
    struct queue q;
    q.size = 10;
    q.f = q.r = 0;
    q.arr = (int*) malloc(q.size*sizeof(int));
    
    // Enqueue few elements
    enqueue(&q, 12);
    enqueue(&q, 15);
    enqueue(&q, 1); 
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("\n");
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("\n");
    printf("Dequeuing element %d\n", dequeue(&q)); 
    enqueue(&q, 55);
    enqueue(&q, 55);
    enqueue(&q, 55);
 
    if(isEmpty(&q)){
        printf("Queue is empty\n");
    }
    if(isFull(&q)){
        printf("Queue is full\n");
    }
 
    return 0;
}

int isEmpty(struct queue* q)
{
if(q->f==q->r)
{
return 1;
}
else{
return 0;
}
}

int isFull(struct queue* q)
{
if(q->r == q->size-1)
{
return 1;
}
else{
return 0;
}
}

void enqueue(struct queue* q, int val)
{
if(isFull(q))
{
printf("This queue is full.\n");
printf("\n");
}

else{
q->r++;
q->arr[q->r]= val;
printf("enqueued element is: %d", val);
printf("\n");
}
}

int dequeue(struct queue* q)
{
int a= -1;
if(isEmpty(q))
{
printf("This queue is Empty. \n");
printf("\n");
}
else{


q->f++;

a= q->arr[q->f];
}
return a;

}





