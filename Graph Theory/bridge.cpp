#include <bits/stdc++.h>
using namespace std;
const int MX=100005;

bool vis[MX];
int tin[MX],low[MX],T,cnt;
vector <int> adj[MX],bridge[MX];

void init(int n)
{
    for(int i=0;i<n;i++){
        adj[i].clear();
        bridge[i].clear();
        vis[i]=false;
    }
    T=1,cnt=0;
}

void f(int u,int p)
{
    vis[u]=true;
    tin[u]=low[u]=T++;
    int l=adj[u].size();
    for(int i=0;i<l;i++){
        int v=adj[u][i];
        if(v==p) continue;
        if(vis[v]){
            low[u]=min(low[u],tin[v]);
            continue;
        }
        f(v,u);
        low[u]=min(low[u],low[v]);
        if(tin[u]<low[v]){
            cnt++;
            int x=min(u,v);
            int y=max(u,v);
            bridge[x].push_back(y);
        }
    }
}

int main()
{
    // ...
    return 0;
}