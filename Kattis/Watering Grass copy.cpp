#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define min 1e-8
struct data{double x; double y;}p[10005];
int cmp( const void *a ,const void *b) 
{return (*(data *)a).x>(*(data *)b).x?1:-1;} 
int main()
{
    int n,l,w,x,r,i,j;
    while(scanf("%d%d%d",&n,&l,&w)!=EOF)
    {
        int c=0,f=0,ans=0;
        double s=0,e=0,d;
        for(i=0;i<n;i++)
        {
            scanf("%lf%d",&d,&r);
            if(r<w/2.0) continue;
            double temp=sqrt((double)r*r-(double)w*w/4.0);
            p[c].x=d-temp;
            p[c].y=d+temp;
            c++;
        }
        qsort(p,c,sizeof(p[0]),cmp);
        for(i=0;i<c;i++)
            if(p[i].x>e) 
                break;
            else if(p[i].y>e)  
            {  
                for(j=i;j<c&&p[j].x-s<min;j++)  
                    if(e-p[j].y<-min) 
                        e=p[j].y;  
                ans++;  
                if(e>=l)  
                {f=1;break;}  
                s=e;  
            }  
            if(f)  
                printf("%d\n",ans);  
            else  
                printf("-1\n");  
    }
    return 0;
}