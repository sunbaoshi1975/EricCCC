#include<bits/stdc++.h>
using namespace std;

#define LOCAL

typedef long long ll;

// fast i/o
#define FAST_IO    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)

int main() {
#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "Sierpinski Circumference.01";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif
    FAST_IO;

    int n, c = 0;
    while(scanf("%d", &n) == 1) {
        // dm = 3 * pow(3/2, n)
        double d = log10f(3.0) + log10f(1.5) * n;
        printf("Case %d: %ld\n", ++c, (ll)ceil(d));
    }
    return 0;
}