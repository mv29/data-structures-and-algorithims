

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
#define MOD          1000000007
bool b[M];
int sp[M];
template<class T> // correct value till 10^9
 T pow(T x, T y){
     ll ret=1;
     while(y>0){
         if(y%2==0)
            {
             x=(x*x)%MOD;
            }
         else
          {
           ret*=x;x=(x*x)%MOD;
           ret%=MOD;
          }
         y/=2;
     }
     return ret%MOD;
}/*
inline void inp( int &n )
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
}*/
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll n,i,j;
    for(i=2;i<M;i+=2)
        sp[i]=2;
    for( i=3;i<M;i+=2)
    {
       // cout << i << "\n";
        if(b[i]==false)
        {
            sp[i]=i;
            b[i]=true;
            for(j=i;(j*i)<M;j+=2)
            {
              //  cout << j*i << "\n";
                if(b[j*i]==false)
                {
                    b[j*i]=true;
                    sp[j*i]=i;
                }
            }
        }
    }
   int t;
   cin >> t;
   while(t--)
   {
   	cin >> n;
   	int x=n;
   	map<int,int> b;
   	while(n!=1)
   	{
   		b[sp[n]]++;
   		n/=sp[n];
   	}
   	ll ans=1;
   	ll mv;
   	ll y;
   	for(auto k: b)
   	{
   		mv=0;
   		while(k.se!=-1)
   		{
   		mv+=pow(k.fi,k.se);
   		k.se--;
   		}
   		if(k.fi==2)
        {
            y=mv;
        }
        else
   		ans*=mv;
   	}
    return 0;
}

