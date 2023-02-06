/* Wrong Answer ? */
#include<bits/stdc++.h>
using namespace std;

// fast i/o
#define FAST_IO    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define MAX_T      10010

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
        int nextLeft, nextRight;
        // if need to change side in the first place?
        if(side[left][0] > 0 && side[1 - left][0] == 0) {
            time+=t;
            left = 1 - left;
        }
        while(side[0].size() > 0 || side[1].size() > 0) {
            nextLeft = MAX_T;
            nextRight = MAX_T;
            // Go for a ride?
            if(side[left].size() > 0) {
                if(side[left][0] <= time) {
                    int space = n;
                    while(side[left].size() > 0) {
                        if(side[left][0] <= time && space > 0) {
                            space--;
                            cout << time + t << endl;
                            side[left].pop_front();
                        } else break;
                    }
                    time+=t;
                    left = 1 - left;
                    continue;
                } else {
                    nextLeft = side[left][0];
                }
            }
            // Need go empty?
            if(side[1 - left].size() > 0) {
                if(side[1 - left][0] <= time) {
                    time+=t;
                    left = 1 - left;
                    continue;
                } else {
                    nextRight = side[1 - left][0];
                }
            }
            // Wait at where I am until the next car appears,
            // which could be on either bank.
            if(nextLeft == MAX_T && nextRight == MAX_T) break;
            if(nextLeft <= nextRight) {
                time = nextLeft;
            } else {
                time = nextRight + t;
                left = 1 - left;
            }
        }
        cout << endl;
    }
    return 0;
}