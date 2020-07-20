#include <stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
    
};
void display(struct Node* traverse)
{
    while(traverse != NULL)
    {
        printf("%d ",traverse -> data);
        traverse=traverse -> next;
        
    }
    
}
void create()
{
    struct Node *first,*last;
    first=(struct Node*)malloc(sizeof(struct Node));
    int x;
    scanf("%d",&x);
    first -> data = x;
    
    last=first;
    first -> next = last;
    scanf("%d",&x);
    while(x!=-1)
    {
        struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
        newnode -> data=x;
        last -> next = newnode;
        last=newnode;
        scanf("%d",&x);
    }
    last -> next = NULL;
    display(first);
}

int main()
{
    create();

    return 0;
}
