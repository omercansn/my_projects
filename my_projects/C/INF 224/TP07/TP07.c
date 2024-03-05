#include <stdio.h>
#include <limits.h>
#include <assert.h>
#include "TP07.h"

void print_heap(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void max_heapify_recursive(int *arr, int index, int size) {
    int largest = index;
    int left_child = 2*index+1;
    int right_child = 2*index+2;

    if (left_child < size && arr[left_child] > arr[largest]) {
        largest = left_child;
    }

    if (right_child < size && arr[right_child] > arr[largest]) {
        largest = right_child;
    }

    if (largest != index) {
        SWAP(arr[index],arr[largest]);
        max_heapify_recursive(arr, largest, size);
    }
}

void build_max_heap(int *arr, int size) {
    for (int i=(size/2)-1; i>=0; i--) {
        max_heapify_recursive(arr, i, size);
    }
}

int extractMax(int *arr, int size) {
    int max = arr[0];
    arr[0] = arr[size - 1];
    size--;
    max_heapify_recursive(arr, 0, size);
    return max;
}

void bubbleUp(int *arr, int index) {
    while (index > 0 && arr[(index-1) / 2] < arr[index]) {
        SWAP(arr[index],arr[(index-1) / 2]);
        index = (index-1) / 2;
    }
}

void insertData(int *arr, int data) {
    int size = sizeof(&arr);
    size++;
    arr[size-1] = data;
    bubbleUp(arr, size-1);
}

void removeIndex(int *arr, int index) {
    int size = sizeof(&arr);
    if (index<0 || index>=size) {
        printf("Invalid index to remove\n");
        return;
    }

    arr[index] = arr[size];
    size--;
    max_heapify_recursive(arr, index, size);
}

void changePriority(int *arr, int index, int priority) {
    int size = sizeof(&arr);
    int oldPriority = arr[index];
    arr[index] = priority;
    if (priority > oldPriority) {
        bubbleUp(arr, index);
    } else {
        max_heapify_recursive(arr, index, size);
    }
}