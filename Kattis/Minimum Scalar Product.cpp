#include<bits/stdc++.h>
using namespace std;

#define LOCAL

typedef long long ll;
typedef vector<int> vi;

// fast i/o
#define FAST_IO    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)

int main() {
#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "Minimum Scalar Product.01";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif
    FAST_IO;

    int T, n;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        cin >> n;
        vi v1, v2;
        int temp;
        for(int j = 0; j < n; j++) {
            cin >> temp;
            v1.push_back(temp);
        }
        for(int j = 0; j < n; j++) {
            cin >> temp;
            v2.push_back(temp);
        }
        sort(v1.begin(), v1.end(), greater<int>());
        sort(v2.begin(), v2.end(), less<int>());
        //qsort(v2.data(), n, sizeof(int), std::less<int>());
        ll min = 0;
        for(int j = 0; j < n; j++) {
            min += ((ll)v1[j] * (ll)v2[j]);
        }

        printf("Case #%d: %lld\n", i, min);
    }

    return 0;
}