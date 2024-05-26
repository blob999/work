
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define NUM_QUEUES 3 // Number of queues

// Structure to represent a queue
typedef struct {
    int arr[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Function to initialize the queue
void initializeQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(Queue *q) {
    return (q->front == -1 && q->rear == -1);
}

// Function to check if the queue is full
int isFull(Queue *q) {
    return ((q->rear + 1) % MAX_SIZE == q->front);
}

// Function to add an element to the queue
void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue.\n");
    } else {
        if (isEmpty(q)) {
            q->front = 0;
            q->rear = 0;
        } else {
            q->rear = (q->rear + 1) % MAX_SIZE;
        }
        q->arr[q->rear] = value;
        printf("Enqueued %d to the queue.\n", value);
    }
}

// Function to remove an element from the queue
int dequeue(Queue *q) {
    int dequeuedValue;
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    } else if (q->front == q->rear) {
        dequeuedValue = q->arr[q->front];
        q->front = -1;
        q->rear = -1;
    } else {
        dequeuedValue = q->arr[q->front];
        q->front = (q->front + 1) % MAX_SIZE;
    }
    printf("Dequeued %d from the queue.\n", dequeuedValue);
    return dequeuedValue;
}

// Function to display the elements of the queue
void displayQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue: ");
        int i = q->front;
        while (i != q->rear) {
            printf("%d ", q->arr[i]);
            i = (i + 1) % MAX_SIZE;
        }
        printf("%d\n", q->arr[q->rear]);
    }
}

int main() {
    Queue queues[NUM_QUEUES]; // Array of queues

    // Initialize all queues
    for (int i = 0; i < NUM_QUEUES; i++) {
        initializeQueue(&queues[i]);
    }

    int choice, queueNumber, value;
    while (1) {
        printf("\n1. Addq (Enqueue)\n2. Delq (Dequeue)\n3. Display Queue\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the queue number (1 to %d): ", NUM_QUEUES);
                scanf("%d", &queueNumber);
                if (queueNumber < 1 || queueNumber > NUM_QUEUES) {
                    printf("Invalid queue number\n");
                } else {
                    printf("Enter value to enqueue: ");
                    scanf("%d", &value);
                    enqueue(&queues[queueNumber - 1], value);
                }
                break;
            case 2:
                printf("Enter the queue number (1 to %d): ", NUM_QUEUES);
                scanf("%d", &queueNumber);
                if (queueNumber < 1 || queueNumber > NUM_QUEUES) {
                    printf("Invalid queue number\n");
                } else {
                    dequeue(&queues[queueNumber - 1]);
                }
                break;
            case 3:
                printf("Enter the queue number (1 to %d): ", NUM_QUEUES);
                scanf("%d", &queueNumber);
                if (queueNumber < 1 || queueNumber > NUM_QUEUES) {
                    printf("Invalid queue number\n");
                } else {
                    displayQueue(&queues[queueNumber - 1]);
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice, please try again\n");
        }
    }

    return 0;
}
