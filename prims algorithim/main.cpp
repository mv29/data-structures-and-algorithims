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

typedef pair< ll, int> PII;
bool marked[M];
vector <PII> a[M];
int p[M];
int ans=-1;
long long prim(int x)
{
    priority_queue<PII, vector<PII>, greater<PII> > Q;
    int y;
    long long minimumCost = 0;
    PII p;
    Q.push(make_pair(0, x));
    while(!Q.empty())
    {
        p = Q.top();
        Q.pop();
        x = p.second;
        if(marked[x] == true)
            continue;
        ans=max(ans,p.first);
        minimumCost += p.first;
        marked[x] = true;
        for(int i = 0;i < a[x].size();++i)
        {
            y = a[x][i].second;
            if(marked[y] == false)
              {
                  p[y]=x;
                Q.push(a[x][i]);
              }
        }
    }
    return minimumCost;
}

int main()
{
    int n, m, x, y;
    long long weight, minimumCost;
    cin >> n >> m;
    for(int i = 0;i < m;++i)
    {
        cin >> x >> y >> weight;
        a[x].push_back(make_pair(weight, y));
        a[y].push_back(make_pair(weight, x));
    }
    minimumCost = prim(1);
    cout << minimumCost-ans << endl;
    return 0;
}
