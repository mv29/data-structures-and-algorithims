
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
#define  M           10001
#define INF          1001001001
int d[M];
void dijkstra1(int so,vector< vi > &a ,int n)
{
    int i;
    FOR(i,M)
    d[i]=INF;
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
        for(i=0;i<n;i++) // traversing the adjacent vertices of a vertex
        {
            int e=i;
            int w=a[x][i];
            if(d[x]+w<d[e]) // checking their if it is less than their current sending them in priority queue
            {
             d[e]=d[x]+w;
             s.insert(mp(d[e],e));
            }
        }
    }
}
void dijkstra1(int so,vector< vi > &a ,int n)
{
    int i;
    FOR(i,M)
    d[i]=INF;
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
        for(i=0;i<n;i++) // traversing the adjacent vertices of a vertex
        {
            int e=i;
            int w=a[x][i];
            if(d[x]+w<d[e]) // checking their if it is less than their current sending them in priority queue
            {
             d[e]=d[x]+w;
             s.insert(mp(d[e],e));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,i,j;
    vector< vi > road(n,vi(n)),rail(n,vi(n));
    FOR(i,n)
    FOR(j,n)
    cin >> road[i][j];
    FOR(j,n)
    cin >> rail[i][j];
    int road1[n],road2[n],rail1[n],rail2[n];

    return 0;
}
