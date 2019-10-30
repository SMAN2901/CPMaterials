#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
const int MX=102;

pii e[MX];
int dis[MX],cost[MX],par[MX];
vector <int> nc;

void init(int n)
{
    for(int i=0;i<=n;i++){
        dis[i]=INT_MAX;
        par[i]=-1;
    }
    nc.clear();
}

void negative_cycle(int x,int n)
{
    int y=x;
    while(n--) y=par[y];
    nc.push_back(y),x=par[y];
    while(x!=y){
        nc.push_back(x);
        x=par[x];
    }
}

void bellman_ford(int n,int m,int s)
{
    dis[s]=0;
    int x;
    for(int i=0;i<n;i++){
        x=-1;
        for(int j=0;j<m;j++){
            int u=e[j].first;
            int v=e[j].second;
            if(dis[u]==INT_MAX) continue;
            int d=dis[u]+cost[j];
            if(cost[j]<0 && INT_MIN-cost[j]>dis[u]) d=INT_MIN;
            if(dis[v]>d) dis[v]=d,par[v]=u,x=v;
        }
    }
    if(x!=-1) negative_cycle(x,n);
}

int main()
{
    // ...
    return 0;
}