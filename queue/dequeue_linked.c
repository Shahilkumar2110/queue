#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *pre;
    struct node *link;
};

struct node *rear = NULL, *front = NULL;

int isempty()
{
    if (rear == NULL || front == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void insertatrear(int data)
{
    struct node *insert = (struct node *)malloc(sizeof(struct node));
    insert->link = 0;
    insert->pre = 0;
    insert->data = data;
    if (rear == NULL)
    {
        rear = front = insert;
        insert->link = insert;
        insert->pre = insert;
    }
    else
    {
        insert->pre = rear;
        insert->link = front;
        rear->link=insert;
        front->pre=insert;
        rear = insert;
    }
}

void insertatfront(int data)
{
    struct node *insert = (struct node *)malloc(sizeof(struct node));
    insert->link = 0;
    insert->pre = 0;
    insert->data = data;
    if (front == NULL)
    {
        rear = front = insert;
        insert->link = insert;
        insert->pre = insert;
    }
    else
    {
        insert->link = front;
        insert->pre = rear;
        front->pre=insert;
        rear->link=insert;
        front = insert;
    }
}

void deleteatend()
{
    struct node *temp = rear->pre;
    if (isempty())
    {
        printf("dequeue is empty");
    }
    else
    {
        temp->link = front;
        free(rear);
        rear = temp;
    }
   
}

void deleteatfront()
{
    struct node *temp = front->link;
    if (isempty())
    {
        printf("dequeue is empty ");
    }
    else
    {
        temp->pre = rear;
        free(front);
        front = temp;
    }
}

void display()
{
    struct node *temp = front;
    printf("your dequeue is :");
    while (temp != rear)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("%d", rear->data);
    printf("\n");
}

int main()
{
    int n, data;
    printf("enter the total number to be inserted in rear ");
    scanf("%d", &n);
    printf("enter the data at rear :\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&data);
        insertatrear(data);
    }
    display();

    printf("enter the total number to be inserted in front ");
    scanf("%d", &n);
    printf("enter the data at front :\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&data);
        insertatfront(data);
    }
    display();

    int clean;
    printf("enter the total element to be clean from front ");
    scanf("%d", &clean);
    for (int i = 0; i < clean; i++)
    {
        deleteatfront();
    }
    display();

    printf("enter the total element to be clean from rear ");
    scanf("%d", &clean);
    for (int i = 0; i < clean; i++)
    {
        deleteatend();
    }
    display();
    return 0;
}