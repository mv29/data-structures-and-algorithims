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
/*** for reducing time use the below logic in main to reduce function call overhead ***/
bool prime(ll n) // can be used for long long int
{
    int i,j=0;
    if(n==2 || n==3 || n==5 || n==7 || n==11)
        return true;
    if(n%2==0 ||n%3==0 || n%5==0 || n%7==0 || n%11==0)
     return false;
    for(i=13;i*i<=n;i++)
    {
        if(n%i==0)
        {
            j=1;
            break;
        }
    }
    if(j==0)
        return true;
    else
        return false;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll n;
    cin >> n;
    if(prime(n))
        cout << "prime\n";
    else
        cout << "not prime\n";
    return 0;
}
