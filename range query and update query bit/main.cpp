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
// b1 and b2 are two binary indexed trees
// Original array entries are assumed to be 0
// and only updates are stored.
int b1[M];
int b2[M];
// Point query
int query(int x,int b[])
{
     int sum = 0;
     for(; x > 0; x -= x&-x)
        sum += b[x];
     return sum;
}
// Range query: Returns the sum of all elements in [1...b]
int query(int b)
{
    cout << b << " lol " <<  query(b,b1)*b  << " " << query(b,b2) << "\n";
    return query(b,b1)*b - query(b,b2);
}

// Range query: Returns the sum of all elements in [i...j]
int rquery(int i, int j)
{
    return query(j) - query(i - 1);
}
// Point update: Adds v to the value at position k in the array
void update(int i,int v,int b[],int n)
{
    for(; i <= n; i += i&-i)
        b[i] += v;
}
// Range update: Adds v to each element in [i...j]
void rupdate(int i, int j, int v,int n)
{
	update(i,v,b1,n);
	update(j+1,-v,b1,n);
	update(i,v*(i - 1),b2,n);
	update(j+1,-v*j,b2,n);
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int i,j,n,x,y,m;
    cin >> n >> m;
    FORK(i,1,n)
    {
        cin >>  x >> y;
        rupdate(x,y,1,M);
    }
    ll ans=0;
    FOR(i,10)
    cout << b1[i] << " ";
    cout << "\n";
        FOR(i,10)
    cout << b2[i] << " ";
    cout << "\n";
    FORK(i,1,m)
    {
        cin >>  x >> y;
        cout << rquery(x,y) << "\n";
        ans+=rquery(x,y);
    }
    cout << ans;
    return 0;
}
