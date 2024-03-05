//
//  main.c
//  queue_cpu_scheduling
//
//  Created by timoteosonurozcelik on 12/04/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include "process.h"

#define NPROC 5
#define ProcessID 30000

struct process create_process(int PID, int duration, int is_interrupt) {
    struct process proc = {PID, duration, is_interrupt};
    return proc;
}

void round_robin(struct process_queue* head, int pid) {
    int i = 0; // Buradaki pid ve i değerleri PID değerlerinin unique olması için belirtilen parametreler. Pek takılmanıza gerek yok.
    while(!is_empty(head)) {
        // %20 ihtimalle kesme gelir ve (10, 20)ms sürelerinden birinin uzunluğunda kesme process'i kuyruğa eklenir.
        if((rand() % 10) <= 1) {
            printf("Interruption with PID: %d came.\n", pid + i);
            struct process process = create_process(pid + i, (rand() % 2 + 1) * 10, 1);
            
            //TODO: Kesme geldiğinde, kesme processi kuyruğun başına eklenir.
            push(&head, process);
            i++;
        }
        //TODO: Process çekilecek.
        struct process_queue *RelatedProcess;
        RelatedProcess = peek(head);
        //TODO: Eğer process interrupt(kesme) ise süresinden (dur) 10 düşülecek, işlem süresi kalmadıysa kuyruktan silinecek.
        if(RelatedProcess->process.is_interrupt == 1){
            RelatedProcess->process.dur -= 10;
            if(RelatedProcess->process.dur < 10){
                dequeue_and_pop(&head);
            }
        }
        //TODO: Eğer process standart process ise süresinden (dur) 10 düşülecek, işlem süresi kalmadıysa kuyruktan silinecek. İşlem süresi kaldıysa kuyruğun sonuna aktarılacak.
        else{
            RelatedProcess->process.dur -= 10;
            if(RelatedProcess->process.dur >= 10){
                round_queue(&head);
            }
            else dequeue_and_pop(&head);
        }
        print_queue(head);
    }
}

int main(int argc, const char * argv[]) {
    int i;
    struct process_queue* head = NULL;
    // Tanımlanan NPROC değeri kadar ProcessID'den ProcessID + NPROC'a kadar PID'si olan kesme olmayan standart süreçler kuyruğa eklenir.
    for(i=0; i<NPROC; i++) {
        printf("***");
        // create process with duration among (10, 20, 30, 40) ms.
        struct process process = create_process(ProcessID + i, (rand() % 4 + 1) * 10, 0);
        
        //TODO: Yaratılan process'i kuyruğun sonuna ekleyin.
        enqueue(&head, process);
        print_queue(head);
    }
    
    round_robin(head, ProcessID + i);
    return 0;
}
