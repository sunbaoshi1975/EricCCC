#include <bits/stdc++.h>
using namespace std;

int main() {

    int X, temp;
    scanf("%ld", &X);

    // Get digits
    int i, j, k, l;
    int d[10] = {0};
    temp = X;
    for(i = 0; i < 10; i++) {
        if(temp > 0) {
            d[i] = temp % 10;
            temp /= 10;
        } else break;
    }

    for(j = 0; j < i - 1; j++) {
        for(k = j + 1; k < i; k++) {
            if(d[k] < d[j]) {
                // Switch place
                temp = d[k];
                d[k] = d[j];
                d[j] = temp;
                break;
            }
        }
        if(k < i) break;
    }

    if(k == i) {
        printf("%d", 0);
    } else {
        // sort below position k
        if(k > 1) {
            vector<int> a(d, d + k);
            sort(a.begin(), a.end());
            for(l = k - 1; l >= 0; l--) {
                d[l] = a.at(k - l - 1);
            }
        }

        for(l = i - 1; l >= 0; l--) {
            printf("%d", d[l]);
        }
    }
        return 0;
}