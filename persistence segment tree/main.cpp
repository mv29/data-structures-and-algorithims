#include <bits/stdc++.h>
using namespace std;
/*------- Constants---- */

#define Long                    long long
#define Ulong                   unsigned long long
#define forn(i,n)               for( int i=0 ; i < n ; i++ )
#define mp(i,j)                 make_pair(i,j)
#define pb(a)                   push_back((a))
#define all(x)                  (x).begin(),(x).end()
#define gc                      getchar_unlocked
#define PI                      acos(-1.0)
#define EPS                     1e-9
#define xx                      first
#define yy                      second
#define lc                      ((n)<<1)
#define rc                      ((n)<<1|1)
#define db(x)                   cout << #x << " -> " << x << endl;
#define Di(x)                   int x;scanf("%d",&x)
#define min(a,b)                ((a)>(b) ? (b) : (a) )
#define max(a,b)                ((a)>(b) ? (a):(b))
#define ms(ara_name,value)      memset(ara_name,value,sizeof(ara_name))

/*************************** END OF TEMPLATE ****************************/

const int N = 5e5+5;
int n,q;
int a[N],b[N];
int sz;
vector<int>v;
int root[N]; // storing the root of i segment tree
struct Node
{
 int ls,rs,cnt;
}
node[N*20];
void update(int &n,int pre,int b,int e,int pos)
{
    n = ++sz;
    node[n] = node[pre];
    if(b==e && b== pos) {
        node[n].cnt ++;
        node[n].ls = node[n].rs = 0;
        return;
    }
    int mid = (b+e) >> 1;
    if(pos<= mid) update(node[n].ls, node[pre].ls, b, mid,pos);
    else update(node[n].rs, node[pre].rs, mid+1,e,pos);
    node[n].cnt = node[node[n].ls].cnt + node[node[n].rs].cnt;
}

int query(int r1,int r2, int b,int e,int x )
{
    if(b==e) return b;
    int oo = node[node[r1].ls].cnt - node[node[r2].ls].cnt;
    int mid = (b+e)>>1;
    if(oo >= x) return query(node[r1].ls, node[r2].ls,b, mid,x);
    else return query(node[r1].rs , node[r2].rs, mid+1,e,x - oo );
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> q;

    for(int i = 1; i <= n; i ++ )
    {
    cin >> a[i];
        v.pb(a[i]);
    }

    sort(all(v));

    for(int i = 1;i <= n; i ++ ) {
        a[i] = lower_bound(all(v),a[i]) - v.begin() + 1;
    }
    int S = v.size();
    update(root[1], 0, 1, S,a[1]); // 0 -> is the initial empty segment tree

    for(int i = 2; i <= n; i ++ )
    update(root[i], root[i-1],1,S,a[i]);

    while(q--)
    {
        int l,r,x;
       cin >> l >> r  >> x;
        int k = query(root[r], root[l-1], 1,S,x);
       cout << v[k-1] << "\n";
    }
    return 0;
}
