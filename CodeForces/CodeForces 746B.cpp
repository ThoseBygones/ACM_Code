#include <bits/stdc++.h>
using namespace std;

deque <char> dq;

char str[2005];

int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",str+1);
    int cnt=0;
    for(int i=1; i<=n; i++)
    {
        if(n%2)
        {
            if(cnt%2)
                dq.push_front(str[i]);
            else
                dq.push_back(str[i]);
            cnt++;
        }
        else
        {
            if(cnt%2)
                dq.push_back(str[i]);
            else
                dq.push_front(str[i]);
            cnt++;
        }

    }
    while(!dq.empty())
    {
        printf("%c",dq.front());
        dq.pop_front();
    }
    return 0;
}
