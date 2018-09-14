#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
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
vector<int> a[100001]; //it is an array of vectors
bool b[1000001]; // array to keep track of the vertices
 int c[1000001];
 int d[1000001]; // this array stores the discovery time of each vertex
 int l[1000001]; // this array stores the ancestor with which it or any vertex in its subtree has a back edge
 int p[1000001]; // stores the parent of each vertex
 bool ar[1000001]; // ar is true if the vertex at that index is a articulation point
 vector<int> h[1000001];
 int k;
 int t;
 int q;
void dfs(int s,int v, long int t)
{
    b[s] = true;
    int children=0; // counts the children of s
     d[s]=t+1;
     l[s]=t+1;
    for(int i = 0; i< a[s].size();++i)
    {
     if(b[a[s][i]] == false)
      {
      children++;
      p[a[s][i]]=s;
      dfs(a[s][i],v,t+1); // dfs call
      l[s]=min(l[s],l[a[s][i]]);
     if(p[s]==-1 && children>1) // checking for root
        {
            ar[s]=true;
        }
      if(p[s]!=-1 && l[a[s][i]]>=d[s]) // this means no children of s is  connected to any vertex which is discovered before s
       {
        ar[s]=true;
       }
      }
      else if(a[s][i]!=p[s])
      {
          l[s]=min(l[s],d[a[s][i]]);
      }
    }
}
void initialize()
{
    for(int i = 0;i <1000001;++i)
    {
        ar[i]=false;
        d[i]=0;
        l[i]=100000000;
        p[i]=-1;
        b[i] = false;
    }
}
/***a Back Edge is an edge that connects a
vertex to a vertex that is discovered before it's parent.***/
int main()
    {
       ios_base::sync_with_stdio(false);
        k=0;
        t=0;
        q=0;
        int x, y, n,m,i,r=0;
        cin >> n >> m;
        initialize();
        while(m--)
        {
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
         }
         for(i=0;i<n;i++)
         {
             if(b[i]==false)
            dfs(i,n,0);
         }
         cout << k << "\n";
    return 0;
    }
