#include <bits/stdc++.h>
using namespace std;

const int MX=100005;
struct state{
    int len,link;
    map <char,int> to;
};

state sa[MX<<1];
int size,last;
char s[MX];

void init_state(int n)
{
    sa[n].len=0;
    sa[n].link=-1;
    sa[n].to.clear();
}

void sa_init()
{
    init_state(0);
    size=1,last=0;
}

void extend(char c)
{
    int cur=size++;
    init_state(cur);
    sa[cur].len=sa[last].len+1;
    int p=last;
    while(p!=-1 && !sa[p].to.count(c)){
        sa[p].to[c]=cur;
        p=sa[p].link;
    }
    if(p==-1){
        sa[cur].link=0;
        last=cur;
        return;
    }
    int q=sa[p].to[c];
    if(sa[q].len==sa[p].len+1) sa[cur].link=q;
    else{
        int clone=size++;
        init_state(clone);
        sa[clone].len=sa[p].len+1;
        sa[clone].link=sa[q].link;
        sa[clone].to=sa[q].to;
        while(p!=-1 && sa[p].to[c]==q){
            sa[p].to[c]=clone;
            p=sa[p].link;
        }
        sa[cur].link=sa[q].link=clone;
    }
    last=cur;
}

int main()
{
    // ...
    return 0;
}