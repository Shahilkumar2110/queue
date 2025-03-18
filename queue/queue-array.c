#include <stdio.h>

#define n 10  

void enque(int array[], int data, int *rear, int *front) {
    if (*rear == n - 1) {
        printf("Queue is overflow\n");
        return;
    } else if (*front == -1 && *rear == -1) {
        *front = 0;
        *rear = 0;
        array[*rear] = data;
    } else {
        (*rear)++;
        array[*rear] = data;
    }
}

void deque(int array[], int *rear, int *front) {
    if (*front == -1 || *front > *rear) {
        printf("Queue is empty\n");
        *front = -1;
        *rear = -1;
        return;
    }
    
    printf("Dequeued element: %d\n", array[*front]);
    (*front)++;
    
    if (*front > *rear) {
        *front = -1;
        *rear = -1;
    }
}

void display(int array[], int *rear, int *front) {
    if (*front == -1 || *front > *rear) {
        printf("Queue is empty\n");
        return;
    }

    for (int i = *front; i <= *rear; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int array[n];  
    int rear = -1, front = -1;
    int used, data;

    printf("Enter the number of elements you want (max %d): ", n);
    scanf("%d", &used);

    if (used > n) {
        printf("Requested size exceeds queue capacity. Try again!\n");
        return 0;
    }

    printf("Enter the values: ");
    for (int i = 0; i < used; i++) {
        scanf("%d", &data);
        enque(array, data, &rear, &front);
    }

    printf("Your queue: ");
    display(array, &rear, &front);

    int clean;
    printf("Enter the number of elements to delete: ");
    scanf("%d", &clean);

    for (int i = 0; i < clean; i++) {
        deque(array, &rear, &front);
    }

    printf("Queue after deletion: ");
    display(array, &rear, &front);

    return 0;
}
