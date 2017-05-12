#include <iostream>
#include <cstring>
#include <algorithm>
#define N 15
using namespace std;

struct Lake
{
    int id; //顶点（湖）的编号
    int degree; //顶点（湖）的度
    bool operator <(const Lake &a) const    //重载>运算符，排序的时候使用
    {
        return degree>a.degree;
    }
} lake[N];

int edge[N][N]; //邻接矩阵
bool flag;  //是否存在题目中询问的相连关系的判断标志

int main()
{
    int t,n;
    cin >> t;
    while(t--)
    {
        memset(edge,0,sizeof(edge));
        cin >> n;
        for(int i=0; i<n; i++)
        {
            cin >> lake[i].degree;
            lake[i].id=i;
        }
        flag=true;
        while(true) //运用Havel-Hakimi定理求解
        {
            sort(lake,lake+n);  //对结构体按从大到小排序
            if(lake[0].degree==0)   //根据定理，如果连最大的顶点的度都为零是则跳出循环
                break;
            for(int i=0; i<lake[0].degree; i++)
            {
                lake[i+1].degree--;
                if(lake[i+1].degree<0)    //根据定理，如果某一顶点的度小于零则不存在题目中询问的相连关系
                {
                    flag=false;
                    break;
                }
                edge[lake[0].id][lake[i+1].id]=edge[lake[i+1].id][lake[0].id]=1;    //根据定理，满足条件的在邻接矩阵上标记1
            }
            lake[0].degree=0;   //下次排序之前把最大的顶点的度置0
        }
        if(flag)
        {
            cout << "YES" << endl;
            for(int i=0; i<n; i++)
            {
                cout << edge[i][0];
                for(int j=1; j<n; j++)
                    cout << " " << edge[i][j];
                cout << endl;
            }
        }
        else
            cout << "NO" << endl;
        if(t)
            cout << endl;   //注意，相邻两组测试数据之间输出一个空行！
    }
    return 0;
}
