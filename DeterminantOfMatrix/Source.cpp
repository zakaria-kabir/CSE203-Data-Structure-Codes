#include<iostream>
#include<cmath>
#include<conio.h>
using namespace std;
double determinant(double mat[100][100], int n) {
    double det, submat[100][100];
      
        if (n == 1) {
            return mat[0][0];
        }
        
        else {
            det = 0;     
            for (int col = 0; col < n; col++) {
               int subi = 0, subj = 0;
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        submat[i][j] = 0;
                        if (i != 0 && j != col) {
                            submat[subi][subj] = mat[i][j];
                            if (subj < n - 2) {
                                subj++;
                            }
                            else {
                                subj = 0;
                                subi++;
                            }
                        }
                    }
                }
                det = det + pow(-1,col) * mat[0][col] * determinant(submat, n - 1);                     
            }
        }
    return det;
}
int main() {
    int n;
    double matrix[100][100];
    cout << "Enter the size of the matrix: ";
    cin >> n;
    if (n > 100) {
        exit(0);
    }
    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << "The entered matrix is: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Determinant of the matrix is : " << determinant(matrix, n);
    _getch();    
}
