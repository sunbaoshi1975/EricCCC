#include <bits/stdc++.h>
using namespace std;

#define LOCAL

struct pos {
    char p;
    int c;
    int r;
};

int main() {

#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "Help Me With The Game.01";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif

    int r, c, w;
    string s;
    const string W = "KQRBNP";
    const string B = "kqrbnp";
    const string out[2] = {"White: ", "Black: "};
    map<int, pos> q[2];
    pos piece;

    for(r = 0; r < 16; r++) {
        getline(cin, s);
        if(r & 0x01) {
            for(c = 2; c < s.size(); c+=4) {
                char p = s.at(c);
                piece.p = p;
                piece.c = c >> 2;
                piece.r = 8 - (r >> 1);
                size_t found = W.find(p);
                if(found != string::npos) {
                    // White piece
                    w = (found << 8) + (piece.r << 4) + piece.c;
                    q[0].insert(pair<int, pos>(w, piece));
                } else {
                    found = B.find(p);
                    if(found != string::npos) {
                        // Black piece
                        piece.p += ('A' - 'a');
                        w = (found << 8) + ((8 - piece.r) << 4) + piece.c;
                        q[1].insert(pair<int, pos>(w, piece));                        
                    }
                }
            }
        }
    }

    for(int i = 0; i < 2; i++) {
        int first = 1;
        printf("%s", out[i].c_str());
        for(auto i : q[i]) {
            if(!first) printf(",");
            first = 0;
            if(i.second.p != 'P') printf("%c", i.second.p);
            printf("%c%d", 'a' + i.second.c, i.second.r);
        }
        printf("\n");
    }
    return 0;
}