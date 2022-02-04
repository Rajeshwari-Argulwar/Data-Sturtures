#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *start=NULL; 

void insert()
{
    struct node *temp,*r,*s; 
    int info;
    temp=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter value to be inserted  ");
    scanf("%d",&temp->data);
    temp->next=NULL;
    if(start==NULL)
        start=temp; 
    else
    {
        printf("\nEnter the value after which you want to insert a new value  ");
        scanf("%d",&info);
        r=start; 
        while(r->data!=info)
            r=r->next;
            s=r->next;
            r->next=temp;
            temp->next=s;
    }
    printf("\nNew value %d is inserted",temp->data);
}



void del()
{
    struct node *temp,*r,*s;
    int info;
    if(start==NULL) 
    {
        del();
        printf("\nLinked List is empty");
    }
    else
    {
        printf("\nEnter the value you want to delete ");
        scanf("%d",&info); 
        temp=start;
        while(temp->data!=info)
            temp=temp->next;
            if(temp==NULL)
                {
                    printf("\n%d is deleted",temp->data);
                    r=start;
                    while(r->next!=temp)
                    r=r->next;
                    r->next=NULL;
                    temp->next=NULL;
                }
            else if(temp==start)
            {
                printf("\n%d is deleted",temp->data);
                start=start->next;
                temp->next=NULL;
            }
            else
            {
                printf("\n%d is deleted",temp->data);s=start;
                while(s->next!=temp)
                s=s->next;
                s->next=temp->next;
                temp->next=NULL;
                }
                free(temp);
            }
}



void display()
{
    struct node *temp;
    if(start==NULL)
        printf("\nLinked List is empty");
    else
    {
        temp=start;
        while(temp!=NULL);
        {
             printf("\n%d",temp->data);
            temp=temp->next;
        }
    }   
}
void main()
{
    int choice;
    do
    {
        printf("\n1.Insert");
        printf("\n2.Delete");
        printf("\n3.Display");
        printf("\n4.Exit");
        printf("\nEnter your choice ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : insert();
                    break;
            case 2 : del();
                    break;
            case 3 : display();
                    break;
            case 4 : exit(0);
                    break;            
        }
    }while(choice!=4);
}

    







