#include <iostream>
#include <cstring>
#include <algorithm>
#define INF 0x3f3f3f3f
#define MAXN 20
using namespace std;

int a[MAXN][MAXN],flip[MAXN][MAXN],ans[MAXN][MAXN];
int m,n;
int dx[]={0,-1,0,1,0};
int dy[]={0,0,-1,0,1};

int dfs(int x,int y)
{
    int status=a[x][y]; //��ʼ��Ҫ��ת�Ĵ���
    for(int i=0; i<5; i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0 && nx<m && ny>=0 && ny<n)
            status+=flip[nx][ny];
    }
    return status&1;    //����Ҫ��ת�Ĵ�������(��ʼ+��������������Ҫ��ת�Ĵ���)%2
}

int cal()
{
    for(int i=1; i<m; i++)
    {
        for(int j=0; j<n; j++)  //��i-1,j)Ϊ��ɫ����ת��i,j)
        {
            if(dfs(i-1,j))
                flip[i][j]=1;
        }
    }
    for(int j=0; j<n; j++)  //���һ�л��к�ɫ�ģ����޽�
    {
        if(dfs(m-1,j))
            return INF;
    }
    int res=0;  //��ת����
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
            res+=flip[i][j];
    }
    return res;
}

int main()
{
    while(cin >> m >> n)
    {
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
                cin >> a[i][j];
        }
        int cnt=INF;
        for(int i=0; i<(1 << n); i++)   //ö�ٵ�һ�еķ�ת���
        {
            memset(flip,0,sizeof(flip));
            for(int j=0; j<n; j++)
                flip[0][j]=(i >> j)&1;
            int temp=cal();
            if(temp<cnt)
            {
                cnt=temp;
                for(int j=0; j<m; j++)
                {
                    for(int k=0; k<n; k++)
                        ans[j][k]=flip[j][k];
                }
            }
        }
        if(cnt==INF)
            cout << "IMPOSSIBLE" << endl;
        else
        {
            for(int i=0; i<m; i++)
            {
                for(int j=0; j<n; j++)
                {
                    cout << ans[i][j];
                    if(j!=n-1)
                        cout << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}
