#include <bits/stdc++.h>
using namespace std;

const int MX=100005;
int p[MX],pn[MX],c[MX],cn[MX],cnt[MX];
int lcp[MX];
char s[MX];

void sort_cyclic_shifts(char s[],int n)
{
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<n;i++) cnt[s[i]]++;
    for(int i=1;i<256;i++) cnt[i]+=cnt[i-1];
    for(int i=0;i<n;i++) p[--cnt[s[i]]]=i;
    int classes=1;
    for(int i=0;i<n;i++){
        if(i && s[p[i]]!=s[p[i-1]]) classes++;
        c[p[i]]=classes-1;
    }
    for(int k=0;(1<<k)<n;k++){
        for(int i=0;i<n;i++){
            pn[i]=p[i]-(1<<k);
            if(pn[i]<0) pn[i]+=n;
        }
        fill(cnt,cnt+classes,0);
        for(int i=0;i<n;i++) cnt[c[pn[i]]]++;
        for(int i=1;i<classes;i++) cnt[i]+=cnt[i-1];
        for(int i=n-1;i>=0;i--) p[--cnt[c[pn[i]]]]=pn[i];
        classes=1,cn[p[0]]=0;
        pair <int,int> x,y;
        for(int i=1;i<n;i++){
            x={c[p[i]],c[(p[i]+(1<<k))%n]};
            y={c[p[i-1]],c[(p[i-1]+(1<<k))%n]};
            if(x!=y) classes++;
            cn[p[i]]=classes-1;
        }
        for(int i=0;i<n;i++) c[i]=cn[i];
    }
}

void construct_lcp(char s[],int n,int p[],int lcp[])
{
    int rank[n+2],k=0;
    for(int i=0;i<n;i++) rank[p[i]]=i;
    for(int i=0;i<n;i++){
        if(rank[i]==n-1){
            k=0;
            continue;
        }
        int j=p[rank[i]+1];
        while(i+k<n && j+k<n && s[i+k]==s[j+k]) k++;
        lcp[rank[i]]=k;
        if(k) k--;
    }
}

int main()
{
    // ...
    return 0;
}