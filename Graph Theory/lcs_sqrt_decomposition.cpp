#include <bits/stdc++.h>
using namespace std;

const int MX=1003;

int K;
int par[MX],dis[MX];
int block[MX],head[MX];
vector <int> adj[MX];

void init(int n)
{
    for(int i=0;i<=n;i++){
        adj[i].clear();
    }
}

int dfs(int u,int p)
{
    int h=1;
    int l=adj[u].size();
    for(int i=0;i<l;i++){
        int v=adj[u][i];
        if(v!=p) h=max(h,1+dfs(v,u));
    }
    return h;
}

void f(int u,int p,int k,int b,int h)
{
    dis[u]=K*(b-1)+k;
    block[u]=b,par[u]=p,head[u]=h;
    int l=adj[u].size();
    for(int i=0;i<l;i++){
        int v=adj[u][i];
        if(v==p) continue;
        if(k==K) f(v,u,1,b+1,v);
        else f(v,u,k+1,b,h);
    }
}

void process()
{
    int h=dfs(1,1);
    K=sqrt(h);
    f(1,1,1,1,1);
}

int lca(int u,int v)
{
    if(dis[u]>dis[v]) swap(u,v);
    while(block[u]!=block[v]) v=par[head[v]];
    while(head[u]!=head[v]){
        u=par[head[u]];
        v=par[head[v]];
    }
    while(dis[u]<dis[v]) v=par[v];
    while(u!=v) u=par[u],v=par[v];
    return v;
}

int main()
{
    // ...
    return 0;
}