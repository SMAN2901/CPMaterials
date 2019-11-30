#include <bits/stdc++.h>
using namespace std;

typedef pair <int,int> pii;

const int MX=1003;

pii sp[MX<<1][12];
int dis[MX],pos[MX],euler[MX<<1];
vector <int> adj[MX];

void init(int n)
{
    for(int u=1;u<=n;u++){
        adj[u].clear();
    }
}

int f(int u,int p,int k)
{
    pos[u]=k;
    euler[k++]=u;
    dis[u]=(p!=-1)?dis[p]+1:0;
    int l=adj[u].size();
    for(int i=0;i<l;i++){
        int v=adj[u][i];
        if(v==p) continue;
        k=f(v,u,k);
        euler[k++]=u;
    }
    return k;
}

void build(int n)
{
    for(int i=0;i<n;i++){
        int u=euler[i];
        sp[i][0]={dis[u],u};
    }
    for(int j=1;(1<<j)<=n;j++){
        for(int i=0;i<n;i++){
            if(i+(1<<j)>n) continue;
            sp[i][j]=min(sp[i][j-1],sp[i+(1<<(j-1))][j-1]);
        }
    }
}

pii query(int i,int j)
{
    int k=__lg(j-i+1);
    return min(sp[i][k],sp[j-(1<<k)+1][k]);
}

int lca(int u,int v)
{
    int x=pos[u],y=pos[v];
    if(x>y) swap(x,y);
    return query(x,y).second;
}

int main()
{
    // ...
    return 0;
}