#include<bits/stdc++.h>
using namespace std;

#define LOCAL

int main() {
#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "Kolone.03";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif

    int N1, N2, T;
    string r1, r2, both;
    cin >> N1 >> N2 >> r1 >> r2 >> T;
    char out[400];
    memset(out, 0x00, sizeof(out));
    cin >> T;
    int pos;
    for(int i = 0; i < r1.size(); ++i) {
        pos = (r1.size() + T - i + 50) * 2;
        out[pos] = r1.at(i);
    }
    for(int i = 0; i < r2.size(); ++i) {
        pos = (r1.size() + 50 + i) * 2 + 1;
        out[pos] = r2.at(i);
    }
    
    for(int i = 0; i < sizeof(out); ++i) {
        if(out[i] > 0) cout << out[i];
    }
    cout << endl;
    return 0;
}