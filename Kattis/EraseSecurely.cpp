#include <bits/stdc++.h>
using namespace std;

#define LOCAL

int main() {

#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "EraseSecurely.01";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif

    int N;
    scanf("%d\n", &N);
    string f, h;
    getline(cin, f);
    getline(cin, h);
    int bit = (N & 0x01);
    for(int i = 0; i < f.size(); i++) {
        if(f.at(i) == h.at(i)) {
            if(bit) {
                printf("Deletion failed");
                return 0;                
            }
        } else {
            if(!bit) {
                printf("Deletion failed");
                return 0;                
            }
        }
    }
    printf("Deletion succeeded");
    return 0;
}