#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<ll> vi;
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

vi t[4*M+5];
ll a[M];
vi merge(vi a,vi b)
{
    int i=0,j=0;
    int n=sz(a);
    int m=sz(b);
    vi k;
    while(1)
    {
        if(i==n && j==m)
            break;
        if(i==n)
         {
             k.pb(b[j]);
             j++;
         }
         else if(j==m)
         {
             k.pb(a[i]);
             i++;
         }
        else if(a[i]>b[j])
        {
            k.pb(b[j]);
            j++;
        }
        else if(b[i]>=a[j])
        {
            k.pb(a[i]);
            i++;
        }
    }
    return k;
}
void st(ll i,ll s,int e)
{
    if(s>e)
    return ;
    if(s==e)
    {
     t[i].pb(a[s]);
     return;
    }
    int k= (s+e)/2;
    st(2*i,s,k);
    st(2*i+1,k+1,e);
    t[i]=merge(t[2*i],t[2*i+1]);
}
vi query(int i,int s,int e,int n,int m) // n lower and m upper index of given range
{
  //  cout << i << " " << s << " " << e << "\n";
    if(e<n || s>m)
     {
         vi a;
         return a;
     }
    else if(s>=n && e<=m )
     {
         return t[i];
     }
    int k=(s+e)/2;
    vi t1=query(2*i,s,k,n,m);
    vi t2=query(2*i+1,k+1,e,n,m);
    vi mv= merge(t1,t2);
    return mv;
}
inline void inp( ll &n )
 {
    n=0;
    int ch=getchar_unlocked();int sign=1;
    while( ch < '0' || ch > '9' )
    {
        if(ch=='-')sign=-1;
         ch=getchar_unlocked();
    }
    while(  ch >= '0' && ch <= '9' )
        n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();

    n=n*sign;
}
int main()
{
   // ios_base::sync_with_stdio(false);cin.tie(0);
    ll n,q,i,j;
  //  cin >> n >> q;
    inp(n);inp(q);
    FORK(i,1,n)
    //cin >> a[i];
    inp(a[i]);
    st(1,1,n);
    int x,y,k;
    while(q--)
    {
        //cin >> x >> y >> k;
        inp(x);inp(y);inp(k);
        vi a=query(1,1,n,x,y);
        printf("%lld\n",a[k-1]);
    }
    return 0;
}
