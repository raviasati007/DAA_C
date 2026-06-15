#include <stdio.h>
/* Aim: You are an engineer aboard a cutting-edge ISRO interplanetary spacecraft en route to Mars. The navigation computer must perform lightning-fast 4×4 matrix multiplications to continuously adjust the spacecraft's flight trajectory.
To conserve fuel and reduce computational load, the system uses Strassen's Divide and Conquer Matrix Multiplication algorithm. Instead of multiplying directly, the 4×4 matrices are split into 2×2 quadrants and Strassen's method is applied recursively.
*/

// Function to add two matrices
void add(int n, int A[n][n], int B[n][n], int C[n][n]) {
	int i,j;
    for ( i = 0; i < n; i++)
        for ( j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

// Function to subtract two matrices
void subtract(int n, int A[n][n], int B[n][n], int C[n][n]) {
		int i,j;
    for ( i = 0; i < n; i++)
        for ( j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

// Strassen’s multiplication for 2x2 matrices
void strassen2(int A[2][2], int B[2][2], int C[2][2]) {
    int m1 = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);
    int m2 = (A[1][0] + A[1][1]) * B[0][0];
    int m3 = A[0][0] * (B[0][1] - B[1][1]);
    int m4 = A[1][1] * (B[1][0] - B[0][0]);
    int m5 = (A[0][0] + A[0][1]) * B[1][1];
    int m6 = (A[1][0] - A[0][0]) * (B[0][0] + B[0][1]);
    int m7 = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1]);

    C[0][0] = m1 + m4 - m5 + m7;
    C[0][1] = m3 + m5;
    C[1][0] = m2 + m4;
    C[1][1] = m1 - m2 + m3 + m6;
}

// Strassen’s multiplication for 4x4 matrices
void strassen4(int A[4][4], int B[4][4], int C[4][4]) {
	int i,j;
    // Split into 2x2 submatrices
    int A11[2][2], A12[2][2], A21[2][2], A22[2][2];
    int B11[2][2], B12[2][2], B21[2][2], B22[2][2];
    int C11[2][2], C12[2][2], C21[2][2], C22[2][2];

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j+2];
            A21[i][j] = A[i+2][j];
            A22[i][j] = A[i+2][j+2];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j+2];
            B21[i][j] = B[i+2][j];
            B22[i][j] = B[i+2][j+2];
        }
    }

    // Compute submatrix products using Strassen
    int P1[2][2], P2[2][2], P3[2][2], P4[2][2];
    int P5[2][2], P6[2][2], P7[2][2];

    int tempA[2][2], tempB[2][2];

    // P1 = (A11 + A22)(B11 + B22)
    add(2, A11, A22, tempA);
    add(2, B11, B22, tempB);
    strassen2(tempA, tempB, P1);

    // P2 = (A21 + A22)B11
    add(2, A21, A22, tempA);
    strassen2(tempA, B11, P2);

    // P3 = A11(B12 - B22)
    subtract(2, B12, B22, tempB);
    strassen2(A11, tempB, P3);

    // P4 = A22(B21 - B11)
    subtract(2, B21, B11, tempB);
    strassen2(A22, tempB, P4);

    // P5 = (A11 + A12)B22
    add(2, A11, A12, tempA);
    strassen2(tempA, B22, P5);

    // P6 = (A21 - A11)(B11 + B12)
    subtract(2, A21, A11, tempA);
    add(2, B11, B12, tempB);
    strassen2(tempA, tempB, P6);

    // P7 = (A12 - A22)(B21 + B22)
    subtract(2, A12, A22, tempA);
    add(2, B21, B22, tempB);
    strassen2(tempA, tempB, P7);

    // Compute C submatrices
    for (i = 0; i < 2; i++) {
        for ( j = 0; j < 2; j++) {
            C11[i][j] = P1[i][j] + P4[i][j] - P5[i][j] + P7[i][j];
            C12[i][j] = P3[i][j] + P5[i][j];
            C21[i][j] = P2[i][j] + P4[i][j];
            C22[i][j] = P1[i][j] - P2[i][j] + P3[i][j] + P6[i][j];
        }
    }

    // Combine submatrices into C
    for (i = 0; i < 2; i++) {
        for ( j = 0; j < 2; j++) {
            C[i][j]     = C11[i][j];
            C[i][j+2]   = C12[i][j];
            C[i+2][j]   = C21[i][j];
            C[i+2][j+2] = C22[i][j];
        }
    }
}

int main() {
    int A[4][4], B[4][4], C[4][4];
     int i,j;
    printf("Enter elements of the first 4x4 matrix (A):\n");
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            scanf("%d", &A[i][j]);

    printf("Enter elements of the second 4x4 matrix (B):\n");
    for ( i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            scanf("%d", &B[i][j]);

    strassen4(A, B, C);

    printf("\nProduct Matrix (Result):\n");
    for ( i = 0; i < 4; i++) {
        for ( j = 0; j < 4; j++) {
            printf("%d\t", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}

