#include <bits/stdc++.h>
using namespace std;

const int MX=100005;
int z[MX];
char s[MX],st[MX];

void compute(int len,char s[],int z[])
{
    memset(z,0,len*sizeof(z[0]));
    int l=0,r=0;
    for(int i=1;i<len;i++){
        if(i<=r) z[i]=min(z[i-l],r-i+1);
        for(int j=i+z[i],p=z[i];j<len;j++,p++){
            if(s[p]==s[j]) z[i]++;
            else break;
        }
        if(i+z[i]-1>r) l=i,r=i+z[i]-1;
    }
}

int main()
{
    // ...
    return 0;
}