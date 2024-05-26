#include <stdio.h>
#include <stdlib.h>

// Node structure to represent a term in the polynomial
typedef struct Node {
    int coeff;
    int power;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int coeff, int power) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->power = power;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the linked list
void insertEnd(Node** head, int coeff, int power) {
    Node* newNode = createNode(coeff, power);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to display the polynomial
void displayPoly(Node* head) {
    if (head == NULL) {
        printf("0");
        return;
    }
    while (head != NULL) {
        printf("%d*x^%d", head->coeff, head->power);
        head = head->next;
        if (head != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

// Function to add two polynomials
Node* addPolynomials(Node* poly1, Node* poly2) {
    Node* result = NULL;
    Node* temp1 = poly1;
    Node* temp2 = poly2;

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->power > temp2->power) {
            insertEnd(&result, temp1->coeff, temp1->power);
            temp1 = temp1->next;
        } else if (temp1->power < temp2->power) {
            insertEnd(&result, temp2->coeff, temp2->power);
            temp2 = temp2->next;
        } else {
            insertEnd(&result, temp1->coeff + temp2->coeff, temp1->power);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    while (temp1 != NULL) {
        insertEnd(&result, temp1->coeff, temp1->power);
        temp1 = temp1->next;
    }

    while (temp2 != NULL) {
        insertEnd(&result, temp2->coeff, temp2->power);
        temp2 = temp2->next;
    }

    return result;
}

int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;
    Node* result = NULL;

    int n, coeff, power;

    // Input for the first polynomial
    printf("Enter the number of terms for the first polynomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and power for term %d: ", i + 1);
        scanf("%d %d", &coeff, &power);
        insertEnd(&poly1, coeff, power);
    }

    // Input for the second polynomial
    printf("Enter the number of terms for the second polynomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and power for term %d: ", i + 1);
        scanf("%d %d", &coeff, &power);
        insertEnd(&poly2, coeff, power);
    }

    // Displaying the polynomials
    printf("First polynomial: ");
    displayPoly(poly1);
    printf("Second polynomial: ");
    displayPoly(poly2);

    // Adding the polynomials
    result = addPolynomials(poly1, poly2);

    // Displaying the result
    printf("Resultant polynomial: ");
    displayPoly(result);

    return 0;
}
