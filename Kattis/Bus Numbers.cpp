#include<bits/stdc++.h>
using namespace std;

#define LOCAL

typedef vector<int> vi;

int main() {
#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "Bus Numbers";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif
    int N;
    cin >> N;
    vi buses(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> buses[i];
    }
    sort(buses.begin(), buses.end());
    for(int i = 0; i < N; i++) {
        cout << buses[i];
        int j = i + 1;
        while(j < N) {
            if(buses[j] - buses[i] != j - i) {
                j--;
                break;
            }
            j++; 
        }
        if(j == N) j--;
        if(j == i) {
            cout << " ";
        } else {
            cout << (j - i > 1 ? "-" : " ") << buses[j] << " ";
            i = j;
        }
    }
    return 0;
}