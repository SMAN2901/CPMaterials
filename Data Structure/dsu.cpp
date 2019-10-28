#include <bits/stdc++.h>
using namespace std;
const int MX=100005;

int par[MX],sz[MX];

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

int main()
{
    // ...
    return 0;
}