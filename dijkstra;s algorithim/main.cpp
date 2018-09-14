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
vii a[M];
int d[M];
bool b[M];
int pa[M];
void dijkstra(int so)
{
    memset(b,false,sizeof(b));
    d[so]=0;
    multiset<ii> s; // working as our priority queue
    s.insert(mp(0,so)); // starting form source vertex

    while(!s.empty())
    {
        ii p= *s.begin();
        s.erase(s.begin());
        int x =p.se;
        if(b[x]==true) // checking if vertex has been visited or not
            continue;
        b[x]=true;
        for(unsigned int i=0;i<a[x].size();i++) // traversing the adjacent vertices of a vertex
        {
            int e=a[x][i].se;
            int w=a[x][i].fi;
            if(d[x]+w<d[e]) // checking their if it is less than their current sending them in priority queue
            {
             pa[e]=x; // parent of e in its shortest distance path
             d[e]=d[x]+w;
             s.insert(mp(d[e],e));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m;
    cin >> n >> m;
    int x,y,w,i;
     FOR(i,M)
    {
        a[i].clear();
    }
    while(m--)
    {
        cin >> x >>y >> w;
        a[x].pb(mp(w,y));
        a[y].pb(mp(w,x));
    }
    FORK(i,1,n)
     d[i]=INF;
    dijkstra(1);
    FORK(i,2,n)
    cout << d[i] << " ";

    return 0;
}
