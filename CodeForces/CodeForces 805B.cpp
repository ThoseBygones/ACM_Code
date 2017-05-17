#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        if(i%4>=2)
            printf("%c",'b');
        else
            printf("%c",'a');
    }
    puts("");
    return 0;
}
