#include <bits/stdc++.h>
using namespace std;

#define LOCAL

int main() {

#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "Emag Eht Htiw Em Pleh.02";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif

    int r, c, pos;
    string s;
    const string W = "KQRBNP";
    const int chg[2] = {0, 32};
    char chess[8][8] = {0};

    for(int i = 0; i < 2; i++) {
        getline(cin, s);
        pos = 7;
        while(pos < s.size()) {
            // 2 or 3 char?
            char p = s.at(pos);
            size_t found = W.find(p);
            if(found == string::npos) p = 'P';
            else pos++;
            p += chg[i];
            c = s.at(pos++) - 'a';
            r = '8' - s.at(pos++);
            pos++;  // ,
            chess[r][c] = p;
        }        
    }

    printf("+---+---+---+---+---+---+---+---+\n");
    for(r = 0; r < 8; r++) {
        for(c = 0; c < 8; c++) {
            char t = ((r + c) & 0x01 ? ':' : '.');
            char p = (chess[r][c] == 0 ? t : chess[r][c]);
            printf("|%c%c%c", t, p, t);
        }
        printf("|\n+---+---+---+---+---+---+---+---+\n");
    }

    return 0;
}