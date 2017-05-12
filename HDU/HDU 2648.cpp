//STL map
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
//#include <unordered_map>  //C++11���ϲſ���
using namespace std;

map <string,int> shop;
//unordered_map <string,int> shop;  ////C++11���ϲſ��ã��÷���map��ͬ
int price[10005];

int main()
{
    int n,m;
    while(~scanf("%d",&n))
    {
        int pos;
        memset(price,0,sizeof(price));
        string str;
        for(int i=0; i<n; i++)
        {
            cin >> str;
            if(str == "memory")
                pos=i;
            shop[str]=i;
        }
        scanf("%d",&m);
        while(m--)
        {
            for(int i=1; i<=n; i++)
            {
                int val;
                scanf("%d",&val);
                cin >> str;
                price[shop[str]]+=val;
            }
            int rk=1;   //����
            for(int i=0; i<n; i++)
            {
                if(price[pos]<price[i])
                    rk++;
            }
            printf("%d\n",rk);
        }
    }
    return 0;
}


//Hash
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

#define MAXN 10005

struct Shop
{
    char name[35];
    int price;
    Shop()
    {
        price=0;
    }
};

vector <Shop> hashlist[MAXN];
vector <int> ans;  //�۸�䶯����̵�ļ۸�

unsigned int BKDRHash(char *str)
{
    unsigned int seed=31;
    unsigned int key=0;
    while(*str)
        key=key*seed+ *str++;
    return key&(0x7fffffff);
}

int main()
{
    int n,m;
    int key,val;
    char str[35];
    int cnt;  //��memory�̵�۸�ߵ��̵������
    Shop temp;
    while(~scanf("%d",&n))
    {
        for(int i=0; i<MAXN; i++)
            hashlist[i].clear();
        for(int i=0; i<n; i++)  //�����ϣ��
        {
            scanf("%s",str);
            strcpy(temp.name,str);
            key=BKDRHash(str)%MAXN;
            hashlist[key].push_back(temp);
        }
        scanf("%d",&m);
        while(m--)  //��ϣ���ѯ
        {
            cnt=0;
            int rec;    //��ʱ��¼��ֵ
            int mprice=0;   //memory�̵�ļ۸�
            ans.clear();
            for(int i=0; i<n; i++)
            {
                scanf("%d%s",&val,str);
                key=BKDRHash(str)%MAXN;
                int sz=hashlist[key].size();
                for(int j=0; j<sz; j++)
                {
                    if(!strcmp(hashlist[key][j].name,str))
                    {
                        hashlist[key][j].price+=val;
                        rec=hashlist[key][j].price;
                        break;
                    }
                }
                if(strcmp(str,"memory"))
                    ans.push_back(rec);
                else
                    mprice=rec;
            }
            for(int i=0; i<ans.size(); i++)
            {
                if(mprice<ans[i])
                    cnt++;
            }
            printf("%d\n",cnt+1);
        }
    }
    return 0;
}
