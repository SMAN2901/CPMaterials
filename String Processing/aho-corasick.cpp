#include <bits/stdc++.h>
using namespace std;

string s,t;
int n,l,a[1003];

struct node{
    bool f=false;
    char c;
    int p=-1,link=-1,ex=-1;
    int to[52],go[52];
    vector <int> id;
    node(){
        memset(to,-1,sizeof(to));
        memset(go,-1,sizeof(go));
    }
};

int size=1;
vector <node> trie(1);

void insert(string &s,int len,int j)
{
    int u,v=0;
    for(int i=0;i<len;i++){
        int c=(s[i]<97)?s[i]-65:s[i]-97;
        if(trie[v].to[c]==-1){
            trie.emplace_back();
            trie[v].to[c]=size++;
        }
        u=v;
        v=trie[v].to[c];
        trie[v].p=u,trie[v].c=s[i];
    }
    trie[v].f=true;
    trie[v].id.push_back(j);
}

int go(int v,char c);

int get_link(int v)
{
    if(trie[v].link==-1){
        if(v==0 || trie[v].p==0) trie[v].link=0;
        else trie[v].link=go(get_link(trie[v].p),trie[v].c);
    }
    return trie[v].link;
}

int get_exit_link(int v)
{
    if(trie[v].ex==-1){
        if(v==0) trie[v].ex=0;
        else{
            int u=get_link(v);
            trie[v].ex=trie[u].f?u:get_exit_link(u);
        }
    }
    return trie[v].ex;
}

int go(int v,char c)
{
    int x=c-97;
    if(trie[v].go[x]==-1){
        if(trie[v].to[x]!=-1) trie[v].go[x]=trie[v].to[x];
        else trie[v].go[x]=v?go(get_link(v),c):0;
    }
    return trie[v].go[x];
}

void mark(int v)
{
    int sz=trie[v].id.size();
    for(int j=0;j<sz;j++){
        int p=trie[v].id[j];
        a[p]++;
    }
}

void fun(string &s,int len,int i,int v)
{
    if(trie[v].f) mark(v);
    int u=get_exit_link(v);
    while(u>0){
        if(trie[u].f) mark(u);
        u=get_exit_link(u);
    }
    if(i<len) fun(s,len,i+1,go(v,s[i]));
}

int main()
{
    // ...
    return 0;
}