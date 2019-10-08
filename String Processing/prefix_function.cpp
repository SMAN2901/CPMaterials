#include <bits/stdc++.h>
using namespace std;

const int MX=1000006;
char s[MX],t[MX];
int pi[MX],to[MX][26];

void compute(int len,char s[],int pi[])
{
    pi[0]=0;
    for(int i=1;i<len;i++){
        int j=pi[i-1];
        while(j){
            if(s[j]==s[i]){
                pi[i]=j+1;
                break;
            }
            j=pi[j-1];
        }
        if(j==0) pi[i]=(s[i]==s[0])?1:0;
    }
}

void make_automaton(char s[],int n,int pi[])
{
    for(int i=0;i<=n;i++){
        for(int c=0;c<26;c++){
            if(s[i]==c+97) to[i][c]=i+1;
            else to[i][c]=i?to[pi[i-1]][c]:0;
        }
    }
}

int main()
{
    // ...
    return 0;
}