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
    const string strFile = "CaloriesFromFat.01";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif
    const int cal[5] = {9, 4, 4, 4, 7};

    double C = 0.0, F = 0.0;
    int cnt = 0;
    string s[5];
    while(true) {
        cin >> s[0];
        if(s[0].at(0) == '-') {
            if(++cnt > 1) return 0;
            // Finishing current test case
            printf("%d%%\n", (int)(F * 100 / C + 0.5));
            // Prepare for the next test case
            C = 0;
            F = 0;
        } else {
            cnt = 0;
            double itemC = 0.0;
            double itemF = 0.0;
            int fatPercent = 0;
            int itemPercent = 0;
            cin >> s[1] >> s[2] >> s[3] >> s[4];
            for(int i = 0; i < 5; i++) {
                char unit = s[i].back();
                int num = atoi(s[i].substr(0, s[i].size() - 1).c_str());
                int calories = 0;
                int percent = 0;           
                switch(unit) {
                    case 'g':
                    calories = (num * cal[i]);
                    break;
                    case 'C':
                    calories = num;
                    break;
                    case '%':
                    percent = num;
                    break;                    
                }
                if(i == 0) {
                    itemF = calories;
                    fatPercent = percent;
                }
                itemC += calories;
                itemPercent += percent;
            }
            if(itemPercent > 0) {
                itemC = itemC * 100 / (100 - itemPercent);
                if(fatPercent > 0) {
                    itemF = itemC * fatPercent / 100;
                }
            }
            C += itemC;
            F += itemF;
        }

    }

    return 0;
}