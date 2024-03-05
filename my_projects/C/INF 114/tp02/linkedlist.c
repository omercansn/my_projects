//
//  linkedlist.c
//  linkedlist
//

#include "linkedlist.h"

void insert_element(struct node** head, int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    struct node *prev = NULL;
    struct node *current = *head;

    while (current != NULL && current->data < data)
    {
        prev = current;
        current = current->next;
    }

    if (prev == NULL)
    {
        new_node->next = *head;
        *head = new_node;
    }
    else
    {
        prev->next = new_node;
        new_node->next = current;
    }
}

void remove_element(struct node** head, int data) {
    struct node *prev = NULL;
    struct node *current = *head;

    while (current != NULL)
    {
        if (current->data == data)
        {
            if (prev == NULL) *head = current->next;
            else prev->next = current->next;

            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

int search_element(struct node* head, int data) {
    int index=0;
    struct node* tmp = (head)->next;
    while(tmp!=NULL){
        if(tmp->data==data){
            index++;
            return index;
        }
        else{
            tmp = tmp->next;
            index++;
        }
    }
}

int get_length(struct node* head) {
    int length=1;
    struct node* tmp = (head)->next;
    while(tmp!=NULL){
        length++;
        tmp = tmp->next;
    }
    return length;
}

void reverse(struct node** head_ref) {
    struct node* prev = NULL;
    struct node* current = *head_ref;
    struct node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head_ref=prev;
}

void print(struct node* head) {
    struct node* tmp = head;
    printf("Linked list: ");
    while (tmp != NULL) {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}
