#include<bits/stdc++.h>
using namespace std;

#define LOCAL

#define ROWS        7
#define COLS        6

const char font[10][ROWS][COLS] = {
    "+---+",
    "|   |",
    "|   |",
    "+   +",
    "|   |",
    "|   |",
    "+---+",

    "    +",
    "    |",
    "    |",
    "    +",
    "    |",
    "    |",
    "    +",

    "+---+",
    "    |",
    "    |",
    "+---+",
    "|    ",
    "|    ",
    "+---+",

    "+---+",
    "    |",
    "    |",
    "+---+",
    "    |",
    "    |",
    "+---+",

    "+   +",
    "|   |",
    "|   |",
    "+---+",
    "    |",
    "    |",
    "    +",

    "+---+",
    "|    ",
    "|    ",
    "+---+",
    "    |",
    "    |",
    "+---+",

    "+---+",
    "|    ",
    "|    ",
    "+---+",
    "|   |",
    "|   |",
    "+---+",

    "+---+",
    "    |",
    "    |",
    "    +",
    "    |",
    "    |",
    "    +",

    "+---+",
    "|   |",
    "|   |",
    "+---+",
    "|   |",
    "|   |",
    "+---+",

    "+---+",
    "|   |",
    "|   |",
    "+---+",
    "    |",
    "    |",
    "+---+"
};

int main() {
#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "Digital display";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif

    char buf[10];
    while(fgets(buf, 9, stdin)) {
        int hh, mm;
        if(strncmp(buf, "end", 3) == 0) break;
        sscanf(buf, "%d:%d", &hh, &mm);
        for(int i = 0; i < ROWS; i++) {
            printf("%s  %s  %c  %s  %s\n", font[hh/10][i], font[hh%10][i], ((i == 2 || i == 4) ? 'o' : ' '), font[mm/10][i], font[mm%10][i]);
        }
        printf("\n\n");
    }
    printf("end\n");
    return 0;
}