#include <bits/stdc++.h>
using namespace std;

#define LOCAL

// 0-13 -> A-G, a-g
const int bitMap[14] = {0x007, 0x003, 0x004, 0x1CF, 0x0CF, 0x04F, 0x00F,
                        0x006, 0x002, 0x3CE, 0x1CE, 0x0CE, 0x04E, 0x00E};

int main() {
	// fast i/o 
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "EbAltoSaxophonePlayer.01";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif
    
    int N;
    int cnt[10];
    cin >> N;
    cin.ignore();
    while(N--) {
        string song;
        getline(cin, song);

        int bm_last = 0;
        memset(cnt, 0x00, sizeof(cnt));
        for(int i = 0; i < song.size(); i++) {
            char note = song.at(i);
            int index = (note >= 'a' ? note - 'a' + 7 : note - 'A');
            int bm_cur = bitMap[index];
            // Any new fingers pressed?
            int bm_new = (~bm_last) & bm_cur;
            if(bm_new) {
                for(int j = 0; j < 10; j++) {
                    // Only count new pressed fingers
                    if(bm_new & 0x001) cnt[j]++;
                    bm_new >>= 1;
                }
            }
            bm_last = bm_cur;
        }

        for(int j = 0; j < 10; j++) {
            printf("%d%c", cnt[j], (j == 9 ? '\n' : ' '));
        }
    }

    return 0;
}