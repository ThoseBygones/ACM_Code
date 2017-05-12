#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

#define MAXN 55
//ÃüÃûË³Ðò{ÉÏ,ÏÂ,×ó,ÓÒ}
char land[11][5]={"1010","1001","0110","0101","1100","0011","1011","1110","0111","1101","1111"};
char map[MAXN][MAXN];
int par[MAXN][MAXN];
int m,n;

int find_set(int r)
{
    if(r!=par[r/n][r%n])
        par[r/n][r%n]=find_set(par[r/n][r%n]);
    return par[r/n][r%n];
}

void merge_set(int x,int y)
{
    int setx=find_set(x);
    int sety=find_set(y);
    if(setx!=sety)
        par[sety/n][sety%n]=setx;
}

void judge(int i,int j)
{
    if(i>0 && land[map[i][j]-'A'][0]=='1' && land[map[i-1][j]-'A'][1]=='1')
        merge_set((i-1)*n+j,i*n+j);
    if(j>0 && land[map[i][j]-'A'][2]=='1' && land[map[i][j-1]-'A'][3]=='1')
        merge_set(i*n+j-1,i*n+j);
}

int main()
{
    while(scanf("%d %d",&m,&n))
    {
        if(m==-1 && n==-1)
            break;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                par[i][j]=i*n+j;
        for(int i=0;i<m;i++)
            scanf("%s",map[i]);
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                judge(i,j);
        int sum=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(par[i][j]==i*n+j)
                    sum++;
            }
        }
        cout << sum << endl;
    }
    return 0;
}
