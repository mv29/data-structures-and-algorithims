#include <bits/stdc++.h>
using namespace std;
typedef long int ll;
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
#define  M           100005
#define INF          1000000007
#define ull          unsigned long long

/*** https://www.topcoder.com/community/data-science/data-science-tutorials/primality-testing-non-deterministic-algorithms/ ***/

/* calculates (a * b) % c taking into account that a * b might overflow */
ull mulmod(ull a, ull b, ull mod)
{
    ull x = 0,y = a % mod;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            x = (x + y) % mod;
        }
        y = (y * 2) % mod;
        b /= 2;
    }
    return x % mod;
}

/* accurate till 10^18
 * modular exponentiation
 */
ull modulo(ull base, ull exponent, ull mod)
{
    ull x = 1;
    ull y = base;
     while (exponent > 0)
     {
        if (exponent % 2 == 1)
         x = mulmod(x, y, mod);
        y = mulmod(y, y, mod);
        exponent = exponent / 2;
     }
    return x % mod;
}
int main()
{
    ios_base::sync_with_stdio(false);  cin.tie(0);
    ull b,e,mod;
    cin >> b >>e >> mod;
    cout << modulo(b,e,mod);
    return 0;
}
