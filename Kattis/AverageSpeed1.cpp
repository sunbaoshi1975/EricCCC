#include <bits/stdc++.h>
using namespace std;

#define LOCAL

int main(){
#ifdef LOCAL
    const string strPath = ".\\testcase\\";
    const string strFile = "AverageSpeed.02";

    string strInFile = strPath + strFile + ".in";
    string strOutFile = strPath + strFile + ".my.out";
    freopen(strInFile.c_str(), "r", stdin);
    freopen(strOutFile.c_str(), "w", stdout);
#endif

   int hh, mm, ss, speed=0, newspeed, i, j, k, n, time = 0, now;
   char buf[2000];
   double dist = 0;

   while(fgets(buf, 90, stdin)) {
      n = sscanf(buf,"%d:%d:%d %d",&hh,&mm,&ss,&newspeed);
      now = hh*3600 + mm*60 + ss;
      dist += (now - time) / 3600. * speed;
      time = now;
      if (n == 3) printf("%02d:%02d:%02d %0.2lf km\n",hh,mm,ss,dist);
      else if (n == 4) speed = newspeed;
   }
   return 0;
}