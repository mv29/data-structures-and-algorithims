#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<ll> vll;
#define FOR(i,n) for (i = 0; i < n; ++i)
#define FORK(i,k,n) for (i = k; i <= n; ++i)
#define FORR(i,k,n) for (i = k; i >= n; --i)

#define re(a,b)   memset(a,b,sizeof(a))
#define sz(a)      (int)(a.size())
#define MIN(a,b)     (a) = min((a),(b))
#define MAX(a,b)     (a) = max((a),(b))
#define input(in)    freopen(in,"r",stdin)
#define output(out)  freopen(out,"w",stdout)
#define ALL(a)       a.begin(),a.end()
#define RALL(a)      a.rbegin(),a.rend()
#define LEN(a)       (int)(a.length())

#define fi           first
#define se           second
#define pb           push_back
#define mp           make_pair
#define  M           100001
#define INF          1001001001
#define B             break
#define C             continue
#define R              return
#define  M           100001
#define INF          1001001001
#define I            1000000007
int p[M*2];
string cha(const string &s)
{
    int i,j;
    string a;
    FOR(i,sz(s))
    {
        a+= "#"+ s.substr(i,1);
    }
    a+="#";
    R a;
}
string manachers(string s)
{
    string q=cha(s);
    int c=0,r=0,i,m;
    FOR(i,sz(q)-1)
    {
        m=c-(i-c);
          if(r>i)
          p[i]=min(r-i,p[m]);

         while(q[i+1+p[i]]==q[i-1-p[i]])
            p[i]++;

        if(i+p[i]>r)
         {
             c=i;
             r=i+p[i];
         }
     }
    int mp=-1;
    FOR(i,sz(q)-1)
    {
        if(p[i]>mp)
        {
            mp=p[i];
            c=i;
        }
    }
    cout << mp << "\n";
    R s.substr((c-1-mp)/2,mp);
}
int main()
{
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    cout << manachers(s);
    return 0;
}
