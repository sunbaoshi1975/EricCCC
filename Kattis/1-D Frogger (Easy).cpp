#include <bits/stdc++.h>
using namespace std;

int main() {
    const char strResult[5][10] = {"hop", "magic", "left", "right", "cycle"};

    // Input
    int N, s, m;
    cin >> N >> s >> m;

    int board[202] = {0};
    int visited[202] = {0};
    for(int i = 1; i <= N; i++) {
        cin >> board[i];
    }

    // Process
    int r = 0, h = 0;
    while(r == 0) {
        if(visited[s]) {
            r = 4;  // cycle
        } else {
            visited[s] = 1;
            if(board[s] == m) {
                r = 1;  // magic
            } else {
                // Hop
                h++;
                s += board[s];
                if(s <= 0 ) {
                    r = 2; // left
                } else if(s > N) {
                    r = 3; // right
                }
            }
        }
    }
    
    // Output    
    cout << strResult[r] << endl;
    cout << h << endl;

    return 0;
}