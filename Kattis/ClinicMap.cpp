#include <bits/stdc++.h>
using namespace std;

#define LOCAL

struct Clinic {
    /* data */
    int t;
    int s;
    char name[11];
};

#define cli_it      multimap<long, Clinic>::iterator

struct clsNameComp {
    bool operator() (string lhs, string rhs) const
    { return(lhs.compare(rhs.c_str()) < 0); }
};

multimap<long, Clinic> t1;
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

bool findFirstPatient(const int time) {
    cli_it itlow, itup, i;
    long maxPri = 0;
    if(t1.size() > 0) {
        maxPri = t1.begin()->first;
        itlow = t1.lower_bound(maxPri);
        itup = t1.upper_bound (maxPri);
        string minName = itlow->second.name;
        it1 = itlow;
        itlow++;
        for(i = itlow; i != itup; ++i) {
            if(minName.compare(i->second.name) > 0) {
                it1 = i;
                minName = i->second.name;
            }
        }
    } else {
        return false;
    }
    return true;
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
    int n, type;
    long prio;
    Clinic query;
    while(N-- >= 0) {
        if(fgets(buf, 49, stdin)) {
            n = sscanf(buf, "%d %d %s %d", &type, &query.t, query.name, &query.s);
            if(n > 1) {
                if(type == 1) {
                    prio = query.t * (long)K - query.s;
                    cli_it ret = t1.insert(pair<long, Clinic>(prio, query));
                    t2.insert(pair<string, cli_it>(query.name, ret));
                } else if(type == 2) {
                    if(findFirstPatient(query.t)) {
                        printf("%s\n", it1->second.name);
                        findName(it1->second.name);
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