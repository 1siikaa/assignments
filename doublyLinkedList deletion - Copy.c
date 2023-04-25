#include<stdio.h>
#include<stdlib.h>

struct Node{
int data;
struct Node * next;
struct Node *prevNode;
};


void doublyLinkedListTraversal(struct Node * head);
// Deletion methods

struct Node *deleteAtFirst(struct Node *head );
struct Node *deleteAtIndex(struct Node * head, int index);
struct Node *deleteAtEnd(struct Node *head);
struct Node *deleteAtValue(struct Node *head, int value);

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


head->data = 8;
head->prevNode= NULL;
head->next = second;

//Linked second and third nodes
second->data = 27;
second->prevNode= head;
second->next = third;

//Linked third and fourth nodes
third->data = 64;
third->prevNode= second;
third->next = fourth;

fourth->data = 125;
fourth->prevNode= third;
fourth->next = fifth;

fifth->data= 216;
fifth->prevNode= fourth;
fifth->next= sixth;

sixth->data= 343;
sixth->prevNode = fifth;
sixth->next= NULL;


printf("printing the created linked list:\n");
doublyLinkedListTraversal(head);

printf("\n");

head= deleteAtFirst(head);

printf("After deleting at the beginning:\n");
doublyLinkedListTraversal(head);

printf("\n");


head= deleteAtIndex(head, 2);

printf("After deleting at index:\n");
doublyLinkedListTraversal(head);

printf("\n");

head = deleteAtEnd(head);

printf("After deleting at the end:\n");
doublyLinkedListTraversal(head);

printf("\n");

head= deleteAtValue(head, 64);

printf("After deleting  a given value:\n");
doublyLinkedListTraversal(head);

return 0;
}

void doublyLinkedListTraversal(struct Node* head)
{

struct Node *ptr=head;
struct Node *q;
printf("\n");
printf("forward printing of doublyLinkedListTraversal\n");
printf("\n");
do
{
printf("The element is %d:\n", ptr->data);
q=ptr;
ptr=ptr->next;
}
while(ptr!=NULL);

printf("\n");
printf("reverse printing of doublyLinkedListTraversal\n");
printf("\n");
do{
printf("The element is %d:\n", q->data);
q= q->prevNode;
}
while(q!=NULL);
}

//case 1
struct Node *deleteAtFirst(struct Node *head )
{

struct Node* ptr= head;
struct Node * q= head->next;


q->prevNode=ptr->prevNode;
head=ptr->next;
free(ptr);
return head;

}




// case 2
 
struct Node *deleteAtIndex(struct Node * head, int index)
{

struct Node * p = head;
struct Node * q = head->next;
int i=0;
while(i<(index-1))
{
p=p->next;
q=q->next;
i++;
} 
p->next=q->next;
q->next->prevNode = q->prevNode;
free(q);
return head;
}




// case 3

struct Node * deleteAtEnd(struct Node *head)
{
 
 
struct Node * p = head;
struct Node * q = head->next;
while(q->next!=NULL)
{
p = p->next;
q = q->next;
}
p->next = q->next;
free(q);
return head; 
}



//case 4

struct Node * deleteAtValue(struct Node *head, int value)
{
struct Node *p= head;
struct Node *q= head->next;
while(q->data!=value && q->next!= NULL)
{
p= p->next;
q= q->next;
}

if(q->data==value)
{
p->next = q->next;
q->next->prevNode = q->prevNode;
free(q);
}
return  head;
}









    