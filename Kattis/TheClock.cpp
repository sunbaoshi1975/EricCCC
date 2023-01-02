#include <bits/stdc++.h>
using namespace std;

int main() {

    int N, i, hh, mm, dd;
    scanf("%d", &N);
    for(i = 0; i < 12 * 60; i++) {
        mm = (60 * i) % 3600;
        hh = (5 * i) % 3600;
        dd = (mm >= hh ? mm - hh : 3600 - hh + mm);
        if(dd == N) break;
    }
    printf("%02d:%02d\n", i / 60, i % 60);
    return 0;
}