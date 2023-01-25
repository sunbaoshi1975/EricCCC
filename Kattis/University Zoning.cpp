/*
 WA !!! ???
*/
#include<bits/stdc++.h>
using namespace std;

#define LOCAL

const int INF = 1e9;

// fast i/o
#define FAST_IO   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)

typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, ll> ii;

struct clsComp {
    bool operator() (const ii& lhs, const ii& rhs) const
    { if(lhs.first < rhs.first) return(true);
      else if(lhs.first > rhs.first) return(false);
      else return(lhs.second < rhs.second);
    }
};

struct faculty {
    int K;
    int E;
    int T;
    int cnt;
    set<ii, clsComp> pos;
    set<ii, clsComp>::iterator occu;
    vi st;
};

struct stu {
    int D;
    int f;
    ll r;
    ll c;
    ll ar;
    ll ac;
    ll gap;
};

int main() {
#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "University Zoning.02";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif

    FAST_IO;

    ll steps = 0;
    ll R, C;
    int F, S, G;
    cin >> R >> C >> F >> S >> G;
    vector<faculty> fa(F);
    for(int i = 0; i < F; ++i) {
        cin >> fa[i].K;
        fa[i].E = 0;
        fa[i].cnt = 0;
        fa[i].pos.clear();
        fa[i].st.clear();
        for(int k = 0; k < fa[i].K; ++k) {
            int r, c;
            cin >> r >> c;
            fa[i].pos.insert({r, c});
            fa[i].occu = fa[i].pos.begin();
        }
    }

    vector<stu> slist;
    vector<stu>::iterator sit;
    for(int i = 0; i < S; ++i) {
        stu sa;
        cin >> sa.r >> sa.c >> sa.D >> sa.f;
        sa.ar = 0;
        sa.ac = 0;
        sa.gap = 0;
        for(sit = slist.begin(); sit < slist.end(); sit++) {
            if(sa.D < sit->D) break;
        }
        slist.insert(sit, sa);
    }

    for(sit = slist.begin(); sit < slist.end(); sit++) {
        int af = sit->f - 1;
        // Asigned cell
        sit->ar = fa[af].occu->first;
        sit->ac = fa[af].occu->second;
        fa[af].occu++;
        fa[af].E++;
        
        if(sit->r == sit->ar && sit->c == sit->ac) {
            sit->gap = 0;
            fa[af].cnt++;
        } else {
            sit->gap = abs(sit->r - sit->ar) + abs(sit->c - sit->ac);
            vi::iterator v;
            for(v = fa[af].st.begin(); v < fa[af].st.end(); v++) {
                if(sit->gap < *v) break;
            }
            fa[af].st.insert(v, sit->gap);
        }
    }

    int gg = 0;
    for(int i = 0; i < F; ++i) {
        cin >> fa[i].T;
        if(fa[i].cnt >= fa[i].T) gg++;
    }
    if(gg < G) {
        vi sortFa;
        for(int i = 0; i < F; ++i) {
            if(fa[i].cnt < fa[i].T) {
                int needAdd = fa[i].T - fa[i].cnt;
                if(needAdd <= fa[i].st.size()) {
                    ll faStep = 0;
                    for(int k = 0; k < needAdd; ++k) {
                        faStep += fa[i].st[k];
                    }
                    vi::iterator v;
                    for(v = sortFa.begin(); v < sortFa.end(); v++) {
                        if(faStep < *v) break;
                    }
                    sortFa.insert(v, faStep);
                }
            }
        }
        for(int i = 0; i < G - gg; ++i) {
            steps += sortFa[i];
        }
    }

    cout << steps << endl;
    return 0;
}