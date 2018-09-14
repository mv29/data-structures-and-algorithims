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
#define  M           500001
#define INF          1001001001

int main()
{
   ios_base::sync_with_stdio(false);cin.tie(0);
   int n,i,j,q;
   cin >> n;
   int a[n];
   FOR(i,n)
   cin >> a[i];

    int LOG[n+1];
    LOG[1] = 0;
    for (int i = 2; i <= n; i++)
    LOG[i] = LOG[i/2] + 1;
    int K=log2(n)+1;
    int st[n][K];

    for (int i = 0; i < n; i++)
    st[i][0] = a[i];

    for (int j = 1; j <= K; j++)
    for (int i = 0; i + (1 << j) <= n; i++)
        st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);

    cin >> q;
    int l,r,x;
    while(q--)
    {
        cin >>l >> r;
        x = LOG[r - l + 1];
        cout <<  min(st[l][x], st[r - (1 << x) + 1][x]) << "\n";
    }

    return 0;
}
