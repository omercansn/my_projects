#include <vector>
#include <iostream>
#include <ctype.h>
#include <unistd.h>
using namespace std;

using matrice = vector<vector<double>>;

class Matrice {
public:
    matrice addition(matrice A, matrice B);
    matrice soustraction(matrice A, matrice B);
    matrice multiplication(matrice A, matrice B);
};

matrice Matrice::addition(matrice A, matrice B) {
    matrice C = A;  // Initialize C with the same size as A
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < B.size(); j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

matrice Matrice::soustraction(matrice A, matrice B) {
    matrice C = A;  // Initialize C with the same size as A
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < B.size(); j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    return C;
}

matrice Matrice::multiplication(matrice A, matrice B) {
    int n = A.size();
    int m = B[0].size();
    int p = B.size();
    matrice C(n, vector<double>(m, 0.0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < p; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

matrice saisirMatrice(int n) {
    matrice N(n, vector<double>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "[" << i << "][" << j << "] : ";
            cin >> N[i][j];
        }
    }
    return N;
}

int main() {
    int n;
    char caseChar[2];
    cout << "Enter the element number of the square matrice : ";
    cin >> n;
    if (n==0){
        cout << "There is no space for entering number. Program will be terminated.";
        sleep(1);
        return 0;
    }
    cout << "Enter the elements of first matrice : ";
    matrice A = saisirMatrice(n);
    cout << "Enter the elements of second matrice : ";
    matrice B = saisirMatrice(n);

    Matrice matriceCalculator;
    while(1){
        cout << "For exiting press 0, " << endl;
        cout << "For additioning press 1, " << endl;
        cout << "For substracting press 2, " << endl;
        cout << "For multiplication press 3, " << endl;
        cout << "Enter a number for the desired operation: " << endl;
        cin >> caseChar;
        int caseNo = atoi(caseChar);
        switch(caseNo){
            case 0: break;
            case 1: {
                matrice C_add = matriceCalculator.addition(A, B);
                for (int i = 0; i < C_add.size(); i++) {
                    for (int j = 0; j < C_add.size(); j++) {
                        cout << C_add[i][j] << " ";
                    }
                    cout << endl;
                }
        
                break;
            }
            case 2: {
                matrice C_sub = matriceCalculator.soustraction(A, B);
                for (int i = 0; i < C_sub.size(); i++) {
                    for (int j = 0; j < C_sub.size(); j++) {
                        cout << C_sub[i][j] << " ";
                    }
                    cout << endl;
                }
                break;
            }
            case 3: {
                matrice C_mul = matriceCalculator.multiplication(A, B);
                for (int i = 0; i < C_mul.size(); i++) {
                    for (int j = 0; j < C_mul.size(); j++) {
                        cout << C_mul[i][j] << " ";
                    }
                    cout << endl;
                }
                break;
            }
            default: {
                cout << "Wrong number, please enter 0,1,2 or 3!" << endl;
                sleep(1);
                continue;
            }
        }
        if(caseNo == 0) break;
        sleep(1);
        cout << endl;
    }
    
    return 0;
}
