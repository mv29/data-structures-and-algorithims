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

#define fi           first
#define se           second
#define pb           push_back
#define mp           make_pair
#define  M           100001
#define INF          1001001001
#define B             break
#define C             continue
#define R             return

bool dfs(vector< vector<int> > &a, vector< vector<int> > &b,int n,int m,int x,int y)
{
     if(x<0 || y< 0)
        return false;
     if(x==n-1 && y==m-1)
        return true;
    if(x>=n || y>=m)
     return false;
    if(b[x][y]!=0)
       return false;
       if(a[x][y]==0)
       return false;
       b[x][y]=1;
    if(dfs(a,b,n,m,x+1,y)==true)
        return true;
    if(dfs(a,b,n,m,x-1,y)==true)
        return true;
    if(dfs(a,b,n,m,x,y+1)==true)
        return true;
    if(dfs(a,b,n,m,x,y-1)==true)
        return true;
return false;
}
int main()
{
    //cout << "Hello world!" << endl;
    int n,m,i,j;
    cin >> n >> m;
    vector< vector<int> > a(n,vector<int> (m));
    vector< vector<int> > b(n,vector<int> (m,0));
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        cin >> a[i][j];
    if(dfs(a,b,n,m,0,0))
      cout << "Yes";
    else
        cout << "No";
    return 0;
}
