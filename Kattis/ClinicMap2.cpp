#include <bits/stdc++.h>
using namespace std;

#define LOCAL

struct Clinic {
    /* data */
    long prio;
    char name[11];
};

#define cli_it      multimap<Clinic, long>::iterator

struct clsKeyComp {
    bool operator() (const Clinic lhs, const Clinic rhs) const
    {if(lhs.prio < rhs.prio) return true; 
     else if(lhs.prio == rhs.prio) return(strcmp(lhs.name, rhs.name) < 0);
     else return false; }
};

struct clsNameComp {
    bool operator() (const string lhs, const string rhs) const
    { return(lhs.compare(rhs.c_str()) < 0); }
};

multimap<Clinic, long, clsKeyComp> t1;
map<string, cli_it, clsNameComp> t2;
cli_it it1;

int N, K;

int findName(const string pName) {
    map<string, cli_it, clsNameComp>::iterator i = t2.find(pName);
    if (i != t2.end()) {
        it1 = i->second;
        t2.erase(i);
        return 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

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
    int n, type, time, severity;
    Clinic query;
    while(N-- >= 0) {
        if(fgets(buf, 49, stdin)) {
            n = sscanf(buf, "%d %d %s %d", &type, &time, query.name, &severity);
            if(n > 1) {
                if(type == 1) {
                    query.prio = time * (long)K - severity;
                    cli_it ret = t1.insert(pair<Clinic, long>(query, query.prio));
                    t2.insert(pair<string, cli_it>(query.name, ret));
                } else if(type == 2) {
                    if(t1.size() > 0) {
                        it1 = t1.begin();
                        printf("%s\n", it1->first.name);
                        findName(it1->first.name);
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