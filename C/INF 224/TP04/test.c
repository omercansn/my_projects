#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"
#define MAX_SIZE 10
#define INPUT_SIZE 1



int main() {
    srand(time(0));
    struct person removed_member_customer;
    struct person removed_member_noncustomer;
    
    char input[INPUT_SIZE];
    scanf("%s", input);
    int case_no = atoi(input);

    switch(case_no)
    {
      case 1:{
        printf("Using customer and non-customer queues:\n");
        printf("---------------------------------------\n");

        // TODO:
        // Create two queues of type queue, named customer and non-customer, 
        // and do as requested in the assignment document:

       

        // Create empty customer and non-customer queues of size 5 each
        
        queue *bankQueueCustomer = create(5);
        if (bankQueueCustomer == NULL) {
            return -1;
        }
        queue *bankQueueNonCustomer = create(5);
        if (bankQueueNonCustomer == NULL) {
            return -1;
        }
        person *Customer = bankQueueCustomer->people;
        person *NonCustomer = bankQueueNonCustomer->people;
        
        // First, 4 non-customers come to the bank.
        for(int i=0; i<4; i++) {
          NonCustomer[i].isClient = false;
          NonCustomer[i].money = (1 + rand() % 190 / 10 ) * 50 + rand() % 2 / 2.0; // ondalik kisim ve tam kisim 50 ve katlari olsun diye
          add(bankQueueNonCustomer, NonCustomer[i]);
        }


        printf("4 non-customers are added to non-customer queue:\n");
        printf("Customer queue:\n");
        display_all(bankQueueCustomer);

        printf("Non-customer queue:\n");
        display_all(bankQueueNonCustomer);
        printf("\n");


        // Then 2 people who are customers come in.
        for(int j=0; j<2; j++) {
          Customer[j].isClient = true;
          Customer[j].money = (1 + rand() % 190 / 10 ) * 50 + rand() % 2 / 2.0; // ondalik kisim ve tam kisim 50 ve katlari olsun diye
          add(bankQueueCustomer, Customer[j]);
        }

        printf("2 customers are added to customer queue:\n");
        printf("Customer queue:\n");
        display_all(bankQueueCustomer);

        printf("Non-customer queue:\n");
        display_all(bankQueueNonCustomer);
        printf("\n");

        // Then 3 people take turns at the bank and exit their queues. 
        // But here, first the queue of customers will be empty, 
        // then the queue of non-customers will start to be processed.  
        // Therefore, until there are no more people in the customer queue, 
        //the customers will take turns to do their bank transactions
        for(int k=0; k<2; k++){
          remove_person(bankQueueCustomer);
        }
        for(int k=0; k<1; k++){
          remove_person(bankQueueNonCustomer);
        }

        printf("3 people exit the queue (2 customer, 1 non-customer):\n");
        printf("Customer queue:\n");
        display_all(bankQueueCustomer);

        printf("Non-customer queue:\n");
        display_all(bankQueueNonCustomer);
        printf("\n");

        free(bankQueueCustomer->people);
        free(bankQueueNonCustomer->people);
        break;
    
      }
      case 2: {
        int i,j,k,l; // variables for the loops
        printf("Using solely one queue:\n");
        printf("------------------------\n");

        // TODO
        // Create a queue of type queue, 
        // do the things requested in the assignment document
      
        // Create an empty queue of size 10
        queue *bankQueue = create(MAX_SIZE);
        if (bankQueue == NULL) {
            return -1;
        }
        person *Person = bankQueue->people;

        // Add 5 non-customers to queue
        for(i=0; i<5; i++) {
          Person[i].isClient = false;
          Person[i].money = (1 + rand() % 190 / 10 ) * 50 + rand() % 2 / 2.0; // ondalik kisim ve tam kisim 50 ve katlari olsun diye
          add(bankQueue, Person[i]);
        }

        printf("5 non-customers are added to queue:\n");
        display_all(bankQueue);
        printf("\n");

        

        // Add 2 bank customers to the queue.
        for(j=0; j<2; j++) {
          shift_all(bankQueue);
          Person[j].isClient = true;
          Person[j].money = (1 + rand() % 190 / 10 ) * 50 + rand() % 2 / 2.0; // ondalik kisim ve tam kisim 50 ve katlari olsun diye
          
          add_customer(bankQueue, Person[j]);
        }

        printf("2 customers are added to queue:\n");
        display_all(bankQueue);
        printf("\n");


        // Add 4 new non-customers to the queue 
        // (Note that it will give an error if the queue is full)
        for(k=i+2; k<i+6; k++) {
          Person[k].isClient = false;
          Person[k].money = (1 + rand() % 190 / 10 ) * 50 + rand() % 2 / 2.0; // ondalik kisim ve tam kisim 50 ve katlari olsun diye
          add(bankQueue, Person[k]);
        }

        printf("4 non-customers are added to queue:\n");
        display_all(bankQueue);
        printf("\n");

        // First remove 2 people from the queue. 

        for(l=0; l<2; l++){
          remove_person(bankQueue);
        }

        printf("2 people are removed from the queue:\n");
        display_all(bankQueue);
        printf("\n");

        // Then add 1 non-bank customer
        
        add(bankQueue, Person[k-1]);

        printf("1 non-customers are added to queue:\n");
        display_all(bankQueue);
        printf("\n");

        free(bankQueue);
        bankQueue = NULL;
        break;

      }
      
    }

    
    return 0;
}
