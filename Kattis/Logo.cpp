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

int main() {
#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "Logo.01";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif
    FAST_IO;

    int T;
    cin >> T;
    while(T--) {
        ld x = 0, y = 0;
        ll angle = 0;
        int n;
        cin >> n;
        while(n--) {
            string cmd;
            int value;
            cin >> cmd >> value;
            if(cmd.compare("fd") == 0) {
                x += ((ld)value * sin(DEG_to_RAD((ld)angle)));
                y += ((ld)value * cos(DEG_to_RAD((ld)angle)));
            } else if(cmd.compare("bk") == 0) {
                x -= ((ld)value * sin(DEG_to_RAD((ld)angle)));
                y -= ((ld)value * cos(DEG_to_RAD((ld)angle)));                
            } else if(cmd.compare("lt") == 0) {
                angle -= value;
            } else if(cmd.compare("rt") == 0) {
                angle += value;
            }
        }
        double dist = sqrt(x * x + y * y); 
        cout << (int)(dist + 0.5) << endl;
    }
    return 0;
}