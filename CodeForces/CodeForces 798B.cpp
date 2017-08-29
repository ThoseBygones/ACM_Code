#include <bits/stdc++.h>
using namespace std;

#define MAXN 55
#define INF 0x3f3f3f3f

string s[MAXN];

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> s[i];
    bool flag=true;
    int ans=INF;
    for(int i=1; i<=n; i++)
    {
        int cnt=0;
        for(int j=1; j<=n; j++)
        {
            if(j!=i)
            {
                int sz=s[j].length();
                bool match=false;
                string temp=s[j];
                if(temp==s[i])
                    continue;
                while(sz)
                {
                    temp=temp.substr(1)+temp[0];
                    //cout << temp << endl;
                    //system("pause");
                    cnt++;
                    sz--;
                    if(temp==s[i])
                    {
                        match=true;
                        break;
                    }
                }
                if(!match)
                    flag=false;
            }
        }
        ans=min(ans,cnt);
    }
    if(flag)
        printf("%d\n",ans);
    else
        puts("-1");
}
