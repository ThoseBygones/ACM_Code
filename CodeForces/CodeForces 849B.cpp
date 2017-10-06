#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005
#define EPS 1e-6

double y[MAXN];
int n;

bool check(double k)
{
    int temp=-1;
    bool flag=false;
    for(int i=2; i<=n; i++)
    {
        if(fabs(y[i]-y[1]-k*(i-1))<=EPS)
            continue;
        flag=true;
        if(temp==-1)
            temp=i;
        else if(fabs(y[i]-y[temp]-k*(i-temp))>EPS)
        {
            flag=false;
            break;
        }
    }
    return flag?true:false;
}

int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%lf",&y[i]);
    double k12=1.0*(y[2]-y[1]);
    double k13=0.5*(y[3]-y[1]);
    double k23=1.0*(y[3]-y[2]);
    //cout << k12 << " " << k13 << " " << k23 << endl;
    if(check(k12) || check(k13) || check(k23))
        puts("Yes");
    else
        puts("No");
    return 0;
}
