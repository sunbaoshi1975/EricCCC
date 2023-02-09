#include<bits/stdc++.h>
using namespace std;

#define LOCAL

typedef long long ll;

// fast i/o
#define FAST_IO    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)

int main() {
#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "Blocks on Blocks.01";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif
    FAST_IO;

    int t;
    for(int i = 1; i <= t; i++) {
        ll n, num;
        cin >> n;

        printf("Case %d: %d\n", i, num)
    }
    return 0;
}