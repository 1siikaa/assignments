#include<stdio.h>
#include<stdlib.h>

struct Node{
int data;
struct Node * next;
struct Node *prevNode;
};


void doublyLinkedListTraversal(struct Node * head);
//Insertion at the beginning of the linked list

struct Node *insertAtFirst(struct Node *head , int data);
struct Node *insertAtIndex(struct Node * head, int data, int index);
struct Node *insertAtEnd(struct Node *head, int data);
struct Node *insertAfterNode(struct Node *head, struct Node *previousNode, int data);

int main()
{
struct Node *head;
struct Node *second;
struct Node *third;
struct Node *fourth;
struct Node *fifth;



//Allocate memory for the nodes in the linked list in heap
head = (struct Node *)malloc(sizeof(struct Node));
second = (struct Node *)malloc(sizeof(struct Node));   
third = (struct Node *)malloc(sizeof(struct Node));
fourth = (struct Node *)malloc(sizeof(struct Node)); 
fifth = (struct Node *)malloc(sizeof(struct Node));
//Linked first and second nodes

head->data = 67;
head->prevNode= NULL;
head->next = second;

//Linked second and third nodes
second->data = 55;
second->prevNode= head;
second->next = third;

//Linked third and fourth nodes
third->data = 48;
third->prevNode= second;
third->next = fourth;

//Terminate the list at the third Node
fourth->data = 77;
fourth->prevNode= third;
fourth->next = fifth;

fifth->data= 91;
fifth->prevNode= fourth;
fifth->next= NULL;


printf("printing the original linked list:\n");
doublyLinkedListTraversal(head);

printf("\n");

head= insertAtFirst(head, 90);

printf("After inserting at the beginning:\n");
doublyLinkedListTraversal(head);

printf("\n");


head= insertAtIndex(head, 91, 3);

printf("After inserting in between the 2 and 3rd node:\n");
doublyLinkedListTraversal(head);

printf("\n");


head = insertAtEnd(head, 92);

printf("After inserting at the end:\n");
doublyLinkedListTraversal(head);

printf("\n");


head= insertAfterNode(head, second, 93);

printf("After inserting after a node:\n");
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
struct Node *insertAtFirst(struct Node *head , int data)
{
struct Node *ptr= (struct Node *)malloc(sizeof(struct Node));
ptr->data= data;
ptr->next=head;
ptr->prevNode= NULL;
head->prevNode=ptr;
head=ptr;
return head;
}




// case 2 
 
struct Node *insertAtIndex(struct Node * head, int data, int index)
{
struct Node *ptr= (struct Node *)malloc(sizeof(struct Node));
struct Node * p = head;
struct Node* q =head->next;
int i = 0; 
while (i!=index-1) 
{ 
p = p->next;
 i++; 
}
int j=1;
while(j !=index)
{
q=q->next;
j++;
}
ptr->data = data;
 
ptr->prevNode=p;
p->next=ptr;
ptr->next=q;
q->prevNode=ptr;
return head; 
}




// case 3

struct Node * insertAtEnd(struct Node *head, int data)
{
 struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
 ptr->data = data;
 struct Node * p = head;
 while(p->next!= NULL)
{
 p = p->next; 
}
p->next = ptr;
ptr->next = NULL; 
ptr->prevNode = p;
return head; 
}


//case 4

struct Node * insertAfterNode(struct Node *head, struct Node *previousNode, int data)
{
struct Node * ptr = (struct Node *) malloc(sizeof(struct Node)); 
ptr->data = data; 


ptr->next= previousNode->next; 
ptr->prevNode=previousNode;
previousNode->next->prevNode=ptr;
previousNode->next = ptr;
return head; 
}







    