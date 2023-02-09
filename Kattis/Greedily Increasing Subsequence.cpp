#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main() {
    int N;
    cin >> N;
    vi arr;
    int max = 0;
    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if(max < a) {
            max = a;
            arr.push_back(a);
        }
    }
    cout << arr.size() << endl;
    for(auto i : arr) cout << i << " ";
    return 0;
}