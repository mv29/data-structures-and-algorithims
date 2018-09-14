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
vector< ii> a[M]; // first vertex , second edge
bool b[M];
long long int d[M];
\
int p[M];
// this code is for bidirectional or undirectional edges
void bfs(int x)
{
    deque<int> c;
    c.push_back(x);
    d[x]=0;
    while(!c.empty())
    {
        int y=c.front();
        c.pop_front();
      for(int i=0;i<a[y].size();i++)
      {
        int m=a[y][i].fi; // vertex
        int v=a[y][i].se; // weight of edge
      if(d[y]+v<=d[m])
       {
         d[m]=d[y]+v;

         if(v==0) // same level
         {
            c.push_front(m);
         }
          else // one level below
          {
            c.push_back(m);
         }
       }
    }
  }
}
int main()
{
    ios_base::sync_with_stdio(false);
    int n,m,i,j;
    cin >> n >> m ;
    int x,y;
    while(m--)
    {
        cin >> x >>y;
        a[x].pb(mp(y,1));
        a[y].pb(mp(x,1));
    }
    FORK(i,0,M)
    d[i]=INF;
    bfs(1);
    i=4;
    while(i!=0)
        cout << i << " ";
        i=p[i];
    }
    return 0;
}
