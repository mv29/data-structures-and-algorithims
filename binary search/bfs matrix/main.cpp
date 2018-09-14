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
/*
void lol()
{
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
                            if(b[a[p-1][j]-1]==0)
                     {
                             b[a[p-1][j]-1]=1;
                             l[a[p-1][j]-1]=l[p-1]+1;
                             c.push(a[p-1][j]);
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

}*/
int main()
{
        ios_base::sync_with_stdio(false);  cin.tie(0);
        int n,m,k,i,j;
        cin >> n >> m >> k;
        int a[n][m];
        int ans=0;
        FOR(i,n){
        FOR(j,m)
        {
            cin >> a[i][j];
            if(a[i][j]==1)
            ans++;
        }
        }
   //     cout << ans << "\n";
        while(k--)
        {
            int x1,y1;
            cin >>x1 >>y1;
            x1--;y1--;
            if(a[x1][y1]==1)
            {
             queue< ii > c;
             int b[n][m]={{0}};
             c.push(mp(x1,y1));
             b[x1][y1]=1;
             int mv=0;
             while(!c.empty())
             {
                 ii p=c.front();
                 c.pop();
                 int x=p.fi;
                 int y=p.se;
                 a[x][y]=0;
                 mv++;
                 if(x>0 && a[x-1][y]!=0)
                 {
                     if(b[x-1][y]==0)
                     {
                         b[x-1][y]=1;
                         c.push(mp(x-1,y));
                     }
                 }
                 if(x<n-1 && a[x+1][y]!=0)
                 {
                     if(b[x+1][y]==0)
                     {
                         b[x+1][y]=1;
                         c.push(mp(x+1,y));
                     }
                 }
                 if(y>0 && a[x][y-1]!=0)
                 {
                     if(b[x][y-1]==0)
                     {
                         b[x][y-1]=1;
                         c.push(mp(x,y-1));
                     }
                 }
                 if(y<m-1 && a[x][y+1]!=0)
                 {
                     if(b[x][y+1]==0)
                     {
                         b[x][y+1]=1;
                         c.push(mp(x,y+1));
                     }
                 }
             }
             ans-=mv;
             cout << ans << "\n";
            }
            else
            cout << ans << "\n";
        }
    return 0;
    }
