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
#define  M           1001
#define INF          100001
/* this code is taking first vertice as 0*/
vi a[M];
bool v[M]; // for visited
bool g[M]; // for those vertices whose all children are not yet visited
bool b[M]; // for those vertices whose all children have been visited
vector<ii> d;
int aa[101][101];
int ans=0;
void dfs(int x)
{
    v[x]=true;
    g[x]=true;
   // cout << x << "\n";
    for(int i=0;i<a[x].size();i++)
    {
        int y=a[x][i];
        if(v[y]==false && b[y]==false && g[y]==false)
          {
           dfs(y);
          }
        if(g[y]==true && v[y]==true)
         d.pb(mp(y,x));
    }
    g[x]=false;
    b[x]=true;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        d.clear();
        memset(v,false,sizeof(v));
        memset(g,false,sizeof(g));
        memset(b,false,sizeof(b));
     ios_base::sync_with_stdio(false);
    int n,m,i,j,k;
    cin >> n >> m;
    FOR(i,M)
    a[i].clear();
    FOR(i,101)
    {
        FOR(j,101)
        {
            aa[i][j]=INF;
        }
    }
    int x,y,w;
    for(i=1;i<=m;i++)
    {
        cin >> x >> y >> w;
        a[x].pb(y);
        x=x;
        y=y;
        if(aa[x][y]!=INF)
        aa[x][y]=max(w,aa[x][y]);
        else
            aa[x][y]=w;

    }
    FORK(i,1,n)
    {
        if(v[i]==false)
            dfs(i);
    }
    FORK(k,1,n)
    {
        FORK(i,1,n)
        {
          FORK(j,1,n)
          if(aa[i][j]>aa[i][k]+aa[k][j])
          {
              aa[i][j]=aa[i][k]+aa[k][j];
          }
        }
    }
    int flag=0;
    FOR(i,sz(d))
    {
        n=d[i].fi;
        m=d[i].se;
       // cout << n << " " << m << "\n";
          y= aa[n][m]+aa[m][n];
       // cout << y << "\n";
        if(y>0)
         {
             flag=1;
          //   break;
         }
    }
         if(flag==1)
            cout << "YES\n";
         else
            cout << "NO\n";
    }
    return 0;
}
