#include<stdio.h>
#include<stdlib.h>

struct Node 
{
int data;
struct Node* next
};

void linkedListTraversal(struct Node*ptr);
struct Node *deleteAtFirst(struct Node*head);
struct Node *deleteAtAGivenIndex(struct Node*head, int index);
struct Node *deleteAtLast(struct Node*head);
struct Node *deleteAtAGivenValue(struct Node*head, int value);


int main()
{
struct Node *head;
struct Node *second;
struct Node *third;
struct Node *fourth;
struct Node *fifth;

head= (struct Node *)malloc(sizeof(struct Node));
second= (struct Node *)malloc(sizeof(struct Node));
third= (struct Node *)malloc(sizeof(struct Node));
fourth= (struct Node *)malloc(sizeof(struct Node));
fifth=(struct Node *)malloc(sizeof(struct Node));

head->data= 44;
head->next= second;

second->data= 55;
second->next= third;

third->data= 66;
third->next= fourth;

fourth->data= 77;
fourth->next= fifth;

fifth->data=88;
fifth->next= NULL;

printf("linked list traversal:\n");
linkedListTraversal(head);

printf("\n");
printf("deleting first element:\n");
printf("\n");
head= deleteAtFirst(head);
linkedListTraversal(head);
printf("\n");
printf("deleting index element:\n");
printf("\n");
head= deleteAtAGivenIndex(head,2);
linkedListTraversal(head);
printf("\n");
printf("deleting last element:\n");
printf("\n");
head= deleteAtLast(head);
linkedListTraversal(head);
printf("\n");
printf("deleting the Node of a given value:\n");
printf("\n");
head =deleteAtAGivenValue(head, 66);
linkedListTraversal(head);
printf("\n");
printf("linked list traversal:\n");
linkedListTraversal(head);
    
return 0;
}

void linkedListTraversal(struct Node*ptr)
{
while(ptr!=NULL)
{
printf("Element is %d:\n", ptr->data);
ptr= ptr->next;

}
printf("\n");
}

struct Node *deleteAtFirst(struct Node *head)
{
struct Node *ptr= head;
head = head->next;
free(ptr);
return head;
}

struct Node* deleteAtAGivenIndex(struct Node *head, int index)
{
struct Node* p= head;
struct Node* q= head->next;

for(int i=0; i<(index-1) ; i++)
{

p = p->next;
q = q->next;

}

p->next= q->next;
free(q);
return head;
}

struct Node *deleteAtLast(struct Node *head)
{
struct Node* p= head;
struct Node* q= head->next;

while(q->next !=NULL)
{
p= p->next;
q= q->next;
}
p->next=q->next;
free(q);
return head;
}

struct Node* deleteAtAGivenValue(struct Node *head, int value)
{
struct Node *p =head;
struct Node *q =head->next;

while(q->data!=value && q->next!=NULL)
{
p= p->next;
q= q->next;
}

if(q->data==value)
{
p->next=q->next;
free(q);
}

return head;
}





