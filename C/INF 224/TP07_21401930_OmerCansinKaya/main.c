#include <stdio.h>
#include <limits.h>
#include <assert.h>
#include "TP07.h"

int main() {

    int arr1[] = { 16, 4, 10, 14, 7, 9, 3, 2, 8, 1 };
    int arr2[] = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
    int heap[] = { 16, 14, 10, 8, 7, 9, 3, 2, 4, 1 };
    int size = sizeof(heap) / sizeof(heap[0]);

    // Call the max heapify recursive function for the element of arr1 that breaks the max-heap property
    printf(">> max_heapify_recursive called for arr1\n");
    int index_to_heapify = 1;  // Choose an index to heapify
    max_heapify_recursive(arr1, index_to_heapify, SIZE);
    printf("heap after max_heapify_recursive: ");
    print_heap(arr1, SIZE);

    // Test case for max heapify recursive
    printf("\n>> max_heapify_recursive is working smoothly, continue on your way...\n");

    // Transform arr2 to a heap with build_max_heap
    printf(">> build_max_heap called for arr2\n");
    build_max_heap(arr2, SIZE);
    printf("heap after build_max_heap: ");
    print_heap(arr2, SIZE);

    // Test case for build_max_heap
    printf("\n>> build_max_heap is working smoothly, continue on your way...\n");

    // We will perform the next operations using priority queue functions on the heap array.
    printf("----- Priority Queue -----\n");

    // In the priority queue, pull the highest priority element from the queue, print the updated
    // queue structure and the value of the element you have drawn on the screen.
    int max = extractMax(heap, size);
	size--;
    printf(">> extracted max = %d\nqueue: ", max);
    print_heap(heap, size);

    // repeat previous action
    int max2 = extractMax(heap, size);
	size--;
    printf("\n>> extracted max = %d\nqueue: ", max2);
    print_heap(heap, size);
    printf("\n");

    // Add an element with a value (priority) of 35 to the priority queue
    insertData(heap, 35);
    printf(">> 35 is added\nqueue: ");
	size++;
    print_heap(heap, size);
    printf("\n");

    // remove the element with index 5 from the priority queue
    removeIndex(heap, 5);
    printf(">> The element with priority %d is removed from the queue\nqueue: ", heap[5]);
	size--;
    print_heap(heap, size);
    printf("\n");

    // Set the priority of the 3-index element of the priority queue to 41
    changePriority(heap, 3, 41);
    printf(">> The priority of the element with priority %d has been updated\nqueue: ",
            heap[3]);
    print_heap(heap, size);

    return 0;
    
}