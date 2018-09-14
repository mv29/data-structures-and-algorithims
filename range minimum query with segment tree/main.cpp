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
#define  M           100005
#define INF          1000000007

ll t1[4*M+5];
ll a[M];
void st(ll i,ll s,int e)
{
    if(s>e)
    return ;
    if(s==e)
    {
     t1[i]=a[s];
     return;
    }
    int k= (s+e) >> 1;
    st(2*i,s,k);
    st(2*i+1,k+1,e);
    t1[i]= min(t1[2*i],t1[2*i+1]);
}
void update(int i,int s,int e,int m,int value) // s-start and e-end index for a range
{
    //cout << i << " " << s << " " << e << "\n";
    if(s==e)
    {
      //  cout << i << "\n";
        t1[i]+=value;
        return;
    }
    int k=(s+e) >> 1;
    if(m<=k && m>=s)
    update(2*i,s,k,m,value);
    else
    update(2*i+1,k+1,e,m,value);
    t1[i]=min(t1[2*i],t1[2*i+1]);
}
int query(int i,int s,int e,int n,int m) // n lower and m upper index of given range
{
    if(e<n || s>m)
     return 0;
    else if(s>=n && e<=m )
     {
         return t1[i];
     }
    int k= (s+e) >> 1;
    int t11=query(2*i,s,k,n,m);
    int t22=query(2*i+1,k+1,e,n,m);
    return  min(t11,t22);
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,q,i,j,x,y;
    cin >> q >> n;
    FORK(i,1,n)
    cin >> a[i];
    st(1,1,n);
    return 0;
}
