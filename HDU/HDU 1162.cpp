#include<iostream>
#include<iomanip>
#include<cmath>
#include<algorithm>
using namespace std;

int par[105];

struct picture
{
    int a;
    int b;
    double len;
} pic[5055];

struct point
{
    double x;
    double y;
} p[105];

double cmp(picture m,picture n)
{
    return m.len < n.len;
}

double dis(point m,point n)
{
    return sqrt((m.x-n.x)*(m.x-n.x)+(m.y-n.y)*(m.y-n.y));
}

int findset(int r)
{
    if(r!=par[r])
        return par[r]=findset(par[r]);
    return r;
}

bool mergeset(int x,int y)
{
    int xx=findset(x);
    int yy=findset(y);
    if(xx!=yy)
    {
        par[yy]=xx;
        return true;
    }
    return false;
}

double kruskal(int n)
{
    double sum=0.0;
    for(int i=0; i<n; i++)
    {
        if(mergeset(pic[i].a,pic[i].b))
        {
            sum+=pic[i].len;
            //cout << sum << endl;
        }
    }
    return sum;
}

int main()
{
    int n;
    while(cin >> n)
    {
        for(int i=1; i<=n; i++)
            par[i]=i;
        for(int i=1; i<=n; i++)
            cin >> p[i].x >> p[i].y;
        int cnt=0;
        for(int i=1; i<n; i++)
        {
            for(int j=i+1; j<=n; j++)
            {
                pic[cnt].a=i;
                pic[cnt].b=j;
                pic[cnt].len=dis(p[i],p[j]);
                //cout << pic[cnt].len << endl;
                cnt++;
            }
        }
        sort(pic,pic+cnt,cmp);
        double sum=kruskal(cnt);
        cout << fixed << setprecision(2) << sum << endl;
    }
    return 0;
}
