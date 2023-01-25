/*
Convention
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
memset(memo, 0, sizeof memo);		// To clear array of ints
memset(memo, -1, sizeof memo);		// To init DP memo table
vi memo(n, -1);						// alternative way

const int INF = 1e9;
const int LLINF = 4e18;
const double EPS = 1e-9
index = (index+1) % n;				// to right or back to 0
index = (index+n-1) % n;			// to left or back to n-1

// fast i/o
#define FAST_IO    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)

freopen("XXXXX.in", "r", stdin);
freopen("XXXXX.out", "w", stdout);

#define LOCAL
#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "XXXXX.01";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif