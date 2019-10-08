#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
const int MX=1000006;

char s[MX],t[MX];
ll pw1[MX],pw2[MX];

struct roll_hash{
    ll p1=257,p2=347;
    ll m1=2e9+203,m2=2e9+333;

    // calculates powers of bases
    roll_hash(int len,ll pw1[],ll pw2[])
    {
        pw1[0]=pw2[0]=1;
        for(int i=1;i<=len;i++){
            pw1[i]=(pw1[i-1]*p1)%m1;
            pw2[i]=(pw2[i-1]*p2)%m2;
        }
    }

    // return hash of s[x..y]
    pll hash(char s[],int x,int y,ll pw1[],ll pw2[])
    {
        ll h1=0,h2=0;
        for(int i=x;i<=y;i++){
            ll c=s[i];
            h1=(h1+c>=m1)?h1+c-m1:h1+c;
            h1=(h1*p1)%m1;
            h2=(h2+c>=m2)?h2+c-m2:h2+c;
            h2=(h2*p2)%m2;
        }
        return {h1,h2};
    }

    // return hash of s[x+1..y+1] given s[x..y]
    pll roll(char s[],int x,int y,pll h)
    {
        ll h1=h.first,h2=h.second;
        ll c=s[x],d=s[y+1];
        ll cp1=(c*pw1[y-x+1])%m1;
        ll cp2=(c*pw2[y-x+1])%m2;
        h1=(h1+d>m1)?h1+d-m1:h1+d;
        h1=(h1-cp1+m1)%m1;
        h1=(h1*p1)%m1;
        h2=(h2+d>m2)?h2+d-m2:h2+d;
        h2=(h2-cp2+m2)%m2;
        h2=(h2*p2)%m2;
        return {h1,h2};
    }
};
int main()
{
    // ...
    return 0;
}
