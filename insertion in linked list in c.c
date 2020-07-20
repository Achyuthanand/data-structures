#include <stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* insertnode(struct Node* P, int data, int insertion_point)
{
    printf("Enter element and Enter insertion point: ");
    scanf("%d%d",&data,&insertion_point);
    struct Node* First=P;
    for(int i=0;i<insertion_point-1;i++)
    {
        P = P->next;
    }
    struct Node* t=(struct Node*)malloc(sizeof(struct Node));
    t->data=data;
    if(insertion_point==0)
    {
        t->next=First;
        First=t;
    }
    else
    {
        t->next=P->next;
        P->next=t;
    }
    return First;
}
//iterative
void display(struct Node* temp)
{
    while(temp!=NULL)
    {
        printf("\n%d ",temp->data);
        temp=temp->next;
    }
}

//iterative
struct Node* search(struct Node* temp,int key)
{
    printf("Enter the element you want to search: ");
    scanf("%d",&key);
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
    
    first=insertnode(first,0,0);
    struct Node* result=search(first,0);    //iterative call
    //struct Node* result=Rsearch(first,12);     //recursive call
    if(result==NULL)
    {
        printf("Element is not found");
    }
    else
    {
        printf("The element %d is found",result->data);
    }
     display(first);//iterative call
    //Rdisplay();//recursive call
}
int main()
{
    create();

    return 0;
}
