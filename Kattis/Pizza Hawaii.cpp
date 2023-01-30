#include<bits/stdc++.h>
using namespace std;

#define LOCAL

typedef map<string, int>            msi;
typedef map<string, int>::iterator  mit;

// fast i/o
#define FAST_IO    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)

int main() {
#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "Pizza Hawaii.01";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif
    FAST_IO;

    msi pizza;
    msi dict;
    msi ingr;
    int t, n, m;
    cin >> t;
    while(t--) {
        cin >> n;
        pizza.clear();
        dict.clear();
        ingr.clear();
        while(n--) {
            string name;
            vector<string> Ita, Eng;
            cin >> name;
            cin >> m;
            while(m--) {
                cin >> name;
                Ita.push_back(name);
                mit it = dict.find(name);
                if(it == dict.end()) {
                    dict.insert({name, 1});
                } else {
                    int cnt = it->second + 1;
                    dict.at(name) = cnt;
                }         
            }
            cin >> m;
            while(m--) {
                cin >> name;
                Eng.push_back(name);
                mit it = ingr.find(name);
                if(it == ingr.end()) {
                    ingr.insert({name, 1});
                } else {
                    int cnt = it->second + 1;
                    ingr.at(name) = cnt;
                }                    
            }
            for(int i = 0; i < Ita.size(); i++) {
                for(int j = 0; j < Eng.size(); j++) {
                    name = Ita[i] + ", " + Eng[j];
                    mit it = pizza.find(name);
                    if(it == pizza.end()) {
                        pizza.insert({name, 1});
                    } else {
                        int cnt = it->second + 1;
                        pizza.at(name) = cnt;
                    }
                }
            }
        }
        for(auto it : pizza) {
            int pos = it.first.find(',');
            mit dit = dict.find(it.first.substr(0, pos));
            mit iit = ingr.find(it.first.substr(pos + 2));
            if(dit != dict.end() && iit != ingr.end()) {
                if(dit->second == it.second && iit->second == it.second) {
                    printf("(%s)\n", it.first.c_str());
                }
            }
        }
        printf("\n");
    }

    return 0;
}