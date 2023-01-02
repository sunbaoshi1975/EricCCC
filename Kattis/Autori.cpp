#include <bits/stdc++.h>
using namespace std;

//#define LOCAL

int isUpper(const char c) {
    return(c >= 'A' && c <= 'Z');
}

int isLower(const char c) {
    return(c >= 'a' && c <= 'z');
}

int main() {
#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "Autori.01";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif
    char s[101] = "";
    cin >> s;
    char *str, *p = NULL;
    for(str = strtok_r(s, "-", &p); str; str = strtok_r(NULL, "-", &p)) {
        if(isUpper(str[0])) cout << str[0];
    }
    cout << endl;
    return 0;
}