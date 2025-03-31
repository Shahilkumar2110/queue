#include <stdio.h>
#define n 7

int rear = -1, front = -1;
int isempty()
{
    if (rear == -1 || front == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isfull()
{
    if ((rear + 1) % n == front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(int array[], int data)
{
    if (isfull())
    {
        printf("the queue is full: ");
    }
    else
    {
        if (front == -1)
        {
            rear = (rear + 1) % n;
            front = (front + 1) % n;
            array[rear] = data;
        }
        else
        {
            rear = (rear + 1) % n;
            array[rear] = data;
        }
    }
}

void display(int array[])
{
    if (isempty())
    {
        printf("first enter the value in array ");
    }
    else
    {
        printf("your value is: ");
        for (int i = front; i != rear; i = ((i + 1) % n))
        {
            printf("%d ", array[i]);
        }
        printf("%d",array[rear]);
    }
    printf("\n");
}

void dequeue(int array[])
{
    if (isempty())
    {
        printf("queue is empty ");
    }
    else
    {
        printf("the %d values is dequeue\n", array[front]);
       if (rear==front){
        rear=front=-1;
       }else{
        front = (front + 1) % n;
       }
    }
}

int main()
{
    int data;
    int array[n];
    printf("enter the first 7 to enqueue: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        enqueue(array, data);
    }

    display(array);

    int clean;
    printf("enter the data to be delete: ");
    scanf("%d", &clean);
    for (int i = 0; i < clean; i++)
    {
        dequeue(array);
    }

    display(array);

    int insert;
    printf("enter the node to be insertion :");
    scanf("%d",&insert);
    printf("insert the value ");
    for (int i = 0; i < insert; i++)
    {
        scanf("%d",&data);
        enqueue(array,data);
    }
    display(array);
    int clearr;
    printf("enter the number of node to be delete ");
    scanf("%d",&clearr);
    for (int  i = 0; i < clearr; i++)
    {
        dequeue(array);
    }

    printf("your final queue is ");
    display(array);
    return 0;
}
