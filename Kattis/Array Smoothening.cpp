#include<bits/stdc++.h>
using namespace std;

#define LOCAL

// fast i/o
#define FAST_IO    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)

int main() {
#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "Array Smoothening.02";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif
    FAST_IO;

    int N, K;
    cin >> N >> K;

    unordered_map<int, int> A;
    unordered_map<int, int>::iterator it;
    priority_queue<int> pq;

    int a;
    while(N--) {
        cin >> a;
        it = A.find(a);
        if(it != A.end()) it->second++;
        else A.insert({a, 1});
    }
    for(auto &[k, v]: A) pq.push(v);
    for(int i = 0; i < K; i++) {
        a = pq.top() - 1;
        pq.pop();
        pq.push(a);
    }
    cout << pq.top();
    return 0;
}