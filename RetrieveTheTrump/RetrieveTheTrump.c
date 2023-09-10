#include<stdlib.h>
#include<stdio.h>

// Define a structure for the list node
struct Node
{
    int data;
    struct Node *next;
};
// Global variable for the start of the linked list
struct Node *start = NULL;

// Function to add a new node with data 'value' to the end of the linked list
void Add(int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    
    if(start ==  NULL){
        start = newNode; // If the list is empty, make the new node the end
    }else
    {
        struct Node* curr = start;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = newNode; // Otherwise, add the new node to the end
        
    }
    
}

void Delete(){
    if(start == NULL){
        printf("\nNothing to Delete , List is Empty!\n");
        return;  //nothing to delete in the list
    }else if(start->next == NULL){
        free(start);  // if there is only one node
        start = NULL;
    }else{
        struct Node* curr = start;
        while (curr->next->next != NULL)
        {
            curr=curr->next;
        }
        free(curr->next); //delete the last node
        curr->next = NULL;
        
        
    }
}

void GetTrump(){
    struct Node* fast = start;
    struct Node* slow = start;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast == NULL){
        // Even number of nodes, print the two middle numbers
        printf("%d %d\n", slow->data, slow->next->data);
    }else
    {
        // Odd number of nodes, print the middle number
        printf("%d\n",slow->data);
    }
    
    
}
int main() {
    char command[10];
    int value;

    FILE *inputFile = fopen("Test05.txt", "r");
    
    while (fscanf(inputFile, "%s", command) != EOF) {
        //This line uses fscanf to read a string (denoted by %s) from the inputFile and store it in the command variable. inputFile is assumed to be a previously opened file handle for reading.
        //EOF denotes the end of file

        if (strcmp(command, "ADD") == 0) {
            //strcmp is a command in C which compares 2 strings and returns 0 if they are equal
            fscanf(inputFile, "%d", &value);
            // now it is reading integral value from input file and stores it in value so that we can append it in linked list
            Add(value);
            
        } else if (strcmp(command, "DELETE") == 0) {
            //same process for Delete, if command is DELETE then perform deletion
            Delete();
        } else if (strcmp(command, "END") == 0) {
            //same process for END, if command is END then finish the program

            break;
        }
    }
    fclose(inputFile);

    //the program calls the GetTrump function to determine and print the middle customer(s) based on the restaurant's policy.
    GetTrump();

    return 0;
}
