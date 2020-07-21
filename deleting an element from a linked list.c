#include <stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
    
};
//recursive
struct Node* RdeleteNode(struct Node* p,struct Node* q,int i,int pos,int flag)
{
    if(flag)
    {
        printf("Enter the position of the element you want to delete :");
        scanf("%d",&pos);    
    }
    if(pos==1)
    {
        struct Node* temp=p->next;
        free(p);
        return temp;
    }
    else if(i<pos)
    {
        RdeleteNode(p->next,p,i+1,pos,0);
    }
    else
    {
        q->next=p->next;
        free(p);
        return NULL;
    }
}
//iterative
struct Node* deleteNode(struct Node* p, struct Node* q, int pos)
{
    printf("Enter the position of the element you want to delete :");
    scanf("%d",&pos);
    if(pos==1)
    {
        struct Node* temp=p->next;
        free(p);
        return temp;
    }
    else
    {
        int i=1;
        while(i<pos)
        {
            q=p;
            p=p->next;
            i++;
        }
        q->next=p->next;
        free(p);
        return NULL;
        
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
    
   //struct Node* flag=deleteNode(first,NULL,0);//iterative call
   
   struct Node* flag=RdeleteNode(first,NULL,1,0,1);//recursive call
    
    if(flag!=NULL)
    {
        first=flag;
    }
    //display(first);//iterative call
    
    RDisplay(first);//recursive call
}

int main()
{
    create();

    return 0;
}


