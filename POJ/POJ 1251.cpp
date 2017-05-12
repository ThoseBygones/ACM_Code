#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int par[30];

struct city
{
    int s;
    int e;
    int len;
} c[105];

bool cmp(city a,city b)
{
    return a.len<b.len;
}

int findset(int r)
{
    if(r!=par[r])
        return par[r]=findset(par[r]);
    return r;
}

bool mergeset(int x,int y)
{
    int xx=findset(x);
    int yy=findset(y);
    if(xx!=yy)
    {
        par[yy]=xx;
        return true;
    }
    return false;
}

int main()
{
    int n,cnt,sum,k;
    while(cin >> n,n)
    {
        for(int i=0; i<27; i++)
            par[i]=i;
        k=0;
        for(int i=0; i<n-1; i++)
        {
            char str1[3];
            int m;
            cin >> str1 >> m;
            for(int j=0; j<m; j++,k++)
            {
                char str2[3];
                int l;
                cin >> str2 >> l;
                c[k].s=str1[0]-'A';
                c[k].e=str2[0]-'A';
                c[k].len=l;
            }
        }
        sort(c,c+k,cmp);
        cnt=0;
        sum=0;
        for(int i=0; i<k; i++)
        {
            if(mergeset(c[i].s,c[i].e))
            {
                sum+=c[i].len;
                cnt++;
            }
            if(cnt==n-1)
                break;
        }
        cout << sum << endl;
    }
    return 0;
}
