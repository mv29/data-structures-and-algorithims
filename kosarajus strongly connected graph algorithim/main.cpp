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
#define MOD          1000000007

using namespace std;
vector <int> a1[1000001]; //it is an array of vectors
vector <int> a2[1000001];
bool b[1000001];
stack<int> c;
int ans=0;
void dfs1(int m)
{
    b[m]=true;
    for(int i=0;i<a1[m].size();i++)
    {
        if(b[a1[m][i]]==false)
        {
            ans++;
            dfs1(a1[m][i]);
        }
    }
    c.push(m);
}
void dfs2(int m)
{
    b[m]=true;
    ans++;
    for(int i=0;i<a2[m].size();i++)
    {
        if(b[a2[m][i]]==false)
        {
            dfs2(a2[m][i]);
        }
    }
}
int main()
    {
        int x,y,n,j,i,m;
        cin >> n >> m;
        int odd=0,even=0;
        while(m--)
        {
         cin >> x >> y;
         a1[x].push_back(y);
         a2[y].push_back(x);
         }
         for(i=1;i<=n;i++)
         {
             if(b[i]==false)
                dfs1(i);
         }
         memset(b,false,sizeof(b));
         //cout << "\n";
         while(!c.empty())
         {
             x=c.top();
             ans=0;
             if(b[x]==false)
             {
              dfs2(x);
        //      cout << x << " " << ans << "\n";
             if(ans!=0 && (ans&1))
                odd=odd+ans;
             else
                even =even +ans;
             }
             c.pop();
         }
         //cout << odd << " " << even  <<" \n";
         odd=odd-even;
         cout << odd ;
    return 0;
}
