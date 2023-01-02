#include <bits/stdc++.h>
using namespace std;

#define LOCAL

int processLine(string line);
int main() {
#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "A_Different_Problem.01";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif
    string line;
    while(getline(std::cin, line)) {
        if(!processLine(line)) break;
    }
    return 0;
}

int isLarger(const char *s1, const char *s2) {
    int l1 = strlen(s1);
    int l2 = strlen(s2);
    if(l1 == l2) {
        // First different digit
        return(strcmp(s1, s2));
    } else {
        return(l1 - l2);
    }
}

int strToArray(int *a, string s) {
    int len = s.length();
    for(int i = 0; i < len; i++) {
        a[i] = s[len - i - 1] - '0';
    }
    return(len);
}

// s1 is greater
void printDiff(string s1, string s2) {
    int a[100] = {0}, b[100] = {0}, c[100] = {0};
    int la = strToArray(a, s1);
    int lb = strToArray(b, s2);
    int i = 0;
    while(i < la) {
        if(a[i] < b[i]) {
            a[i] += 10;
            a[i + 1]--;
        }
        c[i] = a[i] - b[i];
        i++;
    }
    while(c[i] == 0 && i) i--;
    while(i >= 0) {
        cout << c[i];
        i--;
    }
    cout << endl;
}

int processLine(string line) {
    char *str, *p = NULL;
    char sTemp[100];
    memset(sTemp, 0x00, sizeof(sTemp));
    strcpy(sTemp, line.c_str());
    str = strtok_r(sTemp, " ", &p);
    if(str && p) {
        int cmp = isLarger(str, p);
        if(cmp == 0) printf("0\n");
        else if(cmp > 0) printDiff(str, p);
        else printDiff(p, str);
        return 1;
    }
    return 0;
}