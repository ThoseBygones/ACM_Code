#include <bits/stdc++.h>
using namespace std;

int a[105];
char str[105];
char alpha[]= {'a', 'e', 'i', 'o', 'u', 'y'};

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    bool flag=true;
    getchar();
    for(int i=1; i<=n; i++)
    {
        gets(str);
        int len=strlen(str);
        int cnt=0;
        for(int j=0; j<len; j++)
        {
            for(int k=0; k<6; k++)
            {
                if(str[j]==alpha[k])
                {
                    cnt++;
                    break;
                }
            }
        }
        //cout << cnt << endl;
        if(cnt!=a[i])
            flag=false;
    }
    if(flag)
        puts("YES\n");
    else
        puts("NO\n");
    return 0;
}
