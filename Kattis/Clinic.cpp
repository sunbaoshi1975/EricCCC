#include <bits/stdc++.h>
using namespace std;

#define LOCAL

struct Clinic {
    /* data */
    int t;
    int s;
    char name[11];
};

struct NameNode {
    /* data */
    char name[11];
    list<Clinic>::iterator it;
};

list<Clinic> t1;
list<Clinic>::iterator it1;
int N, K;

int findName(const char *pName) {
    list<Clinic>::iterator i;
    for(i = t1.begin(); i != t1.end(); ++i) {
        if(strcmp(i->name, pName) == 0) {
            it1 = i;
            return 1;
        } 
    }
    return 0;
}

long findFirstPatient(const int time) {
    list<Clinic>::iterator i, max;
    long maxPri = 0, pri;
    for(i = t1.begin(); i != t1.end(); ++i) {
        pri = (time - i->t) * (long)K + i->s;
        if(pri > maxPri) {
            it1 = i;
            maxPri = pri;
        } else if(pri == maxPri) {
            if(strcmp(i->name, it1->name) < 0) {
                it1 = i;
            }
        }
    }
    return maxPri;
}

int main() {

#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "Clinic.01";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif

    scanf("%d %d", &N, &K);

    char buf[50] = {0};
    int n, type;
    Clinic query;
    while(N-- >= 0) {
        if(fgets(buf, 49, stdin)) {
            n = sscanf(buf, "%d %d %s %d", &type, &query.t, query.name, &query.s);
            if(n > 1) {
                if(type == 1) {
                    t1.push_back(query);
                } else if(type == 2) {
                    if(findFirstPatient(query.t)) {
                        printf("%s\n", it1->name);
                        t1.erase(it1);
                    } else {
                        printf("doctor takes a break\n");
                    }
                } else {
                    // type 3: sb left, may need index for fast query on name
                    if(findName(query.name)) {
                        t1.erase(it1);
                    }
                }
            }
        }
    }

    return 0;
}