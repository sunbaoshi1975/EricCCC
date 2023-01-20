#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;

#define LOCAL

struct sprinkler {
    int x;
    int r;
    double left;
    double right;
};

int main() {
	// fast i/o 
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "Watering Grass";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif

    int n, l, w;
    while(scanf("%d %d %d", &n, &l, &w) == 3) {
        double wwq = (double)w * w / 4.0; 
        vector<sprinkler> slist;
        while(n--) {
            sprinkler tmp;
            scanf("%d %d", &tmp.x, &tmp.r);
            if(tmp.r * 2 > w) {
                double t = sqrt((double)tmp.r * tmp.r - wwq);
                tmp.left = (tmp.x > t ? tmp.x - t : 0.0);
                tmp.right = tmp.x + t;
                // Insert by left ascending
                vector<sprinkler>::iterator it;
                for(it = slist.begin(); it != slist.end(); ++it) {
                    if(it->left > tmp.left) {
                        break;
                    }
                }
                slist.insert(it, tmp);
            }            
        }

        // Find solution
        int minNum = 0;
        double step = 0.0;
        for(int i = 0; i < slist.size();) {
            if(slist.at(i).left > step) {
                minNum = -1; // No answer
                break;
            }
            // Pick the largest right whose left <= step
            double lr = slist.at(i).right;
            int j;
            for(j = i + 1; j < slist.size(); j++) {
                if(slist.at(j).left - step > EPS) break;
                if(slist.at(j).right - lr > EPS) {
                    lr = slist.at(j).right;
                }
            }
            step = lr;
            minNum++;
            if(step >= l) break;
            i = j;
        }
        printf("%d\n", minNum);
    }

    return 0;
}