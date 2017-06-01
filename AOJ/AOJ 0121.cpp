#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
using namespace std;

map <string,int> step;
int dir[]={-1,1,-4,4};

void bfs()
{
    queue <string> q;
    string temp="01234567";
    q.push(temp);
    while(!q.empty())
    {
        string now=q.front();
        q.pop();
        int p=0;
        for(int i=0; i<8; i++)
        {
            if(now[i]=='0')
            {
                p=i;
                break;
            }
        }
        for(int i=0; i<4; i++)
        {
            int np=p+dir[i];
            if(np>=0 && np<8)
            {
                if((p==3 && np==4) || (p==4 && np==3))
                    continue;
                string next=now;
                swap(next[p],next[np]);
                if(!step[next])
                {
                    q.push(next);
                    step[next]=step[now]+1;
                }
            }
        }
    }
}

int main()
{
    step["01234567"]=1;
    bfs();
    int n;
    while(~scanf("%d",&n))
    {
        string s;
        s=n+'0';
        for(int i=1; i<8; i++)
        {
            scanf("%d",&n);
            s+=n+'0';
        }
        printf("%d\n",step[s]-1);
    }
    return 0;
}
