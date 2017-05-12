#include<iostream>
#include<cstdio>
using namespace std;

int a[1000005];

int main()
{
    int n,cnt,temp;
    while(scanf("%d",&n)!=EOF)
    {
        cnt=0;
        for(int i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
            if(cnt==0)
            {
                temp=a[i];
                cnt++;
            }
            else if(a[i]==temp)
                cnt++;
            else
                cnt--;
        }
        cout << temp << endl;
    }
}
