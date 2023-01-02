#include <iostream>
using namespace std;

int main() {
    int t1 = 0, t2 = 1, nextTerm = 0, n, terms = 0;

    cout << "Enter a positive number: ";
    cin >> n;

    // displays the first two terms which is always 0 and 1
    cout << "Fibonacci Series: " << t1 << ", " << t2;
    terms = 2;

    //while(terms < n) {
    while(1) {
        nextTerm = t1 + t2;
        terms++;
        if(nextTerm > n) break;
        cout  << ", " << nextTerm;
        t1 = t2;
        t2 = nextTerm;
    }
}
