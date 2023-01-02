/* Block based Dynamic Programming
 * Time Comlexity: O(t*t), t <= 1000, N <= 500,000
 * Space Comlexity: O(t) 
 */

// Testing command
// cmd.exe /c ".\ac.exe < .\testcase\j5.sample.01.in" 
// cmd.exe /c ".\ac.exe < .\testcase\j5.sample.02.in" 
// cmd.exe /c ".\ac.exe < .\testcase\j5.1-01.in"
// cmd.exe /c ".\ac.exe < .\testcase\j5.2-03.in"
// cmd.exe /c ".\ac.exe < .\testcase\j5.3-01.in"
// cmd.exe /c ".\ac.exe < .\testcase\j5.4-09.in"

#include <bits/stdc++.h>

using namespace std;

const int MaxN = 5e5;
const int MAX_TREES = 100;

struct pos_t {
    int row;
    int col;
    int r_idx;
    int c_idx;
};

int N, T, max_square = 0;
pos_t tree_pos[MAX_TREES];
int *lstRow;
int *lstCol;

int compareRow (const void * a, const void * b) {
    return(tree_pos[*(int*)a].row != tree_pos[*(int*)b].row ? tree_pos[*(int*)a].row - tree_pos[*(int*)b].row : tree_pos[*(int*)a].col - tree_pos[*(int*)b].col);
}

int compareCol (const void * a, const void * b) {
    return(tree_pos[*(int*)a].col != tree_pos[*(int*)b].col ? tree_pos[*(int*)a].col - tree_pos[*(int*)b].col : tree_pos[*(int*)a].row - tree_pos[*(int*)b].row);
}

int squareLen(const int i) {
    int t, s, r, k;
    int min_dist;
    int dist, dist2; 
    int p[4] = {-1, -1, -1, -1};
    int _left = 0, _right = N + 1, _up = 0, _down = N + 1;
    int _leftHand, _upHand;

    // Find other 3 sides by taking tree_pos[i] when at 0 & 1
    min_dist = N;
    // 1: check all up rows
    for(t = tree_pos[i].r_idx - 1; t >= -2; t--) {
        _left = tree_pos[i].col;
        _right = N + 1;
        _leftHand = 0;
        if(t == -1) {
            _up = 0;
            dist = 0;
            p[1] = -1;
        } else if(t == -2) {
            _up = 0;
            dist = 0;
            p[1] = -1;
            _leftHand = 1;
            _right = _left;
            _left = 0;        
        } else {
            k = lstRow[t];
            if(tree_pos[k].row <= tree_pos[i].row) {
                if(tree_pos[k].col > _left) {
                    // Right hand square
                    dist = tree_pos[k].col - _left;
                } else if(tree_pos[k].col < _left) {
                    // Left hand square
                    _leftHand = 1;
                    _right = _left;
                    _left = 0;
                    dist = _right - tree_pos[k].col;
                } else continue;
                
                //if(dist > min_dist) continue;
                _up = tree_pos[k].row;
                p[1] = k;
            } else continue;
        }            
        // 3: check all down rows
        for(s = tree_pos[i].r_idx + 1; s <= T; s++) {
            if(s == T) {
                _down = N + 1;
                dist2 = 0;
                p[3] = -1;
            } else {
                k = lstRow[s];
                if(tree_pos[k].row >= tree_pos[i].row) {
                    dist2 = N;
                    if(_leftHand == 0) {
                        // Right hand square
                        if(tree_pos[k].col > _left) {
                            dist2 = tree_pos[k].col - _left;
                        } else continue;
                    } else {
                        // Left hand square
                        if(tree_pos[k].col < _right) {
                            dist2 = _right - tree_pos[k].col;                            
                        } else continue;
                    }
                    //if(dist2 > min_dist) continue;
                    _down = tree_pos[k].row;
                    if(_down - _up <= max_square) continue;
                    p[3] = k;
                } else continue;
            }
            dist = max(dist, dist2);
            // 2: find the most close col# that between 1 and 3
            int _temp;
            if(_leftHand == 0) {
                // Right hand square
                p[0] = i;
                for(r = tree_pos[i].c_idx + 1; r <= T; r++) {
                    if(r == T) {
                        _temp = tree_pos[i].row;
                        _right = N + 1;                        
                        p[2] = -1;
                    } else {
                        k = lstCol[r];
                        _temp = tree_pos[k].row;
                        _right = tree_pos[k].col;
                        p[2] = k;
                        if(_temp > _up && _temp < _down) break; 
                    }
                }
            } else {
                // Left hand square
                p[2] = i;
                for(r = tree_pos[i].c_idx - 1; r >= -1; r--) {
                    if(r == -1) {
                        _temp = tree_pos[i].row;
                        _left = 0;
                        p[0] = -1;
                    } else {
                        k = lstCol[r];
                        _temp = tree_pos[k].row;
                        _left = tree_pos[k].col;
                        p[0] = k;
                        if(_temp > _up && _temp < _down) break; 
                    }
                }                
            }
            if(_right >= _left + dist) {
                int _w = _right - _left - 1;
                int _h = _down - _up - 1;
                int _square = min(_w, _h);
                // Found bigger square
                if(_square > max_square) {
                    max_square = _square;
                    min_dist = _w;
                }
            }
        }
    }

    min_dist = N;
    // 0: check all left cols
    for(t = tree_pos[i].c_idx - 1; t >= -2; t--) {
        _up = tree_pos[i].row;
        _down = N + 1;
        _upHand = 0;
        if(t == -1) {
            _left = 0;
            dist = 0;
            p[0] = -1;
        } else if(t == -2) {
            _left = 0;
            dist = 0;
            p[0] = -1;
            _upHand = 1;
            _down = _up;
            _up = 0;        
        } else {
            k = lstCol[t];
            if(tree_pos[k].col <= tree_pos[i].col) {
                if(tree_pos[k].row > _up) {
                    // Down hand square
                    dist = tree_pos[k].row - _up;
                } else if(tree_pos[k].row < _up) {
                    // Up hand square
                    _upHand = 1;
                    _down = _up;
                    _up = 0;
                    dist = _up - tree_pos[k].row;
                } else continue;
                
                //if(dist > min_dist) continue;
                _left = tree_pos[k].col;
                p[0] = k;
            } else continue;
        }            
        // 2: check all right side cols
        for(s = tree_pos[i].c_idx + 1; s <= T; s++) {
            if(s == T) {
                _right = N + 1;
                dist2 = 0;
                p[2] = -1;
            } else {
                k = lstCol[s];
                if(tree_pos[k].col >= tree_pos[i].col) {
                    dist2 = N;
                    if(_upHand == 0) {
                        // Down hand square
                        if(tree_pos[k].row > _up) {
                            dist2 = tree_pos[k].row - _up;
                        } else continue;
                    } else {
                        // Up hand square
                        if(tree_pos[k].row < _down) {
                            dist2 = _down - tree_pos[k].row;                            
                        } else continue;
                    }
                    //if(dist2 > min_dist) continue;
                    _right = tree_pos[k].col;
                    if(_right - _left <= max_square) continue;
                    p[2] = k;
                } else continue;
            }
            dist = max(dist, dist2);
            // 3: find the most close row# that between 0 and 2
            int _temp;
            if(_upHand == 0) {
                // Down hand square
                p[1] = i;
                for(r = tree_pos[i].r_idx + 1; r <= T; r++) {
                    if(r == T) {
                        _temp = tree_pos[i].col;
                        _down = N + 1;                        
                        p[3] = -1;
                    } else {
                        k = lstRow[r];
                        _temp = tree_pos[k].col;
                        _down = tree_pos[k].row;
                        p[3] = k;
                        if(_temp > _left && _temp < _right) break;
                    }
                }
            } else {
                // Up hand square
                p[3] = i;
                for(r = tree_pos[i].r_idx - 1; r >= -1; r--) {
                    if(r == -1) {
                        _temp = tree_pos[i].col;
                        _up = 0;
                        p[1] = -1;
                    } else {
                        k = lstRow[r];
                        _temp = tree_pos[k].col;
                        _up = tree_pos[k].row;
                        p[1] = k;
                        if(_temp > _left && _temp < _right) break;
                    }
                }                
            }
            if(_down >= _up + dist) {
                int _w = _right - _left - 1;
                int _h = _down - _up - 1;
                int _square = min(_w, _h);
                // Found bigger square
                if(_square > max_square) {
                    max_square = _square;
                    min_dist = _w;
                }
            }
        }
    }

    return max_square; 
}

#define LOCAL

int main() {
    int i, row, col;

#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    //const string strFile = "j5.sample.02";
    const string strFile = "j5.4-07";       // j5.4-05, j5.4-02

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif

    // Get inputs
#ifndef LOCAL
    printf("Please input N (<=%d): ", MaxN);
#endif    
    scanf("%d", &N);
    assert(N<=MaxN);

#ifndef LOCAL
    printf("Please input trees (<=%d): ", MAX_TREES);
#endif
    scanf("%d", &T);
    assert(T<=MAX_TREES);
    lstRow = new int[T];
    lstCol = new int[T];

    // Read positions for each tree
#ifndef LOCAL    
    printf("Please input position of trees \n\r");
#endif    
    for(i = 0; i < T; i++) {
        scanf("%d %d", &row, &col);
        //assert(row>0 && row<=N && col>0 && col<=N);
        lstRow[i] = i;
        lstCol[i] = i;
        tree_pos[i].row = row;
        tree_pos[i].col = col;
    }

    //  Sort row list by col list
    qsort (lstRow, T, sizeof(int), compareRow);
    qsort (lstCol, T, sizeof(int), compareCol);
    for(i = 0; i < T; i++) {
        tree_pos[lstRow[i]].r_idx = i;
        tree_pos[lstCol[i]].c_idx = i;
    }

    // Find max square by dertrmining 4 sides: O(T^2)
    max_square = 0;
    if(T < N * N) {
        max_square = 1;
        for(i = 0; i < T; i++) {
            squareLen(i);
        }
    }

    // Print the result
    cout << max_square << endl;

#ifdef LOCAL
    // Close all opened files
    fclose(stdin);
    fclose(stdout);
#endif

    // Free buffers
    delete []lstRow;
    delete []lstCol;

    return max_square;
}