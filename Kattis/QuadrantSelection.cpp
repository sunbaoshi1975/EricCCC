#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y, q;
    cin >> x;
    cin >> y;
    if(x > 0) {
        if(y > 0) q = 1;
        else q = 4;
    } else {
        if(y > 0) q = 2;
        else q = 3;
    }
    cout << q;
    return 0;
}