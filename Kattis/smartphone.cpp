#include<bits/stdc++.h>
using namespace std;

#define LOCAL

// fast i/o
#define FAST_IO    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)

int rewrite(string sZ, string suggZ) {
    deque<char> s, sugg;

    for(auto i : sZ) {
        s.push_back(i);
    }
    for(auto i : suggZ) {
        sugg.push_back(i);
    }

    while(s.size() > 0 && sugg.size() > 0 && s.front() == sugg.front()) {
        s.pop_front();
        sugg.pop_front();
    }
    return s.size() + sugg.size();
}

void solve() {
    string des, wri, s1, s2, s3;
    cin >> des >> wri >> s1 >> s2 >> s3;

    int op1 = 1 + rewrite(des, s1);
    int op2 = 1 + rewrite(des, s2);
    int op3 = 1 + rewrite(des, s3);
    int op4 = rewrite(des, wri);

    cout << min({op1, op2, op3, op4}) << endl;
}

int main() {
#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "SmartPhone.01";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif
    FAST_IO;

    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}
