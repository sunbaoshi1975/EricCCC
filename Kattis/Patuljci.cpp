#include <bits/stdc++.h>
using namespace std;

#define LOCAL
#define N       9

int main() {

#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "Patuljci.02";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif

    vector<int> n(N);
    int sum = 0;
    for(auto &i : n) {
        scanf("%d", &i);
        sum += i;
    }

    // Eliminate two members
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            if(sum - n.at(i) - n.at(j) == 100) {
                for(int k = 0; k < N; k++) {
                    if(k == i || k == j) continue;
                    printf("%d\n", n.at(k));
                }
                break;
            }
        }
    }
    return 0;
}