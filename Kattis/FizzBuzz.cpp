/*
Convention
*/

#include<bits/stdc++.h>
using namespace std;

#define LOCAL

int main() {
#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "FizzBuzz.01";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif

    int X, Y, N;
    cin >> X >> Y >> N;
    for(int i = 1; i <= N; i++) {
        if(i % X == 0 && i % Y == 0) {
            cout << "FizzBuzz" << endl;
        } else if(i % X == 0) {
            cout << "Fizz" << endl;
        } else if(i % Y == 0) {
            cout << "Buzz" << endl;
        } else {
            cout << i << endl;
        }
    }
    return 0;
}