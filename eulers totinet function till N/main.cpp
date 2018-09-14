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
 void euler(int x)
 {
     int i,j,a[x+1];
     FORK(i,0,x)
     a[i]=i;
     for(i=2;i<=x;i++)
     {
         //cout << i << " " << a[i] << "\n";
         if(a[i]==i)
         {
             a[i]=i-1;
             for(j=2*i;j<=x;)
             {
                 a[j]=(a[j]/i)*(i-1);
                 j=j+i;
             }
         }
     }
     FOR(i,x+1)
     cout << a[i] << " ";
 }

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    euler(n) ;
    return 0;
}
