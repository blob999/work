#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure to represent two stacks
typedef struct {
    int arr[MAX_SIZE];
    int top1; // Top index of the first stack
    int top2; // Top index of the second stack
} TwoStacks;

// Function to initialize the two stacks
void initialize(TwoStacks *ts) {
    ts->top1 = -1;
    ts->top2 = MAX_SIZE;
}

// Function to push an element to the first stack
void push1(TwoStacks *ts, int value) {
    if (ts->top1 < ts->top2 - 1) {
        ts->arr[++ts->top1] = value;
    } else {
        printf("Stack Overflow in stack1 by element: %d\n", value);
    }
}

// Function to push an element to the second stack
void push2(TwoStacks *ts, int value) {
    if (ts->top1 < ts->top2 - 1) {
        ts->arr[--ts->top2] = value;
    } else {
        printf("Stack Overflow in stack2 by element: %d\n", value);
    }
}

// Function to pop an element from the first stack
int pop1(TwoStacks *ts) {
    if (ts->top1 >= 0) {
        return ts->arr[ts->top1--];
    } else {
        printf("Stack UnderFlow in stack1\n");
        exit(EXIT_FAILURE);
    }
}

// Function to pop an element from the second stack
int pop2(TwoStacks *ts) {
    if (ts->top2 < MAX_SIZE) {
        return ts->arr[ts->top2++];
    } else {
        printf("Stack UnderFlow in stack2\n");
        exit(EXIT_FAILURE);
    }
}

// Function to check if both stacks are full
int isStackFull(TwoStacks *ts) {
    return ts->top1 >= ts->top2 - 1;
}

// Function to check if the first stack is empty
int isStack1Empty(TwoStacks *ts) {
    return ts->top1 == -1;
}

// Function to check if the second stack is empty
int isStack2Empty(TwoStacks *ts) {
    return ts->top2 == MAX_SIZE;
}

// Function to display the first stack
void displayStack1(TwoStacks *ts) {
    if (isStack1Empty(ts)) {
        printf("Stack 1 is empty\n");
    } else {
        printf("Stack 1: ");
        for (int i = 0; i <= ts->top1; i++) {
            printf("%d ", ts->arr[i]);
        }
        printf("\n");
    }
}

// Function to display the second stack
void displayStack2(TwoStacks *ts) {
    if (isStack2Empty(ts)) {
        printf("Stack 2 is empty\n");
    } else {
        printf("Stack 2: ");
        for (int i = MAX_SIZE - 1; i >= ts->top2; i--) {
            printf("%d ", ts->arr[i]);
        }
        printf("\n");
    }
}

int main() {
    TwoStacks ts;
    initialize(&ts);

    int choice, stackNumber, value;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Check if Stacks are Full\n4. Check if Stack is Empty\n5. Display Stack\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter stack number (1 or 2): ");
                scanf("%d", &stackNumber);
                printf("Enter value to push: ");
                scanf("%d", &value);
                if (stackNumber == 1) {
                    push1(&ts, value);
                } else if (stackNumber == 2) {
                    push2(&ts, value);
                } else {
                    printf("Invalid stack number\n");
                }
                break;
            case 2:
                printf("Enter stack number (1 or 2): ");
                scanf("%d", &stackNumber);
                if (stackNumber == 1) {
                    printf("Popped element from stack1: %d\n", pop1(&ts));
                } else if (stackNumber == 2) {
                    printf("Popped element from stack2: %d\n", pop2(&ts));
                } else {
                    printf("Invalid stack number\n");
                }
                break;
            case 3:
                if (isStackFull(&ts)) {
                    printf("Both stacks are full\n");
                } else {
                    printf("Stacks are not full\n");
                }
                break;
            case 4:
                printf("Enter stack number (1 or 2): ");
                scanf("%d", &stackNumber);
                if (stackNumber == 1) {
                    if (isStack1Empty(&ts)) {
                        printf("Stack 1 is empty\n");
                    } else {
                        printf("Stack 1 is not empty\n");
                    }
                } else if (stackNumber == 2) {
                    if (isStack2Empty(&ts)) {
                        printf("Stack 2 is empty\n");
                    } else {
                        printf("Stack 2 is not empty\n");
                    }
                } else {
                    printf("Invalid stack number\n");
                }
                break;
            case 5:
                printf("Enter stack number (1 or 2): ");
                scanf("%d", &stackNumber);
                if (stackNumber == 1) {
                    displayStack1(&ts);
                } else if (stackNumber == 2) {
                    displayStack2(&ts);
                } else {
                    printf("Invalid stack number\n");
                }
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice, please try again\n");
        }
    }

    return 0;
}

