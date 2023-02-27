#include<bits/stdc++.h>
using namespace std;

#define LOCAL

// fast i/o
#define FAST_IO    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)

int main() {
#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "Combination Lock.01";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif
    FAST_IO;

    int a[4];
    while(cin >> a[0] >> a[1] >> a[2] >> a[3] && !(a[0]==0 && a[1]==0 && a[2]==0 && a[3]==0)) {
        int degree = 720;
        degree += ((a[0] + 40 - a[1]) % 40) * 9;
        degree += 360;
        degree += ((a[2] + 40 - a[1]) % 40) * 9;
        degree += ((a[2] + 40 - a[3]) % 40) * 9;
        cout << degree << endl;
    }

    return 0;
}