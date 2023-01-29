#include<bits/stdc++.h>
using namespace std;

#define LOCAL

#define countOnes(n)        __builtin_popcount((n))
#define BIT(n)              ( 1<<(n) )
#define BITTEST(var,pos)    (((var)>>(pos)) & 0x0001)
#define BITSET(var,pos)     ((var) | BIT(pos))
#define BITUNSET(var,pos)   ((var) & (~BIT(pos)))

#define N       23      // 12
const int MaxBoards = BIT(N) + 1;
int saved[MaxBoards];

int GetMin(int board) {
    int &best = saved[board];
    if(best == -1) {
        best = countOnes(board);
        // 011: Shift to the left
        for(int i = 2; i < N; ++i) {
            if(BITTEST(board, i) && BITTEST(board, i - 1) && !BITTEST(board, i - 2)) {
                int newBoard = board ^ (1 << i) ^ (1 << (i - 1)) ^ (1 << (i - 2));
                best = min(best, GetMin(newBoard));
            }
        }
        
        // 110: Shift to the right
        for(int i = N - 3; i >= 0; --i) {
            if(BITTEST(board, i) && BITTEST(board, i + 1) && !BITTEST(board, i + 2)) {
                int newBoard = board ^ (1 << i) ^ (1 << (i + 1)) ^ (1 << (i + 2));
                best = min(best, GetMin(newBoard));
            }
        }
    }    
    return best;
}

int main() {
#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "Pebble Solitaire.02";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif

    int n;
    cin >> n;

    // Only need to reset once
    for(int i = 0; i < MaxBoards; ++i) saved[i] = -1;

    while(n--) {
        string s;
        cin >> s;
        int a = 0x00;
        for(auto c : s) {
            a <<= 1;
            if(c == 'o') a |= 0x01;
        }
        cout << GetMin(a) << endl;
    }
    return 0;
}