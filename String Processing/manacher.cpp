#include <bits/stdc++.h>
using namespace std;

void manacher_odd(char s[],int n,int d[])
{
    int l=0,r=-1;
    memset(d,0,n*sizeof(d[0]));
    for(int i=0;i<n;i++){
        int p=i-1,q=i+1;
        d[i]=1;
        if(i<=r){
            int j=l+r-i;
            int x=d[j]>>1;
            int y=j-max(j-x,l);
            p=i-y-1,q=i+y+1,d[i]=y+y+1;
        }
        while(p>=0 && q<n && s[p]==s[q]){
            d[i]+=2,q++,p--;
        }
        if(r<q-1) l=p+1,r=q-1;
    }
}

void manacher_even(char s[],int n,int d[])
{
    int l=0,r=-1;
    memset(d,0,n*sizeof(d[0]));
    for(int i=0;i<n-1;i++){
        int p=i,q=i+1;
        if(i<r){
            int j=l+r-i-1;
            int x=d[j]>>1;
            int y=j-max(j-x+1,l)+1;
            p=i-y,q=i+y+1,d[i]=y+y;
        }
        while(p>=0 && q<n && s[p]==s[q]){
            d[i]+=2,q++,p--;
        }
        if(r<q-1) l=p+1,r=q-1;
    }
}

int main()
{
    // ...
    return 0;
}