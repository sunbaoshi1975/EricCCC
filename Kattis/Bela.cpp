#include <bits/stdc++.h>
using namespace std;

#define LOCAL

int main() {
	// fast i/o 
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "Bela.02";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif

    map<char, int> dom;
    map<char, int> ndom;
    dom['A'] = 11;
    dom['K'] = 4;
    dom['Q'] = 3;
    dom['J'] = 20;
    dom['T'] = 10;
    dom['9'] = 14;
    dom['8'] = 0;
    dom['7'] = 0;
    
    ndom['A'] = 11;
    ndom['K'] = 4;
    ndom['Q'] = 3;
    ndom['J'] = 2;
    ndom['T'] = 10;
    ndom['9'] = 0;
    ndom['8'] = 0;
    ndom['7'] = 0;

    int N, hands, score;
    char B;
    cin >> N >> B;
    cin.ignore();
    hands = N * 4;
    score = 0;
    string card;
    while(hands--) {
        cin >> card;
        if(card.at(1) == B) {
            score += dom[card.at(0)];
        } else {
            score += ndom[card.at(0)];
        }
    }

    cout << score;
    return 0;
}