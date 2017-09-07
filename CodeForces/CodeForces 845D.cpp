#include <bits/stdc++.h>
using namespace std;

stack <int> sta;

int main()
{
    int n,t,s;
    scanf("%d",&n);
    int cnt=0;
    int ans=0;
    int speed=0;    //Polycarp现在的车速
    for(int i=0; i<n; i++)
    {
        scanf("%d",&t);
        if(t==1)    //Polycarp变速
        {
            scanf("%d",&s);
            speed=s;
            while(!sta.empty() && sta.top()<speed) //之前限速更低
            {
                ans++;
                sta.pop();
            }
        }
        if(t==2)   //Polycarp超车
        {
            ans+=cnt;
            cnt=0;
        }
        if(t==3)   //限速s
        {
            scanf("%d",&s);
            if(speed>s)
                ans++;
            else
                sta.push(s);
        }
        if(t==4)   //允许超车
            cnt=0;
        if(t==5)   //取消限速
        {
            while(!sta.empty())
                sta.pop();
        }
        if(t==6)   //禁止超车
            cnt++;
    }
    printf("%d\n",ans);
    return 0;
}
