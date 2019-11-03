#include <bits/stdc++.h>
using namespace std;

const int MX=100005;

struct edge{
    int u,v,w;
    bool operator < (const edge &e) const
    {
        return w<e.w;
    }
};

edge e[MX];
int par[MX],sz[MX];
vector <int> mst[MX];

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

int kruskal(int n,int m)
{
    int w=0;
    sort(e,e+m);
    for(int u=1;u<=n;u++) make_set(u);
    int i=0,j=1;
    while(i<m && j<n){
        int u=e[i].u,v=e[i].v;
        if(find_set(u)!=find_set(v)){
            union_set(u,v),w+=e[i].w;
            mst[u].push_back(v),j++;
        }
        i++;
    }
    if(j<n) return -1;
    return w;
}

int main()
{
    // ...
    return 0;
}