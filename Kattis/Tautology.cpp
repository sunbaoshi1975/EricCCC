#include<bits/stdc++.h>
using namespace std;

#define LOCAL

typedef vector<int> vi;

// fast i/o
#define FAST_IO    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)

bool EvalWFF(string WFF, int *v);

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
    while(cin >> WFF && WFF != "0") {
        vi var(5, 0);
        for(auto i : WFF) if(i >= 'p' && i <= 't') var[i - 'p'] = 1;
        bool ts = 1;
        int v[5];
        for(v[0] = 0; v[0] <= var[0] && ts; v[0]++) {
            for(v[1] = 0; v[1] <= var[1] && ts; v[1]++) {
                for(v[2] = 0; v[2] <= var[2] && ts; v[2]++) {
                    for(v[3] = 0; v[3] <= var[3] && ts; v[3]++) {
                        for(v[4] = 0; v[4] <= var[4] && ts; v[4]++) {
                            if(!EvalWFF(WFF, v)) {
                                cout << "not" << endl;
                                ts = 0;
                                break;                
                            }
                        }
                    }
                }
            }
        }
        if(ts) cout << "tautology" << endl;
    }
    return 0;
}

bool GetWFFValue(string WFF) {
    if(WFF[0] == '0' || WFF[0] == '1') return(WFF[0] == '1');
    else if(WFF[0] == 'N') {
        return(!GetWFFValue(WFF.substr(1, WFF.size() - 1)));
    } else {
        int pos = WFF.find_first_of("01");
        string s1 = WFF.substr(1, pos);
        string s2 = WFF.substr(pos + 1, WFF.size() - pos - 1);
        if(WFF[0] == 'K') {
            return(GetWFFValue(s1) && GetWFFValue(s2));
        } else if(WFF[0] == 'A') {
            return(GetWFFValue(s1) || GetWFFValue(s2));
        } else if(WFF[0] == 'C') {
            return(GetWFFValue(s1) <= GetWFFValue(s2));
        } else if(WFF[0] == 'E') {
            return(GetWFFValue(s1) == GetWFFValue(s2));
        }
    }
    return 1;
}

bool EvalWFF(string WFF, int *v) {
    for(int i = 0; i < WFF.size(); i++) {
        if(WFF[i] >= 'p' && WFF[i] <= 't') {
            int p = WFF[i] - 'p';
            WFF[i] = v[p] + '0';
        }
    }
    return(GetWFFValue(WFF));
}