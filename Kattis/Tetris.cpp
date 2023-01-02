#include <bits/stdc++.h>
using namespace std;

#define LOCAL

int main() {

#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "Tetris.03";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif

    int C, P, tot = 0;
    scanf("%d %d", &C, &P);
    vector<int> h(C);
    for(auto &i : h) {
        scanf("%d", &i);
    }

    if(P == 1) {
        if(C >= 1) {
            // -
            tot += C;
        }
        if(C >= 4) {
            // ----, max: C - 3
            for(int i = 0; i < C - 3; i++) {
                if(h.at(i) == h.at(i + 1) && h.at(i) == h.at(i + 2) && h.at(i) == h.at(i + 3)) {
                    tot++;
                }
            }
        }
    } else if(P == 2) {
        if(C >= 2) {
            // --, max: C - 1
            for(int i = 0; i < C - 1; i++) {
                if(h.at(i) == h.at(i + 1)) {
                    tot++;
                }                
            }
        }
    } else if(P == 3) {
        if(C >= 3) {
            // --|, max: C - 2
            for(int i = 0; i < C - 2; i++) {
                if(h.at(i) == h.at(i + 1) && h.at(i) + 1 == h.at(i + 2)) {
                    tot++;
                }                
            }
        }
        if(C >= 2) {
            // |-, max: C - 1
            for(int i = 0; i < C - 1; i++) {
                if(h.at(i) == h.at(i + 1) + 1) {
                    tot++;
                }                
            }
        }        
    } else if(P == 4) {
        if(C >= 3) {
            // |--, max: C - 2
            for(int i = 0; i < C - 2; i++) {
                if(h.at(i) == h.at(i + 1) + 1 && h.at(i + 1) == h.at(i + 2)) {
                    tot++;
                }                
            }
        }
        if(C >= 2) {
            // -|, max: C - 1
            for(int i = 0; i < C - 1; i++) {
                if(h.at(i) + 1 == h.at(i + 1)) {
                    tot++;
                }                
            }
        }        
    } else if(P == 5) {
        if(C >= 3) {
            // --- or |-|, max: C - 2
            for(int i = 0; i < C - 2; i++) {
                if((h.at(i) == h.at(i + 1) && h.at(i) == h.at(i + 2)) || 
                   (h.at(i) == h.at(i + 1) + 1 && h.at(i) == h.at(i + 2))) {
                    tot++;
                }                
            }
        }
        if(C >= 2) {
            // -| or |-, max: C - 1
            for(int i = 0; i < C - 1; i++) {
                if(h.at(i) + 1 == h.at(i + 1) || h.at(i) == h.at(i + 1) + 1) {
                    tot++;
                }                
            }
        }        
    } else if(P == 6) {
        if(C >= 3) {
            // --- or -||, max: C - 2
            for(int i = 0; i < C - 2; i++) {
                if((h.at(i) == h.at(i + 1) && h.at(i) == h.at(i + 2)) || 
                   (h.at(i) + 1 == h.at(i + 1) && h.at(i + 1) == h.at(i + 2))) {
                    tot++;
                }                
            }
        }
        if(C >= 2) {
            // -- or ^-, max: C - 1
            for(int i = 0; i < C - 1; i++) {
                if(h.at(i) == h.at(i + 1) || h.at(i) == h.at(i + 1) + 2) {
                    tot++;
                }                
            }
        }        
    } else if(P == 7) {
        if(C >= 3) {
            // --- or ||-, max: C - 2
            for(int i = 0; i < C - 2; i++) {
                if((h.at(i) == h.at(i + 1) && h.at(i) == h.at(i + 2)) || 
                   (h.at(i) == h.at(i + 1) && h.at(i) == h.at(i + 2) + 1)) {
                    tot++;
                }                
            }
        }
        if(C >= 2) {
            // -- or -^, max: C - 1
            for(int i = 0; i < C - 1; i++) {
                if(h.at(i) == h.at(i + 1) || h.at(i) + 2 == h.at(i + 1)) {
                    tot++;
                }                
            }
        }        
    }

    printf("%d\n", tot);
    return 0;
}