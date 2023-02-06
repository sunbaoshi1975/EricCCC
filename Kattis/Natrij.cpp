#include<bits/stdc++.h>
using namespace std;

#define LOCAL

int main() {
#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "Natrij.02";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif

    int h[2], m[2], s[2];
    scanf("%d:%d:%d\n", h, m, s);
    scanf("%d:%d:%d\n", h + 1, m + 1, s + 1);
    int start = h[0] * 3600 + m[0] * 60 + s[0];
    int end = h[1] * 3600 + m[1] * 60 + s[1];
    int sec;
    if(end > start) sec = end - start;
    else sec = 3600 * 24 - start + end;
    printf("%02d:%02d:%02d\n", sec / 3600, (sec % 3600) / 60, sec % 60);
    return 0;
}