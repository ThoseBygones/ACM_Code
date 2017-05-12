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
};  //ö�����������п��ܵ�״̬

int cubes[4][6]; //ÿ���������ʼ��ɫ
int color[4][6];   //ÿ����������ת����������ɫ
int rot[4]; //ÿ�����������ת��ʽ
int n,maxcnt;
vector <string> colornames;

int mapId(string name)  //����ƥ����ɫ���ֺ���ɫ���
{
    int len=colornames.size();
    for(int i=0; i<len; i++)
    {
        if(colornames[i]==name) //������ɫ�����Ѵ�����ֱ�ӷ���idֵ
            return i;
    }
    colornames.push_back(name); //������ɫ���ݲ�������������vector�Ķ�β
    return len; //����idֵ
}

void check()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<6; j++)
        {
            color[i][status[rot[i]][j]]=cubes[i][j];    //��ʼ����ת����������������ɫ
        }
    }
    int cnt=0;  //��Ҫ����Ϳɫ������
    for(int i=0; i<6; i++)  //ö��ÿ����
    {
        int times[4*6]; //ÿ����ɫ���ֵĴ���
        memset(times,0,sizeof(times));
        int maxtimes=0;
        for(int j=0; j<n; j++)
            maxtimes=max(maxtimes,++times[color[j][i]]);    //��
        cnt+=n-maxtimes;    //�õ�Ҫ�޸ĵ�����
    }
    maxcnt=min(maxcnt,cnt);
}

void dfs(int depth)
{
    if(depth==n)    //���������������ʼ���л�ɫ����
        check();
    else
    {
        for(int i=0; i<24; i++) //������ö���������ÿһ�֣�24�֣�״̬
        {
            rot[depth]=i;   //��¼����ת��ʽ��
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
        maxcnt=n*6; //��������Ҫ����Ϳɫ������������Ϊn*6����ȫ��״̬���������ȫ���涼Ҫ����Ϳɫ��
        rot[0]=0;   //�Ե�һ���������״̬Ϊ��׼״̬����˵�һ�������岻��ת
        dfs(1);
        printf("%d\n",maxcnt);
    }
    return 0;
}
