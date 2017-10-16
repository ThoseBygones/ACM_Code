#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
char str[30010][20];
class trie{
public :
    int num,id;
    vector<string> ss;
    trie* child[27];
    trie(){
        ss.clear();
        num=0;
        memset(child,0,sizeof(child));
    }
}root;
void insert(int len,char *s,string info,int id){
    class trie *cur=&root;
    for(int i=0;i<len;i++){
        int id=s[i]-'a';
        if(!cur->child[id])
            cur->child[id]=new trie;
        cur=cur->child[id];
    }
    cur->num++;
    cur->ss.push_back(info);
}
int find(char *s){
    class trie *cur=&root;
    int len=strlen(s);
    for(int i=0;i<len;i++){
        int id=s[i]-'a';
        if(!cur->child[id]) return 0;
        cur=cur->child[id];
    }
    return cur->num;
}
struct node{
    int id;
    char s[20];
}tmp[30010];
int cmp(node s1,node s2){
    return strcmp(s1.s,s2.s)<0;
}
int n,num[30010];
void print(vector<string> V)
{
    vector<string> ::iterator it;
    sort(V.begin(),V.end());
    int tot=unique(V.begin(),V.end())-V.begin();
    for(it=V.begin();it!=V.begin()+tot;it++)    cout<<*it<<" ";
}
void make(char *s){
    class trie *cur=&root;
    int len=strlen(s);
    for(int i=0;i<len;i++){
        int id=s[i]-'a';
        if(!cur->child[id]) return ;
        cur=cur->child[id];
    }
    print(cur->ss);
}
vector<int> pos[30010];
void solve(){
    map<string,int> mm;
    int i,j;
    int mx=0,id=-1;
    sort(tmp,tmp+n,cmp);
    memset(num,0,sizeof(num));
    for(i=0;i<=n;i++)pos[i].clear();
    for(i=0;i<n;i++){
        if(mm.find((string)str[tmp[i].id])!=mm.end()) continue;
        int t=find(str[tmp[i].id]);mm[(string)str[tmp[i].id]]=1;
        num[t]++;pos[t].push_back(i);
    }
    int cnt=0;
    for(i=n;i>=1;i--){
        if(num[i]){
            for(j=0;j<pos[i].size();j++){
                cnt++;
                printf("Group of size %d: ",i);
                make(str[tmp[pos[i][j]].id]);
                puts(".");
                if(cnt==5) return ;
            }
        }
    }
}
int main(){
    n=0;
    while(gets(str[n])){
        tmp[n].id=n;
        int len=strlen(str[n]);
        strcpy(tmp[n].s,str[n]);
        sort(str[n],str[n]+len);
        insert(len,str[n],(string)tmp[n].s,n);
        n++;
    }
    solve();
    return 0;
}
