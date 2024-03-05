#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

#define MAX_ROW 100
#define MAX_COL 100


struct Point {
    double x;
    double y;
};


struct Line {
    double x;
    double y;
};

bool isPrime(int num);
void findPrimesInRange(int start, int end);
int greatestCommonDivisor(int a, int b);
int leastCommonMultiple(int a, int b);
int calculateOKEK(int num1, int num2, int num3);
int calculateOBEB(int num1, int num2, int num3);
void findPrimeFactors(int num);
int isTriangle(int a, int b, int c);
double calculateDistance(struct Point p1, struct Point p2);
int collatz(int num);
int searchInArray(int arr[], int size, int target);
void printMatrix(int mat[MAX_ROW][MAX_COL], int rows, int cols);
int matrixAddition(int A[MAX_ROW][MAX_COL], int B[MAX_ROW][MAX_COL], int result[MAX_ROW][MAX_COL], int rows, int cols);
int matrixMultiplication(int A[MAX_ROW][MAX_COL], int B[MAX_ROW][MAX_COL], int result[MAX_ROW][MAX_COL], int m, int n, int p);
struct Line calculateLine(struct Point p1, struct Point p2);
