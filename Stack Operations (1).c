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
int peek(struct stack*ptr, int i);
int stackTop(struct stack*ptr);
int stackBottom(struct stack*ptr);


int main()
{
struct stack* s = (struct stack*)malloc(sizeof(struct stack));
s->size=10;
s->top== -1;
s->arr= (int*)malloc(s->size* sizeof(int));
int i;

printf("Push Operation into a stack.\n");
printf("\n");
push(s, 22);
push(s, 32);
push(s, 42);
push(s, 52);
push(s, 62);
push(s, 72);
push(s, 82);
push(s, 92);
push(s, 102);

printf("\n");

printf("Peek Operations for a given stack.\n");
printf("\n");
for(i=1; i<= s->top; i++)
{
printf("The value at position %d is: %d",i, peek(s, i));
printf("\n");
}

printf("\n");

printf("The top most value of this stack is:%d", stackTop(s));
printf("\n");
printf("The bottom most value of this stack is:%d", stackBottom(s));
printf("\n");
printf("\n");


printf("Pop Operation from a given stack.\n");
printf("\n");
while(s->top!=0)
{
printf("The value of popped element is %d:", pop(s));
printf("\n");
}

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

int peek(struct stack* ptr, int i)
{
int arrayIndex;
arrayIndex= ptr->top-i+1;
if(arrayIndex<0)
{
printf("Not a valid position. \n");
return -1;
}
else
{
return ptr->arr[arrayIndex];
}
for(i=1; i<= ptr->top+1; i++)
{
printf("The value at position %d is %d:",i, peek(ptr, i));
}

}

int stackTop(struct stack*ptr)
{
return ptr->arr[ptr->top];
}


int stackBottom(struct stack*ptr)
{
return ptr->arr[1];
}




    