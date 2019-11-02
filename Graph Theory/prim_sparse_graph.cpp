#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

const int MX=1002;

bool vis[MX];
pii mine[MX];
set <pii> q;
vector <pii> adj[MX];
vector <pii> mst[MX];

void init(int n)
{
    for(int i=0;i<=n;i++){
        vis[i]=false;
        q.clear();
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
        q.insert({w,v}),mine[v]={w,s};
    }
}

int prim(int n,int s)
{
    int mstw=0;
    vis[s]=true;
    compute_min(n,s);
    for(int i=1;i<n;i++){
        if(q.empty()) return -1;
        pii p=*(q.begin());
        q.erase(q.begin());
        int v=p.second,w=p.first;
        vis[v]=true,mstw+=w;
        mst[v].push_back(mine[v]);
        int l=adj[v].size();
        for(int j=0;j<l;j++){
            int u=adj[v][j].second;
            if(vis[u]) continue;
            pii p={adj[v][j].first,v};
            pii pp={adj[v][j].first,u};
            if(p<mine[u]){
                q.erase({mine[u].first,u});
                mine[u]=p,q.insert(pp);
            }
        }
    }
    return mstw;
}

int main()
{
    // ...
    return 0;
}