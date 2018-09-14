
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
vii a[M];
bool b[M];
int p[M];
int ans=0;
void dfs(int x)
{
    b[x]=true;
    FORK(i,a[x].size())
    {
        int y=a[x][i];
        if(b[y]==false)
         {
           dfs(y);
           p[y]=x
         }
         else
         {
             if(p[x]!=y)
                ans=1;
         }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    int x,y,w,i;
    while(m--)
    {
        cin >> x >>y >> w;
        a[x].pb(mp(w,y));
        a[y].pb(mp(w,x));
    }
    dfs(1);
    if(ans==1)
        cout << "yes";
    return 0;
}
