#include <iostream>
#include <algorithm>
using namespace std;

struct Stone
{
    int id;
    int a;
    int b;
    int c;
} s[100005];

bool cmp(Stone x,Stone y)
{
    if(x.a==y.a)
    {
        if(x.b==y.b)
            return x.c<y.c;
        return x.b<y.b;
    }
    return x.a<y.a;
}

int main()
{
    int n;
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> s[i].a >> s[i].b >> s[i].c;
        s[i].id=i;
        if(s[i].a<s[i].b)
            swap(s[i].a,s[i].b);
        if(s[i].a<s[i].c)
            swap(s[i].a,s[i].c);
        if(s[i].b<s[i].c)
            swap(s[i].b,s[i].c);
    }
    sort(s+1,s+n+1,cmp);
    //for(int i=1; i<=n; i++)
    //    cout << s[i].a << " " << s[i].b << " " << s[i].c << endl;
    int k=0;
    int ans=0;
    int id1=0,id2=0;
    int cnt=1;
    for(int i=2; i<=n; i++)
    {
        if(s[i].a==s[i-1].a && s[i].b==s[i-1].b)
        {
            int d=min(min(s[i].a,s[i].b),s[i].c+s[i-1].c);
            if(d>ans)
            {
                ans=d;
                id1=s[i-1].id;
                id2=s[i].id;
                cnt=2;
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        int d=min(min(s[i].a,s[i].b),s[i].c);
        if(d>ans)
        {
            ans=d;
            k=s[i].id;
            cnt=1;
        }
    }
    if(cnt==2)
    {
        cout << "2" << endl;
        cout << id1 << " " << id2 << endl;
    }
    else
        cout << "1" << endl << k << endl;
    return 0;
}
