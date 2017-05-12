#include <iostream>
#include <cstring>
#define MAXN 1005
using namespace std;

int x[MAXN],y[MAXN];
int ok[MAXN];   //记录某台电脑是否被修好
int par[MAXN];  //记录父节点的数组
int n,d;

int findSet(int r)
{
    if(par[r]!=r)
        par[r]=findSet(par[r]);
    return par[r];
}

bool communicate(int a,int b)
{
    if((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b])<=d*d)
        return true;
    return false;
}

int main()
{
    cin >> n >> d;
    for(int i=1; i<=n; i++)
    {
        cin >> x[i] >> y[i];
        par[i]=i;
        ok[i]=false;
    }
    char op;
    int num;
    while(cin >> op)
    {
        if(op=='O')
        {
            cin >> num;
            ok[num]=true;
            for(int i=1; i<=n; i++)
            {
                if(i!=num && ok[i] && communicate(i,num))
                {
                    int xx=findSet(i);
                    int yy=findSet(num);
                    par[xx]=yy;
                }
            }
        }
        if(op=='S')
        {
            int t1,t2;
            cin >> t1 >> t2;
            int xx=findSet(t1);
            int yy=findSet(t2);
            if(xx==yy)
                cout << "SUCCESS" << endl;
            else
                cout << "FAIL" << endl;
        }
    }
    return 0;
}
