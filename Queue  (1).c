#include<stdio.h>
#include<stdlib.h>
 
struct circularQueue
{
    int size;
    int f;
    int r;
    int* arr;
};
 
int isFull(struct circularQueue* q);
int isEmpty(struct circularQueue* q);
void enqueue(struct circularQueue*q, int val);
int dequeue(struct circularQueue*q);

 
 
 
int main(){
    struct circularQueue q;
    q.size = 16;
    q.f = q.r = 0;
    q.arr = (int*) malloc(q.size*sizeof(int));
    
    // Enqueue few elements
    enqueue(&q, 22);
    enqueue(&q, 24);
    enqueue(&q, 26); 
    enqueue(&q, 28);
    enqueue(&q, 30);
    enqueue(&q, 32);
    enqueue(&q, 34);
    enqueue(&q, 36);
    enqueue(&q, 38); 
    enqueue(&q, 40);
    enqueue(&q, 42);
    enqueue(&q, 44);
    enqueue(&q, 46);
    enqueue(&q, 48);
    enqueue(&q, 50); 
    
    printf("\n");
    

    if(isFull(&q)){
        printf("Queue is full.\n");
        printf("\n");
    
    }
 

 for(int i=0; i<q.size-1; i++)
 {
  printf("Dequed element is:%d\n", dequeue(&q));
 }

   printf("\n");
    
    if(isEmpty(&q)){
        printf("Queue is empty.\n");
    }
    
    
    return 0;
}


int isEmpty(struct circularQueue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}
 
int isFull(struct circularQueue *q){
    if((q->r+1)%q->size == q->f){
        return 1;
    }
    return 0;
}
 
void enqueue(struct circularQueue *q, int val){
    if(isFull(q)){
        printf("This Queue is full.\n");
    }
    else{
        q->r = (q->r +1)%q->size;
        q->arr[q->r] = val; 
        printf("Enqued element is:%d\n", val);
    }
    
}
 
int dequeue(struct circularQueue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("This Queue is empty.\n");
    }
    else{
        q->f = (q->f +1)%q->size;
        a = q->arr[q->f]; 
    }
    return a;
    
}

