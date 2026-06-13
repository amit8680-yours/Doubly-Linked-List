#include<stdio.h>
#include<stdlib.h>

void create();
void show();
void reshow();
void first();
void last();
int count();
void specific();
void delfirst();
void dellast();
void delspecific();

struct node{
    struct node *pre;
    int data;
    struct node *next;
};

struct node *head=0,*temp,*newnode;

int main()
{
    int i=1;
    while(i!=0)
    {
        printf("\npress 1 for create :\n");
        printf("press 2 for display :\n");
        printf("press 3 for reverse display :\n");
        printf("press 4 for insert at first :\n");
        printf("press 5 for insert at last :\n");
        printf("press 6 for insert specific :\n");
        printf("press 7 for delete first list :\n");
        printf("press 8 for delete last list :\n");
        printf("press 9 for delete list from specific position :\n");
        printf("press 0 for exit :\n");
        scanf("%d",&i);
        switch(i)
        {
            case 1:
            {
                create();
                break;
            }
            case 2:
            {
                show();
                break;
            }
            case 3:
            {
                reshow();
                break;
            }
            case 4:
            {
                first();
                break;
            }
            case 5:
            {
                count();
                printf("total number of list : %d",count());
                break;
            }
            case 6:
            {
                specific();
                break;
            }
            case 7:
            {
                delfirst();
                break;
            }
            case 8:
            {
                dellast();
                break;
            }
            case 9:
            {
                delspecific();
                break;
            }
    
        }

    }
    return 0;
}

void create ()
{
    int i=1;
    while(i!=0)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data :");
        scanf("%d",&newnode->data);
        newnode->pre=0;
        newnode->next=0;

        if(head==0)
        {
            head=newnode;
            temp=newnode;
        }
        else
        {
            temp->next=newnode;
            newnode->pre=temp;
            temp=newnode;
        }
        printf("press 0 for exit :");
        scanf("%d",&i); 
    }
}

void show()
{
    if(head==0)
    {
        printf("list is empty");
        return;
    }
    else
    {
        temp=head;
        while(temp!=0)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}

void reshow()
{
    if(head==0)
    {
        printf("list is empty ");
        return;
    }

    else
    {
        temp=head;
        while(temp->next!=0)
        {
            temp=temp->next;
        }

        while(temp!=0)
       {
         printf("[%d]",temp->data);
         temp=temp->pre;
       }
    }
}
void first()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter a data :");
    scanf("%d",&newnode->data);
    newnode->next=0;
    newnode->pre=0;

    if(head==0)
    {
        head=newnode;
    }
    else
    {
        head->pre=newnode;
        newnode->next=head;
        head=newnode;
    }
}

void last()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter the data :");
    scanf("%d",&newnode->data);
    newnode->next=0;
    newnode->pre=0;

    if(head==0)
    {
        head=newnode;
        return;
    }
    else
    {
        temp=head;
        while(temp->next!=0)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->pre=temp;
    }
}

int count()
{
    int i=0;
    if(head==0)
    {
        printf("list is empty :");
        return 0;
    }

    temp=head;
    while(temp!=0)
    {
        i++;
        temp=temp->next;
    }
    return i;
}

void specific()
{
    int no;
    printf("enter the position :");
    scanf("%d",&no);
    if(no==0)
    {
        printf("wrong position");
        return;
    }

    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter the data :");
    scanf("%d",&newnode->data);
    newnode->pre=0;
    newnode->next=0;

    if(no==1)
    {
        if(head==0)
        {
           head=newnode;
           printf("item inserted");
           return;
        }
        else
        {
            head->pre=newnode;
            newnode->next=head;
            head=newnode;
            printf("item inserted");
            return;
        }
        
    }

    if(no<=count()+1)
    {
        int i=1;
        temp=head;
        while(i<no-1)
        {
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        newnode->pre=temp;
        if(temp->next!=0)
        {
            temp->next->pre=newnode;
        }
        temp->next=newnode;
        printf("item inserted \n");
    }
    else
    {
        printf("invalid position");
    }

}

void delfirst()
{
    if(head==0)
    {
        printf("list is empty ");
        return;
    }
    temp=head;
    if(head->next!=0)
    {
        head=head->next;
        head->pre=0;
        free(temp);
    }
    else
    {
        free(head);
        head=0;
    }

    printf("deleted 1st list");
}

void dellast()
{
    if(head==0)
    {
        printf("list is empty");
        return;
    }

    temp=head;
    while(temp->next!=0)
    {
        temp=temp->next;
    }
    
    if(temp==head)
    {
        free(temp);
        head=0;
    }
    else
    {
        temp->pre->next=0;
        free(temp);
    }
    printf("item deleted");

}

void delspecific()
{
    if(head==0)
    {
        printf("list is empty");
        return;
    }
    int no;
    printf("Enter the position :");
    scanf("%d",&no);

    if(no<=0 || no>count())
    {
        printf("wrong position enter \n");
        printf("item not deleted\n");
        return;
    }

    temp=head;
    int i=1;
    while(i<no)
    {
        temp=temp->next;
        i++;
    }
    if(temp==head)
    {
        if(temp->next!=0)
        {
            head=head->next;
            head->pre=0;
            free(temp);
        }
        else
        {
            free(temp);
            head=0;
        }
    }
    else
    {
        temp->pre->next=temp->next;
        if(temp->next!=0)
        {
            temp->next->pre=temp->pre;
            free(temp);
        }
        else
        {
            free(temp);
        }
    }
    printf("item deleted");
}