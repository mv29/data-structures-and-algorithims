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
/*** time complexity = O((n log n)(log log n)) ***/
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
    a[1]=false;
    a[0]=false;
    FORK(i,2,n+1)
    {
        if(a[i]==true)
            cout << i <<  " ";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,i,j;
    cin >> n;
    sieve(n);
    return 0;
}
