#include<bits/stdc++.h>
using namespace std;

const double EPS = 10000.0;

int main() {
    int a;
    cin >> a;
    double p1 = 100.0 / a;
    //p1 = ((int)(p1 * EPS + 0.5)) / EPS;
    printf("%0.10f\n", p1);
    double p2 = 100.0 / (100.0 - a);
    //p2 = ((int)(p2 * EPS + 0.5)) / EPS;
    printf("%0.10f\n", p2);
    return 0;
}