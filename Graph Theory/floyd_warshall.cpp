#include <bits/stdc++.h>
using namespace std;

const int INF=INT_MAX;
const int MX=102;

int dis[MX][MX];

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
                dis[u][v]=min(dis[u][v],dis[u][k]+dis[k][v]);
            }
        }
    }
}

bool negative_cycle(int n)
{
    for(int u=1;u<=n;u++){
        for(int v=1;v<=n;v++){
            for(int k=1;k<=n;k++){
                if(dis[u][k]==INF || dis[k][v]==INF) continue;
                if(dis[k][k]<0) return true;
            }
        }
    }
    return false;
}

int main()
{
    // ...
    return 0;
}