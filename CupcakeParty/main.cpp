#include <iostream>
#include <fstream>>         // or <cstdio>

using namespace std;

#define LOCAL

const int N_STUDENTS = 28;

int main() {
    int R, S;

#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "j1.01";     // j1.01 - j1.07

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif

    cin >> R;
    cin >> S;
    cout << (R * 8 + S * 3 - N_STUDENTS) << endl;
    return 0;
}