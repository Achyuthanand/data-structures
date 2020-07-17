#include <stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
//iterative
struct Node* search(struct Node* temp,int key)
{
    while(temp!=NULL)
    {
        if(temp->data==key)
        {
            return temp;
        }
        temp=temp->next;
    }
    return NULL;
    
}
//recursive
struct Node* Rsearch(struct Node* temp,int key)
{
    if(temp==NULL)
    {
        return NULL;
    }
    if(temp->data==key)
    {
        return temp;
    }
    Rsearch(temp->next,key);
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
    struct Node* result=search(first,12);    //iterative call
    //struct Node* result=Rsearch(first,12);     //recursive call
    if(result==NULL)
    {
        printf("Element is not found");
    }
    else
    {
        printf("The element %d is found",result->data);
    }
}
int main()
{
    create();

    return 0;
}
