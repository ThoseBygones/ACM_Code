#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//map <string,int> id;

int status[24][6]={
{0,1,2,3,4,5},{0,2,4,1,3,5},{0,4,3,2,1,5},{0,3,1,4,2,5},
{1,5,2,3,0,4},{1,2,0,5,3,4},{1,0,3,2,5,4},{1,3,5,0,2,4},
{2,1,5,0,4,3},{2,5,4,1,0,3},{2,4,0,5,1,3},{2,0,1,4,5,3},
{3,0,4,1,5,2},{3,4,5,0,1,2},{3,5,1,4,0,2},{3,1,0,5,4,2},
{4,0,2,3,5,1},{4,2,5,0,3,1},{4,5,3,2,0,1},{4,3,0,5,2,1},
{5,1,3,2,4,0},{5,3,4,1,2,0},{5,4,2,3,1,0},{5,2,1,4,3,0}
};  //枚举立方体所有可能的状态

int cubes[4][6]; //每个立方体初始颜色
int color[4][6];   //每个立方体旋转后各个面的颜色
int rot[4]; //每个立方体的旋转方式
int n,maxcnt;
vector <string> colornames;

int mapId(string name)  //用于匹配颜色名字和颜色编号
{
    int len=colornames.size();
    for(int i=0; i<len; i++)
    {
        if(colornames[i]==name) //若该颜色数据已存在则直接返回id值
            return i;
    }
    colornames.push_back(name); //若该颜色数据不存在则将其加入该vector的队尾
    return len; //返回id值
}

void check()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<6; j++)
        {
            color[i][status[rot[i]][j]]=cubes[i][j];    //初始化旋转后立方体各个面的颜色
        }
    }
    int cnt=0;  //需要重新涂色的面数
    for(int i=0; i<6; i++)  //枚举每个面
    {
        int times[4*6]; //每种颜色出现的次数
        memset(times,0,sizeof(times));
        int maxtimes=0;
        for(int j=0; j<n; j++)
            maxtimes=max(maxtimes,++times[color[j][i]]);    //？
        cnt+=n-maxtimes;    //得到要修改的面数
    }
    maxcnt=min(maxcnt,cnt);
}

void dfs(int depth)
{
    if(depth==n)    //若搜索已至最深处则开始进行换色处理
        check();
    else
    {
        for(int i=0; i<24; i++) //否则在枚举立方体的每一种（24种）状态
        {
            rot[depth]=i;   //记录在旋转方式中
            dfs(depth+1);
        }
    }
}

int main()
{
    while(~scanf("%d",&n),n)
    {
        colornames.clear();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<6; j++)
            {
                string temp;
                cin >> temp;
                cubes[i][j]=mapId(temp);
            }
        }
        maxcnt=n*6; //理论上需要重新涂色的正方体面数为n*6（即全部状态的立方体的全部面都要重新涂色）
        rot[0]=0;   //以第一个立方体的状态为标准状态，因此第一个立方体不旋转
        dfs(1);
        printf("%d\n",maxcnt);
    }
    return 0;
}
