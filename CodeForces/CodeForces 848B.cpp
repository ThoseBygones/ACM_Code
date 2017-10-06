#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

struct Dancer
{
    int g,p,t,id;
} a[MAXN];

int x[MAXN],y[MAXN];
int q1[MAXN],q2[MAXN];  //make queue for vertically and horizontally moving dancers

bool cmp(Dancer &x,Dancer &y)   //Format: t1+p2=t2+p1 => t1-p1=t2-p2
{
    if(x.t-x.p==y.t-y.p)
        return x.p<y.p;
    return x.t-x.p<y.t-y.p;
}

int main()
{
    int n,w,h;
    scanf("%d%d%d",&n,&w,&h);
    for(int i=1; i<=n; i++)
    {
        scanf("%d%d%d",&a[i].g,&a[i].p,&a[i].t);
        a[i].id=i;
    }
    sort(a+1,a+1+n,cmp);
    int i;
    for(i=1; i<=n; i++)
    {
        int p1,p2,cnt;
        p1=p2=0;
        if(a[i].g==1)   //vertically
            q1[++p1]=i;
        else    //horizontally
            q2[++p2]=i;
        while(i<n && a[i].t-a[i].p==a[i+1].t-a[i+1].p)
        {
            i++;
            if(a[i].g==1)
                q1[++p1]=i;
            else
                q2[++p2]=i;
        }
        bool flag=false;
        cnt=p2+1;
        for(int j=1; j<=p1; j++)    //deal with vertical dancer queue
        {
            if(flag)
                cnt++;  //choose vertically dancers from left to right
            else
                cnt--;  //choose horizontally dancers from up to down
            if(cnt==0)  //all the horizontally dancers have been matched
            {
                cnt++;  //choose dancers from the vertical dancer
                flag=true;
            }
            if(flag)    //all the horizontally dancers have been matched
            {
                x[a[q1[cnt]].id]=a[q1[j]].p;
                y[a[q1[cnt]].id]=h;
            }
            else    //matching with horizontal dancers
            {
                x[a[q2[cnt]].id]=a[q1[j]].p;
                y[a[q2[cnt]].id]=h;
            }
        }
        flag=false;
        cnt=p1+1;
        for(int j=1; j<=p2; j++)    //deal with horizontal dancer queue
        {
            if(flag)
                cnt++;  //choose vertically dancers from left to right
            else
                cnt--;  //choose horizontally dancers from up to down
            if(cnt==0)  //all the horizontally dancers have been matched
            {
                cnt++;
                flag=true;
            }
            if(flag)    //all the vertically dancers have been matched
            {
                x[a[q2[cnt]].id]=w;
                y[a[q2[cnt]].id]=a[q2[j]].p;
            }
            else    //matching with horizontally dancers
            {
                x[a[q1[cnt]].id]=w;
                y[a[q1[cnt]].id]=a[q2[j]].p;
            }
        }
    }
    for(int i=1; i<=n; i++)
        printf("%d %d\n",x[i],y[i]);
    return 0;
}
