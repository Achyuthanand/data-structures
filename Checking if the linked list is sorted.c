#include <stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
    
};
int RSorted(struct Node* temp,int x)
{
    if(temp!=NULL && temp->data>=x)
    {
        RSorted(temp->next,temp->data);
    }
    else
    {
        if(temp==NULL)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}
//iterative
int Sorted(struct Node* temp)
{
    int x=-1;
    while(temp!=NULL && temp->data>=x)
    {
        x=temp->data;
        temp=temp->next;
    }
    if(temp==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
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
    
    //int flag=Sorted(first);//iterative call
    
    int flag=RSorted(first,first->data);//recursive call
    
    if(flag)
    {
        printf("The linked list is Sorted\n");
    }
    else
    {
        printf("The linked list is not Sorted\n");
    }
    
    //display(first);//iterative call
    
    RDisplay(first);//recursive call
}

int main()
{
    create();

    return 0;
}
