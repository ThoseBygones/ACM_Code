#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005

vector <int> ans;

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=90; i++)
    {
        int x=n-i;
        int temp=x;
        while(temp)
        {
            x+=temp%10;
            temp/=10;
        }
        if(x==n)
            ans.push_back(n-i);
    }
    sort(ans.begin(),ans.end());
    printf("%d\n",ans.size());
    for(int i=0; i<ans.size(); i++)
    {
        if(i)
            printf(" %d",ans[i]);
        else
            printf("%d",ans[i]);
    }
    puts("");
    return 0;
}
