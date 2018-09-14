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

void lis(int a[],int n)
{
    int i,j;
    int b[n];
    FOR(i,n)
    b[i]=1;
    int ans=1;
    FORK(i,1,n-1)
    {
        FOR(j,i)
        {
            if(a[j]<=a[i])
            b[i]=max(b[i],b[j]+1);
        }
        ans=max(ans,b[i]);
    }
    cout << ans << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,i;
        cin >> n ;
        int a[n];
        FOR(i,n)
        cin >> a[i];
        lis(a,n);
    }
    return 0;
}
