/* ticky: 
    If there are more than n, those that have been waiting the longest are loaded.
    So, ship may cross for opposite car w/o loading, 
    just because car on other side arrived a bit ealier.
*/
#include<bits/stdc++.h>
using namespace std;

// fast i/o
#define FAST_IO    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define MAX_T      INT_MAX

#define LOCAL

int main() {
#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "Ferry Loading III.01";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif
    FAST_IO;

    int c;
    cin >> c;
    while(c--) {
        int n, t, m;
        cin >> n >> t >> m;
        deque<int> side[2];
        while(m--) {
            int tm;
            string s;
            cin >> tm >> s;
            side[s == "left"].push_back(tm);
        }
        int time = 0;
        int left = 1;
        int next[2], space = n;
        while(side[0].size() > 0 || side[1].size() > 0) {
            // Who is next?
            next[0] = MAX_T;
            next[1] = MAX_T;
            if(side[left].size() > 0) next[left] = side[left][0];
            if(side[1 - left].size() > 0) next[1 - left] = side[1 - left][0];
            if(next[left] <= next[1 - left] && next[left] < MAX_T) {
                if(time < next[left]) {
                    if(space < n) {
                        time += t;
                        left = 1 - left;
                        space = n;
                        continue;
                    }
                    if(time < next[left]) time = next[left];
                }
            } else if(next[1 - left] < next[left]) {
                // Change side
                if(space < n) {
                    time += t;
                    if(time < next[1 - left]) time = next[1 - left];
                } else {
                    if(time < next[1 - left]) time = next[1 - left];
                    time += t;
                }
                left = 1 - left;
                space = n;
            }

            // Go for a ride?
            if(side[left].size() > 0) {
                if(side[left][0] <= time) {
                    space--;
                    cout << time + t << endl;
                    side[left].pop_front();
                    if(space == 0) {
                        // Change side
                        time += t;
                        left = 1 - left;
                        space = n;                        
                    }
                }
            }
        }
        if(c) cout << endl;
    }
    return 0;
}