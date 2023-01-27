#include<bits/stdc++.h>
using namespace std;

#define LOCAL

#define KEYS        26
const char keysnd[KEYS][8] = {
"clank", "bong", "click", "tap", "poing", "clonk", "clack", "ping", "tip", "cloing",
"tic", "cling", "bing", "pong", "clang", "pang", "clong", "tac", "boing", "boink",
"cloink", "rattle", "clock", "toc", "clink", "tuc"};

#define SND_SPACE       "whack"
#define SND_CAPSL       "bump"
#define SND_DEL         "pop"
#define SND_SHFT_H      "dink"
#define SND_SHFT_R      "thumb"

// fast i/o
#define FAST_IO    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)

int main() {
#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "Keylogger.03";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif
    FAST_IO;

    map<string, int> km;
    map<string, int>::iterator it;
    string tmp;
    for(int i = 0; i < KEYS; i++) {
        tmp = keysnd[i];
        km.insert({tmp, i});
    }

    bool shift_st = false;
    bool caps_st = false;
    bool lower = true;
    vector<char> s;

    int N;
    cin >> N;
    while(N--) {
        cin >> tmp;
        if(tmp.compare(SND_DEL) == 0) {
            if(s.size() > 0) s.pop_back();
        } else if(tmp.compare(SND_SPACE) == 0) {
            s.push_back(' ');
        } else if(tmp.compare(SND_CAPSL) == 0) {
            caps_st = !caps_st;
            lower = (shift_st == caps_st);
        } else if(tmp.compare(SND_SHFT_H) == 0) {
            shift_st = true;
            lower = caps_st;
        } else if(tmp.compare(SND_SHFT_R) == 0) {
            shift_st = false;
            lower = !caps_st;
        } else {
            it = km.find(tmp);
            char letter = (lower ? 'a' : 'A') + it->second;
            s.push_back(letter);
        }
    }

    for(auto a : s) {
        cout << a;
    }
    return 0;
}