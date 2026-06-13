#include<stdio.h>
#include<stdlib.h>

void create();
void first();
void show();
void last();
int count();
void specific();
void delfirst();
void dellast();
void delspecific();

struct node
{
    int data;
    struct node *next;
};

struct node *head=0, *temp, *newnode;

int main()
{
    int no=1;
    
    while(no!=0)
    {
        printf("\npress 1 for create a list :\n");
        printf("press 2 for display lists :\n");
        printf("press 3 for insert at first position :\n");
        printf("press 4 for insert at last position :\n");
        printf("press 5 to count total list :\n");
        printf("press 6 for insert at specific position :\n");
        printf("press 7 for delete the first position :\n");
        printf("press 8 for delete the last position :\n");
        printf("press 9 for delete at specific position :\n");
        printf("press 0 for exit :\n");
        scanf("%d",&no);

        switch(no)
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
                first();
                break;
            }
            case 4:
            {
                last();
                break;
            }
            case 5:
            {
                printf("Total lists : %d",count());
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

void create()
{
    int i=1;
    while(i!=0)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data :");
        scanf("%d",&newnode->data);
        if(head==0)
        {
            head=newnode;
            newnode->next=newnode;
            printf("Data inerted\n");
        }
        else
        {
            temp=head;
            while(temp->next!=head)
            {
                temp=temp->next;
            }
            newnode->next=temp->next;
            temp->next=newnode;
            printf("Data inerted\n");
        }
        printf("press 0 for exit :");
        scanf("%d",&i);
    }
}

void first()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data :");
    scanf("%d",&newnode->data);

    if(head==0)
    {
        head=newnode;
        head->next=newnode;
        printf("Data inerted\n");
    }
    else
    {
        temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        newnode->next=head;
        temp->next=newnode;
        head=newnode;
        printf("Data inerted\n");
    }
}

void show()
{
    if(head==0)
    {
        printf("List is empty");
        return;
    }
    else
    {
        temp=head;
        do
        {
            printf("%d ",temp->data);
            temp=temp->next;
        } while (temp!=head);
    }
}

void last()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data :");
    scanf("%d",&newnode->data);

    if(head==0)
    {
        head=newnode;
        newnode->next=newnode;
        printf("Data inerted\n");
    }
    else
    {
        temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=head;
        printf("Data inerted\n");
    }
}

int count()
{
    int i=0;
    if(head==0)
    {
        return i;
    }
    else
    {
        temp=head;
        do{
            i++;
            temp=temp->next;
        }while(temp!=head);
    }
    return i;
}

void specific()
{
    int no;
    int total=count();
    printf("Enter the position :");
    scanf("%d",&no);
    if(no<=0 || no>total+1)
    {
        printf("Wrong position ");
        return;
    }

    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data :");
    scanf("%d",&newnode->data);

    if(no==1)
    {
        if(head==0)
        {
            head=newnode;
            newnode->next=newnode;
            printf("Data inerted\n");
        }
        else
        {
            temp=head;
            while(temp->next!=head)
            {
                temp=temp->next;
            }
            temp->next=newnode;
            newnode->next=head;
            head=newnode;
            printf("Data inerted\n");
        }
    }
    else
    {
        temp=head;
        int i=1;
        for(i=1;i<no-1;i++)
        {
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
        printf("Data inerted\n");
    }
}

void delfirst()
{
    if(head==0)
    {
        printf("list is empty");
        return;
    }
    else
    {
        if(head==head->next)
        {
            free(head);
            printf("Data deleted");
            head=0;
            return;
        }
        struct node *pre;
        temp=head;
        pre=head;

        while(temp->next!=head)
        {
            temp=temp->next;
        }
        head=head->next;
        temp->next=head;
        free(pre);
        printf("Data deleted");
    }
}

void dellast()
{
    if(head==0)
    {
        printf("List is empty");
        return;
    }

    if(head==head->next)
    {
        free(head);
        head=0;
        printf("Data deleted");
        return;
    }

    struct node *pre;
    temp=head;
    while(temp->next!=head)
    {
        pre=temp;
        temp=temp->next;
    }
    pre->next=temp->next;
    free(temp);
    printf("Data deleted");
}

void delspecific()
{
    if(head==0)
    {
        printf("List is empty");
        return;
    }
    int no;
    printf("Enter the position :");
    scanf("%d",&no);
    
    int total=count();
    if(no<1 || no>total)
    {
        printf("Wrong position entered");
        return;
    }
    if(no==1)
    {
        delfirst();
        return;
    }
    if(no==total)
    {
        dellast();
        return;
    }
    struct node *pre;
    temp=head;
    pre=head;

    int i=1;
    while(i<no)
    {
        pre=temp;
        temp=temp->next;
        i++;
    }
    pre->next=temp->next;
    free(temp);
    printf("Data deleted");
}