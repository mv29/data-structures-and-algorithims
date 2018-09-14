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
#define INF          1000000007

vi a[2*M]; //  an array of vector of pairs
bool v[2*M];
vi euler; // euler and level indexing starts from '0'
vi level; // nodes starts from '1' and level starts from '1'
int occurence[2*M];;
void dfs(int x,int l)
{
    v[x]=true;
    int i;
    euler.pb(x);
    level.pb(l);
    occurence[x]=sz(euler)-1;
    FOR(i,sz(a[x]))
    {
        int y=a[x][i];
        if(v[y]==false)
         {
           dfs(y,l+1);
           euler.pb(x);
           level.pb(l);
         }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,q,i,j,m,x,y;
    cin >> n >> q;
    FOR(i,n-1)
    {
        cin >> x >> y;
        a[x].pb(y);
        a[y].pb(x);
    }
    dfs(1,0);
    // preprocessing
    int len = (int) sqrt (sz(level) + .0) + 1; // size of the block and the number of blocks
    vector<int> b (len,INF); // storing min in b
    vector<int> indexs (len); // storing index in indexes
    for (int i=0; i<sz(level); ++i)
    {
        if(b[i / len]<level[i])
        {
            indexs[i/len]=i;
        }
        b[i / len] = min(level[i],b[i / len]);
    }
    int l,r,l1,r1;
    while(q--)
    {
        cin >> l >> r;
           if(l==r)
           cout <<"no\n";
           else{
           l1=l;r1=r;
           l=occurence[l];
           r=occurence[r];
           if(l>r)
            swap(l,r);
           int ans = INF;
           int index;
           int c_l = l / len,   c_r = r / len;
           if (c_l == c_r)
           {
               for (int i=l; i<=r; ++i)
             {
               if(level[i]<ans)
               {
                   index=i;
                   ans= min(level[i],ans);
               }
             }
           }
           else
           {
           for (int i=l, end=(c_l+1)*len-1; i<=end; ++i)
           {
             if(level[i]<ans)
               {
                   index=i;
                   ans= min(level[i],ans);
               }
           }
           for (int i=c_l+1; i<=c_r-1; ++i)
           {
               if(b[i]<ans)
               {
                 index=indexs[i];
                 ans= min(b[i],ans);
               }
           }
            for (int i=c_r*len; i<=r; ++i)
            {
                if(level[i]<ans)
               {
                   index=i;
                   ans= min(level[i],ans);
               }

            }
          }
           if(euler[index]==l1 || euler[index]==r1)
           cout << "YES\n";
           else
           cout << "no\n";
           }
        }
return 0;
}
