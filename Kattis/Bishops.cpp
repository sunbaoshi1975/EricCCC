#include<bits/stdc++.h>
using namespace std;

#define LOCAL

int main() {
#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "Bishops.01";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif

    int N;
    while(scanf("%d", &N) == 1) {
        int b = (N < 2 ? N : (2 * N - 2));
        cout << b << endl;
    }
    return 0;
}