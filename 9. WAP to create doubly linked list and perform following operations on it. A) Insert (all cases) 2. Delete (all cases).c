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
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the doubly linked list
Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    newNode->next = head;
    head->prev = newNode;
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

// Function to insert a node after a given node in the doubly linked list
Node* insertAfter(Node* head, Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL.\n");
        return head;
    }
    Node* newNode = createNode(data);
    newNode->next = prevNode->next;
    if (prevNode->next != NULL) {
        prevNode->next->prev = newNode;
    }
    prevNode->next = newNode;
    newNode->prev = prevNode;
    return head;
}

// Function to delete a node from the doubly linked list
Node* deleteNode(Node* head, Node* delNode) {
    if (head == NULL || delNode == NULL) {
        printf("Cannot delete node. List is empty or node does not exist.\n");
        return head;
    }
    if (head == delNode) {
        head = delNode->next;
    }
    if (delNode->prev != NULL) {
        delNode->prev->next = delNode->next;
    }
    if (delNode->next != NULL) {
        delNode->next->prev = delNode->prev;
    }
    free(delNode);
    return head;
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
    Node* head = NULL;
    int choice, data, prevData;
    Node* prevNode;

    while (1) {
        printf("\n1. Insert at beginning\n2. Insert at end\n3. Insert after a node\n");
        printf("4. Delete first node\n5. Delete last node\n6. Delete a node after a given node\n");
        printf("7. Display list\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter data of the node after which to insert: ");
                scanf("%d", &prevData);
                prevNode = head;
                while (prevNode != NULL && prevNode->data != prevData) {
                    prevNode = prevNode->next;
                }
                if (prevNode != NULL) {
                    head = insertAfter(head, prevNode, data);
                } else {
                    printf("Node with given data not found. Cannot insert.\n");
                }
                break;
            case 4:
                head = deleteNode(head, head);
                break;
            case 5:
                if (head != NULL) {
                    Node* temp = head;
                    while (temp->next != NULL) {
                        temp = temp->next;
                    }
                    head = deleteNode(head, temp);
                } else {
                    printf("List is empty. Cannot delete last node.\n");
                }
                break;
            case 6:
                if (head != NULL) {
                    printf("Enter data of the node after which to delete: ");
                    scanf("%d", &prevData);
                    prevNode = head;
                    while (prevNode != NULL && prevNode->data != prevData) {
                        prevNode = prevNode->next;
                    }
                    if (prevNode != NULL && prevNode->next != NULL) {
                        head = deleteNode(head, prevNode->next);
                    } else {
                        printf("Node not found or it is the last node. Cannot delete.\n");
                    }
                } else {
                    printf("List is empty. Cannot delete.\n");
                }
                break;
            case 7:
                displayList(head);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice, please try again\n");
        }
    }

    return 0;
}
