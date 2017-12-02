/*
Given an image represented by an NxM matrix, where each pixel in the image is
4 bytes, write a method to rotate the image by 90 degrees. Can you do this in
place?.

Approach:
an int is 4 bytes... hence lets do this with a matrix of integers.
lets suppose we have a matrix of 3x4
1 2  3  4
5 6  7  8
9 10 11 12

And we want to rotate it 90 deg clockwise so it should look like:
9  5 1
10 6 2
11 7 3
12 8 4

So we basically need to map a normal matrix that we go through to the new
indexes, basically find a pattern that does this:
0,0 -> 0,2
0,1 -> 1,2
0,2 -> 2,2
0,3 -> 3,2
1,0 -> 0,1
1,1 -> 1,1
1,2 -> 2,1
1,3 -> 3,1
2,0 -> 0,0
2,1 -> 1,0
.
.

After this we can conclude that in the rotated matrix each newI becomes a j in
the unrotated matrix and the newJ is a N-i-1.
*/

#include <iostream>

using namespace::std;

const int N = 3;
const int M = 4;

void PrintMatrix(int* matrix, int n, int m);

void RotateMatrixClockWise(int* matrix, int* rot, int originalN, int originalM);

int GetValue(int matrixWidth, int *matrix, int i, int j) {
    return matrix[i*matrixWidth+j];
}

void SetValue(int matrixWidth, int* matrix, int i, int j, int val) {
    matrix[i*matrixWidth+j] = val;
}

int test[] = {
    1,2,3,4,
    5,6,7,8,
    9,0,1,2
};
int rotatedMatrix[N*M];

int main(int argc, char* argv[]) {
    cout << "Original Picture" << endl;
    PrintMatrix(test, N, M);

    cout << endl << "Rotated picture" << endl;
    RotateMatrixClockWise(test, rotatedMatrix, N, M);
    PrintMatrix(rotatedMatrix, M, N);
}

void RotateMatrixClockWise(int* matrix, int* rot, int originalN, int originalM) {
    for(int i = 0; i < originalN; i++)
        for(int j = 0; j < originalM; j++) {
            int newI = j;
            int newJ = originalN-i-1;
            SetValue(originalN, rot, newI, newJ, GetValue(originalM, matrix, i, j));//we use originalN as width because after rotating, the matrix that was NxM converts to MxN
        }
}


void PrintMatrix(int* matrix, int n, int m) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << GetValue(m, matrix, i, j) << " ";
        }
        cout << endl;
    }
}
