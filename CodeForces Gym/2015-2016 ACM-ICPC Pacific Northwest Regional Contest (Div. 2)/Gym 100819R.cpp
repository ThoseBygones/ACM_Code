#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define LL long long
#define INF 0x3f3f3f3f
#define MAXN 105

struct StuName
{
    string f;
    string l;
} name[MAXN];

bool cmp(StuName a,StuName b)
{
    if(a.l==b.l)
        return a.f<b.f;
    return a.l<b.l;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        cin >> name[i].f >> name[i].l;
    sort(name+1,name+n+1,cmp);
    for(int i=1; i<=n; i++)
        cout << name[i].f << " " << name[i].l << endl;
    return 0;
}
