#include<stdio.h>
#include<stdlib.h>

struct Node{
int data;
struct Node * next;
};


void circularLinkedListTraversal(struct Node * head);
struct Node * deleteAtFirst(struct Node *head);
struct Node *deleteAtIndex(struct Node *head, int data);
struct Node *deleteAtLast(struct Node *head);
struct Node *deleteAtValue(struct Node *head,int value);

int main()
{
struct Node *head;
struct Node *second;
struct Node *third;
struct Node *fourth;
struct Node *fifth;
struct Node *sixth;


//Allocate memory for the nodes in the linked list in heap
head = (struct Node *)malloc(sizeof(struct Node));
second = (struct Node *)malloc(sizeof(struct Node));   
third = (struct Node *)malloc(sizeof(struct Node));
fourth = (struct Node *)malloc(sizeof(struct Node)); 
fifth = (struct Node *)malloc(sizeof(struct Node));   
sixth = (struct Node *)malloc(sizeof(struct Node));
 
//Linked first and second nodes
head->data = 67;
head->next = second;

//Linked second and third nodes
second->data = 55;
second->next = third;

//Linked third and fourth nodes
third->data = 48;
third->next = fourth;

//Terminate the list at the third Node
fourth->data = 77;
fourth->next = fifth;

fifth->data =88;
fifth->next = sixth;

sixth->data=99;
sixth->next =head;

printf("printing the original linked list:\n");
circularLinkedListTraversal(head);

printf("\n");

head= deleteAtFirst(head);
circularLinkedListTraversal(head);
printf("\n");

head=deleteAtIndex(head, 1);
circularLinkedListTraversal(head);
printf("\n");

head=deleteAtLast(head);
circularLinkedListTraversal(head);
printf("\n");

head=deleteAtValue(head, 88);
circularLinkedListTraversal(head);
printf("\n");
    return 0;
}


void circularLinkedListTraversal(struct Node* head)
{
struct Node *ptr=head;
do{ 
printf("The element is: %d\n", ptr->data);
ptr=ptr->next;
}while(ptr!=head);
}

struct Node *deleteAtFirst(struct Node*head)
{
struct Node*ptr= head;
struct Node*q=head->next;
do{
ptr=ptr->next;
}
while(ptr->next!=head);

ptr->next=q;
head=q;
free(ptr);
return (head);

}

//case 2

struct Node *deleteAtIndex(struct Node *head, int index)
{

struct Node* p= head;
struct Node* q= head->next;

for(int i=0; i<(index-1) ; i++)
{

p = p->next;
q = q->next;
}
p->next=q->next;
free(q);
return head;
}

//case 3
struct Node *deleteAtLast(struct Node *head)
{
struct Node *p=head;
struct Node *q=head->next;
do{
p=p->next;
q=q->next;
}
while(q->next!=head);

p->next=head;
free(q);
return head;
}

//case 4
struct Node *deleteAtValue(struct Node *head, int value)
{
struct Node* p= head;
struct Node* q=head->next;
do{
p= p->next;
q= q->next;
}
while(q->data!=value && q->next!=head);
if(q->data==value)
{
p->next=q->next;
free(q);
}

return head;
}
