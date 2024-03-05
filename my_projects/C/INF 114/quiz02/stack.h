//
//  stack.h
//  stack
//
//  Created by timoteosonurozcelik on 08/04/2023.
//

#ifndef stack_h
#define stack_h

#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node* next;
};

void push(struct node** top, int value);
int pop(struct node** top);

int is_empty(struct node* top);
int get_size(struct node* top);


#endif /* stack_h */
