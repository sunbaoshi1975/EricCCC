#include <bits/stdc++.h>
using namespace std;

#define LOCAL

int a[13];
int cards, p;

void stepFW(const int k) {
    for(int i = 1; i <= k; i++) {
        while(1) {
            p = (p + 1) % cards;
            if(a[p] == 0) break;
        }
    }
}

int main() {

#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "CardTrick.01";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif

    int T;
    scanf("%d", &T);

    for(int i = 0; i < T; i++) {
        scanf("%d", &cards);
        p = 0;
        for(int j = 0; j < cards; j++) a[j] = 0;
        for(int j = 1; j <= cards; j++) {
            stepFW(j);
            a[p] = j;
            if(j < cards - 1) {
                stepFW(1);
            }
        }
        for(int j = 0; j < cards; j++) {
            printf("%d ", a[j]);
        }
        printf("\n");
    }

    return 0;
}