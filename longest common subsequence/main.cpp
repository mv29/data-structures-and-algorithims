
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

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll n,i;
    cin >> n;
    ll a[n];
    FOR(i,n)
    cin >> a[i];
   int  x=0,y=0,z=0;
   int start=0;
    while(start==0)
    {

     FORK(i,x+1,n-2)
     {
        if(a[i]>a[x])
        {
            y=i;
            start=1;
            break;
        }
     }
      if(start==0)
      x++;
    }
    FORK(i,y+1,n-1)
    {
        if(a[i]>a[y])
        {
            z=i;
            break;
        }
    }
    FORK(i,z+1,n-1)
    {
        if(a[i]>a[z])
        {
            x=y;
            y=z;
            z=i;
        }
    }
    cout << a[x]*a[y]*a[z];
    return 0;
}
