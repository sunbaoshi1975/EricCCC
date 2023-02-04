#include<bits/stdc++.h>
using namespace std;

#define LOCAL
#define MAX_STEPS       15

typedef long long ll;

map<std::pair<int, std::pair<int, int>>, ll> step;
vector<ll> walks(MAX_STEPS, 0);

ll walk(const int x, const int y, const int n) {
    // No steps left
    if(n == 0) {
        //if on start position return 1, otherwise return 0
        return(x == 0 && y == 0);
    } if(step.count({n, {y, x}}) != 0) {
        return step[{n, {y, x}}];
    }
    ll out = walk(x, y+1, n-1) + walk(x, y-1, n-1) + walk(x+1, y+1, n-1)
            + walk(x-1, y-1, n-1) + walk(x-1, y, n-1) + walk(x+1, y, n-1);
    step[{n, {y, x}}] = out;
    return out;
}

// A recusive problem
int main() {
#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "Honeycomb Walk.01";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif

    for(int i = 0; i < MAX_STEPS; i++) {
        walks[i] = walk(0, 0, i);
    }

    int T, n;
    cin >> T;
    while(T--) {
        cin >> n;
        cout << walks[n] << endl;
    }

    return 0;
}