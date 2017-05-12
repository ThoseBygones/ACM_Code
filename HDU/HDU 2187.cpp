#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

struct rice
{
    int p;
    int w;
};
rice r[1005];

bool cmp(rice a,rice b)
{
    if(a.p<b.p)
        return true;
    return false;
}

int main()
{
    int cas;
    while(cin >> cas)
    {
        while(cas--)
        {
            int n,m;
            cin >> n >> m;
            for(int i=0; i<m; i++)
                cin>>r[i].p>>r[i].w;

            sort(r,r+m,cmp);

            double sum=0;
            int money=0;
            for(int i=0; i<m; i++)
            {
                money+=r[i].p*r[i].w;
                sum+=r[i].w;
                if(money>n)
                {
                    sum-=(money-n)*1.0/r[i].p;
                    break;
                }
            }
            printf("%.2lf\n",sum);
        }

    }
    return 0;
}
