#include<bits/stdc++.h>
using namespace std;

#define LOCAL
//#define PI          3.14159265358979323856

typedef long long   ll;
typedef long double ld;
const ld EPS = 1e-8;

// fast i/o
#define FAST_IO    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)

// Counter Clockwise Rotation about Pivot which defaults to origin
ld DEG_to_RAD(ld d) { return d * M_PI / 180; }
ld RAD_to_DEG(ld r) { return r * 180 / M_PI; }

struct point {
    ld x, y;
    point() { x = y = 0; }
    point(ld _x, ld _y) : x(_x), y(_y) {}
};

// Vector Struct
struct vec {
    ld x, y;
    vec(ld _x, ld _y) : x(_x), y(_y) {}
    vec(point p1, point p2) : x(p2.x - p1.x), y(p2.y - p1.y) {}

    // Vector Operations
    vec operator+(const vec &v) const { return vec(x + v.x, y + v.y); }
    vec operator-(const vec &v) const { return vec(x - v.x, y - v.y); }
    vec operator*(const ld &r) const { return vec(x * r, y * r); }
    vec operator/(const ld &r) const { return vec(x / r, y / r); }

    // Length
    ld length() { return hypot(x, y); }

    // Length Square
    ld length_sq() { return x * x + y * y; }
};

vec rotate(ld rad, vec v) {
    ld x = v.x;
    ld y = v.y;
    ld nx = x * cos(rad) - y * sin(rad);
    ld ny = x * sin(rad) + y * cos(rad);
    return vec(nx, ny);
}

int main() {
#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "Logo.02";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif
    FAST_IO;

    vector<pair<string, string>> cmds;

    int T;
    cin >> T;
    while(T--) {
        cmds.clear();
        ld x = 0, y = 0;
        ll angle = 0;
        int n, query;
        cin >> n;
        while(n--) {
            string cmd, value;
            cin >> cmd >> value;
            cmds.push_back({cmd, value});
            if(value == "?") {
                if(cmd.compare("fd") == 0) {
                    query = 1;
                } else if(cmd.compare("bk") == 0) {
                    query = 2;
                } else if(cmd.compare("lt") == 0) {
                    query = 3;
                } else if(cmd.compare("rt") == 0) {
                    query = 4;
                }
            }
        }

        if(query == 1 || query == 2) {
            vec direction = vec(point(0, 0), point(0, 1));  // toward positive y
            vec cur_vec = vec(point(0, 0), point(0, 0));
            for(int i = 0; i < cmds.size(); i++) {
                if(cmds[i].second == "?") continue;
                if(cmds[i].first == "lt") {
                    direction = rotate(DEG_to_RAD(stoi(cmds[i].second) % 360), direction);
                    direction = direction / direction.length();
                } else if (cmds[i].first == "rt") {
                    direction = rotate(DEG_to_RAD(-(stoi(cmds[i].second) % 360)), direction);
                    direction = direction / direction.length();
                } else if (cmds[i].first == "fd") {
                    cur_vec = cur_vec + direction * stoi(cmds[i].second);
                } else if (cmds[i].first == "bk") {
                    cur_vec = cur_vec - direction * stoi(cmds[i].second);
                }
            }
            cout << int(roundl(cur_vec.length())) << endl;
        } else {
            for(int theta = 0; theta < 360; theta++) {
                vec direction = vec(point(0, 0), point(0, 1));  // toward positive y
                vec cur_vec = vec(point(0, 0), point(0, 0));
                for(int i = 0; i < cmds.size(); i++) {
                    if(cmds[i].second == "?") {
                        if(cmds[i].first == "lt") {
                            direction = rotate(DEG_to_RAD(theta), direction);
                            direction = direction / direction.length();
                        } else if (cmds[i].first == "rt") {
                            direction = rotate(DEG_to_RAD(360 - theta), direction);
                            direction = direction / direction.length();
                        }
                        continue;
                    }

                    if(cmds[i].first == "lt") {
                        direction = rotate(DEG_to_RAD(stoi(cmds[i].second) % 360), direction);
                        direction = direction / direction.length();
                    } else if(cmds[i].first == "rt") {
                        direction = rotate(DEG_to_RAD(-(stoi(cmds[i].second) % 360)), direction);
                        direction = direction / direction.length();
                    } else if(cmds[i].first == "fd") {
                        cur_vec = cur_vec + direction * stoi(cmds[i].second);
                    } else if(cmds[i].first == "bk") {
                        cur_vec = cur_vec - direction * stoi(cmds[i].second);
                    }
                }
                if(fabs(cur_vec.x) < EPS && fabs(cur_vec.y) < EPS) {
                    cout << theta << endl;
                    break;
                }
            }
        }            
    }
    return 0;
}