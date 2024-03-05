# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "TP03.h"


////////// Singly Linked List ////////

int isEmpty(struct linearNode* head){ // checks if singly linked list is empty or not
    return(head==NULL?1:0);
}

int isEmptyDL(struct doublyNode* head){ // checks if doubly linked list is empty or not
    return(head==NULL?1:0);
}


struct linearNode* createLinearNode(int id, char childName[], char parentName[], int childBY, int parentPhone) 
{
    struct linearNode* new = (struct linearNode*) malloc(sizeof(struct linearNode));
    new->id = id;
    new->childBY = childBY;
    strcpy(new->childName, childName);
    strcpy(new->parentName, parentName);
    new->parentPhone = parentPhone;
    new->linearNext = NULL;
    return new;
}




void SL_insertBeginning(struct linearNode** head, int id, char childName[], char parentName[], int childBY, int parentPhone) 
{
    struct linearNode* forInsert = createLinearNode(id, childName, parentName, childBY, parentPhone);
    if(isEmpty(*head)) forInsert->linearNext = NULL;
    else forInsert->linearNext = *head;
    *head = forInsert;
}

void SL_insertAtEnd(struct linearNode** head, int id, char childName[], char parentName[], int childBY, int parentPhone) 
{
    struct linearNode* forInsert = createLinearNode(id, childName, parentName, childBY, parentPhone);
    if(isEmpty(*head)) {
        *head = forInsert;
        forInsert->linearNext = NULL;
    }
    else{
        struct linearNode* current = *head;
        while(current->linearNext != NULL){
            current = current -> linearNext;
        }
        current->linearNext = forInsert;
    }
}

void SL_insertAfterNode(struct linearNode *prevNode, struct linearNode *newNode)
{
    struct linearNode* current;
    if(isEmpty(prevNode))
        printf("Previous node cannot be NULL\n");
    else{
        current = prevNode;
        prevNode = current -> linearNext;
    }
    current->linearNext = newNode;
    newNode->linearNext = prevNode;
}



void SL_deleteAtBeginning(struct linearNode **head)
{
    if(isEmpty(*head))
        printf("List is empty, cannot delete.\n");
    else{
        struct linearNode *temp = *head;
        *head = (*head)->linearNext;
        free(temp);
    }

}

void SL_deleteAtEnd(struct linearNode **head)
{
    if(isEmpty(*head))
        printf("List is empty, cannot delete.\n");
    else{
        struct linearNode *tail = *head;
        while(tail->linearNext->linearNext!=NULL){
            tail=tail->linearNext;
        }
        struct linearNode (*temp) = tail->linearNext;
        free(temp);
        tail->linearNext = NULL;
    }

} 

void SL_deleteAfterNode(struct linearNode *head, int targetID)
{   
    if(isEmpty(head))
        printf("List is empty, cannot delete.\n");
    else{
        struct linearNode *tail = head;
        while(tail->id != targetID){
            tail=tail->linearNext;
        }
        if(tail->linearNext == NULL){
            printf("Node with ID %d is the last element of the linked list, cannot delete.\n", targetID);
            return;
        }
        struct linearNode *temp = tail->linearNext;
        tail->linearNext=tail->linearNext->linearNext;
        free(temp); 
    }
}

void printSinglyLinearList(struct linearNode* head)
{
    // TODO
    if(isEmpty(head))
        printf("List is empty.\n");
    
    struct linearNode* current = head;
    while(current!=NULL){
        printf("ID: %d, Child Name: %s, Parent Name: %s, Child Birth Year: %d, Parent Phone: %d\n", current->id, current->childName, current->parentName, current->childBY, current->parentPhone);
        current = current -> linearNext;
    }
    

}

struct linearNode *searchSinglyNode(struct linearNode *head, int id)
{
    
    if(isEmpty(head)) printf("List is empty.\n");
    int targetID = id;
    struct linearNode *current = head;
    while(current!=NULL){
        if(current->id == targetID) return current;
        current = current->linearNext;
    }

    printf("Node with ID %d not found in the list, cannot insert or delete.\n", targetID);
    return NULL;
}

////////// Circular Singly Linked List ////////

void CSL_insertBeginning(struct linearNode** head, int id, char childName[], char parentName[], int childBY, int parentPhone) {
    struct linearNode* forInsert = createLinearNode(id, childName, parentName, childBY, parentPhone);
    struct linearNode* tail = *head;
    if(isEmpty(*head)) forInsert->linearNext = forInsert;
    else{
        while(tail->linearNext!=(*head)){
            tail = tail->linearNext;
        }
        forInsert->linearNext = *head;
        tail->linearNext = forInsert;
    }
    *head = forInsert;
    
}

void CSL_insertAtEnd(struct linearNode** head, int id, char childName[], char parentName[], int childBY, int parentPhone) 
{
    struct linearNode* forInsert = createLinearNode(id, childName, parentName, childBY, parentPhone);
    struct linearNode* tail = *head;
    if(isEmpty(*head)) {
        *head = forInsert;
        forInsert->linearNext = forInsert;
    }
    else{
        while(tail->linearNext!=(*head)){
            tail = tail->linearNext;
        }
        tail->linearNext = forInsert;
        forInsert->linearNext = (*head);
    }
}

void CSL_insertAfterNode(struct linearNode *prevNode, struct linearNode *newNode)
{
    struct linearNode* current = prevNode;
    if(isEmpty(prevNode))
        printf("Previous node cannot be NULL\n");
    else{
        prevNode = current -> linearNext;
    }
    current->linearNext = newNode;
    newNode->linearNext = prevNode;
}



void CSL_deleteAtBeginning(struct linearNode **head)
{
    if(isEmpty(*head))
        printf("List is empty, cannot delete.\n");
    else{
        struct linearNode *temp = *head;
        struct linearNode* tail = *head;
        
        while(tail->linearNext!=(*head)){
            tail = tail->linearNext;
        }
        *head = (*head)->linearNext;
        tail->linearNext=(*head);
        free(temp);
        
    }
}

void CSL_deleteAtEnd(struct linearNode **head)
{
    if(isEmpty(*head))
        printf("List is empty, cannot delete.\n");
    else{
        struct linearNode *tail = *head;
        while(tail->linearNext->linearNext!=(*head)){
            tail=tail->linearNext;
        }
        struct linearNode (*temp) = tail->linearNext;
        tail->linearNext = *head;
        free(temp);
        
    }
}

void CSL_deleteAfterNode(struct linearNode* head, int targetID) 
{
    if(isEmpty(head))
        printf("List is empty, cannot delete.\n");
    
    else {
        struct linearNode *tail = head;

        while (tail->id != targetID) {
            tail = tail->linearNext;
            if (tail->linearNext == head) {
                printf("Node with ID %d not found in the list, cannot delete.\n", targetID);
                return;
            }
        }

        if (tail->linearNext == head) {
            
            struct linearNode *temp = head;
            head = head->linearNext;
            free(temp);
        } else {
            struct linearNode *temp = tail->linearNext;
            tail->linearNext = temp->linearNext;
            free(temp);
        }
    }
}

struct linearNode *searchCircularSinglyNode(struct linearNode *head, int id)
{
    // TODO
    if(isEmpty(head))
        printf("List is empty.\n");
    int targetID = id;
    struct linearNode *current = head;
    do{
        if(current->id == targetID) return current;
        current = current->linearNext;
    }while(current!=head);
    printf("Node with ID %d not found in the list, cannot insert or delete.\n", targetID);
    return NULL;
    
}

void printSinglyCircularList(struct linearNode* head)
{
    if(isEmpty(head))
        printf("List is empty.\n");
    else{
        struct linearNode* current = head;
        do{
            printf("ID: %d, Child Name: %s, Parent Name: %s, Child Birth Year: %d, Parent Phone: %d\n", current->id, current->childName, current->parentName, current->childBY, current->parentPhone);
            current = current -> linearNext;
        }
        while(current!=(head));
    }
    
}


////////// Doubly Linked List ////////

// Function to create a node for the circular doubly linked list
struct doublyNode *createDoublyNode(int id, char childName[], char parentName[], int childBY, int parentPhone) 
{
    struct doublyNode* new = (struct doublyNode*) malloc(sizeof(struct doublyNode));
    new->id = id;
    new->childBY = childBY;
    strcpy(new->childName, childName);
    strcpy(new->parentName, parentName);
    new->parentPhone = parentPhone;
    new->doublyPrev = NULL;
    new->doublyNext = NULL;
    return new;
}

void DL_insertBeginning(struct doublyNode **head, int id, char childName[], char parentName[], int childBY, int parentPhone) 
{
    struct doublyNode* forInsert = createDoublyNode(id, childName, parentName, childBY, parentPhone);
    if(isEmptyDL(*head)) {
        forInsert->doublyNext = NULL;
        forInsert->doublyPrev = NULL;
    }
    else {
        forInsert->doublyNext = *head;
        (*head)->doublyPrev = forInsert;
    }
    *head = forInsert;
    (*head)->doublyPrev = NULL;
}

void DL_insertAtEnd(struct doublyNode **head, int id, char childName[], char parentName[], int childBY, int parentPhone) 
{
    struct doublyNode* forInsert = createDoublyNode(id, childName, parentName, childBY, parentPhone);
    if(isEmptyDL(*head)) {
        *head = forInsert;
        forInsert->doublyNext = NULL;
        forInsert->doublyPrev = NULL;
    }
    else{
        struct doublyNode* current = *head;
        (*head)->doublyPrev = NULL;
        while(current->doublyNext != NULL){
            current = current -> doublyNext;
        }
        current->doublyNext = forInsert;
        forInsert->doublyPrev = current;
    }
}

void DL_insertAfterNode(struct doublyNode* prevNode, struct doublyNode* newNode) 
{
    struct doublyNode* current = prevNode;
    if(isEmptyDL(prevNode))
        printf("Previous node cannot be NULL\n");

    else{
        prevNode = current -> doublyNext;
    }
    current->doublyNext = newNode;
    newNode->doublyNext = prevNode;
}

void DL_deleteAtBeginning(struct doublyNode **head) 
{
    if(isEmptyDL(*head))
        printf("List is empty, cannot delete.\n");
    else{
        struct doublyNode *temp = *head;
        *head = (*head)->doublyNext;
        free(temp);
        (*head)->doublyPrev = NULL;
    }
}


void DL_deleteAtEnd(struct doublyNode** head) 
{
    if(isEmptyDL(*head))
        printf("List is empty, cannot delete.\n");
    else{
        struct doublyNode *tail = *head;
        (*head)->doublyPrev = NULL;
        while(tail->doublyNext->doublyNext!=NULL){
            tail=tail->doublyNext;
        }
        struct doublyNode (*temp) = tail->doublyNext;

        free(temp);
        tail->doublyNext = NULL;
        
    }
}

void DL_deleteAfterNode(struct doublyNode *head, int targetID)
{
    if(isEmptyDL(head))
        printf("List is empty, cannot delete.\n");
    else{
        struct doublyNode *tail = head;
        while(tail->id != targetID){
            tail=tail->doublyNext;
            if (tail == head) {
                printf("Node with ID %d not found in the list, cannot delete.\n", targetID);
            }
        }
        struct doublyNode *temp = tail->doublyNext;
        tail->doublyNext=tail->doublyNext->doublyNext;
        free(temp); 
    }
}

void printDoublyLinearList(struct doublyNode *head) 
{
    if(isEmptyDL(head))
        printf("List is empty.\n");
    
    struct doublyNode* current = head;
    while(current!=NULL){
        printf("ID: %d, Child Name: %s, Parent Name: %s, Child Birth Year: %d, Parent Phone: %d\n", current->id, current->childName, current->parentName, current->childBY, current->parentPhone);
        current = current -> doublyNext;
    }
}

struct doublyNode* searchDoublyNode(struct doublyNode* head, int id) 
{
    if(isEmptyDL(head)) printf("List is empty.\n");
    int targetID = id;
    struct doublyNode *current = head;
    while(current!=NULL){
        if(current->id == targetID) return current;
        current = current->doublyNext;
    }
    printf("Node with ID %d not found in the list, cannot insert or delete.\n", targetID);
    return NULL;
}

/////// Circular Doubly Linked List /////////////

void CDL_insertBeginning(struct doublyNode** head, int id, char childName[], char parentName[], int childBY, int parentPhone)
{
    struct doublyNode* forInsert = createDoublyNode(id, childName, parentName, childBY, parentPhone);
    struct doublyNode* tail = *head;
    if(isEmptyDL(*head)) forInsert->doublyNext = forInsert;
    else{
        while(tail->doublyNext!=(*head)){
            tail = tail->doublyNext;
        }
        forInsert->doublyNext = *head;
        tail->doublyNext = forInsert;
    }
    *head = forInsert;
    (*head)->doublyPrev = tail;
}

void CDL_insertAtEnd(struct doublyNode** head, int id, char childName[], char parentName[], int childBY, int parentPhone) 
{
    struct doublyNode* forInsert = createDoublyNode(id, childName, parentName, childBY, parentPhone);
    struct doublyNode* tail = *head;
    if(isEmptyDL(*head)) {
        *head = forInsert;
        forInsert->doublyNext = forInsert;
        forInsert->doublyPrev = *head;
    }
    else{
        while(tail->doublyNext!=(*head)){
            tail = tail->doublyNext;
        }
        (*head)->doublyPrev = tail;
        tail->doublyNext = forInsert;
        forInsert->doublyNext = (*head);
    }
}

void CDL_insertAfterNode(struct doublyNode* prevNode, struct doublyNode* newNode) 
{
    struct doublyNode* current = prevNode;
    if(isEmptyDL(prevNode))
        printf("Previous node cannot be NULL\n");
    else{
        prevNode = current -> doublyNext;
    }
    current->doublyNext = newNode;
    newNode->doublyNext = prevNode;
}

void CDL_deleteAtBeginning(struct doublyNode** head) 
{
    if(isEmptyDL(*head))
        printf("List is empty, cannot delete.\n");
    else{
        struct doublyNode *temp = *head;
        struct doublyNode* tail = *head;
        
        while(tail->doublyNext!=(*head)){
            tail = tail->doublyNext;
        }
        *head = (*head)->doublyNext;
        tail->doublyNext=(*head);
        free(temp);
        (*head)->doublyPrev = tail;
    }
}

void CDL_deleteAtEnd(struct doublyNode** head) 
{
    if(isEmptyDL(*head))
        printf("List is empty, cannot delete.\n");
    else{
        struct doublyNode *tail = *head;
        (*head)->doublyPrev = tail;
        while(tail->doublyNext->doublyNext!=(*head)){
            tail=tail->doublyNext;
        }
        struct doublyNode (*temp) = tail->doublyNext;

        free(temp);
        tail->doublyNext = *head;
        (*head)->doublyPrev = tail;
        
    }
}

void CDL_deleteAfterNode(struct doublyNode* head, int targetID) 
{
    if(isEmptyDL(head))
        printf("List is empty, cannot delete.\n");
    
    else {
        struct doublyNode *tail = head;
        while (tail->id != targetID) {
            tail = tail->doublyNext;
            if (tail->doublyNext == head) {
                printf("Node with ID %d not found in the list, cannot delete.\n", targetID);
                return;
            }
        }
        if (tail->doublyNext == head) {
            
            struct doublyNode *temp = head;
            head = head->doublyNext;
            free(temp);
        } else {
            struct doublyNode *temp = tail->doublyNext;
            tail->doublyNext = temp->doublyNext;
            free(temp);
        }
    }
}


void printDoublyCircularList(struct doublyNode* head)
{
    if(isEmptyDL(head))
        printf("List is empty.\n");
    else{
        struct doublyNode* current = head;
        do{
            printf("ID: %d, Child Name: %s, Parent Name: %s, Child Birth Year: %d, Parent Phone: %d\n", current->id, current->childName, current->parentName, current->childBY, current->parentPhone);
            current = current -> doublyNext;
        }
        while(current!=(head));
    }
}


struct doublyNode* searchCircularDoublyNode(struct doublyNode* head, int id) 
{
    if(isEmptyDL(head))
        printf("List is empty.\n");
    int targetID = id;
    struct doublyNode *current = head;
    do{
        if(current->id == targetID) return current;
        current = current->doublyNext;
    }while(current!=head);
    printf("Node with ID %d not found in the list, cannot insert or delete.\n", targetID);
    return NULL;
}



