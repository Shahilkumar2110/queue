#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int priority;
    struct Node *next;
};

struct Node *front = NULL;

void enqueue(int data, int priority) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;

    if (front == NULL || priority < front->priority) {
        newNode->next = front;
        front = newNode;
    } else {
        struct Node *temp = front;
        while (temp->next != NULL && temp->next->priority <= priority) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    struct Node *temp = front;
    front = front->next;
    printf("Dequeued element: %d with priority: %d\n", temp->data, temp->priority);
    free(temp);
}

void display() {
    if (front == NULL) {
        printf("Priority Queue is empty!\n");
        return;
    }

    printf("Priority Queue (Priority wise):\n");
    struct Node *temp = front;
    while (temp != NULL) {
        printf("Data: %d, Priority: %d\n", temp->data, temp->priority);
        temp = temp->next;
    }
}

int main() {
    int n,data,priority;
    printf("total node to be enter ");
    scanf("%d",&n);
    printf("enter the data and priority of node(data,priority) ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d",&data,&priority);
        enqueue(data,priority);
    }

    display();
    int clean;
    printf("enter the node to to delete ");
    scanf("%d",&clean);
    for (int i = 0; i < clean; i++)
    {
        dequeue();
    }
    display();

    return 0;
}
