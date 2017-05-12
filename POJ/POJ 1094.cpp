#include <cstdio>
#include <cstring>
#define MAXN 30
using namespace std;

int indegree[MAXN],mat[MAXN][MAXN],q[MAXN];

int TopoSort(int n)
{
    int cnt=0;  //记录入队点数
    int temp[MAXN]; //临时数组，用来复制indegree数组，方便进行修改
    int p;  //入度为零的点的指针
    int num;    //查找入度为零点的个数
    int flag=1; //判断是否有序
    for(int i=1; i<=n; i++)
        temp[i]=indegree[i];
    for(int i=1; i<=n; i++)
    {
        num=0;
        for(int j=1; j<=n; j++)
        {
            if(temp[j]==0)
            {
                num++;
                p=j;
            }
        }
        if(num==0)
            return 0;
        if(num>1)
            flag=-1;
        q[cnt++]=p;
        temp[p]=-1;
        for(int j=1; j<=n; j++)
        {
            if(mat[p][j]==1)
                temp[j]--;
        }
    }
    return flag;
}

int main()
{
    int n,m;
    bool sure;  //是否能判断能否排序？
    char str[5];
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0 && m==0)
            break;
        memset(mat,0,sizeof(mat));
        memset(indegree,0,sizeof(indegree));
        memset(q,0,sizeof(q));
        sure=false;
        int flag;
        int temp;
        for(int i=1; i<=m; i++)
        {
            scanf("%s",str);
            if(sure)
                continue;
            int x=str[0]-'A'+1;
            int y=str[2]-'A'+1;
            mat[x][y]=1;
            indegree[y]++;
            flag=TopoSort(n);
            if(flag==0) //有环
            {
                printf("Inconsistency found after %d relations.\n",i);
                sure=true;
            }
            if(flag==1)
            {
                temp=i;
                sure=true;
            }
        }
        if(flag==1)
        {
            printf("Sorted sequence determined after %d relations: ",temp);
            for(int j=0; j<n; j++)
                printf("%c",q[j]+'A'-1);
            printf(".\n");
            sure=true;
        }
        if(!sure)
            printf("Sorted sequence cannot be determined.\n");
    }
    return 0;
}
