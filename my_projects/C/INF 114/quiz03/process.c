//
//  process.c
//
//

#include "process.h"
#include <assert.h>

// kuyruk boş mu değil mi kontrol etme
int is_empty(struct process_queue* head) {
    return(head==NULL?1:0);
}
//kuyruğun sonuna eleman ekleme
void enqueue(struct process_queue** head, struct process proc) {
    struct process_queue *new = (struct process_queue *) malloc(sizeof(struct process_queue));
    new->process = proc;
    new->next = NULL;

    if (is_empty(*head)) {
        *head = new;
        return;
    } else {
        struct process_queue *tail = *head;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = new;
    }
    return;
}

//kuyruğun başından eleman silme; process çekilip işlendikten sonra işlem süresi kalmadıysa.
void dequeue_and_pop(struct process_queue** head) {
    if(is_empty(*head)){
        printf("Queue is empty, I can't dequeue a process.");
        return;
    }
    else{
        struct process_queue *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    return;
}

//kuyruğun başına eleman ekleme
void push(struct process_queue** top, struct process proc) {
    struct process_queue *new = (struct process_queue *) malloc(sizeof(struct process_queue));
    new->process = proc;
    new->next = *top;
    *top = new;
    
    return;
}
//kuyruğun başındaki elemanı çekme; free işlemi yok
struct process_queue* peek(struct process_queue* head) {
    return(head==NULL?NULL:head);   
}



//kuyruğun başındaki elemanı sona atma; standart process çekilip işlendikten sonra süresi kaldıysa.
void round_queue(struct process_queue** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return;  // Nothing to round or only one element in the queue
    }
    struct process_queue* first = *head;
    *head = (*head)->next;
    first->next = NULL;

    struct process_queue* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = first;
    return;
}

void print_queue(struct process_queue* head) {
    if(head == NULL) {
        printf("Process Queue is empty \n");
    }
    while(head != NULL) {
        printf("Process PID: %d -> ", head->process.PID);
        head = head->next;
    }
    printf("NULL \n");
    return;
}
