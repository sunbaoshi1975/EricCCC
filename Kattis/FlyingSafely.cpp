#include <bits/stdc++.h>
using namespace std;

#define LOCAL

int main() {

#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "FlyingSafely.01";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif

    int C, n, m;
    int flag[1001];
    string s;
    scanf("%d\n", &C);
    while(C--) {
        scanf("%d %d\n", &n, &m);
        while(m--) {
            getline(cin, s);
        }
        printf("%d\n", n - 1);
    }
    return 0;
}