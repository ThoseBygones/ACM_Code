#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#define MAXN 10
using namespace std;

int win[MAXN][MAXN];
int indegree[MAXN];
int dx[]={0,0,1,1};
int dy[]={0,1,0,1};

vector <int> value[MAXN][MAXN];

bool TopoSort()
{
    queue <int> q;
    for(int i=0; i<9; i++)
    {
        if(indegree[i]==0)
            q.push(i);
    }
    int sum=0;
    while(!q.empty())
    {
        int temp=q.front();
        q.pop();
        for(int j=0; j<9; j++)
        {
            if(win[temp][j])
            {
                win[temp][j]=0;
                indegree[j]--;
                if(!indegree[j])
                    q.push(j);
            }
        }
        sum++;
    }
    if(sum==9)
        return true;
    return false;
}

int main()
{
    for(int i=0; i<9; i++)
    {
        int x=i/3;
        int y=i%3;
        for(int j=0; j<4; j++)
        {
            int nx=x+dx[j];
            int ny=y+dy[j];
            value[nx][ny].push_back(i);
        }
    }
    string str;
    while(cin >> str && str!="ENDOFINPUT")
    {
        memset(win,0,sizeof(win));
        memset(indegree,0,sizeof(indegree));
        for(int i=0; i<4; i++)
        {
            for(int j=0; j<4; j++)
            {
                int num;
                cin >> num;
                num--;
                for(int k=0; k<value[i][j].size(); k++)
                {
                    if(value[i][j][k]!=num)
                    {
                        int temp=value[i][j][k];
                        if(win[temp][num]==0)
                        {
                            indegree[num]++;
                            win[temp][num]=1;
                        }
                    }
                }
            }
        }
        cin >> str;
        if(TopoSort())
            cout << "THESE WINDOWS ARE CLEAN" << endl;
        else
            cout << "THESE WINDOWS ARE BROKEN" << endl;
    }
    return 0;
}
