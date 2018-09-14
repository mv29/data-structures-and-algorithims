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
#define  M           100002
#define INF          1001001001
int main()
{
   int n,i,j,q;
   cin >> n >> q;
   int a[n];
   FOR(i,n)
   cin >> a[i];

   // preprocessing
    int len = (int) sqrt (n + .0) + 1; // size of the block and the number of blocks
    vector<int> b (len,INF);
    for (int i=0; i<n; ++i)
    b[i / len] = min(a[i],b[i / len]);

    int l,r;
    char c;
    /** range minimum part is correct but getting wrong answer for the RMQ question on Hackerearth **/
    while(q--)
    {
        cin >> c >> l >> r;
        l--;r--;
        if(c=='q')
        {
           int ans = INF;
           int c_l = l / len,   c_r = r / len;
           if (c_l == c_r)
           for (int i=l; i<=r; ++i)
           ans= min(a[i],ans);
           else
           {
           for (int i=l, end=(c_l+1)*len-1; i<=end; ++i)
           ans= min(a[i],ans);
           for (int i=c_l+1; i<=c_r-1; ++i)
           ans= min(b[i],ans);
           for (int i=c_r*len; i<=r; ++i)
           ans= min(a[i],ans);
           }
           cout << ans << "\n";
        }
        else
        {
         a[l]=r;
         b[l/len]=min(b[l/len],r);
        }
    }

}
