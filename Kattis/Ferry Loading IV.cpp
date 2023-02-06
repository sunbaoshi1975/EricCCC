#include<bits/stdc++.h>
using namespace std;

// fast i/o
#define FAST_IO    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)

#define LOCAL

int main() {
#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "Ferry Loading IV.01";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif
    FAST_IO;

    int c;
    cin >> c;
    while(c--) {
        int l, m;
        cin >> l >> m;
        l *= 100;   // m -> cm
        deque<int> side[2];
        
        while(m--) {
            int len;
            string s;
            cin >> len >> s;
            side[s == "left"].push_back(len);
        }
        int cnt = 0;
        int left = 1;
        while(side[0].size() > 0 || side[1].size() > 0) {
            if(side[left].size() > 0) {
                int space = l;
                while(side[left].size() > 0) {
                    if(side[left][0] <= space) {
                        space-=(side[left][0]);
                        side[left].pop_front();
                    } else break;
                }
                cnt++;
                left = 1 - left;
            } else if(side[1 - left].size() > 0) {
                cnt++;
                left = 1 - left;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}