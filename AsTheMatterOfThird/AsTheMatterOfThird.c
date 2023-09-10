#include <stdio.h>
#include <stdlib.h>

// Define a structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Global variable for the head of the linked list
struct Node* head = NULL;

// Function to find the third last element of the linked list
int FindThirdLast() {
    struct Node* current = head;

    if (current == NULL || current->next == NULL || current->next->next == NULL) {
        // Less than three elements in the list, return -1
        return -1;
    }

    while (current->next->next->next != NULL) {
        current = current->next;
    }

    // Return the data of the third last element
    return current->data;
}

// Function to insert a new node at the end of the linked list
void InsertEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode; // If the list is empty, make the new node the head
    } else {
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode; // Otherwise, add the new node to the end
    }
}

int main() {
    // Read integers from the input file and construct the linked list
    FILE* inputFile = fopen("Test01.txt", "r");
    int value;
    while (fscanf(inputFile, "%d", &value) != EOF) {
        InsertEnd(value);
    }
    fclose(inputFile);

    // Find the third last element and print the result
    int thirdLast = FindThirdLast();
    if (thirdLast != -1) {
        printf("Third Last: %d\n", thirdLast);
    } else {
        printf("Less than three elements in the list.\n");
    }

    // Free memory by deallocating the linked list
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
