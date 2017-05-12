#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 1005

vector <int> ans;

int lowbit(int x)
{
    return x&(-x);
}

int main()
{
    int sum,limit;
    scanf("%d%d",&sum,&limit);
    for(int i=limit; i>=1; i--) //从后往前贪，能保证每次贪的数是最大的
    {
        int val=lowbit(i);
        if(val<=sum)
        {
            ans.push_back(i);
            sum-=val;
        }
    }
    if(sum)
        puts("-1\n");
    else
    {
        int sz=ans.size();
        printf("%d\n",sz);
        for(int i=0; i<sz; i++)
            printf("%d ",ans[i]);
        printf("\n");
    }
    return 0;
}
