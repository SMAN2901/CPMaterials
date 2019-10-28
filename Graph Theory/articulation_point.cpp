#include <bits/stdc++.h>
using namespace std;
const int MX=100005;

bool vis[MX];
int tin[MX],low[MX],T;
vector <int> adj[MX],ap;

void init(int n)
{
    for(int u=1;u<=n;u++){
        adj[u].clear();
        vis[u]=false;
    }
    ap.clear(),T=1;
}

void f(int u,int p)
{
    vis[u]=true;
    bool marked=false;
    tin[u]=low[u]=T++;
    int l=adj[u].size(),k=0;
    for(int i=0;i<l;i++){
        int v=adj[u][i];
        if(v==p) continue;
        if(vis[v]){
            low[u]=min(low[u],tin[v]);
            continue;
        }
        f(v,u),k++;
        low[u]=min(low[u],low[v]);
        if(p!=-1 && low[v]>=tin[u] && !marked){
            marked=true;
            ap.push_back(u);
        }
    }
    if(p==-1 && k>1) ap.push_back(u);
}

int main()
{
    // ...
    return 0;
}