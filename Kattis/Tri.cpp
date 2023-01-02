#include <bits/stdc++.h>
using namespace std;

#define LOCAL

int main() {

#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "Tri.02";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif

    int a[3], r, n;
    char s[2];
    scanf("%d %d %d", a, a + 1, a + 2);
    for(int i = 0; i < 2; i++) {
        r = i * 2;
        n = (i + 1) % 2;
        s[i] = '=';
        s[1 - i] = 0;
        for(int j = 0; j < 4; j++) {
            if(j == 0) {
                if(a[r] == a[n] + a[n + 1]) {
                    s[1 - i] = '+';
                    break;
                }
            } else if(j == 1) {
                if(a[r] == a[n] - a[n + 1]) {
                    s[1 - i] = '-';
                    break;
                }
            } else if(j == 2) {
                if(a[r] == a[n] * a[n + 1]) {
                    s[1 - i] = '*';
                    break;
                }
            } else if(j == 3) {
                if(a[r] == a[n] / a[n + 1]) {
                    s[1 - i] = '/';
                    break;
                }
            }
        }
        if(s[1 - i] != 0) break;
    }
    printf("%d%c%d%c%d\n", a[0], s[0], a[1], s[1], a[2]);

    return 0;
}