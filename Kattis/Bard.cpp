#include<bits/stdc++.h>
using namespace std;

#define LOCAL

typedef long long ll;
typedef vector<ll> vl;

// fast i/o
#define FAST_IO    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)

int main() {
#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "Bard.03";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif
    FAST_IO;

    int N, E, K;
    cin >> N >> E;
    vl v(N, 0);     // villagers known songs (bits)
    while(E--) {
        cin >> K;
        vl e(N, 0); // villagers presented in event
        ll known = 0;
        while(K--) {
            int id;
            cin >> id;
            if(id == 1) {
                v[0] <<= 1; 
                v[0] |= 0x01;
            } else {
                known |= v[id - 1];
            }
            e[id - 1] = 1;
        }
        if(e[0] == 1) {
            // bard presented
            for(int i = 1; i < N; ++i) {
                v[i] <<= 1;
                // only those presented villagers knew the new song
                if(e[i] == 1) v[i] |= 0x01;
            }
        } else {
            // bard not presented, those presented villagers exchange all they knew
            for(int i = 1; i < N; ++i) {
                if(e[i] == 1) v[i] = known;
            }
        }
    }
    cout << 1 << endl;
    for(int i = 1; i < N; ++i) {
        if(v[i] == v[0]) {
            cout << i + 1 << endl;
        }
    }
    return 0;
}