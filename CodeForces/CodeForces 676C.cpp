#include <bits/stdc++.h>
using namespace std;

char s[100005];

queue <char> q;

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    scanf("%s",s);
    int Max=0;  //最长长度
    int t=0;  //修改的次数
    for(int i=0; i<n; i++)
    {
        if(s[i]=='a')   //对a操作
            q.push(s[i]);
        else
        {
            if(t<k) //还可修改
            {
                q.push(s[i]);
                t++;
            }
            else
            {
                Max=max(Max,(int)q.size());
                while(!q.empty() && q.front()=='a') //弹出的都是未修改的a
                    q.pop();
                if(!q.empty())  //弹出了个修改后的a
                {
                    q.pop();
                    q.push(s[i]);
                }
            }
        }
    }
    Max=max(Max,(int)q.size());
    while(!q.empty())   //清空队列
        q.pop();
    t=0;
    for(int i=0; i<n; i++)
    {
        if(s[i]=='b')   //对b操作
            q.push(s[i]);
        else
        {
            if(t<k) //还可修改
            {
                q.push(s[i]);
                t++;
            }
            else
            {
                Max=max(Max,(int)q.size());
                while(!q.empty() && q.front()=='b') //弹出的都是未修改的a
                    q.pop();
                if(!q.empty())  //弹出了个修改后的a
                {
                    q.pop();
                    q.push(s[i]);
                }
            }
        }
    }
    Max=max(Max,(int)q.size());
    printf("%d\n",Max);
    return 0;
}
