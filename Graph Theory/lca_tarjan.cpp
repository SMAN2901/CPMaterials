#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

const int MX=1003;

bool vis[MX];
int par[MX],sz[MX];
int anc[MX],ans[MX];
vector <int> adj[MX];
vector <pii> qry[MX];

void init(int n)
{
    for(int i=0;i<=n;i++){
        vis[i]=false;
        adj[i].clear();
        qry[i].clear();
    }
}

void make_set(int v)
{
    par[v]=v;
    sz[v]=1;
}

int find_set(int v)
{
    if(v==par[v]) return v;
    return par[v]=find_set(par[v]);
}

void union_set(int u,int v)
{
    int a=find_set(u);
    int b=find_set(v);
    if(a==b) return;
    if(sz[a]<sz[b]) swap(a,b);
    par[b]=a,sz[a]+=sz[b];
}

void answer(int u)
{
    int k=qry[u].size();
    for(int i=0;i<k;i++){
        int v=qry[u][i].first;
        int j=qry[u][i].second;
        if(vis[v]) ans[j]=anc[find_set(v)];
    }
}

void f(int u)
{
    vis[u]=true;
    make_set(u),anc[u]=u;
    int l=adj[u].size();
    for(int i=0;i<l;i++){
        int v=adj[u][i];
        if(vis[v]) continue;
        f(v);
        union_set(u,v);
        anc[find_set(u)]=u;
    }
    answer(u);
}

int main()
{
    // ...
    return 0;
}