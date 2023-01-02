#include <bits/stdc++.h>
using namespace std;

#define LOCAL
int main() {
#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "Modulo.03";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif

    int check[42] = {0};
    int i, n;
    for(i = 0; i < 10; i++) {
        cin >> n;
        check[n % 42] = 1;
    }
    n = 0;
    for(i = 0; i < 42; i++) {
        n += check[i];
    }
    cout << n;
    return 0;
}