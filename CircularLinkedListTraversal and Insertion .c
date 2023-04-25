#include<stdio.h>
#include<stdlib.h>

struct Node{
int data;
struct Node * next;
};


void circularLinkedListTraversal(struct Node * head);
//Insertion at the beginning of the linked list

struct Node *insertAtFirst(struct Node *head , int data);
struct Node *insertAtIndex(struct Node * head, int data, int index);
struct Node *insertAtEnd(struct Node *head, int data);
struct Node *insertAfterNode(struct Node *head, struct Node *prevNode, int data);

int main()
{
struct Node *head;
struct Node *second;
struct Node *third;
struct Node *fourth;

//Allocate memory for the nodes in the linked list in heap
head = (struct Node *)malloc(sizeof(struct Node));
second = (struct Node *)malloc(sizeof(struct Node));   
third = (struct Node *)malloc(sizeof(struct Node));
fourth = (struct Node *)malloc(sizeof(struct Node)); 
    
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
fourth->next = head;


printf("printing the original linked list:\n");
circularLinkedListTraversal(head);

printf("\n");

head= insertAtFirst(head, 90);

printf("After inserting at the beginning:\n");
circularLinkedListTraversal(head);

printf("\n");


head= insertAtIndex(head, 91, 3);

printf("After inserting in between the 2 and 3rd node:\n");
circularLinkedListTraversal(head);

printf("\n");

head = insertAtEnd(head, 92);

printf("After inserting at the end:\n");
circularLinkedListTraversal(head);

printf("\n");

head= insertAfterNode(head, second, 93);

printf("After inserting after a node:\n");
circularLinkedListTraversal(head);

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

//case 1
struct Node *insertAtFirst(struct Node *head , int data)
{
struct Node *ptr= (struct Node *)malloc(sizeof(struct Node));
ptr->data= data;
struct Node* p= head->next;
while(p->next!=head)
{
p=p->next;
}
p->next=ptr;
ptr->next=head;
head=ptr;
return head;
}




// case 2
 
struct Node *insertAtIndex(struct Node * head, int data, int index)
{
struct Node *ptr= (struct Node *)malloc(sizeof(struct Node));
struct Node * p = head;
int i = 0; 
while (i!=index-1) 
{ 
p = p->next;
 i++; 
}
 ptr->data = data;
 ptr->next = p->next;
 p->next = ptr;
 return head; 
}




// case 3

struct Node * insertAtEnd(struct Node *head, int data)
{
 struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
 ptr->data = data;
 struct Node * p = head;
 while(p->next!=head)
{
 p = p->next; 
}
p->next = ptr;
ptr->next = head; 
return head; 
}

//case 4

struct Node * insertAfterNode(struct Node *head, struct Node *prevNode, int data)
{
struct Node * ptr = (struct Node *) malloc(sizeof(struct Node)); 
ptr->data = data; 


ptr->next= prevNode->next; 
prevNode->next = ptr;
 
return head; 
}







    