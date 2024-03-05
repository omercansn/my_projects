#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

#include "stack.h"
#include "rpn.h"

#define LINE_MAX 20

int main(int argc, char *argv[]) {

	char line[LINE_MAX];
	
	struct stackNode *stack = NULL;
	while(1){
		printf("For quitting the program, type \"exit\" and press ENTER\n");
		printf("Enter an equation: ");
		scanf("%s", line);
		if(strcmp("exit", line)==0 || strcmp("EXIT", line)==0 || strcmp("Exit", line)==0){
			return 0;
		}
		else{
			double finalResult = evaluate_RPN(line, &stack);
			printf("The result of this equation is: %.2f\n", finalResult);
			continue;
		}
	}

}
