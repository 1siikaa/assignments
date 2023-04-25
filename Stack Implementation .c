#include<stdio.h>
#include<stdlib.h>


struct stack{
int*arr;
int size;
int top;
};

int isFull(struct stack* ptr);
int isEmpty(struct stack* ptr);
void push(struct stack* ptr, int val);
int pop(struct stack* ptr);



int main()
{
struct stack* s = (struct stack*)malloc(sizeof(struct stack));
s->size=10;
s->top== -1;
s->arr= (int*)malloc(s->size* sizeof(int));
int val;


push(s, 22);
push(s, 32);
push(s, 42);
push(s, 52);
push(s, 62);
push(s, 72);
push(s, 82);
push(s, 92);



pop(s);



return 0;
}

int isFull(struct stack* ptr)
{
if(ptr->top==ptr->size-1)
{
return 1;
}
else
{
return 0;
}
}

int isEmpty(struct stack* ptr)
{
if(ptr->top== -1)
{
return 1;
}
else 
{
return 0;
}
}

void push(struct stack* ptr, int val)
{
if(isFull(ptr))
{
printf("stack overflow\n");
}
else 
{
ptr->top++;
ptr->arr[ptr->top]= val;
printf("pushed %d into the stack\n", val);

}
}

int pop(struct stack* ptr)
{
if(isEmpty(ptr))
{
printf("stack underflow\n");
return -1;
}
else
{
int val= ptr->arr[ptr->top];
ptr->top--;
return val;

}

}
    