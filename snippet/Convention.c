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

// get the lease significant bit
#define LSOne(S)    ((S) & -(S))    // important speedup for DP

#define BIT(n)                    ( 1<<(n) )
#define BITTEST(var,pos)          (((var)>>(pos)) & 0x0001)
#define BITSET(var,pos)           ((var) | BIT(pos))
#define BITUNSET(var,pos)         ((var) & (~BIT(pos)))
#define BITFLIP(var,pos)          ((var) & (~BIT(pos)))

#define _BV(x)                    (1<<(x))

// Create a bitmask of length len.
#define BIT_MASK(len)             ( BIT(len)-1 )
// Create a bitfield mask of length starting at bit 'start'.
#define BF_MASK(start, len)       ( BIT_MASK(len)<<(start) )

// Prepare a bitmask for insertion or combining.
#define BF_PREP(x, start, len)    ( ((x)&BIT_MASK(len)) << (start) )
// Extract a bitfield of length len starting at bit 'start' from y.
#define BF_GET(y, start, len)     ( ((y)>>(start)) & BIT_MASK(len) )
// Insert a new bitfield value x into y.
#define BF_SET(y, x, start, len)  ( y= ((y) &~ BF_MASK(start, len)) | BF_PREP(x, start, len) )


// count ones
__builtin_popcount()
__builtin_popcountl()
// count trailing zeroes
__builtin_ctz()
__builtin_ctzl()

// fast i/o
#define FAST_IO    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)

freopen("XXXXX.in", "r", stdin);
freopen("XXXXX.out", "w", stdout);

#define LOCAL

int main() {
#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "XXXXX.01";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif
    FAST_IO;

    return 0;
}