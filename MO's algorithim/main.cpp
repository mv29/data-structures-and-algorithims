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
// indexing starts from one
int BLOCK_SIZE;
ll ans=0;
inline bool cmp(const pair< pair<int, int>, int> &x, const pair< pair<int, int>, int> &y)
{
    int block_x = x.first.first / BLOCK_SIZE;
    int block_y = y.first.first / BLOCK_SIZE;
    if(block_x != block_y)
    return block_x < block_y;
    return x.first.second < y.first.second;
}
int f[1000005];
pair< ii ,int > qu[200001];
/*void add(int x)
{
    f[x]++;
    if(f[x]==1)
        ans++;
}
void sub(int x)
{
    f[x]--;
    if(f[x]==0)
        ans--;
}*/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,i,j,q;
    cin >> n;
    BLOCK_SIZE= (int)ceil(sqrt(n));
    int a[n];
    FOR(i,n)
    cin >> a[i];
    cin >>q;
    int mv[q+1];
    FOR(i,q)
    {
        cin >> qu[i].fi.fi >> qu[i].fi.se ;
        qu[i].se=i;
    }
    int l=0,r=-1;
    sort(qu,qu+q,cmp);
    FOR(i,q)
    {
        int left=qu[i].fi.fi;
        int right=qu[i].fi.se;
       // cout << i << " " << q << " " << l << " " << r  << " " << left << " " << right << "\n";
        while(r<right-1)
        {
            r++;
         //   cout <<r << " " << a[r] << "\n";
        //    add(a[r]);
         f[a[r]]++;
         if(f[a[r]]==1)
         ans++;
        }
        while(r>right-1)
        {
            //sub(a[r]);
        f[a[r]]--;
       if(f[a[r]]==0)
        ans--;
            r--;
        }
        while(l<left-1)
        {
           //sub(a[l]);
         f[a[l]]--;
        if(f[a[l]]==0)
        ans--;
            l++;
        }
        while(l>left-1)
        {
            l--;
             f[a[l]]++;
         if(f[a[l]]==1)
         ans++;
        //    add(a[l]);
        }
        //cout << ans << " " << qu[i].se << "\n";
        mv[qu[i].se]=ans;
    }
    FOR(i,q)
    cout << mv[i] << "\n";
    return 0;
}
