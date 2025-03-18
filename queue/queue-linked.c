#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *front = NULL, *rear = NULL;

void enqueue(int data) {
    struct node *insertion = (struct node*)malloc(sizeof(struct node));
    insertion->data = data;
    insertion->link = NULL;

    if (front == NULL) { 
        front = insertion;
        rear = insertion;
    } else {
        rear->link = insertion;
        rear = insertion;
    }
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct node *temp = front;
    front = front->link;
    free(temp);

    if (front == NULL) {
        rear = NULL; 
    }
}

void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct node *temp = front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main() {
    int n, data;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the values: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        enqueue(data);  
    }

    printf("Queue before deletion:\n");
    display();

    int clean;
    printf("Enter the number of elements to delete: ");
    scanf("%d", &clean);
    for (int i = 0; i < clean; i++) {
        dequeue();
    }

    printf("Queue after deletion:\n");
    display();

    return 0;
}
