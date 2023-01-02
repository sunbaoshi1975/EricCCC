#include <bits/stdc++.h>
using namespace std;

#define LOCAL

int speed = 0;
int sec = 0;
double km = 0.0;

int processLine(string line);
int main() {
#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "AverageSpeed.02";

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

int getSeconds(string tm) {
    int hour, min, sec;
    hour = atoi(tm.substr(0, 2).c_str());
    min = atoi(tm.substr(3, 2).c_str());
    sec = atoi(tm.substr(6, 2).c_str());
    return(hour * 3600 + min * 60 + sec);
}

int processLine(string line) {
    char *str, *p = NULL;
    char sTemp[100];
    memset(sTemp, 0x00, sizeof(sTemp));
    strcpy(sTemp, line.c_str());
    str = strtok_r(sTemp, " ", &p);
    if(str) {
        // Current time in seconds
        int tm = getSeconds(str);
        int passed = tm - sec;
        // Update km
        km += passed / 3600.0 * speed;
        // Update time
        sec = tm;
        if(p) {
            // Speed changed
            speed = atoi(p);
        } else {
            // Query
            printf("%s %0.2lf km\n", str, km);
        }
        return 1;
    }
    return 0;
}