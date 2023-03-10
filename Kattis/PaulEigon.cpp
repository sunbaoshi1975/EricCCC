#include <bits/stdc++.h>
using namespace std;

#define LOCAL

int main() {

#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "PaulEigon.02";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif

    int N, P, Q;
    scanf("%d %d %d", &N, &P, &Q);
    const char names[2][10] = {"paul", "opponent"};

    int t = (P + Q) / N;
    printf("%s", names[t & 0x01]);
    return 0;
}