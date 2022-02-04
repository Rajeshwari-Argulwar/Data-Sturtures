#include<stdio.h>
#include<stdlib.h>
struct node_qu1
{
    struct node_qu*next1;
    int data1;
};

struct node_qu1*f1=NULL,*r1=NULL,*q1=NULL;

struct node_qu2
{
    struct node_qu2*next2;
    int data2;
};

struct node_qu2*f2=NULL,*r2=NULL,*q2=NULL;


void enqueue1(int a)
{
    struct node_qu1*np1;
    np1=(struct node_qu1*)malloc(sizeof(struct node_qu1));
    np1->data1=a;
    np1->next1=NULL;
        if(f1=NULL)
        {
            r1=np1;
            f1=r1;
        }
        else
        {
            r1->next1=np1;
            r1=np1;
        }
}


int dequeue1()
{
    int a;
    if(f1==NULL)
    {
        printf("Queue 1 is empty \n");
    }
    else
    {
        q1=f1;
        f1=f1->next1;
        a=q1->data1;
        free(q1);
        return a;
    }
}

void enqueue2(int a)
{
    struct node_qu2*np2;
    np2=(struct node_qu2*)malloc(sizeof(struct node_qu2));
    np2->data2=a;
    np2->next2=NULL;
    if(f2==NULL)
    {
        r2=np2;
        f2=r2;
    }
    else
    {
        r2->next2=np2;
        r2=np2;
    }
}

int dequeue2()
{
    int a;
    if(f2==NULL)
    {
        printf("\n Queue 2 is empty");
    }
    else
    {
        q2=f2;
        f2=f2->next2;
        a=q2->data2;
        free(q2);
        return a;
    }
}

int main()
{
    int n,a,i=0;
    printf("\n ENter the number of elements to be entered into stack \n");
    scanf("%d",&n);
    while(i<n)
    {
        printf("Enter the element to be entered\n");
        scanf("%d",&a);
        enqueue1(a);
        i++;   
    }
    printf("\n Elements pooped are \n\n");
    while(f1!=NULL||f2!=NULL)
    {
        if(f2==NULL)
        {
            while(f1->next1!=NULL)
            {
                enqueue2(dequeue1());
            }
            printf("\n%d",dequeue1());
        }
        else
        {
            while(f2->next2!=NULL)
            {
                enqueue1(dequeue2());
            }
            printf("\n%d",dequeue2());
        }
    }
}