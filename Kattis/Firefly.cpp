#include<bits/stdc++.h>
using namespace std;

#define LOCAL

typedef vector<int> vi;

// fast i/o
#define FAST_IO    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)

int main() {
#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "Firefly.02";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif
    FAST_IO;
    int N, H;
    cin >> N >> H;
    N /= 2;
    vi stalagmite(N);
    vi stalactite(N);
    for(int i = 0 ; i < N; i++) {
        cin >> stalagmite[i] >> stalactite[i];
    }
    sort(stalagmite.begin(), stalagmite.end());
    sort(stalactite.begin(), stalactite.end());

    int minV = 1e9, dis = 0;
    for(int j = 0; j < H; j++) {
        int hist = N - (int)(lower_bound(stalagmite.begin(), stalagmite.end(), j + 1) - stalagmite.begin());
        hist += (N - (int)(lower_bound(stalactite.begin(), stalactite.end(), H - j) - stalactite.begin()));
        if(minV > hist) {
            minV = hist;
            dis = 1;
        } else if(minV == hist) {
            dis++;
        }
    }
    cout << minV << " " << dis << endl;
    return 0;
}