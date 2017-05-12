#include<iostream>
#include<algorithm>
using namespace std;

struct trap
{
    int lbx;
    int lby;
    int rtx;
    int rty;
} t[105];

struct sandbag
{
    int x;
    int y;
    int dis;
} sb[20005];

int cmp(sandbag a,sandbag b)
{
    return a.dis>b.dis;
}

int main()
{
    int m,n;
    cin >> m >> n;
    for(int i=0; i<m; i++)
        cin >> sb[i].x >> sb[i].y;
    for(int i=0; i<n; i++)
        cin >> t[i].lbx >> t[i].lby >> t[i].rtx >> t[i].rty;
    for(int i=0; i<m; i++)
    {
        bool flag=false;
        for(int j=0; j<n; j++)
        {
            if(sb[i].x>=t[j].lbx && sb[i].x<=t[j].rtx && sb[i].y>=t[j].lby && sb[i].y<=t[j].rty)
            {
                sb[i].dis=2*(t[j].rtx-t[j].lbx+t[j].rty-t[j].lby);
                flag=true;
                break;
            }
        }
        if(!flag)
            sb[i].dis=0;
    }
    sort(sb,sb+m,cmp);
    for(int i=0; i<m; i++)
        cout << sb[i].dis << endl;
    return 0;
}
