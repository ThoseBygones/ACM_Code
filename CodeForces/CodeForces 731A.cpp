#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

char a[105];

int main()
{
    a[0]='a';
    cin >> a+1;
    int sum=0;
    int len=strlen(a);
    for(int i=1; i<len; i++)
    {
        if(a[i]>a[i-1])
            sum+=min(a[i]-a[i-1],a[i-1]-a[i]-'a'+'z'+1);
        else
            sum+=min(a[i-1]-a[i],a[i]-a[i-1]-'a'+'z'+1);
    }
    cout << sum << endl;
    return 0;
}
