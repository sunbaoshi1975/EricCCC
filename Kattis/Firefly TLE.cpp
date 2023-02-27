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
    int N, H, h;
    cin >> N >> H;
    vi s(H, 0);
    for(int i = 0 ; i < N; i++) {
        cin >> h;
        if(i % 2) for(int j = H - h; j < H; j++) s[j]++;
        else for(int j = 0; j < h; j++) s[j]++;
    }
    int minV = s[0], dis = 1;
    for(int j = 1; j < H; j++) {
        if(minV > s[j]) {
            minV = s[j];
            dis = 1;
        } else if(minV == s[j]) {
            dis++;
        }
    }
    cout << minV << " " << dis << endl;
    return 0;
}