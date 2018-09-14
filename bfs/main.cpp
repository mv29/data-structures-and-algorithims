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

vector <int> a[100000]; //it is an array of vectors
bool b[10000];
int l[100000];
int main()
    {
        ios_base::sync_with_stdio(false);  cin.tie(0);cout.tie(0);
        int x, y, n,e;
        cin >> n;
        int i=n-1;
        while(i--)
        {
                cin >> x >> y;
            a[x-1].push_back(y);
             a[y-1].push_back(x);
         }
         queue<int> c;
         c.push(1);
         b[0]=1;
         l[0]=0;
         while(!c.empty())
         {
             int p=c.front();
             c.pop();
                        for(int j=0;j<a[p-1].size();j++)
                        {
                            x=a[p-1][j];
                            if(b[x]==0)
                            {
                             b[x]=1;
                             l[x]=l[p-1]+1;
                             c.push(a[x);
                            }
                        }
        }
        cin >> x;
        y=0;
        for(i=0;i<=n;i++)
        {
            if(l[i]==x-1)
             y++;
        }
        cout << y << "\n";
    return 0;
    }
