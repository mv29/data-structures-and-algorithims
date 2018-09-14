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
vi a[M];
int d[M];
int p[M];
void init()
{
    int i;
    FOR(i,M)
    {
        d[i]=INF;
        p[i]=-1;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    int n,m,i,j;
    cin >> n >> m;
    int x,y,w;
    for(i=1;i<=m;i++)
    {
        cin >> x >> y >> w;
        a[i].pb(x);
        a[i].pb(y);
        a[i].pb(w);
    }
    cout << "\n";
    init();
    d[1]=0;
    FOR(i,n)
    {
        FORK(j,1,m)
        {
            x=a[j][0];
            y=a[j][1];
            w=a[j][2];
            if(d[y]>d[x]+w && d[x]<INF)
            {
             d[y]=d[x]+w;
             p[y]=x;
            }
        }
    }
    FORK(i,2,n)
    cout << d[i] << " " ;

    return 0;
}
