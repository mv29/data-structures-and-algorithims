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

    n=sz(level);

    int LOG[n+1];
    LOG[1] = 0;
    for (int i = 2; i <= n; i++)
    LOG[i] = LOG[i/2] + 1;

    int K=log2(n)+1;
    int st[n][K]; // storing the index of the minimum element

    for (int i = 0; i < n; i++)
    st[i][0] = i;

    for (int j = 1; j <= K; j++)
   {
       for (int i = 0; i + (1 << j) -1< n; i++)
      {
            if(level[st[i][j-1]]<level[st[i + (1 << (j - 1))][j - 1]])
            st[i][j]= st[i][j-1];
            else
            st[i][j]= st[i + (1 << (j - 1))][j - 1];
      }
   }
     FOR(i,n)
     cout << level[i] << " ";
     cout << "\n";

     FOR(i,n)
     {
        FOR(j,K)
        cout << st[i][j] << " ";
        cout << "\n";
     }
    int l,r,l1,r1;
    while(q--)
    {
        cin >>l >> r;
        l1=l;
        r1=r;
        l=occurence[l];
        r=occurence[r];
        if(l==r)
        {
            cout << "no\n";
        }
        else
        {
        if(l>r)
        swap(l,r);

        x = LOG[r - l + 1];
        cout << x << " " << l << " " << r << "\n";
        cout  << st[l][x] << " " << st[r - (1 << x) + 1][x] << " " << level[st[l][x]] << " " << level[st[r - (1 << x) + 1][x]] << "\n";
        if(level[st[l][x]]<=level[st[r - (1 << x) + 1][x]])
        {
            if(euler[st[l][x]]==l1 || euler[st[l][x]]==r1)
                cout << "YES\n";
            else
                cout << "no\n";
        }
        else
        {
             if(euler[st[r - (1 << x) + 1][x]]==l1 || euler[st[r - (1 << x) + 1][x]]==r1)
                cout << "YES\n";
            else
                cout << "no\n";
        }
        }
    }
    return 0;
}
