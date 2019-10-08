#include <bits/stdc++.h>
using namespace std;

struct node{
    bool f=false;
    int to[26];
    node(){memset(to,-1,sizeof(to));}
};

int size=1;
vector <node> trie(1);

void insert(string &s,int len)
{
    int v=0;
    for(int i=0;i<len;i++){
        int c=s[i]-97;
        if(trie[v].to[c]==-1){
            trie.emplace_back();
            trie[v].to[c]=size++;
        }
        v=trie[v].to[c];
    }
    trie[v].f=true;
}

bool find(string &s,int len)
{
    int v=0;
    for(int i=0;i<len;i++){
        int c=s[i]-97;
        if(trie[v].to[c]==-1) return false;
        v=trie[v].to[c];
    }
    return trie[v].f;
}

int main()
{
    // ...
    return 0;
}