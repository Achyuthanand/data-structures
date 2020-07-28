#include <stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
    
};
//recursive
void Rduplicate(struct Node* p,struct Node* q)
{
    if(q!=NULL)
    {
        if(p->data==q->data)
        {
            p->next=q->next;
            Rduplicate(p,q->next);
        }
        else
        {
            Rduplicate(p->next,q->next);
        }
    }
    
}
//iterative
void duplicate(struct Node* p,struct Node* q)
{
    while(q!=NULL)
    {
        if(p->data==q->data)
        {
            p->next=q->next;
            free(q);
            q=q->next;
        }
        else
        {
            p=p->next;
            q=q->next;
        }
    }
}
// display in iterative way
void display(struct Node* traverse)
{
    while(traverse != NULL)
    {
        printf("%d ",traverse -> data);
        traverse=traverse -> next;
        
    }
    
}
// display in recursive way
void RDisplay(struct Node* temp)
{
    if(temp!=NULL)
    {
        printf("%d ",temp->data);
        RDisplay(temp->next);
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
    Rduplicate(first,first->next);//recursive call
    
    //duplicate(first,first->next);//iterative call
    
    //display(first);// iterative call
    
    RDisplay(first);//recursive call
}

int main()
{
    create();

    return 0;
}
