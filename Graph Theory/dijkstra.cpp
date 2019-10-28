#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int MX=100005;

int dis[MX],par[MX];
vector <pii> adj[MX];

void init(int n)
{
    for(int i=0;i<=n;i++){
        adj[i].clear();
        dis[i]=INT_MAX;
        par[i]=-1;
    }
}

void dijkstra(int n,int s)
{
    dis[s]=0;
    priority_queue <pii,vector<pii>,greater<pii>> q;
    q.push({0,s});
    while(!q.empty()){
        int u=q.top().second;
        int d=q.top().first;
        q.pop();
        if(dis[u]!=d) continue;
        int l=adj[u].size();
        for(int i=0;i<l;i++){
            int v=adj[u][i].second;
            int w=adj[u][i].first;
            if(d+w<dis[v]){
                dis[v]=d+w;
                par[v]=u;
                q.push({dis[v],v});
            }
        }
    }
}

int main()
{
    // ...
    return 0;
}