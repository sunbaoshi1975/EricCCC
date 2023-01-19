#include <bits/stdc++.h>
using namespace std;

#define LOCAL
#define MAX_LEN     200

typedef long long ll;

int maxLen = 0;
ll solution[MAX_LEN];
ll work[MAX_LEN] = {0};
const ll pow10[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000, 100000000000, 1000000000000, 10000000000000 };

// Get how many digis in a number
int getDigits(const ll num, int *digits) {
    char s[MAX_LEN] = "";
    sprintf(s, "%lld", num);
    int len = strlen(s);
    if(digits != NULL) {
        for(int i = 0; i < len; ++i) {
            digits[len - i - 1] = (int)(s[i] - '0');
        }
    }
    return(len);
}

void copy2Solution() {
    for(int i = 0; i < maxLen; ++i) {
        solution[i] = work[i];
    }
}

void BFS(const ll x, const int n) {
    // Last item
    if(x == 0 || x == 1) {
        // Discard
        if(n < maxLen) return;
        else if(n > maxLen) {
            // Got a better solution
            maxLen = n;
            copy2Solution();
        } else {
            // Same length, so need to check order
            for(int i = 0; i < maxLen; ++i) {
                if(work[i] < solution[i]) {
                    copy2Solution();
                    break;
                } else if(work[i] > solution[i]) break;
            }
        }
        return;
    }

    int digit[30] = {0};
    int len = getDigits(x, digit);
    int mask = (1 << len) - 2;
    for(int i = mask; i >= 0; i--) {
        ll subs = 0, fact = 0, subsLen = 0, factLen = 0, bitflag = 1;
        for(int j = 0; j < len; j++) {
            if(i & bitflag) {
                subs += (digit[j] * pow10[subsLen++]);
            } else {
                fact += (digit[j] * pow10[factLen++]);
            }
            bitflag <<= 1;
        }
        if(fact > 1 && (x % fact == 0) && getDigits(fact, NULL) == factLen) {
            if(subsLen > 0) {
                work[n] = subs;
                BFS(subs, n + 1);
            } else {
                BFS(0, n);
            }
        }
    }
}

/* BFS */
int main() {
	// fast i/o 
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "Primary X-Subfactor Series.01";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif

    ll n;
    while(cin >> n, n) {
        printf("%lld", n);
        maxLen = 0;
        BFS(n, 0);
        for(int i = 0; i < maxLen; ++i) {
            printf(" %lld", solution[i]);
        }
        printf("\n");
    }

    return 0;
}