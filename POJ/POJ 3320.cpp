#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#define MAXN 1000005

int a[MAXN];
set <int> s;
map <int,int> cnt;

int main()
{
    int p;
    scanf("%d",&p);
    for(int i=0; i<p; i++)
    {
        scanf("%d",&a[i]);
        s.insert(a[i]);
    }
    int n=s.size();
    int ans=p;
    int l=0,r=0;
    int sum=0;
    while(true)
    {
        while(r<p && sum<n)
        {
            if(!cnt[a[r]])
                sum++;
            cnt[a[r]]++;
            r++;
        }
        if(sum<n)
            break;
        ans=min(ans,r-l);
        cnt[a[l]]--;
        if(!cnt[a[l]])
            sum--;
        l++;
    }
    printf("%d\n",ans);
    return 0;
}
