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
#define J            100001
vector<int> a[J]; //it is an array of vectors
bool b[J];
 long int c[J];
 long int d[J];
long int l[J];
 long int p[J];
 bool ar[J];
 stack< pair <int,int> > mv;
 long int k;
 long int t;
 int odd=0,even=0;
void dfs( int s, int t)
{
    b[s] = true;
    int children=0;
     d[s]=t+1;
     l[s]=t+1;
    for( int i = 0; i< a[s].size();++i)
    {
        int j=a[s][i];
     if(b[j] == false)
      {
       mv.push(make_pair(s,j));
      children++;
      p[a[s][i]]=s;
      dfs(a[s][i],t+1);
      l[s]=min(l[s],l[a[s][i]]);
       if((p[s]==-1 && children>1) || p[s]!=-1 && (l[a[s][i]]>=d[s]))
       {
           set<int> node;
            ar[s]=true;
            while(mv.top().first!=s && mv.top().second!=j)
            {
                node.insert(mv.top().first);
                node.insert(mv.top().first);
                mv.pop();
            }
                node.insert(mv.top().first);
                node.insert(mv.top().first);
                mv.pop();
                if(node.size()!=0 && node.size()&1)
                    odd++;// biconnected components with odd no of vertices
                else
                    even++; // biconnected components with even no of vertices
       }
     }
      else if(a[s][i]!=p[s])
      l[s]=min(l[s],d[a[s][i]]);
    }
}
void initialize()
{
    for( int i = 0;i <J;++i)
    {
        ar[i]=false;
        d[i]=0;
        l[i]=1000;
        p[i]=-1;
        b[i] = false;
    }
}
int main()
    {
       ios_base::sync_with_stdio(false);
        k=0;
        t=0;
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
            dfs(i,0);
         }
         cout << odd <<" " << even;
         int ans=odd+even; // total no of biconnected components
    return 0;
    }
