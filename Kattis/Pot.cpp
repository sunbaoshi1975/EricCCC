#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int main() {
    int N;
    ll X = 0;
    cin >> N;
    while(N--) {
        int P, nm, pw;
        cin >> P;
        nm = P / 10;
        pw = P % 10;
        X += pow(nm, pw);
    }
    cout << X;
    return 0;
}