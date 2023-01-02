#include <bits/stdc++.h>
using namespace std;

#define LOCAL

int main() {

#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "PaulEigon.01";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif

    int N;
    scanf("%d", &N);
    char s1[60], s2[60];
    while(N--) {
        scanf("%s", s1);
        scanf("%s", s2);
        printf("%s\n%s\n", s1, s2);
        int len = strlen(s1);
        // Compare
        for(int i = 0; i < len; i++) {
            printf("%c", s1[i] == s2[i] ? '.' : '*');
        }
        // New lines
        printf("\n\n");
    }

    return 0;
}