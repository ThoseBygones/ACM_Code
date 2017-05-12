#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

char fst[30],mst[30],bst[30];

void buildTree(int len,char *fst,char *mst,char *bst)
{
    if(len<=0)
        return;
    int node=strchr(mst,fst[0])-mst;
    buildTree(node,fst+1,mst,bst);
    buildTree(len-node-1,fst+node+1,mst+node+1,bst+node);
    bst[len-1]=fst[0];
}

int main()
{
    while(scanf("%s %s",fst,mst)!=EOF)
    {
        int len=strlen(fst);
        buildTree(len,fst,mst,bst);
        bst[len]='\0';
        printf("%s\n",bst);
        memset(fst,0,sizeof(fst));
        memset(mst,0,sizeof(mst));
    }
    return 0;
}
