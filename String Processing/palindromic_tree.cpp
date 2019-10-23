#include <bits/stdc++.h>
using namespace std;
const int MX=100005;

struct node{
    int len,link,to[26];
};
node pt[MX];
int size,last;
char s[MX];

void init_node(int n)
{
    pt[n].len=0;
    pt[n].link=-1;
    memset(pt[n].to,-1,sizeof(pt[n].to));
}

void init_pt()
{
    init_node(0);
    init_node(1);
    pt[0].len=pt[0].link=-1;
    pt[1].link=0;
    size=2,last=1;
}

int find(int n,char s[],int i)
{
    while(n){
        int j=i-pt[n].len-1;
        if(j>=0 && s[i]==s[j]) return n;
        n=pt[n].link;
    }
    return n;
}

void extend(char s[],int i)
{
    int c=s[i]-97;
    int n=find(last,s,i);
    if(pt[n].to[c]==-1){
        int m=size++;
        init_node(m);
        pt[n].to[c]=m;
        pt[m].len=pt[n].len+2;
        if(pt[m].len==1) pt[m].link=1;
        else{
            int v=find(pt[n].link,s,i);
            pt[m].link=pt[v].to[c];
        }
        last=m;
    }
    else last=pt[n].to[c];
}

int main()
{

    return 0;
}