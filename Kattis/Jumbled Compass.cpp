#include<bits/stdc++.h>
using namespace std;

#define LOCAL

int main() {
#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "Jumbled Compass.04";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif

    int n1, n2, n3;
    cin >> n1 >> n2;

    if(n2 < n1) n2 += 360;
    n3 = n2 - n1;
    if(n3 > 180) n3 = n3 - 360;

    cout << n3 << endl;

    return 0;
}