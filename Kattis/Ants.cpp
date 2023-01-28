#include<bits/stdc++.h>
using namespace std;

#define LOCAL

// fast i/o
#define FAST_IO    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)

int main() {
#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "Ants.01";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif
    FAST_IO;

    int CaseCnt;
    cin >> CaseCnt;
    while(CaseCnt--) {
        int l, n;
        cin >> l >> n;
        int t1 = 0, t2 = 0;
        for(int i = 0; i < n; i++) {
            int a, b, c;
            cin >> a;
            // t1
            b = min(a, l - a);
            if(b > t1) t1 = b;
            // t2
            c = max(a, l - a);
            if(c > t2) t2 = c;
        }
        cout << t1 << " " << t2 << endl;
    }
    return 0;
}