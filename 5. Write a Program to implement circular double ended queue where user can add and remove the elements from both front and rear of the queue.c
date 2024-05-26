#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int front;
    int rear;
    int size;
} Deque;

// Function to initialize the deque
void initialize(Deque *dq) {
    dq->front = -1;
    dq->rear = 0;
    dq->size = 0;
}

// Function to check if the deque is full
int isFull(Deque *dq) {
    return dq->size == MAX;
}

// Function to check if the deque is empty
int isEmpty(Deque *dq) {
    return dq->size == 0;
}

// Function to add an element at the front of the deque
void addFront(Deque *dq, int value) {
    if (isFull(dq)) {
        printf("Deque Overflow\n");
        return;
    }

    if (dq->front == -1) {
        dq->front = 0;
        dq->rear = 0;
    } else if (dq->front == 0) {
        dq->front = MAX - 1;
    } else {
        dq->front = dq->front - 1;
    }

    dq->arr[dq->front] = value;
    dq->size++;
}

// Function to add an element at the rear of the deque
void addRear(Deque *dq, int value) {
    if (isFull(dq)) {
        printf("Deque Overflow\n");
        return;
    }

    if (dq->front == -1) {
        dq->front = 0;
        dq->rear = 0;
    } else if (dq->rear == MAX - 1) {
        dq->rear = 0;
    } else {
        dq->rear = dq->rear + 1;
    }

    dq->arr[dq->rear] = value;
    dq->size++;
}

// Function to delete an element from the front of the deque
void deleteFront(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque Underflow\n");
        return;
    }

    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = 0;
    } else if (dq->front == MAX - 1) {
        dq->front = 0;
    } else {
        dq->front = dq->front + 1;
    }

    dq->size--;
}

// Function to delete an element from the rear of the deque
void deleteRear(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque Underflow\n");
        return;
    }

    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = 0;
    } else if (dq->rear == 0) {
        dq->rear = MAX - 1;
    } else {
        dq->rear = dq->rear - 1;
    }

    dq->size--;
}

// Function to display the deque
void display(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return;
    }

    int i = dq->front;
    printf("Deque elements: ");

    while (1) {
        printf("%d ", dq->arr[i]);
        if (i == dq->rear) {
            break;
        }
        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main() {
    Deque dq;
    initialize(&dq);

    int choice, value;

    while (1) {
        printf("\n1. Add at front\n2. Add at rear\n3. Delete from front\n4. Delete from rear\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to add at front: ");
                scanf("%d", &value);
                addFront(&dq, value);
                break;
            case 2:
                printf("Enter value to add at rear: ");
                scanf("%d", &value);
                addRear(&dq, value);
                break;
            case 3:
                deleteFront(&dq);
                break;
            case 4:
                deleteRear(&dq);
                break;
            case 5:
                display(&dq);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice, please try again\n");
        }
    }

    return 0;
}
