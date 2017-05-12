#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

int m,n;
int door[25];
string sign;
char str[1005];

int main()
{
    while(cin >> sign)
    {
        if(sign=="ENDOFINPUT")
            break;
        cin >> m >> n;
        getchar();
        int cnt=0;
        memset(door,0,sizeof(door));
        for(int i=0; i<n; i++)
        {
            gets(str);
            int len=strlen(str);
            for(int j=0; j<len; j++)
            {
                if(str[j]!=' ')
                {
                    int num=str[j]-'0';
                    cnt++;
                    door[i]++;
                    door[num]++;
                }
            }
        }
        cin >> sign;
        int odd=0,even=0;
        for(int i=0; i<n; i++)
        {
            if(door[i]%2)
                odd++;
            else
                even++;
        }
        if(odd==0 && m==0)
            cout << "YES " << cnt << endl;
        else if(odd==2 && door[m]%2 && door[0]%2 && m!=0)
            cout << "YES " << cnt << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
