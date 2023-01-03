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
    const string strFile = "Quickscope.06";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif

    int N;
    scanf("%d\n", &N);
    char buf[50] = {0};
    char word[8] = {0};
    char name[8] = {0};
    char type[8] = {0};

    stack<unordered_set<string>> blockDS;
    unordered_set<string> block_0;
    blockDS.push(block_0); // Add first layer
    unordered_map<string, vector<string>> varDS;

    while(N--) {
        if(fgets(buf, 49, stdin)) {
            int n = sscanf(buf, "%s %s %s", word, name, type);
            if(n > 0) {
                if(word[0] == '{') {
                    // Add more new layer
                    unordered_set<string> block_new;
                    blockDS.push(block_new);
                } else if(word[0] == '}') {
                    // Remove all members in current level
                    while(!blockDS.top().empty()) {
                        auto temp = blockDS.top().begin();
                        varDS[*temp].pop_back();
                        if(varDS[*temp].empty()) {
                            varDS.erase(*temp);
                        }
                        blockDS.top().erase(temp);
                    }
                    blockDS.pop();
                } else if(strcmp(word, "TYPEOF") == 0) {
                    // Output
                    if(varDS.count(name) == 0) {
                        printf("UNDECLARED\n");
                    } else {
                        int idx = varDS[name].size() - 1;
                        printf("%s\n", varDS[name][idx].c_str());
                    }
                } else if(strcmp(word, "DECLARE") == 0) {
                    // Check duplication in current level
                    if(blockDS.top().count(name)) {
                        printf("MULTIPLE DECLARATION\n");
                        return 0;                         
                    }
                    // Add into map
                    if(varDS.count(name) == 0) {
                        vector<string> v;
                        varDS.insert({name, v});
                    }
                    varDS[name].push_back(type);
                    blockDS.top().insert(name);
                }
            }  
        }


    }

    return 0;
}