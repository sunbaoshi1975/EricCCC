#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b, t = 0;
    cin >> a >> b;
    while(1) {
        if(a == b * 2) {
            t++;
            break;
        } else if(a > b * 2) {
            if(a % 2 == 0) {
                t++;
                a /= 2;
            } else {
                t += 2;
                a++;
                a /= 2;
            }
        } else if(a > b) {
            // b < a < 2b
            int steps = 0;
            if(a % 2 == 0) {
                steps = b - (a / 2) + 1;
            } else {
                steps = b - ((a + 1) / 2) + 2;
            }
            if(steps < 0) steps = b * 2;
            t += min(2 * b - a + 1, steps);
            break;
        } else {
            // a <= b
            t += (b - a);
            break;
        }
    }
    cout << t << endl;
    return 0;
}