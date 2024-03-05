#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
} node;

int is_empty(node* head){
    return(head==NULL?1:0);
}

void push(node** head, int value){
    node* new = (node*) malloc(sizeof(node));
    new->data = value;
    if(is_empty(*head)){
        new->next = NULL;
    }
    else{
        new->next = *head; 
    }
    *head = new;
    
}
void pop(node** head){
    if(is_empty(*head)){
        printf("The stack is empty, I can't pop any element.");
        return;
    }
    else{
        node* temp = *head;
        *head=(*head)->next;
        free(temp);
    }
    return;
}

void print_stack(node** head) {
    if (is_empty(*head)) {
        printf("Stack is empty.");
    } else {
        node* current = *head;
        while (current != NULL) {
            if(current->next == NULL) printf("%d", current->data);
            else printf("%d - ", current->data);
            current = current->next;
        }
    }
}

int main(int argc, const char* argv[]){
    node *head = NULL;
    printf(">>> Stack: "); print_stack(&head);
    push(&head, 7);
    printf("\n>>> Stack: "); print_stack(&head);
    push(&head, 4);
    printf("\n>>> Stack: "); print_stack(&head);
    push(&head, 12);
    printf("\n>>> Stack: "); print_stack(&head);
    push(&head, 14);
    printf("\n>>> Stack: "); print_stack(&head);
    pop(&head);
    printf("\n>>> Stack: "); print_stack(&head);
    pop(&head);
    printf("\n>>> Stack: "); print_stack(&head);
    pop(&head);
    printf("\n>>> Stack: "); print_stack(&head);
    pop(&head);
    printf("\n>>> Stack: "); print_stack(&head);
    return 0;
}