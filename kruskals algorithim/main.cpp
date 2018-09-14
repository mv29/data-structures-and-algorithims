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

#define me(a,b)   memset(a,b,sizeof(a))
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
#define  M           10010
#define I          1000000007
int a[M],b[M];
void init()
{
    for(int i=1;i<M;i++)
    {
        a[i]=i;
        b[i]=1;
    }
}
int root(int x)
{
    int m=x;
    while(a[m]!=m)
    {
        a[m]=a[a[m]];
        m=a[m];
    }
    return m;
}
void u(int x,int y)
{
    int m= root(x);
    int v=root(y);
    if(m==v)
    return;
    if(b[m]>b[v])
    {
        a[v]=m;
        b[m]=b[m]+b[v];
        b[v]=0;
    }
    else
    {
        a[m]=v;
        b[v]=b[m]+b[v];
        b[m]=0;
    }
}
bool check(int a,int b)
{
    if(root(a)==root(b))
        return true;
    else
       return false;
}
ll kruskals(pair<ll,ii> p[] ,int m)
{
    int x,y,i;
    ll c,mc=0;
    FOR(i,m)
    {
      x=p[i].se.fi;
        y=p[i].se.se;
        c=p[i].fi;
     if(root(x)!=root(y))
     {
         mc +=c;
         u(x,y);
     }
    }
    return mc;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m,x,y,i,j;
    ll w;
    ll ans;
    cin >> n >> m;
    pair<ll,ii> p[m];
    init();
    FOR(i,m)
    {
        cin >> x >> y >> w;
        p[i]= mp(w,mp(x,y));
    }
    cout << "boobs\n";
    sort(p,p+m);
    ans=(kruskals(p,m))*I;
    cout << ans << "\n";
    return 0;
}
