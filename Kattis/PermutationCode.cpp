#include <bits/stdc++.h>
using namespace std;

#define LOCAL

int main() {
	// fast i/o 
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "Permutation Code.01";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif

    int x;
    string S, P, C, M;
    while(true) {
        // Input
        cin >> x;
        cin.ignore();
        if(x == 0) break;

        getline(cin, S);
        getline(cin, P);
        getline(cin, C);
        M = C;

        // Decryption
        int n, d, si, pj, sj;
        n = C.length();
        d = ((int)(pow(n, 1.5) + x)) % n;
        si = S.find(C[d]);
        M[d] = P[si];
        for(int i = 0; i < n - 1; i++) {
            int jp = (d + n - i) % n;   // already knew
            int j = (jp + n - 1) % n;   // to calculate 
            si = S.find(C[j]);
            // find M[j + 1] in S
            sj = S.find(M[jp]);
            // si should be pj ^ sj
            pj = (~si) ^ (~sj);
            // find M[j] in P
            M[j] = P[pj];
        }
        // Output
        cout << M << endl;
    }

    return 0;
}