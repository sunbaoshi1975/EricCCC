/* Space Optimized Dynamic Programming
 * Time Comlexity: O(n*n) , n <= 50000
 * Space Comlexity: O(n) 
 */

// Testing command
// cmd.exe /c ".\sodp.exe < .\testcase\j5.sample.01.in" 
// cmd.exe /c ".\sodp.exe < .\testcase\j5.sample.02.in" 
// cmd.exe /c ".\sodp.exe < .\testcase\j5.1-01.in"
// cmd.exe /c ".\sodp.exe < .\testcase\j5.2-03.in"

#include <bits/stdc++.h>

using namespace std;

struct pos_t {
    int row;
    int col;
};

const int MaxN = 5e5;
const int MAX_TREES = 100;

struct cmp {
    bool operator()(const pos_t& a, const pos_t& b) {
        return(a.row == b.row ? a.col > b.col : a.row > b.row);
    }
};
// Position of trees
priority_queue<pos_t, vector<pos_t>, cmp> tree_pos;
int dp[MaxN] = {0};

//#define LOCAL

int main() {
    int N, T;
    int i, row, col;
    pos_t _pos;
 
#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "j5.sample.02";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif

    // Get inputs
#ifndef LOCAL
    printf("Please input N (<=%d): ", MaxN);
#endif    
    scanf("%d", &N);
    assert(N<=MaxN);
#ifndef LOCAL
    printf("Please input trees (<=%d): ", MAX_TREES);
#endif
    scanf("%d", &T);
    assert(T<=MAX_TREES);

    // Read positions for each tree and sort them
#ifndef LOCAL    
    printf("Please input position of trees \n\r");
#endif    
    for(i = 0; i < T; i++) {
        scanf("%d %d", &row, &col);
        //assert(row>0 && row<=N && col>0 && col<=N);
        _pos.row = row - 1;
        _pos.col = col - 1;
        tree_pos.push(_pos);
    }

    // Scan tree postion list, update the matrix and get max square
    int maxlen = 0;
    if(T == 0) {
        maxlen = N;
    } else if(T < N * N) {
        // O(n^2)
        maxlen = 1;
        int Entrie, PreEntrie;
        _pos = tree_pos.top();
        for(row = 0; row < N; row++) {
            // New row
            PreEntrie = 0;
            for(col = 0; col < N; col++) {
                // Compute the entrie at the current position
                if(_pos.row == row && _pos.col == col) {
                    // This is a tree
                    Entrie = 0;
                    // Next tree
                    tree_pos.pop();
                    if(!tree_pos.empty()) {
                        _pos = tree_pos.top();
                    } else {
                        _pos.row = -1;
                    }
                } else {
                    // Not a tree
                    Entrie = 1;
                }
                if(col) {                    
                    if(Entrie && PreEntrie) {
                        Entrie = min(min(dp[col], dp[col - 1]), PreEntrie) + 1;
                        if(Entrie > maxlen) maxlen = Entrie;
                    }
                    dp[col - 1] = PreEntrie;
                }
                PreEntrie = Entrie;                
            }
            dp[N - 1] = Entrie;
        }
    }

    // Print the result
    cout << maxlen << endl;

    return maxlen;
}