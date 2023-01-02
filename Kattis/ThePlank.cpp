#include <bits/stdc++.h>
using namespace std;

int t = 0;
int puttile(int n) {
    if(n >= 3) {
        return(puttile(n - 1) + puttile(n - 2) + puttile(n - 3));
    } else if(n > 0) {
        return n;
    }
    return 1;
}

int main() {

    int N;
    scanf("%d", &N);
    printf("%d", puttile(N));
    return 0;
}