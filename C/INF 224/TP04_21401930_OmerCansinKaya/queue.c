#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "queue.h"

queue *create(int capacity) 
{
    queue* newQueue = (queue*)malloc(sizeof(queue));
    if (newQueue == NULL) {
        printf("Failed to allocate memory for the queue.\n");
        return NULL;
    }
    newQueue->front = -1;
    newQueue->rear = -1;
    newQueue->capacity = capacity;
    newQueue->size = 0;
    newQueue->people = (person*)calloc(capacity+1,sizeof(person));
    return newQueue;
}


bool is_full(queue *q) 
{
    return (q->rear == q->capacity-1 ? true : false);
}


bool is_empty(queue *q) 
{
    return (q->front == -1 || q->rear == -1 ? true : false);
}

void add(queue *q, person k) {
    if (is_full(q)) {
        printf("Queue is full, failed to add person.\n");
        return;
    } else {
        if (is_empty(q)) {
            q->front++;
        }
        q->rear++;
        q->size++;
        q->people[q->rear] = k;
    }
}


person remove_person(queue *q) 
{
    person toDelete;
    if(is_empty(q)){
        printf("Queue is empty, failed to delete person.\n");
    }
    else{
        toDelete = q->people[q->front];
        for(int n=q->front; n<=q->rear; n++){
            q->people[n] = q->people[n+1];
        }
        q->size--;
        q->rear--;
        
    }
    if (q->front > q->rear) {
        // Reset front and rear indices
        q->front = -1;
        q->rear = -1;
    }
    return toDelete;
}


void shift_all( queue *q) 
{
    if(is_empty(q)) {
        printf("Queue is empty, cannot be shifted.\n");
        return;
    }
    else if(is_full(q)) {
        printf ("Queue is full, cannot be shifted.\n");
        return;
    }
    else{
        for(int i=q->rear; i>=q->front; i--){
            q->people[i+1] = q->people[i];
        }
        q->front++;
        q->rear++;
    }

}


void add_customer( queue *q,  person k) 
{
    if(is_full(q)) {
        printf("Queue is full, failed to add person.\n");
        return;
    }
    else{
        q->front--;
        q->size++;
        q->people[q->front] = k;
    }
}


void display_all(queue *q) 
{
    if(is_empty(q)) printf("Queue is empty.\n");
    else{
        printf("Queue Status:\n");
        int i = q->front;
        int count = 0;
        while (count < q->size) {
            printf("Is Client: %s, Money: %.2f\n", q->people[i].isClient ? "Yes" : "No", q->people[i].money);
            i++;
            count++;
        }
    }
}
