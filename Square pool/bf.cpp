/* Brutal Force
 * Time Comlexity: O(t*n*n) , n <= 1000
 * Space Comlexity: O(1) 
 */

#include <stdio.h>

// Testing command
// cmd.exe /c ".\bf.exe < .\testcase\j5.sample.01.in" 
// cmd.exe /c ".\bf.exe < .\testcase\j5.sample.02.in" 
// cmd.exe /c ".\bf.exe < .\testcase\j5.1-01.in"

#define MAX_TREES       100

int inN;                   // Dimension of the map
int inTrees;                // How many trees
int inTreeRow[MAX_TREES];
int inTreeCol[MAX_TREES];

bool isContainTree(const int _row, const int _col, const int _m);
int findMaxSqure();

int main() {
    // Get inputs
    printf("Please input N (<=500,000): ");
    scanf("%d", &inN);
    printf("Please input trees (<=%d): ", MAX_TREES);
    scanf("%d", &inTrees);

    // Read positions for each tree
    printf("Please input position of trees \n\r");
    for(int i = 0; i < inTrees; i++) {
        scanf("%d %d", &inTreeRow[i], &inTreeCol[i]);       
    }

    // Find and output the result
    printf("Max possible suqare pool is %d\n\r", findMaxSqure());
    return 0;
}

bool isContainTree(const long _row, const long _col, const long _m) {
    // End point
    int _row2 = _row + _m - 1;
    int _col2 = _col + _m - 1;
    
    for(int i = 0; i < inTrees; i++) {
        if(inTreeRow[i] >= _row && inTreeRow[i] <= _row2 && inTreeCol[i] >= _col && inTreeCol[i] <= _col2) {
            // Any tree in the area
            return true;
        }
    }
    return false;
}

int findMaxSqure() {
    int row, col;
    int outMaxM, uBound;
    printf("Searching...\n\r");
    for(outMaxM = inN; outMaxM > 0; outMaxM--) {
        uBound = inN - outMaxM + 1;
        printf("check square %d upto %d \n\r", outMaxM, uBound);
        // Check through all cells
        for(row = 1; row <= uBound; row++) {
            for(col = 1 ; col <= uBound; col++) {
                if(!isContainTree(row, col, outMaxM)) return outMaxM;
            }
        }
    }
    return 0;
}