// 2021 CCC J2: Fergusonball Ratings
#include <iostream>
#include <fstream>>         // or <cstdio>

using namespace std;

const int STAR_SCORE = 5;
const int STAR_FAUL = 3;
const int N_STAR = 40;

#define LOCAL

int main() {
    int N, S, F;
    
#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "j2.04";     // j2.01 - j2.05

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif

    cin >> N;

    int count = 0;
    for(int i = 0; i < N; i++) {
        cin >> S;
        cin >> F;
        if(S * STAR_SCORE - F * STAR_FAUL > N_STAR) count++;
    }
    cout << count << (count == N ? "+" : "") << endl;

    return 0;
}