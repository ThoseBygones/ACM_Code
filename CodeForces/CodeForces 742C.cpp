///����һ������ͼ��ÿ�������Ϊ1�������߳���Ϊ1����һ����С��k��ʹ�ö���ÿ����x������k���ȵ���y����y��������k�ص�x��
///�����γɻ�ֱ��pass�����γɵĻ������֣��滷��ż��
///�滷�еĵ�Ҫ������ĿҪ��ÿ����x����k���ȵ���y�Ҵ�y��������k�ص�x��ֻ�д�����������ص����Լ��������㣬����滷���ȼ�Ϊk��
///ż���еĵ�Ҫ������ĿҪ��ÿ����x����k���ȵ���y�Ҵ�y��������k�ص�x���������˵ֻ�轫����x�㴦�жϣ��γɴ���xΪ��㡢xΪ�յ���߶Σ������߶ε��е㼴Ϊ����������y�㡣���ż�����ȵ�һ�뼴Ϊk
///�����һ����Щkֵ����С����������ΪҪ����������k����Сt�����t��Ȼ����ÿ��k����������
#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define MAXN 105

int a[MAXN];
int vis[MAXN];
vector <int> cir;

int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    int cnt;
    for(int i=1; i<=n; i++)
    {
        if(vis[i])
            continue;
        cnt=1;  //���ڵ������
        int s=i;    //��¼�������
        int t=a[i]; //��һ����
        vis[s]=1;
        while(!vis[t])
        {
            vis[t]=1;
            t=a[t];
            cnt++;
        }
        //cout << s << "#" << t << endl;
        if(s!=t)    //����յ㲻ͬ�������ǻ�
        {
            puts("-1\n");
            return 0;
        }
        if(cnt>=2)  //ֵΪ1ʱ����ν
        {
            if(cnt%2==0)    //ż����2
                cnt/=2;
            cir.push_back(cnt);
        }
    }
    int len=cir.size();
    int ans;
    if(len==0)  //���޴��ڵ���2�Ļ�
        ans=1;
    else
        ans=cir[0];
    for(int i=1; i<len; i++)
    {
        int res=__gcd(ans,cir[i]);    //����С������
        ans=ans*cir[i]/res; //����󹫱���
    }
    printf("%d\n",ans);
    return 0;
}
