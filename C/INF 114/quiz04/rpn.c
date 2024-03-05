#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include"rpn.h"
#include"stack.h"


double compute_operation(double op1, double op2, char operation) {
    
    double result = 0.0;
   
    switch(operation){
        case '+': {
            result = op1 + op2;
            break;
        }
        case '-': {
            result = op1 - op2;
            break;
        }
        case '*': {
            result = op1 * op2;
            break;
        }
        case '/': {
            if(op2==0){
                printf("I can't divide a number by %.0f. The program will be terminated automatically.", result);
                exit(0);
            }
            else result = op1 / op2;
            break;
        }
        default:{
            printf("Invalid character. The program will be terminated.");
            
        }
    }
    return result;
}


double evaluate_RPN(char *expr, struct stackNode **top) {
    double retval = 0.0;
    double number1 = 0., number2 = 0.;
    double miniResult = 0.0;
    char op;
    *top = NULL;
    char unite = expr[0];
    int i = 0;
   
    while(unite!='\0'){
        if(isdigit(unite)){
            stack_push(top, unite - '0');
            stack_print(*top);
            printf("\n");
        }
        else if(unite == '+' || unite == '-' || unite == '*' || unite == '/'){
            if(is_empty(*top)){
                break;
            }
            number2 = stack_pop(top);
            if(is_empty(*top)){
                break;
            }
            number1 = stack_pop(top);
            op = unite;
            miniResult = compute_operation(number1, number2, op);
            stack_push(top, miniResult);
            stack_print(*top);
            printf("\n");
        }
        else{
            printf("Invalid characters.\n");
            break;
        }
        i++;
        unite = expr[i];
    }

    
    if(!is_empty(*top)){
        retval = stack_pop(top);
        if(!is_empty(*top)){
            printf("Compute_operation function ERROR!");
        }

	
    }
    stack_free(top);
    return retval;
}


void rpn_test_evaluate_RPN(){
	
    struct stackNode *stack = NULL;
    printf("Testing equation 13+2-\n");
    
	assert(evaluate_RPN("13+2-", &stack) == 2.0);
    printf("\nTesting equation 62+5*84/-\n");
	assert(evaluate_RPN("62+5*84/-", &stack) == 38.0);
    stack_free(&stack);
	printf("\nThe tests are successful.\n");
}
