#include<bits/stdc++.h>
using namespace std;

#define LOCAL

// fast i/o
#define FAST_IO    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)

int main() {
#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "Toilet Seat.01";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif
    FAST_IO;
    string s;
    cin >> s;
    bool init = (s.at(0) == 'U');
    bool up[3], a[3];
    int c[3] = {0};
    up[0] = init; up[1] = init; up[2] = init;
    a[0] = true; a[1] = false;
    for(int i = 1; i < s.size(); i++) {
        bool need = (s.at(i) == 'U');
        for(int j = 0; j < 3; j++) {
            // prior to using
            if(need != up[j]) { 
                c[j]++;
                up[j] = need;
            }
            // after using
            if(j < 2) {
                if(up[j] != a[j]) {
                    c[j]++;
                    up[j] = a[j];
                }
            }      
        }
    }
    cout << c[0] << endl;
    cout << c[1] << endl;
    cout << c[2] << endl;
    return 0;
}