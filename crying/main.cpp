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
#define INF          1001001001

int n,i,j;
vector<vector<int>> b(M,vector<int>(M,0));
bool dfs(vector<string> a,int n,int x,int y,int c)
{
    if(x<0)
    return false;
    if(y>=n)
        return true;
    if(a[x][y]=='#')
        return false;
    if(b[x][y]==1)
        return true;
    if(b[x][y]==2)
        return false;
    dfs(a,n,x-1,y,c);
    bool mv=dfs(a,n,x,y+1,c);
    if(mv==true && y==c)
        b[x][y]=1;
    else
        b[x][y]=2;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<string> a(n);
        FOR(i,n)
        cin >> a[i];
        for(i=n-1;i>-1;i--)
        {
            if(a[n-1][i]!='#')
                dfs(a,n,n-1,i,i);
        }
        int lol=0;
        FOR(i,n)
        {
            FOR(j,n)
            {
                if(b[i][j]==1)
                lol++;
                b[i][j]=0;
            }
        }
        cout << lol << "\n";
    }
}
