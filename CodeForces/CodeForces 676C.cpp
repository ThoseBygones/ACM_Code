#include <bits/stdc++.h>
using namespace std;

char s[100005];

queue <char> q;

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    scanf("%s",s);
    int Max=0;  //�����
    int t=0;  //�޸ĵĴ���
    for(int i=0; i<n; i++)
    {
        if(s[i]=='a')   //��a����
            q.push(s[i]);
        else
        {
            if(t<k) //�����޸�
            {
                q.push(s[i]);
                t++;
            }
            else
            {
                Max=max(Max,(int)q.size());
                while(!q.empty() && q.front()=='a') //�����Ķ���δ�޸ĵ�a
                    q.pop();
                if(!q.empty())  //�����˸��޸ĺ��a
                {
                    q.pop();
                    q.push(s[i]);
                }
            }
        }
    }
    Max=max(Max,(int)q.size());
    while(!q.empty())   //��ն���
        q.pop();
    t=0;
    for(int i=0; i<n; i++)
    {
        if(s[i]=='b')   //��b����
            q.push(s[i]);
        else
        {
            if(t<k) //�����޸�
            {
                q.push(s[i]);
                t++;
            }
            else
            {
                Max=max(Max,(int)q.size());
                while(!q.empty() && q.front()=='b') //�����Ķ���δ�޸ĵ�a
                    q.pop();
                if(!q.empty())  //�����˸��޸ĺ��a
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
