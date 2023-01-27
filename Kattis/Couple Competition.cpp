/*  WA£¡£¡£¡ */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define LOCAL

// fast i/o
#define FAST_IO    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)

struct clsComp {
    bool operator() (ll lhs, ll rhs) const
    { return(lhs > rhs); }
};

// height, position
multimap<ll, int, clsComp> hs;

struct hill {
    int l;      // level
    int j;      // jump
    int n;      // next jump to
};

#define hit      multimap<ll, int>::iterator

int main() {
#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "Couple Competition.06";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif
    FAST_IO;

    int N;
    cin >> N;
    vector<hill> hl(N);
    ll height, maxh = 0;
    int maxi;
    for(int i = 0; i < N; ++i) {
        cin >> height;
        hs.insert(pair<ll, int>(height, i));
        hl[i].l = -1;
        hl[i].n = -1;
        hl[i].j = N;
        if(maxh < height) {
            maxh = height;
            maxi = i;
        }
    }

    int level = 0, nx;
    height = maxh;
    for(hit it = hs.begin(); it != hs.end(); it++) {
        // Level changed
        if(height > it->first) {
            level++;
            height = it->first;
        }
        hl[it->second].l = level;
        if(level == 0) hl[it->second].j = 0;
    }

    // spread from peaks
    int k;
    for(hit it = hs.begin(); it != hs.end() && it->first == maxh; it++) {
        // left
        if(it->second > 0) {
            nx = it->second - 1;
            while(nx >= 0 && hl[nx].j > 0) {
                // left to right jump
                k = nx + 1;
                while(k <= it->second) {
                    if(hl[nx].l > hl[k].l) {
                        if(hl[nx].j > hl[k].j + 1) {
                            hl[nx].j = hl[k].j + 1;
                            // jump to this node
                            hl[nx].n = k;
                        }
                        break;
                    } else if(hl[nx].l == hl[k].l) {
                        if(hl[nx].j > hl[k].j) {
                            hl[nx].j = hl[k].j;
                            // same level -> jump to the same next node
                            hl[nx].n = hl[k].n;
                        }
                        break;
                    } else {
                        // check next jump
                        k = hl[k].n;
                    }
                }
                nx--;
            }
        }
        // right
        if(it->second < N - 1) {
            nx = it->second + 1;
            while(nx < N && hl[nx].j > 0) {
                // right to left jump
                k = nx - 1;
                while(k >= it->second) {
                    if(hl[nx].l > hl[k].l) {
                        if(hl[nx].j > hl[k].j + 1) {
                            hl[nx].j = hl[k].j + 1;
                            // jump to this node
                            hl[nx].n = k;
                        }
                        break;
                    } else if(hl[nx].l == hl[k].l) {
                        if(hl[nx].j > hl[k].j) {
                            hl[nx].j = hl[k].j;
                            // same level -> jump to the same next node
                            hl[nx].n = hl[k].n;
                        }
                        break;
                    } else {
                        // check next jump
                        k = hl[k].n;
                    }                        
                }
                nx++;
            }
        }                               
    }

    for(int i = 0; i < N; ++i) {
        cout << hl[i].j << " ";
    }

    return 0;
}