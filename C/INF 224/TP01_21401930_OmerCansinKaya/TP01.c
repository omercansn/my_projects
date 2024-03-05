#include "TP01.h"


// QUESTION 1

bool isPrime(int num) // returns true or false
{
    int n;
    if(n<0) exit(1);
    if (num==0||num==1) return false;
    for(n=2;n<=sqrt(num);n++){
        if(num%n==0){
            return false;
        }
    }
    return true;
}

// QUESTION 2
void findPrimesInRange(int start, int end) { //prints the prime numbers in the range
    int num;

    for(num=start+1;num<end;num++){
        if(isPrime(num)==true){
            printf("%d\n", num);
        }
    }
}

// QUESTION 3
int greatestCommonDivisor(int a, int b) { // returns gcd
    return (b == 0) ? a : greatestCommonDivisor(b, a%b);
}

int leastCommonMultiple(int a, int b) { // returns lcm
    int max = (a>b) ? a : b;
    while(max % a !=0 || max % b !=0){
        max++;
    }
    return max;
}

int calculateOKEK(int num1, int num2, int num3) {
    int okek;
    okek = leastCommonMultiple(num1, leastCommonMultiple(num2, num3));
    return okek;
}


// QUESTION 4


int calculateOBEB(int num1, int num2, int num3) {
    int obeb;
    obeb = greatestCommonDivisor(num1, greatestCommonDivisor(num2, num3));
    return obeb;
}


// QUESTION 5
void findPrimeFactors(int num) { // prints the prime factors of the given number
    int factor;
    for(factor = 1; factor <= num; factor++){
        if(isPrime(factor) && num % factor == 0){
            printf("%d\n", factor);
        }
    }

}

// QUESTION 6
int isTriangle(int a, int b, int c) { // returns 1 (for true) or 0 (for false)
    return (((a-c) > -1*b || (c-a) < b)  && (b < (a+c))) ? 1 : 0;
}

//QUESTION 7
double calculateDistance(struct Point p1, struct Point p2) { // returns distance between two points
    double sqrx, sqry;
    sqrx = pow((p1.x-p2.x),2);
    sqry = pow((p1.y-p2.y),2);
    double distance = sqrt(sqrx+sqry);
    return distance;
}

// QUESTION 8
int collatz(int num) { // returns steps (int)
    int step=0;
    while(num>1){
        if(num%2==0){
            num/=2;
            printf("%d\n", num);
            step++;
        }
        else if(num%2!=0){
            num = num*3+1;
            printf("%d\n", num);
            step++;
        }
    }
    return step;
}

// QUESTION 9
int searchInArray(int arr[], int size, int target) { // returns count of the target number in the array
                                                    // should print the following part
	int count=0, position=0;
	while(position<=size){
		if(arr[position]==target){
            count++;
			printf("The number %d is found %d times in the array.\n", target, count);
			printf("Found as the %dth element of the array.\n", position + 1);
			
		}
		position++;
	}

    return count;
}


// QUESTION 10
// Print the matrix
void printMatrix(int mat[MAX_ROW][MAX_COL], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

// Calculate the sum of two matrices
int matrixAddition(int A[MAX_ROW][MAX_COL], int B[MAX_ROW][MAX_COL], int result[MAX_ROW][MAX_COL], int rows, int cols) {
// returns 1 for succes
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            result[i][j]=A[i][j]+B[i][j];
        }
    }
    return 1;
}

// Calculate the multiplication of two matrices
int matrixMultiplication(int A[MAX_ROW][MAX_COL], int B[MAX_ROW][MAX_COL], int result[MAX_ROW][MAX_COL], int m, int n, int p) {
// returns 1 for succes
    if (n != p) {
        return 0;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return 1;
}







// QUESTION 11
struct Line calculateLine(struct Point p1, struct Point p2) {
    struct Line line;
    double slope, intercept;

    if (p1.x == p2.x) {
        slope = -1;
        intercept = p1.x;
    } else {
        slope = (p2.y - p1.y) / (p2.x - p1.x);
        intercept = p1.y - slope * p1.x;
    }

    line.x = slope;
    line.y = intercept;

    return line;
}
