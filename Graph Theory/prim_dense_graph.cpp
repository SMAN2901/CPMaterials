#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

const int MX=1002;

bool vis[MX];
pii mine[MX];
vector <pii> adj[MX];
vector <pii> mst[MX];

void init(int n)
{
    for(int i=0;i<=n;i++){
        vis[i]=false;
        adj[i].clear();
        mst[i].clear();
        mine[i]={INT_MAX,-1};
    }
}

void compute_min(int n,int s)
{
    int l=adj[s].size();
    for(int i=0;i<l;i++){
        int v=adj[s][i].second;
        int w=adj[s][i].first;
        mine[v]={w,s};
    }
}

int prim(int n,int s)
{
    int mstw=0;
    vis[s]=true;
    compute_min(n,s);
    for(int i=1;i<n;i++){
        int v=-1;
        for(int u=1;u<=n;u++){
            if(vis[u]) continue;
            if(v==-1 || mine[u]<mine[v]) v=u;
        }
        if(v==-1 || mine[v].second==-1) return -1;
        vis[v]=true;
        mstw+=mine[v].first;
        mst[v].push_back(mine[v]);
        int l=adj[v].size();
        for(int j=0;j<l;j++){
            int u=adj[v][j].second;
            pii p={adj[v][j].first,v};
            mine[u]=min(mine[u],p);
        }
    }
    return mstw;
}

int main()
{
    // ...
    return 0;
}