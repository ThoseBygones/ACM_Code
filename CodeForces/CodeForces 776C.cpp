#include <bits/stdc++.h>
//#include <unordered_map>
#define LL long long
using namespace std;

#define INF 0x3f3f3f3f
#define MAXN 100005

int a[MAXN];
map <LL,LL> Hash; //ǰ׺��Ϊi������ֵ��k���ݵĸ���
//unordered_map <LL,LL> Hash;   //�ᳬʱ

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    LL ans=0;
    LL sum=0;
    Hash[0]=1;
    for(int i=1; i<=n; i++)
    {
        sum+=a[i];  //ǰ׺�ʹ���
        if(k==-1)   //k=-1ʱ���⴦����Ϊ1��-1��Ϊ-1��m����
            ans+=Hash[sum-1]+Hash[sum+1];
        else
        {
            for(LL j=1; j<=1e18; j*=k)
            {
                ans+=Hash[sum-j];
                if(k==1)    //1��m����ҲΪ1����˲��ؼ���ѭ��
                    break;
            }
        }
        Hash[sum]++;
    }
    printf("%I64d\n",ans);
    return 0;
}
