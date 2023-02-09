#include<bits/stdc++.h>
using namespace std;

#define LOCAL

#define MAX_NUM     49999

typedef unsigned long long llu;

// fast i/o
#define FAST_IO    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)

llu gcd(llu n1, llu n2) {
    return(n2 == 0 ? n1 : gcd(n2, n1 % n2));
}

int main() {
#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "Boastin Red Socks.01";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif
    FAST_IO;

    vector<llu> nums(MAX_NUM);
    for(llu i = 0; i < MAX_NUM; i++) {
        // n * (n + 1)
        nums[i] = (i + 1) * (i + 2);
    }

    llu p, q;
    while(cin >> p >> q && (p || q)) {
        if(p == 0) {
            printf("0 2\n");
            continue;
        } else if(p == q) {
            printf("2 0\n");
            continue;
        }
        llu g = gcd(q, p); p /= g; q /= g;
        // p : q = (red - 1) * red / ((red + black - 1) * (red + black)) 
        llu red, black;
        bool found = false;
        for(int i = 0; i < nums.size(); i++) {
            llu qt = nums[i];
            if(qt % q == 0) {
                int t = qt / q;
                llu tmp = sqrt(p * t);
                if(tmp * (tmp + 1) == p * t) {
                    red = tmp + 1;
                    black = i + 2 - red;
                    found = true;
                    break;
                }                
            }
        }
        if(found) printf("%ld %ld\n", red, black);
        else printf("impossible\n");
    }
    return 0;
}