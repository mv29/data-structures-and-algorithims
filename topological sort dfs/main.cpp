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
vi a[M];
bool b[M];
stack<int> c;
void dfs(int x)
{
    b[x]=true;
    for(int i=0;i<sz(a[x]);i++)
    {
        int y=a[x][i];
        if(b[y]==false)
        {
            dfs(y);
        }
    }
    c.push(x);
}
int main()
{
    ios_base::sync_with_stdio(false);
    int n,m,i;
    cin >> n >> m;
    int x,y;
    for(i=1;i<=m;i++)
    {
        cin >> x >> y ;
        a[x].push_back(y);
    }
    for(i=n;i>0;i--)
    {
    if(b[i]==false)
            {
                dfs(i);
            }
    }
    while(!c.empty())
    {
        x=c.top();
        cout << x << " ";
        c.pop();
    }
    return 0;
}
