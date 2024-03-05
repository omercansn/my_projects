//
//  stack.c
//  stack
//
//  Created by timoteosonurozcelik on 08/04/2023.
//

#include "stack.h"

int is_empty(struct node* top) {
    if(top == NULL) {
        return 1; // stack is empty
    } else {
        return 0; // stack is not empty
    }
}

void push(struct node** top, int value) {
    struct node* new = (struct node*) malloc(sizeof(struct node));
    new->value = value;
    if(is_empty(*top)) {
        new->next = NULL;
    } else {
        new->next = *top;
    }
    *top = new;
}

int pop(struct node** top) {
    if(*top==NULL) {
        printf("Stack is already empty, I can't pop any element.\n");
        return -1;
    } else {
        struct node* temp = *top;
        int value = temp->value;
        *top = (*top)->next;
        free(temp);
        return value;
    }
}

int get_size(struct node* top) {
    struct node * index = top;
    int size=0;
    if(index==NULL) return 0;
    while(index!=NULL){
        size++;
        index=index->next;
    }
    return size;
}
