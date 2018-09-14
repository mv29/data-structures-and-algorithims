
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

#define FIN(x)       freopen(x,"r",stdin)
#define FOUT(x)      freopen(x,"w",stdout)
#define FCLOSE       {fclose(stdin); fclose(stdout);}

#define fi           first
#define se           second
#define pb           push_back
#define mp           make_pair
#define  M           100001
#define INF          1001001001
// index based inversion valid till max array value of 10^7
ll b[M];
void update(ll i,ll v,ll b[],ll n)
{
    for(; i <= n; i += i&-i)
        b[i] += v;
}
int query(ll x,ll b[])
{
     int sum = 0;
     for(; x > 0; x -= x&-x)
        sum += b[x];
     return sum;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--)
    {
    ll i,j,n;
    FOR(i,M)
    b[i]=0;
    cin >> n;
    ll ans=0;
    FORK(i,0,n-1)
    {
       cin >> j;
       ans+=query(M,b)-query(j,b);
       update(j,1,b,M);
    }
    cout << ans << "\n";
    }
    return 0;
}
