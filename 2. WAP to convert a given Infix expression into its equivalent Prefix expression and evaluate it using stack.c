#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to return precedence of operators
int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// Function to return associativity of operators
char associativity(char c) {
    if (c == '^')
        return 'R';
    return 'L'; // Default to left-associative
}

// Function to reverse a string
void reverse(char *exp) {
    int n = strlen(exp);
    for (int i = 0; i < n / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[n - i - 1];
        exp[n - i - 1] = temp;
    }
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char s[], char result[]) {
    int resultIndex = 0;
    int len = strlen(s);
    char stack[1000];
    int stackIndex = -1;

    for (int i = 0; i < len; i++) {
        char c = s[i];

        // If the scanned character is an operand, add it to the output string.
        if (isalnum(c)) {
            result[resultIndex++] = c;
        }
        // If the scanned character is an ‘(‘, push it to the stack.
        else if (c == '(') {
            stack[++stackIndex] = c;
        }
        // If the scanned character is an ‘)’, pop and add to the output string from the stack
        // until an ‘(‘ is encountered.
        else if (c == ')') {
            while (stackIndex >= 0 && stack[stackIndex] != '(') {
                result[resultIndex++] = stack[stackIndex--];
            }
            stackIndex--; // Pop '('
        }
        // If an operator is scanned
        else {
            while (stackIndex >= 0 && (prec(s[i]) < prec(stack[stackIndex]) ||
                                       (prec(s[i]) == prec(stack[stackIndex]) &&
                                        associativity(s[i]) == 'L'))) {
                result[resultIndex++] = stack[stackIndex--];
            }
            stack[++stackIndex] = c;
        }
    }

    // Pop all the remaining elements from the stack
    while (stackIndex >= 0) {
        result[resultIndex++] = stack[stackIndex--];
    }

    result[resultIndex] = '\0';
}

// Function to convert infix to prefix expression
void infixToPrefix(char infix[], char prefix[]) {
    // Reverse the infix expression
    reverse(infix);

    // Replace ( with ) and vice versa
    for (int i = 0; i < strlen(infix); i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        } else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }

    // Convert the modified infix to postfix
    char postfix[1000];
    infixToPostfix(infix, postfix);

    // Reverse the postfix expression to get prefix
    reverse(postfix);
    strcpy(prefix, postfix);
}

// Function to evaluate prefix expression
int evaluatePrefix(char* exp) {
    int stack[1000];
    int stackIndex = -1;

    for (int i = strlen(exp) - 1; i >= 0; i--) {
        if (isdigit(exp[i])) {
            stack[++stackIndex] = exp[i] - '0';
        } else {
            int op1 = stack[stackIndex--];
            int op2 = stack[stackIndex--];
            switch (exp[i]) {
                case '+':
                    stack[++stackIndex] = op1 + op2;
                    break;
                case '-':
                    stack[++stackIndex] = op1 - op2;
                    break;
                case '*':
                    stack[++stackIndex] = op1 * op2;
                    break;
                case '/':
                    stack[++stackIndex] = op1 / op2;
                    break;
                case '^':
                    stack[++stackIndex] = (int)pow(op1, op2);
                    break;
            }
        }
    }
    return stack[stackIndex];
}

int main() {
    char infix[1000];
    char prefix[1000];

    // Taking input from the user
    printf("Enter an infix expression: ");
    scanf("%s", infix);

    // Convert infix to prefix
    infixToPrefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);

    // Evaluate the prefix expression
    int result = evaluatePrefix(prefix);
    printf("Evaluation result: %d\n", result);

    return 0;
}
