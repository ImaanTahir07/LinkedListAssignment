#include <stdio.h>
#include <stdlib.h>

// Define a structure for a linked list node to store transaction information
struct TransactionNode {
    int transactionId;
    int transactionAmount;
    struct TransactionNode* next;
};

// Global variable for the head of the linked list
struct TransactionNode* transactions = NULL;

// Function to add a new transaction node to the end of the linked list
void AddTransaction(int id, int amount) {
    struct TransactionNode* newNode = (struct TransactionNode*)malloc(sizeof(struct TransactionNode));
    newNode->transactionId = id;
    newNode->transactionAmount = amount;
    newNode->next = NULL;

    if (transactions == NULL) {
        transactions = newNode; // If the list is empty, make the new node the head
    } else {
        struct TransactionNode* current = transactions;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode; // Otherwise, add the new node to the end
    }
}

// Function to remove a transaction node with a specific transaction ID
void RemoveTransaction(int id) {
    if (transactions == NULL) {
        return; // Nothing to remove if the list is empty
    }

    if (transactions->transactionId == id) {
        struct TransactionNode* temp = transactions;
        transactions = transactions->next;
        free(temp); // Remove the first node if it matches the ID
        return;
    }

    struct TransactionNode* current = transactions;
    while (current->next != NULL && current->next->transactionId != id) {
        current = current->next;
    }

    if (current->next != NULL) {
        struct TransactionNode* temp = current->next;
        current->next = temp->next;
        free(temp); // Remove the node if it matches the ID
    }
}

// Function to print the remaining transactions in the linked list
void PrintTransactions() {
    struct TransactionNode* current = transactions;
    while (current != NULL) {
        printf("%d,%d\n", current->transactionId, current->transactionAmount);
        current = current->next;
    }
}

int main() {
    int numberOfTransactions, numberOfFraudulentTransactions;
    int transactionId, transactionAmount;

    FILE* inputFile = fopen("Test01.txt", "r");

    fscanf(inputFile, "%d %d", &numberOfTransactions, &numberOfFraudulentTransactions);

    for (int i = 0; i < numberOfTransactions; i++) {
        fscanf(inputFile, "%d,%d", &transactionId, &transactionAmount);
        AddTransaction(transactionId, transactionAmount);
    }

    for (int i = 0; i < numberOfFraudulentTransactions; i++) {
        fscanf(inputFile, "%d", &transactionId);
        RemoveTransaction(transactionId);
    }

    fclose(inputFile);

    // Print the remaining transactions after removing fraudulent ones
    PrintTransactions();

    // Free memory by deallocating the linked list
    while (transactions != NULL) {
        struct TransactionNode* temp = transactions;
        transactions = transactions->next;
        free(temp);
    }

    return 0;
}
