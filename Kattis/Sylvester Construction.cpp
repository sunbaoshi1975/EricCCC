#include <bits/stdc++.h>
using namespace std;

#define LOCAL

const int Hadamard[4][4] = {{1, 1, 1, 1}, 
                            {1,-1, 1,-1}, 
                            {1, 1,-1,-1}, 
                            {1,-1,-1, 1}};

int Sylvester(long n, long x, long y) {
    if(n >= 8) {
        long half = n / 2;
        if(half > x && half > y) {
            return(Sylvester(half, x, y));
        } else if(x >= half && y >= half) {
            return(-Sylvester(half, x - half, y - half));
        } else if(x >= half) {
            return(Sylvester(half, x - half, y));
        } else { // y >= half
            return(Sylvester(half, x, y - half));
        }
    }
    return(Hadamard[x][y]);
}

int main() {
	// fast i/o 
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "Sylvester Construction.01";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif

    int N;
    cin >> N;
    cin.ignore();
    long n, x, y;
    int w, h;
    while(N--) {
        cin >> n >> x >> y >> w >> h;
        for(long i = y; i < y + h; ++i) {
            for(long j = x; j < x + w; ++j) {
                cout << Sylvester(n, i, j) << (j == x + w - 1 ? "\n" : " ");
            }
        }
        cout << endl;
    }

    return 0;
}