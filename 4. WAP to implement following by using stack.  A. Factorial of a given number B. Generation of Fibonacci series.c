#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Stack structure
typedef struct {
    int arr[MAX];
    int top;
} Stack;

// Function to initialize the stack
void initStack(Stack *s) {
    s->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Function to check if the stack is full
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Function to push an element to the stack
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        exit(1);
    } else {
        s->arr[++s->top] = value;
    }
}

// Function to pop an element from the stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        exit(1);
    } else {
        return s->arr[s->top--];
    }
}

// Function to calculate factorial using stack
int factorial(int n) {
    Stack s;
    initStack(&s);
    int result = 1;

    while (n > 0) {
        push(&s, n);
        n--;
    }

    while (!isEmpty(&s)) {
        result *= pop(&s);
    }

    return result;
}

// Function to generate Fibonacci series using stack
void fibonacci(int n) {
    if (n <= 0) {
        printf("Invalid number of terms. Must be greater than 0.\n");
        return;
    }
    
    Stack s;
    initStack(&s);
    int a = 0, b = 1;

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            push(&s, a);
        } else if (i == 1) {
            push(&s, b);
        } else {
            int next = a + b;
            a = b;
            b = next;
            push(&s, next);
        }
    }

    // Display the Fibonacci series
    while (!isEmpty(&s)) {
        printf("%d ", pop(&s));
    }
    printf("\n");
}

int main() {
    int choice, num;

    while (1) {
        printf("1. Factorial\n2. Fibonacci Series\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a number to find its factorial: ");
                scanf("%d", &num);
                printf("Factorial of %d is %d\n", num, factorial(num));
                break;
            case 2:
                printf("Enter a number to generate Fibonacci series up to that term: ");
                scanf("%d", &num);
                printf("Fibonacci series up to %d terms: ", num);
                fibonacci(num);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice, please try again\n");
        }
    }

    return 0;
}
