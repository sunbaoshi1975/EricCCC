#include<bits/stdc++.h>
using namespace std;

#define LOCAL

// fast i/o
#define FAST_IO    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)

typedef long long ll;
typedef vector<int> vi;

int main() {
#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "Pizza Delivery.01";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif
    FAST_IO;

    int n;
    cin >> n;
    while(n--) {
        ll cost = 0;
        int x, y;
        cin >> x >> y;
        vi map(x * y);
        ll w[4] = {0};
        for(int j = 0; j < y; ++j) {
            for(int i = 0; i < x; ++i) {
                int data;
                cin >> data;;
                map[j * x + i] = data;
                w[0] += data * (i + j);
                w[1] += data * (x - 1 - i + j);
                w[2] += data * (i + y - 1 - j);
                w[3] += data * (x + y - 2 - i - j);
            }
        }
        if(w[0] > 0 && w[1] > 0 && w[2] > 0 && w[3] > 0) {
            cost = 1e9;
            double h = (x - 1.0) * w[1] / (w[0] + w[1]);
            double v = (y - 1.0) * w[3] / (w[2] + w[3]);
            for(int py = (int)floor(v); py <= min((int)ceil(v), y - 1); py++) {
                for(int px = (int)floor(h); px <= min((int)ceil(h), x - 1); px++) {
                    ll minV = 0;
                    for(int j = 0; j < y; ++j) {
                        for(int i = 0; i < x; ++i) {
                            minV += map[j * x + i] * (abs(px - i) + abs(py - j));
                        }
                    }
                    if(cost > minV) cost = minV;
                }
            }
        }

        printf("%lld blocks\n", cost);
    }

    return 0;
}