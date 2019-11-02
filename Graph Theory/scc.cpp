#include <bits/stdc++.h>
using namespace std;

const int MX=100005;

int id[MX];
bool vis[MX];
stack <int> s;
vector <int> adj[MX],radj[MX];
vector <int> cadj[MX],comp[MX];

void init(int n)
{
    for(int i=0;i<=n;i++){
        adj[i].clear();
        radj[i].clear();
        comp[i].clear();
        vis[i]=false;
    }
}

void f(int u)
{
    vis[u]=true;
    int l=adj[u].size();
    for(int i=0;i<l;i++){
        int v=adj[u][i];
        if(vis[v]) continue;
        f(v);
    }
    s.push(u);
}

void transpose(int n)
{
    for(int u=0;u<=n;u++){
        int l=adj[u].size();
        for(int i=0;i<l;i++){
            int v=adj[u][i];
            radj[v].push_back(u);
        }
    }
}

void fun(int u,int x)
{
    vis[u]=true,id[u]=x;
    comp[x].push_back(u);
    int l=radj[u].size();
    for(int i=0;i<l;i++){
        int v=radj[u][i];
        if(vis[v]) continue;
        fun(v,x);
    }
}

int scc(int n)
{
    for(int u=1;u<=n;u++){
        if(vis[u]) continue;
        f(u);
    }
    for(int i=0;i<=n;i++) vis[i]=false;
    transpose(n);
    int x=0;
    while(!s.empty()){
        int u=s.top();
        s.pop();
        if(!vis[u]) fun(u,x++);
    }
    return x;
}

void condensation_graph(int n)
{
    for(int u=1;u<=n;u++){
        int l=adj[u].size();
        for(int i=0;i<l;i++){
            int v=adj[u][i];
            if(id[u]==id[v]) continue;
            cadj[id[u]].push_back(id[v]);
        }
    }
}

int main()
{
    // ...
    return 0;
}