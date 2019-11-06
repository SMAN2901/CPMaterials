#include <bits/stdc++.h>
using namespace std;

const int MX=1003;

int bit[3][MX<<1];
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

int mini(int x,int y)
{
    if(x==-1) return y;
    if(y==-1) return x;
    return (dis[x]<dis[y])?x:y;
}

void build(int i,int v,int n)
{
    int j=i;
    bit[2][i]=v;
    while(i<=n){
        bit[0][i]=mini(bit[0][i],v);
        i+=i & -i;
    }
    while(j>0){
        bit[1][j]=mini(bit[1][j],v);
        j-=j & -j;
    }
}

int query(int i,int j)
{
    int p=i,q=j,r,m=-1;
    while(p<=j){
        r=p+(p & -p);
        if(r<=j) m=mini(m,bit[1][p]);
        p=r;
    }
    while(q>=i){
        r=q-(q & -q);
        if(r>=i) m=mini(m,bit[0][q]);
        else m=mini(m,bit[2][q]);
        q=r;
    }
    return m;
}

void construct_bit(int n)
{
    memset(bit,-1,sizeof(bit));
    for(int i=0;i<n;i++){
        int x=euler[i];
        build(i+1,x,n);
    }
}

int lca(int u,int v)
{
    int x=pos[u],y=pos[v];
    if(x>y) swap(x,y);
    return query(x+1,y+1);
}

int main()
{
    // ...
    return 0;
}