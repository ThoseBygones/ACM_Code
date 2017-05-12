#include <iostream>
//#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAXN 1005
#define INF 0x3f3f3f3f
using namespace std;

int num[MAXN][MAXN][2]; //�ֱ��¼2��5������
int dp[MAXN][MAXN][2];  //dp���2��5����С������Ȼ�����������ߵ���Сֵ
int zeroX,zeroY;    //��¼ֵΪ0�������
int n;
bool flag;  //�Ƿ����ֵΪ0�ĵ�

void direction(int x,int y,int k,int dir)   //dirΪ0��������ң�Ϊ1ʱ������£�Ϊ-1�Ǳ��������յ㲻�������
{
    if(x==1 && y==1)    //���ʱ���ٽ��л���
        ;
    else if(x==1)
        direction(x,y-1,k,0);   //���Ϸ�һ��ʱ�����������ϻ���
    else if(y==1)
        direction(x-1,y,k,1);   //�����һ��ʱ���������������
    else    //����Ѱ��·��
    {
        if(dp[x][y][k]==dp[x-1][y][k]+num[x][y][k])
            direction(x-1,y,k,1);
        else
            direction(x,y-1,k,0);
    }
    if(dir==-1)
        return ;    //�����յ㣬�������
    if(dir==1)
        cout << 'D';
    else if(dir==0)
        cout << 'R';
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    int temp;
    flag=false;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin >> temp;
            //scanf("%d",&temp);
            if(!temp)   //��������ֵΪ0����ֻҪ��������·�����ĳ˻�Ϊ0
            {
                num[i][j][0]=num[i][j][1]=1;    //��0����10���ֽ��1��2��1��5
                zeroX=i;
                zeroY=j;
                flag=true;
            }
            else
            {
                while(temp%2==0)
                {
                    num[i][j][0]++;
                    temp/=2;
                }
                while(temp%5==0)
                {
                    num[i][j][1]++;
                    temp/=5;
                }
            }
        }
    }
    memset(dp,INF,sizeof(dp));
    for(int k=0; k<2; k++)  //�ֱ�dp���2��5����Сֵ
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(i!=1)
                    dp[i][j][k]=min(dp[i][j][k],dp[i-1][j][k]); //���i�������Ϸ�һ�У����ж�ĳ��������Ϸ���һ�����ĸ����е�2��5��������С
                if(j!=1)
                    dp[i][j][k]=min(dp[i][j][k],dp[i][j-1][k]); //���j���������һ�У����ж�ĳ������������һ�����ĸ����е�2��5��������С
                if(i==1 && j==1)
                    dp[i][j][k]=0;   //�������������Ϸ�����ʼ�㣬�������е�2��5����СֵΪ0
                dp[i][j][k]+=num[i][j][k];  //�ǵü�������㺬�е�2��5������
            }
        }
    }
    int ans=min(dp[n][n][0],dp[n][n][1]);  //���պ���0������ȡ���ں���2�ͺ���5����������Сֵ
    if(ans>1 && flag)   //������ĵ�����0������£�������dp������0����������1����ô����0����·����Ȼ��ʹ���0���ٵ�·��
    {
        cout << "1" << endl;
        for(int i=1; i<zeroX; i++)
            cout << "D";
        for(int j=1; j<zeroY; j++)
            cout << "R";
        for(int i=zeroX; i<n; i++)
            cout << "D";
        for(int j=zeroY; j<n; j++)
            cout << "R";
        cout << endl;
    }
    else
    {
        cout << ans << endl;
        if(dp[n][n][0]<dp[n][n][1])
            direction(n,n,0,-1);    //���2��������5С�������2������С��·����
        else
            direction(n,n,1,-1);    //���5��������2С�������5������С��·����
        cout << endl;
    }
    return 0;
}
