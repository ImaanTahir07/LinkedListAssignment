#include<stdio.h>
#include<stdlib.h>


// Node of Doubly LL
struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

//global variable for the start of DLL
struct Node* start = NULL;

// Function to insert a new node with data 'value' into the sorted linked list
void insertInSortedDLL(int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (start == NULL)
    {
        start = newNode; // if start is empty, make the start as first node of the linked list
    }else if (value <= start->data)
    {
        newNode->next = start;
        start->prev = newNode;
        newNode = start;
    }else
    {
        struct Node *curr = start;
        while (curr->next != NULL && curr->next->data < value)
        {
            curr = curr->next;
        }
        newNode->next = curr->next;
        if (curr->next != NULL) {
            curr->next->prev = newNode;
        }
        curr->next = newNode;
        newNode->prev = curr; // Insert in the middle or at the end
        
    }
}
// Function to calculate the median of the linked list
double calculateMedian() {
    struct Node* slow = start;
    struct Node* fast = start;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    if (fast == NULL) {
        // Even number of elements, average of two middle elements
        return (double)(slow->data + slow->prev->data) / 2.0;
    } else {
        // Odd number of elements, middle element
        return (double)slow->data;
    }
}

int main() {
    int value;

    FILE *inputFile = fopen("Test02.txt", "r");
    
    while (fscanf(inputFile, "%d", &value) != EOF) {
        insertInSortedDLL(value);
        printf("%d Median: %.1lf\n", value, calculateMedian());
    }

    fclose(inputFile);

    return 0;
}