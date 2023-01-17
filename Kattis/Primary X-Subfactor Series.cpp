#include <bits/stdc++.h>
using namespace std;

#define LOCAL
#define MAX_LEN     50

int main() {
	// fast i/o 
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "Primary X-Subfactor Series.01";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif

    long n;
    while(true) {
        // Input
        cin >> n;
        cin.ignore();
        if(n == 0) break;

        n--;
    }

    return 0;
}