#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005

stack <int> s;

int main()
{
    int n;
    scanf("%d",&n);
    int cnt=0;
    int ans=0;
    for(int i=0; i<2*n; i++)
    {
        char op[15];
        scanf("%s",op);
        if(op[0]=='a')
        {
            int x;
            scanf("%d",&x);
            s.push(x);
        }
        else
        {
            cnt++;
            if(!s.empty() && s.top()==cnt)
                s.pop();
            else if(!s.empty())
            {
                ans++;
                while(!s.empty())
                    s.pop();
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
