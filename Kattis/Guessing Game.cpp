#include<bits/stdc++.h>
using namespace std;

#define LOCAL

// fast i/o
#define FAST_IO    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)

int main() {
#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "Guessing Game.01";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif
    FAST_IO;

    int guess;
    string response;
    int a[11] = {0};
    while(cin >> guess && guess != 0) {
        cin.ignore();
        getline(cin, response);
        if(response == "right on") {
            cout << (a[guess] == 0 ? "Stan may be honest" : "Stan is dishonest") << endl;
            memset(a, 0x00, sizeof(a));
        } else if(response == "too low") {
            for(int i = 0; i <= guess; i++) a[i] = 1;
        } else if(response == "too high") {
            for(int i = guess; i <= 10; i++) a[i] = 1;
        }
    }

    return 0;
}