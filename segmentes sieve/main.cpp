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
/** each prime greater than sqrt(n) will have a factor greater than n so finding all primes less than or equal to sqrt(n) **/
vector<int> prime;
void sieve(int n)
{
    int i,j;
    bool a[n+1];
    memset(a,true,sizeof(a));
    for(i=2;i*i<=n;i++)
    {
        if(a[i]==true)
        {
            for(j=i*2;j<=n;)
            {
                a[j]=false;
                j=j+i;
            }
        }
    }
    FORK(i,2,n+1)
    {
        if(a[i]==true)
        prime.pb(i);
    }
}
void segmented_sieve(ll n)
{
    int limit=sqrt(n);
    int low=limit+1;
    int high= 2*limit;
    sieve(limit);
    bool mark[high-low+1];
    while(low<=n)
    {
        int i,j;
        memset(mark,true,sizeof(mark));
        FOR(i,sz(prime))
        {
            int x = floor(low/prime[i])*prime[i];
            if(x<low)
                x+=prime[i];
            for(j=x;j<=high;)
            {
                    mark[j-low]=false; // as mark is zero indexed and
                    j+=prime[i];
            }
        }
        FORK(i,low+1,high)
        if(mark[i]==true)
            cout << i << " ";
        low+=limit;
        high+=limit;
        if(high>n)
        high=n;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);  cin.tie(0);
    return 0;
}
