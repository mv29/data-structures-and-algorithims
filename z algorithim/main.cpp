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

#define fi           first
#define se           second
#define pb           push_back
#define mp           make_pair
#define  M           100001
#define INF          1001001001
#define B             break;
#define C             continue;
#define  M           100001
#define INF          1001001001
#define R             return
void Z(string s, string p)
{
    int i,j;
    string a;
    a.insert(0,p);
    a.pb('$');
    a.insert(sz(p)+1,s);
    int z[sz(a)];
    z[0]=0;
    int L = 0, R = 0;
   for(int i = 1; i < sz(a); i++)
    {
     if (i > R)
     {
      L = R = i;
      while(R < sz(a) && a[R-L] == a[R]) R++;
       z[i] = R-L; R--;
     } else
     {
      int k = i-L;
      if (z[k] < R-i+1) z[i] = z[k];
     else
    {
      L = i;
      while (R < sz(a) && a[R-L] == a[R]) R++;
      z[i] = R-L; R--;
     }
    }
  }
  int flag=0;
  FOR(i,sz(a))
  {
    if(z[i]==sz(p))
    flag++;
  }
  cout << flag;
}

int main()
{
    ios_base::sync_with_stdio(false);
    string s,p;
    cin >> p >> s;
    Z(s,p);
    return 0;
}
