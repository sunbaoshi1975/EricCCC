#include <bits/stdc++.h>
using namespace std;

#define LOCAL

#define fast_io()   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)

int main() {
	// fast i/o 
    fast_io();

#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "Dvaput.02";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif

    int L;
    scanf("%d\n", &L);
    vector<char> s;
    char ch;
    int i, j, k;
    for(i = 0; i < L; i++) {
        scanf("%c", &ch);
        s.push_back(ch);
    }

    int maxL = 0;
    for(i = 0; i < L - 1; i++) {
        int len = 0;
        for(j = i + 1; j < L; j++) {
            if(s.at(i) == s.at(j)) {
                len = 1;
                // Try to get the maximum out of this position pair (i, j)
                for(k = 1; k < L - j; k++) {
                    if(s.at(i + k) == s.at(j + k)) len++;
                    else break;
                }
                if(len > maxL) maxL = len;
            }
        }
    }
    cout << maxL;
    return 0;
}