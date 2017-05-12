#include <bits/stdc++.h>
using namespace std;

map <string,int> a,b;

int main()
{
    int n,m;
    string str;
    scanf("%d%d",&n,&m);
    int cnta=0; //Polandball能说的与EnemyBall不同的单词数量
    int cntb=0; //EnemyBall能说的与Polandball不同的单词数量
    int cnts=0; //两人能说的相同的单词数量
    for(int i=1; i<=n; i++)
    {
        cin >> str;
        if(!a[str])
        {
            a[str]=1;
            cnta++;
        }
    }
    for(int i=1; i<=m; i++)
    {
        cin >> str;
        if(!b[str])
        {
            b[str]=1;
            cntb++;
            if(a[str])
                cnts++;
        }
    }
    if(cnts%2)
    {
        cnta+=cnts/2+1;
        cntb+=cnts/2;
    }
    if(cnta>cntb)
        puts("YES");
    else
        puts("NO");
    return 0;
}
