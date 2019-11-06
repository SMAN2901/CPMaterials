#include <bits/stdc++.h>
using namespace std;

const int MX=1003;

int K,T;
int tin[MX],tex[MX],p[MX][12];
vector <int> adj[MX];

void init(int n)
{
    T=1,K=__lg(n)+1;
    for(int i=0;i<=n;i++){
        adj[i].clear();
    }
}

void f(int u,int par)
{
    tin[u]=T++;
    p[u][0]=par;
    for(int i=1;i<=K;i++){
        p[u][i]=p[p[u][i-1]][i-1];
    }
    int l=adj[u].size();
    for(int i=0;i<l;i++){
        int v=adj[u][i];
        if(v!=par) f(v,u);
    }
    tex[u]=T++;
}

bool ancestor(int u,int v)
{
    return (tin[u]<=tin[v] && tex[u]>=tex[v]);
}

int lca(int u,int v)
{
    if(ancestor(u,v)) return u;
    if(ancestor(v,u)) return v;
    int k=K+1;
    while(k--) u=ancestor(p[u][k],v)?u:p[u][k];
    return p[u][0];
}

int main()
{
    // ...
    return 0;
}