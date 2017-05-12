#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

char a[1005],b[1005];
int maxlen,sum[1005];

int main()
{
    int t,i,j,k;
    cin >> t;
    for(int n=1; n<=t; n++)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        cin >> a >> b;
        maxlen=max(strlen(a),strlen(b));
        if(strlen(a)>=strlen(b))
        {
            for(j=strlen(a)-1,k=strlen(b)-1; k>=0; j--,k--)
            {
                sum[j]=(a[j]-'0')+(b[k]-'0');
            }
            for(int l=j; l>=0; l--)
                sum[l]=a[l]-'0';
        }
        else if(strlen(a)<strlen(b))
        {
            for(j=strlen(a)-1,k=strlen(b)-1; j>=0; j--,k--)
            {
                sum[k]=(a[j]-'0')+(b[k]-'0');
            }
            for(int l=k; l>=0; l--)
                sum[l]=b[l]-'0';
        }
        for(i=maxlen-1; i>=1; i--)
        {
            if(sum[i]>9)
            {
                sum[i]=sum[i]%10;
                sum[i-1]+=1;
            }
        }
        printf("Case %d:\n",n);
        cout << a << " + " << b << " = ";
        for(i=0; i<maxlen; i++)
            cout << sum[i];
        cout << endl;
        if(n!=t)
            cout << endl;
    }
    return 0;
}
