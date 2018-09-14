#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii; // vector of pairs
typedef vector<int> vi; // vector of int
typedef vector<ll> vll; // vector of long long int
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

vii a[M]; //it is an array of vectors
bool b[M];
map<int,int> c; // map for storing the parent of a vertex , for tracing back the route
int help;
int ans=0;
void bfs(vector<vi> &d,int n);
void flow(int x,vector<vi> &d,int n)
{
    // cout << "boobs\n";
   int i=c[x];
   int j=n;
   help=INF;
   while(i!=0)   // finding the minimum capacity
   {
      // cout << i << " " << d[i][j] << "\n";
       help=min(help,d[i][j]);
        j=i;
       i=c[i];
   }
   //cout << "i will beat my self\n";
   //cout << help << "\n";
   ans=ans+help;
   i=c[x];
   j=n;
   while(i!=0)
   {
     //  cout << i << " " << d[i][j] << "\n";
       d[i][j]-=help;
       d[j][i]+=help;
       j=i;
       i=c[i];
   }
   FOR(i,M)
   {
    b[i]=false;
   }
   c.clear();
   //cout << "mom and dad\n";
   bfs(d,n);
}
void bfs(vector<vi> &d,int n)
{
    queue<int>f;
    f.push(1);
    b[1]=1;
   // cout << "mrinal\n";
    c[1]=0; // declaration of parent of our first node
     while(!f.empty())
         {
             int p=f.front();
             f.pop();
     //       cout << "\n" << p << "\n";
            for(unsigned int j=0;j<a[p].size();j++)
            {
                    int x=a[p][j].first;
         //           cout << x << " ";
                    int y=d[p][x];
                    if(b[x]==0 && y>0 )
                    {
                             c.insert(make_pair(x,p));
                             if(x==n)
                             {
       //                     cout << "hello baby" << "\n";
                            flow(x,d,n);
                            return;
                             }
                             b[x]=1;
                           f.push(x);
                    }
            }

        }
}
int main()
{
    int t;
    cin >> t;
    while(t--)
        {
            ans=0;
        int x,y,n,m,w,i,j;
        cin >> n >> m;
        vector<vi> d(n+1,vi (n+1,0)); // 2d vector for storing the residual capacity of each edge ,it is an (n+1)*(n+1) matrix as my initial node will be 1
        while(m--)
        {
            cin >> x >> y >> w;
            a[x].push_back(make_pair(y,w)); // first-> neighbor  second->weight
          //  a[y].push_back(make_pair(x,0));
            d[x][y]=w;
         }
        FOR(i,n+1)
         {
             cout << i << "\n";
             FOR(j,n+1)
             cout << d[i][j] << " ";
             cout << "\n";
         }
         bfs(d,n);
         cout << ans << "\n";
        }
    return 0;
}
