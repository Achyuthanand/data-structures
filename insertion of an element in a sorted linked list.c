#include <stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
    
};
//recursive call
struct Node* RinsertSortedNode(struct Node* p,struct Node* q,int key,int flag)
{
    if(flag)
    {
        printf("\nEnter the element that is to be inserted in the sorted linked list :");
        scanf("%d",&key);
    }
    
    if(p->data<key)
    {
        
        RinsertSortedNode(p->next,p,key,0);
    }
    else
    {
        struct Node* t=(struct Node*)malloc(sizeof(struct Node));
        t->data=key;
        if(q!=NULL)
        {
            t->next=q->next;
            q->next=t;
        }
        else
        {
            t->next=p;
            return t;
        }
    }
    return NULL;
}
//iterative
struct Node* insertSortedNode(struct Node* p,struct Node* q,int key)
{
    printf("\nEnter the element that is to be inserted in the sorted linked list :");
    scanf("%d",&key);
    while(p->data<key)
    {
        q=p;
        p=p->next;
    }
    struct Node* t=(struct Node*)malloc(sizeof(struct Node));
    t->data=key;
    if(q!=NULL)
    {
        t->next=q->next;
        q->next=t;
    }
    else
    {
        t->next=p;
        return t;
    }
    return NULL;
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
    
    struct Node* flag=insertSortedNode(first,NULL,0);//iterative call
    
    //struct Node* flag=RinsertSortedNode(first,NULL,0,1);//recursive call
    
    if(flag!=NULL)
    {
        first=flag;
    }
    display(first);//iterative call
    
    //RDisplay(first);//recursive call
}

int main()
{
    create();

    return 0;
}



