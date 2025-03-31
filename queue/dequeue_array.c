#include <stdio.h>
#define n 7
int rear = -1, front = -1;

int isempty()
{
    if (rear == -1 && front == -1)
    {
        return 1;
    }
    else
        return 0;
}

int isfull()
{
    if (front == (rear + 1) % n)
    {
        return 1;
    }
    else
        return 0;
}

void display(int array[])
{
    int temp = front;
    printf("your data are: ");
    while (temp != rear)
    {
        printf("%d  ", array[temp]);
        temp = (temp + 1) % n;
    }
    printf("%d", array[rear]);
    printf("\n");
}

void insertatrear(int array[], int data)
{
    if (isfull())
    {
        printf("%d ,no more element is inserted in array \n",data);
    }
    else
    {
        if (rear == -1 || front == -1)
        {
            rear = front = 0;
            array[rear] = data;
        }
        else
        {
            rear = (rear + 1) % n;
            array[rear] = data;
        }
    }
}

void insertatfront(int array[], int data)
{
    if (isfull())
    {
        printf("%d ,no more element are inserted: \n",data);
    }
    else
    {
        if (rear == -1 || front == -1)
        {
            front = rear = 0;
            array[front] = data;
        }
        else
        {
            if (front == 0)
            {
                front = (front + n - 1) % n;
            }
            else
            {
                front = (front - 1) % n;
            }
            array[front] = data;
        }
    }
}

void deleteatfront(int array[])
{
    if (isempty())
    {
        printf("the queue is empty. \nfirst fill the queue");
    }
    else
    {
        printf("%d is dequeue from front\n", array[front]);
        if (rear == front)
        {
            rear = front = -1;
        }
        else
        {
            front = (front + 1) % n;
        }
        
    }
}

void deleteatrear(int array[])
{
    if (isempty())
    {
        printf("the queue is empty. \nfirst fill the queue");
    }
    else
    {
        printf("%d is dequeue from rear\n", array[rear]);
        if (rear == front)
        {
            rear = front = -1;
        }
        else
        {
            if (rear == 0)
            {
                rear = (rear - 1 + n) % n;
            }
            else
            {
                rear = (rear - 1) % n;
            }
        }
    }
}

int main()
{
    int array[n], data;
    printf("enter the 7 element data in the array ");
    for (int i = 0; i < 7; i++)
    {
        scanf("%d", &data);
        insertatrear(array, data);
    }

    display(array);

    int clean;
    printf("enter the element for delete from front: ");
    scanf("%d", &clean);
    for (int i = 0; i < clean; i++)
    {
        deleteatfront(array);
    }
    display(array);
    printf("enter the element for delete from rear: ");
    scanf("%d", &clean);
    for (int i = 0; i < clean; i++)
    {
        deleteatrear(array);
    }
    display(array);
    int insert;
    printf("enter the element to insert at front: ");
    scanf("%d", &insert);
    printf("enter the data: ");
    for (int i = 0; i < insert; i++)
    {
        scanf("%d", &data);
        insertatfront(array, data);
    }
    display(array);
    printf("enter the element to insert at rear: ");
    scanf("%d", &insert);
    printf("enter the data: ");
    for (int i = 0; i < insert; i++)
    {
        scanf("%d", &data);
        insertatrear(array, data);
    }
    printf("your final queue is :\n");
    display(array);
    return 0;
}