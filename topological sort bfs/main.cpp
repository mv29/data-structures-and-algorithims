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
vi t;
int v[M];
void bfs_t(int n)
{
    int i,j;
    FORK(i,1,M)
    {
        b[i]=0;
        v[i]=0;
    }
    FORK(i,1,n)
    {
       // cout << i << " " << v[i] << "\n";
        FOR(j,a[i].size())
       {
         //  cout << a[i][j] << " ";
        v[a[i][j]]=v[a[i][j]]+1;
        // cout << v[a[i][j]] << "\n";
       }
    }
   /* cout << "\n";
    FORK(i,1,n)
    cout << v[i] << " ";
    cout << "\n"; */
    priority_queue<int,vi,greater<int> > c;
    FORK(i,1,n)
    {
        if(v[i]==0)
           {
            c.push(i);
            b[i]=true;
           }
    }
    while(!c.empty())
    {
        int x=c.top();
        c.pop();
        t.push_back(x);
        //cout << x << "\n";
        FOR(i,a[x].size())
        {
            int y=a[x][i];
            if(b[y]==false)
            {
                v[y]=v[y]-1;
                if(v[y]==0)
                {
                 c.push(y);
                 b[y]=true;
                }
            }
        }
    }
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
    bfs_t(n);
    FORK(i,0,n-1)
    cout << t[i] << " ";
    return 0;
}
