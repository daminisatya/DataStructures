/*
Q3:
Write a program to recursively reverse the elements of a singly linked list given only the head pointer as input.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node* next;
};

void reverseLinkedList(struct node** head)
{
    struct node* f;
    struct node* o;

    if (*head == NULL)
       return;   

    f = *head;  
    o = f->next;
 
    if (o == NULL)
       return;   
 
    reverseLinkedList(&o);
    f->next->next  = f;  

    f->next  = NULL;          
    *head = o;              
}

void push(struct node** head, int num)
{
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data  = num;
    newnode->next = (*head);    
    (*head) = newnode;
}

void printList(struct node *head)
{
    struct node *temp = head;
    while(temp != NULL)
    {
        printf("%d\n", temp->data);    
        temp = temp->next;  
    }
}    

int main()
{
    struct node* h = NULL;
   
     push(&h, 10);
     push(&h, 20);
     push(&h, 30); 
     push(&h, 40);      
     
     printList(h);    
     reverseLinkedList(&h);
     printList(h);    
     return 0;
}