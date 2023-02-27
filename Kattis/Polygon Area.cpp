#include<bits/stdc++.h>
using namespace std;

#define LOCAL

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

// fast i/o
#define FAST_IO    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)

int main() {
#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "Polygon Area.01";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif
    FAST_IO;

    int n;
    while(cin >> n && n != 0) {
        vii vertices(n + 1);
        for(int i = 0; i < n; i++) {
            cin >> vertices[i].first >> vertices[i].second;
        }
        vertices[n] = vertices[0];
        ll XX = 0, YY = 0; 
        for(int i = 0; i < n; i++) {
            XX += (vertices[i].first * vertices[i + 1].second);
            YY += (vertices[i].second * vertices[i + 1].first);
        }
        double ans = (XX - YY) / 2.0;
        printf("%s %0.1f\n", (ans > 0 ? "CCW" : "CW"), fabs(ans));
    }
    return 0;
}