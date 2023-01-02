#include <bits/stdc++.h>
using namespace std;

#define LOCAL

int main() {

#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "Heliocentric.01";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif

    int E, M, c = 0;
    int dm, i;
    while(scanf("%d %d ", &E, &M) == 2) {
        dm = (687 - M) % 687;
        i = 0;
        while((E + dm + i) % 365 > 0) {
            i += 687;
        }
        printf("Case %d: %d\n", ++c, dm + i);
    }

    return 0;
}