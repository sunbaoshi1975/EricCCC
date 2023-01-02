#include <bits/stdc++.h>
using namespace std;

int main() {
    int e, f, c, d, r;
    cin >> e >> f >> c;
    d = (e + f) / (c - 1);
    r = (e + f + d - 1) / c;
    cout << r;
    return 0;
}