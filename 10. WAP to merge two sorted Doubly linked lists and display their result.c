#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the doubly linked list
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the doubly linked list
Node* insertAtEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

// Function to merge two sorted doubly linked lists
Node* mergeSortedLists(Node* list1, Node* list2) {
    Node* mergedList = NULL;
    Node* temp1 = list1;
    Node* temp2 = list2;

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->data <= temp2->data) {
            mergedList = insertAtEnd(mergedList, temp1->data);
            temp1 = temp1->next;
        } else {
            mergedList = insertAtEnd(mergedList, temp2->data);
            temp2 = temp2->next;
        }
    }

    while (temp1 != NULL) {
        mergedList = insertAtEnd(mergedList, temp1->data);
        temp1 = temp1->next;
    }

    while (temp2 != NULL) {
        mergedList = insertAtEnd(mergedList, temp2->data);
        temp2 = temp2->next;
    }

    return mergedList;
}

// Function to display the doubly linked list
void displayList(Node* head) {
    Node* temp = head;
    printf("Doubly linked list: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    // Create and populate the first sorted doubly linked list
    Node* list1 = NULL;
    int num1, data1;
    printf("Enter the number of elements in the first list: ");
    scanf("%d", &num1);
    printf("Enter the elements in ascending order: ");
    for (int i = 0; i < num1; i++) {
        scanf("%d", &data1);
        list1 = insertAtEnd(list1, data1);
    }

    // Create and populate the second sorted doubly linked list
    Node* list2 = NULL;
    int num2, data2;
    printf("Enter the number of elements in the second list: ");
    scanf("%d", &num2);
    printf("Enter the elements in ascending order: ");
    for (int i = 0; i < num2; i++) {
        scanf("%d", &data2);
        list2 = insertAtEnd(list2, data2);
    }

    // Merge the two sorted lists
    Node* mergedList = mergeSortedLists(list1, list2);

    // Display the merged list
    displayList(mergedList);

    return 0;
}



