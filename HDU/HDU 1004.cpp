#include<iostream>
#include<cstring>
using namespace std;

char color[1005][18];
int sum[1005],n;

int main()
{
    while(cin >> n)
    {
        if(n==0)
            break;
        sum[0]=0;
        cin >> color[0];
        for(int i=1;i<n;i++)
        {
            sum[i]=0;
            cin >> color[i];
            for(int j=0;j<i-1;j++)
            {
                if(strcmp(color[i],color[j])==0)
                    sum[i]+=1;
            }
        }
        int m=0,t=0;
        for(int i=0;i<n;i++)
        {
            if(m<sum[i])
            {
                m=sum[i];
                t=i;
            }
        }
        cout << color[t] << endl;
    }
    return 0;
}
