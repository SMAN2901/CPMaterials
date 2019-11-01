#include <bits/stdc++.h>
using namespace std;

const int INF=INT_MAX;
const int MX=102;

int dis[MX][MX],path[MX][MX];

void init(int n)
{
    for(int u=1;u<=n;u++){
        for(int v=1;v<=n;v++){
            dis[u][v]=(u==v)?0:INF;
        }
    }
}

void floyd_warshall(int n)
{
    for(int k=1;k<=n;k++){
        for(int u=1;u<=n;u++){
            for(int v=1;v<=n;v++){
                if(dis[u][k]==INF || dis[k][v]==INF) continue;
                int d=dis[u][k]+dis[k][v];
                if(d<dis[u][v]) dis[u][v]=d,path[u][v]=path[u][k];
            }
        }
    }
}

bool negative_cycle(int n)
{
    for(int u=1;u<=n;u++){
        if(dis[u][u]<0) return true;
    }
    return false;
}

int main()
{
    // ...
    return 0;
}