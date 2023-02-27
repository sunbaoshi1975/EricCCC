#include<bits/stdc++.h>
using namespace std;

#define LOCAL

typedef vector<int> vi;

// fast i/o
#define FAST_IO    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)

int main() {
#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "Tautology.01";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif
    FAST_IO;

    string WFF;
    stack <bool> s;
    map<char, int> m; // maps p, q, r, s, t to bit mask bits
    m['p'] = 0; m['q'] = 1; m['r'] = 2; m['s'] = 3; m['t'] = 4;    
    while(cin >> WFF && WFF != "0") {
        reverse(WFF.begin(), WFF.end()); //to get it into post-fix
        bool ts = true;
        for(int bm = 0; bm < (1<<5); bm++) { // bitmask with 5 bits
            for(auto c : WFF) {
                if(c >= 'p' && c <= 't') {
                    s.push((bm & (1 << m[c])) == (1 << m[c]));
                } else if (c == 'N'){
                    bool temp = !s.top();
                    s.pop();
                    s.push(temp);
                } else if (c == 'A') {
                    bool temp1 = s.top();
                    s.pop();
                    bool temp2 = s.top();
                    s.pop();
                    s.push(temp1 | temp2);
                } else if (c == 'K') {
                    bool temp1 = s.top();
                    s.pop();
                    bool temp2 = s.top();
                    s.pop();
                    s.push(temp1 & temp2);
                } else if (c == 'E') {
                    bool temp1 = s.top();
                    s.pop();
                    bool temp2 = s.top();
                    s.pop();
                    s.push(temp1 == temp2);
                } else if (c == 'C') {
                    bool temp1 = s.top();
                    s.pop();
                    bool temp2 = s.top();
                    s.pop();
                    s.push(temp1 <= temp2);
                }
            }
            bool ans = s.top(); s.pop();
            if(!ans){
                ts = false;
                break;
            }       
        }
        cout << (ts ? "tautology" : "not") << endl;
    }
    return 0;
}
