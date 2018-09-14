




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
#define MOD          1000000007
bool b[M];
int sp[M]; // it contains the minimum prime with which the number is divisible
vi p[M];
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
    for(i=2;i<60;i++)
    {
        j=i
        while(j!=1)
        {
            a[i].pb(sp[j]);
            j/=sp[j];
        }
    }
    FOR(i,60)
    {
        cout << i << "\n";
        FOR(j,sz(p[i]))
        cout << p[i][j] << " ";
        cout << "\n";
    }
    return 0;
}

