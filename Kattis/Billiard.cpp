#include <bits/stdc++.h>
using namespace std;

#define LOCAL

int main() {

#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "Billiard.01";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif

    char buf[100];
    int a, b, s, m, n;
    double A, V;
    //double Vh, Vv;
    double PI = 3.1415926;
    while(fgets(buf, 90, stdin)) {
        sscanf(buf, "%d %d %d %d %d",&a, &b, &s, &m, &n);
        if(a == 0 && b == 0 && s == 0 && m == 0 && n == 0) break;
        //Vh = m * a / s;
        //Vv = n * b / s;
        //V = sqrt(Vh * Vh + Vv * Vv);
        double temp = sqrt((double)m * m * a * a + (double)n * n * b * b);
        V = temp / s;
        A = acos((double)m * a / temp);
        printf("%.2lf %.2lf\n", A * 180 / PI, V);
    }
    return 0;
}