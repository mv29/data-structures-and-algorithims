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
#define  M           100010
#define INF          1001001001
#define MOD          1000000007

template<class T> // correct value till 10^9
 T pow(T x, T y){
     ll ret=1;
     while(y>0){
         if(y%2==0)
            {
             x=(x*x)%MOD;
            }
         else
          {
           ret*=x;x=(x*x)%MOD;
           ret%=MOD;
          }
         y/=2;
     }
     return ret%MOD;
}
template<class T>
 T gcd(T a,T b)// a is larger b is smaller
 {
 T xa=max(a,b),xb=min(a,b);
 if(xb==0)
 return xa;
 else
 return gcd(xb,xa%xb);
 }
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int i,j,n,q;
    cin >> n >> q;
    cout << gcd(n,q);
   return 0;
}
