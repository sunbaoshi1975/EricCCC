#include <bits/stdc++.h>
using namespace std;

/* bits Permutation, highly precise (big number) calculation */

#define LOCAL
#define MAX_LEN     50

typedef long long ll;
typedef unsigned long long ull;

int main() {
	// fast i/o 
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "Three Powers.01";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif

    ull n;
    int p[MAX_LEN];
    while(true) {
        // Input
        cin >> n;
        cin.ignore();
        if(n == 0) break;

        n--;
        memset(p, 0x00, sizeof(p));
        int len = 1;
        p[0] = 1;
        cout << "{";
        bool first = true;
        // test bit
        while(n) {
            if(n & 1) {
                cout << (first ? " " : ", ");
                for(int i = len - 1; i >= 0; i--) {
                    cout << p[i];
                }
                first = false;
            }
            // p *= 3;
            int up = 0;
            for(int i = 0; i < len; i++) {
                int t = p[i] * 3 + up;
                p[i] = (t % 10);
                up = t / 10;
                if(t >= 10) {
                    if(len < i + 2) len = i + 2;
                }
            }
            n >>= 1;
        }
        cout << " }" << endl;
    }

    return 0;
}