#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"


void stack_free(struct stackNode** top) {
    
    struct stackNode* cursor = *top;
    
   
    while(cursor!=NULL){
        struct stackNode* orphan = cursor;
        
        
    

        
        cursor = cursor -> next;
       
        free(orphan);
    //}
    }
    
    * top = NULL;  
}



int is_empty(struct stackNode *top){
    int result = 0;
    
    result = (top==NULL?1:0);


    return result;
}


void stack_push(struct stackNode **top, double data) {
	
    
    struct stackNode* new = (struct stackNode*) malloc(sizeof(struct stackNode));
    
    new -> data = data;
    if(is_empty(*top)){
        new -> next = NULL;
    }
    else{
        new -> next = *top;
    }
    
    *top = new;
}



double stack_pop(struct stackNode **top) {
	double retval = -1;

    if(is_empty(*top)){
        return retval;
    }
    else{
        struct stackNode* temp = *top;
        retval = temp -> data;
        *top = (*top) -> next;
        free(temp);

    } 
    return retval;
}



void stack_multi_pop(struct stackNode **top, int number){
    for(int i=1; i<=number; i++){
        stack_pop(top);
    }
}



void stack_print(struct stackNode *top) {
    
    if(is_empty(top)){
        printf("The stack is empty, I can't do any calculation");
        return;
    }
    else{
        struct stackNode* current = top;
        while(current != NULL){
            printf("%.2lf -> ", current -> data);
            current = current -> next;
        }
        printf("NULL");
        
    }
    return ;
}


