#include <bits/stdc++.h>

using namespace std;

int main() {
    int e = 0;
    char in;
    while(1) {
        in = getchar();
        if(in == 'e') e++;
        else if(in == 'y') break;
    }
    e *= 2;
    cout << 'h';
    while(e--) {
        cout << 'e';
    }
    cout << 'y';
    return 0;
}