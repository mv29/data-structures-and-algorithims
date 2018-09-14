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

int ans=1000000;
void dfs(vector< vector<char> > &a, vector< vector<int> > &b,int n,int m,int x,int y,int xd,int yd,int k)
{
     if(x<0 || y< 0)
        return ;
    if(x>=n || y>=m)
     return ;
    if(b[x][y]!=0)
      return ;
     if(a[x][y]=='T')
     return ;
      b[x][y]=1;
      k++;
    if(x==xd && y==yd)
    {
        ans=min(ans,k);
    }
    dfs(a,b,n,m,x+1,y,xd,yd,k);
    dfs(a,b,n,m,x-1,y,xd,yd,k);
    dfs(a,b,n,m,x,y+1,xd,yd,k);
    dfs(a,b,n,m,x,y-1,xd,yd,k);
    b[x][y]=0;
}
int main()
{
    //cout << "Hello world!" << endl;
    int n,m,i,j,x1,y1,x2,y2;
    cin >> n ;
    m=n;
    vector< vector<char> > a(n,vector<char> (m));
    vector< vector<int> > b(n,vector<int> (m,0));
    for(i=0;i<n;i++)
    for(j=0;j<m;j++)
    {
        cin >> a[i][j];
        if(a[i][j]=='S')
        {
            x1=i;
            y1=j;
        }
        if(a[i][j]=='E')
        {
            x2=i;
            y2=j;
        }
    }
    dfs(a,b,n,m,x1,y1,x2,y2,-1);
    cout << ans << "\n";
    return 0;
}
