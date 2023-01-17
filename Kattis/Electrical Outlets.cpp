#include <bits/stdc++.h>

using namespace std;

#define LOCAL

int main() {
#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "Electrical Outlets";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif

    int N, K, O, S;
    cin >> N;
    while(N--) {
        cin >> K;
        S = 1 - K;
        while(K--) {
            cin >> O;
            S += O;
        }
        cout << S << endl;
    }
    return 0;
}