#include<bits/stdc++.h>
using namespace std;

#define LOCAL

// fast i/o
#define FAST_IO    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)

struct hill {
    int h;      // height
    int j;      // jumps
    int n;      // next jump to
};

int main() {
#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "Couple Competition.08";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif
    FAST_IO;

    int N;
    cin >> N;
    vector<hill> hl(N);
    vector<int> peak;
    int maxh = 0;
    for(int i = 0; i < N; ++i) {
        cin >> hl[i].h;
        hl[i].n = -1;
        hl[i].j = N + 1;
        if(maxh < hl[i].h) {
            maxh = hl[i].h;
            peak.clear();
            peak.push_back(i);
        } else if(maxh == hl[i].h) {
            peak.push_back(i);
        }
    }

    // mark peaks with 0 jump
    for(int i = 0; i < peak.size(); ++i) {
        hl[peak[i]].j = 0;
    }

    // spread from peaks
    int nx, k;
    for(int i = 0; i < peak.size(); ++i) {
        // left
        if(peak[i] > 0) {
            nx = peak[i] - 1;
            while(nx >= 0 && hl[nx].j > 0) {
                // left to right jump
                k = nx + 1;
                while(k <= peak[i]) {
                    if(hl[nx].h < hl[k].h) {
                        if(hl[nx].j > hl[k].j + 1) {
                            hl[nx].j = hl[k].j + 1;
                            // jump to this node
                            hl[nx].n = k;
                        }
                        break;
                    } else if(hl[nx].h == hl[k].h) {
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
        if(peak[i] < N - 1) {
            nx = peak[i] + 1;
            while(nx < N && hl[nx].j > 0) {
                // right to left jump
                k = nx - 1;
                while(k >= peak[i]) {
                    if(hl[nx].h < hl[k].h) {
                        if(hl[nx].j > hl[k].j + 1) {
                            hl[nx].j = hl[k].j + 1;
                            // jump to this node
                            hl[nx].n = k;
                        }
                        break;
                    } else if(hl[nx].h == hl[k].h) {
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