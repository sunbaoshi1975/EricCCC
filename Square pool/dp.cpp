/* Dynamic Programming
 * Time Comlexity: O(n*n) , n <= 5000
 * Space Comlexity: O(n*n) 
 */

// Testing command
// cmd.exe /c ".\dp.exe < .\testcase\j5.sample.01.in" 
// cmd.exe /c ".\dp.exe < .\testcase\j5.sample.02.in" 
// cmd.exe /c ".\dp.exe < .\testcase\j5.1-01.in"
// cmd.exe /c ".\dp.exe < .\testcase\j5.2-03.in"

#include <bits/stdc++.h>

using namespace std;

const int MaxN = 5000;
const int MAX_TREES = 100;
int matrix[MaxN][MaxN];
int N, T;

int main() {
    int i, row, col;

    // Get inputs
    printf("Please input N (<=%d): ", MaxN);
    scanf("%d", &N);
    assert(N<=MaxN);
    printf("Please input trees (<=%d): ", MAX_TREES);
    scanf("%d", &T);
    assert(T<=MAX_TREES);

    // Init the matrix and make it an all-one matrix
    for(row = 0; row < N; row++) {
        for(col = 0; col < N; col++) {
            matrix[row][col] = 1;
        }
    }

    // Read positions for each tree
    printf("Please input position of trees \n\r");
    for(i = 0; i < T; i++) {
        scanf("%d %d", &row, &col);
        assert(row>0 && row<=N && col>0 && col<=N);
        matrix[row - 1][col - 1] = 0;
    }

    // Update the matrix and get max square: O(n^2)
    int maxlen = 0;
    if(T < N * N) {
        maxlen = 1;
        for(row = 1; row < N; row++) {
            for(col = 1; col < N; col++) {
                if(matrix[row][col] == 1) {
                    matrix[row][col] = min(min(matrix[row - 1][col], matrix[row][col - 1]), matrix[row - 1][col - 1]) + 1;
                    if(matrix[row][col] >  maxlen) maxlen = matrix[row][col];
                }
            }
        }
    }

    // Print the result
    cout << maxlen << endl;

    return maxlen;
}