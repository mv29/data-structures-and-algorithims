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

/*
m=row,n=col
vector< vector<int> > matrix(m,vector<int>(n));
*/

vector<vi> matrix(vector<vector<int> a,vector<vector<int> b)
{
    int i,j,k;
    int n=sz(a[0])
    vector<vi> result(n,vi(n));

    FOR(i,n)
    FOR(j,n)
    {
        if(i==j)
            result[i][j]=1;
    }

    FOR(i,n)
    FOR(j,n)
    FOR(k,n)
    result[i][j]+=a[i][k]*b[k][j];

    return result;
}

vector<vi> power(vector<vector<int> b,int x)
{

    int i,j,k;
    int n=sz(a[0])

    vector<vi> result(n,vi(n));

    FOR(i,n)
    FOR(j,n)
    {
        if(i==j)
            result[i][j]=1;
    }


    while(x!=0)
    {
        if(x%2==1)// checking the left most bit of the the x therefore if x is odd or even
            result=matrix(result,a)
        x=x/2;
        a=matrix(a,a)
    }
    return result
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,i,j,k,x;
    cin >> n >> x;

    vector<vi> a(n,vi(n));

    FOR(i,n)
    FOR(i,j)
    cin >> a[i][j];

    a=matrix(a,x)
}
