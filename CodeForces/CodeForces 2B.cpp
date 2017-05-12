#include <iostream>
//#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAXN 1005
#define INF 0x3f3f3f3f
using namespace std;

int num[MAXN][MAXN][2]; //分别记录2和5的数量
int dp[MAXN][MAXN][2];  //dp求出2和5的最小个数，然后从中求出两者的最小值
int zeroX,zeroY;    //记录值为0点的坐标
int n;
bool flag;  //是否存在值为0的点

void direction(int x,int y,int k,int dir)   //dir为0是输出向右，为1时输出向下，为-1是表明到达终点不进行输出
{
    if(x==1 && y==1)    //起点时不再进行回溯
        ;
    else if(x==1)
        direction(x,y-1,k,0);   //最上方一行时不可能再向上回溯
    else if(y==1)
        direction(x-1,y,k,1);   //最左边一行时不可能再向左回溯
    else    //回溯寻找路径
    {
        if(dp[x][y][k]==dp[x-1][y][k]+num[x][y][k])
            direction(x-1,y,k,1);
        else
            direction(x,y-1,k,0);
    }
    if(dir==-1)
        return ;    //到达终点，结束输出
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
            if(!temp)   //如果输入的值为0，则只要经过这条路，最后的乘积为0
            {
                num[i][j][0]=num[i][j][1]=1;    //把0看做10，分解成1个2和1个5
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
    for(int k=0; k<2; k++)  //分别dp求出2和5的最小值
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(i!=1)
                    dp[i][j][k]=min(dp[i][j][k],dp[i-1][j][k]); //如果i不是最上方一行，则判断某个点和它上方那一个点哪个含有的2和5的数量最小
                if(j!=1)
                    dp[i][j][k]=min(dp[i][j][k],dp[i][j-1][k]); //如果j不是最左边一列，则判断某个点和它左边那一个点哪个含有的2和5的数量最小
                if(i==1 && j==1)
                    dp[i][j][k]=0;   //如果这个点是左上方的起始点，则它含有的2和5的最小值为0
                dp[i][j][k]+=num[i][j][k];  //记得加上这个点含有的2和5的数量
            }
        }
    }
    int ans=min(dp[n][n][0],dp[n][n][1]);  //最终含有0的数量取决于含有2和含有5的数量的最小值
    if(ans>1 && flag)   //在输入的点中有0的情况下，如果最后dp出含有0的数量大于1，那么经过0这点的路径显然是使最后0最少的路径
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
            direction(n,n,0,-1);    //如果2的数量比5小，则输出2数量最小的路径中
        else
            direction(n,n,1,-1);    //如果5的数量比2小，则输出5数量最小的路径中
        cout << endl;
    }
    return 0;
}
