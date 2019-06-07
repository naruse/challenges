/*
  Write an algorithm such that if an element in an MxN matrix is 0, its entire
  row and column are set to 0.

  Approach: We dont care where are 0's exactly, we just need to know if at a
  given row/column there is a 0 somewhere.

  we use 2 bool arrays to mark 0's and then lets fill the matrix where we
  find 0's in either of the arrays
 */

#include <iostream>

using namespace::std;

int GetValue(int matrixWidth, int* matrix, int i, int j);
void SetValue(int matrixWidth, int* matrix, int i, int j, int val);
void PrintMatrix(int n, int m, int* matrix);
void ZeroMatrix(int n, int m, int* matrix);


const int N = 4;
const int M = 3;

int testMatrix[] = {
    1, 2, 3,
    4, 0, 2,
    7, 8, 9,
    10,11,12
};

int main(int argc, char* argv[]) {
    PrintMatrix(N, M, testMatrix);
    cout << "Zeroed Matrix:" << endl;
    ZeroMatrix(N, M, testMatrix);
    PrintMatrix(N, M, testMatrix);
}

void ZeroMatrix(int n, int m, int* matrix) {
    bool rows[n];
    bool cols[m];

    for(int i = 0; i < n; i++) rows[i] = false;
    for(int j = 0; j < m; j++) cols[j] = false;

    //lets find 0s
    for(int i = 0; i < n; i++) {
        //rows[i] = false;
        for(int j = 0; j < m; j++) {
            //cols[j] = false;
            if(GetValue(m, matrix, i, j) == 0) {
                rows[i] = cols[j] = true;
            }
        }
    }

    //lets set 0s
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(rows[i] || cols[j])
                SetValue(m, matrix, i, j, 0);
}

int GetValue(int matrixWidth, int* matrix, int i, int j) {
    return matrix[i*matrixWidth+j];
}
void SetValue(int matrixWidth, int* matrix, int i, int j, int val) {
    matrix[i*matrixWidth+j] = val;
}
void PrintMatrix(int n, int m, int* matrix) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cout << GetValue(m, matrix, i, j) << " ";
        cout << endl;
    }
}
