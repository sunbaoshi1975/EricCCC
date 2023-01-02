#include <bits/stdc++.h>
using namespace std;

#define LOCAL

int main() {

#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "RadioCommercials.01";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif

    int N, P, s;
    int t = 0, tt = 0, max = 0;
    scanf("%d %d", &N, &P);
    while(N) {
        N--;
        scanf("%d", &s);
        if(s >= P) {
            t += (s - P);
            tt += (s - P);
        } else {
            if(max < t) max = t;
            if(max < tt) max = tt;
            if(tt + s - P > 0) {
                tt = tt + s - P;
            } else {
                tt = 0;
            }
            t = 0; // a new start
        }
    }

    if(max < t) max = t;
    if(max < tt) max = tt;
    printf("%d", max);
    return 0;
}