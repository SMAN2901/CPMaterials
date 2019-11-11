#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MX=30004;

int n,K,T,C,X;
ll bit[MX],w[MX];
int chain[MX],head[MX];
int pos[MX],sub[MX],hc[MX];
int tin[MX],tex[MX],p[MX][16];
vector <int> adj[MX];

void init(int n)
{
    C=1,X=1;
    T=1,K=__lg(n)+1;
    for(int i=0;i<=n;i++){
        adj[i].clear();
        bit[i]=0;
    }
}

void upd(int i,ll v)
{
    while(i<=n){
        bit[i]+=v;
        i+=i & -i;
    }
}

ll qry(int i)
{
    ll r=0;
    while(i>0){
        r+=bit[i];
        i-=i & -i;
    }
    return r;
}

int f(int u,int par)
{
    tin[u]=T++;
    p[u][0]=par;
    for(int i=1;i<=K;i++){
        p[u][i]=p[p[u][i-1]][i-1];
    }
    sub[u]=1,hc[u]=-1;
    int l=adj[u].size();
    for(int i=0;i<l;i++){
        int v=adj[u][i];
        if(v==par) continue;
        sub[u]+=f(v,u);
        if(hc[u]==-1 || sub[hc[u]]<sub[v]) hc[u]=v;
    }
    tex[u]=T++;
    return sub[u];
}

void hld(int u,int k)
{
    pos[u]=X++;
    upd(pos[u],w[u]);
    if(k==1){
        chain[u]=C;
        head[C++]=u;
    }
    else chain[u]=chain[p[u][0]];
    int l=adj[u].size();
    if(hc[u]!=-1) hld(hc[u],0);
    for(int i=0;i<l;i++){
        int v=adj[u][i];
        if(v==p[u][0]) continue;
        if(v!=hc[u]) hld(v,1);
    }
}

void process()
{
    f(1,1);
    hld(1,1);
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

ll qr(int u,int v)
{
    ll r=0;
    while(chain[u]!=chain[v]){
        int h=head[chain[v]];
        r+=qry(pos[v])-qry(pos[h]-1);
        v=p[h][0];
    }
    r+=qry(pos[v])-qry(pos[u]-1);
    return r;
}

ll query(int u,int v)
{
    if(chain[u]==chain[v]){
        if(pos[u]<pos[v]) swap(u,v);
        return qry(pos[u])-qry(pos[v]-1);
    }
    int c=lca(u,v);
    ll r=qr(c,u)+qr(c,v)-w[c];
    return r;
}

int main()
{
    // ...
    return 0;
}