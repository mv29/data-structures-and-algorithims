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
#define B             break
#define C             continue
#define R             return

void kmp(string s,string p)
{
    int n=sz(p);
    int a[n]={0},i=1,j=0;
    while(1)
    {
        if(i==n)
          break;
         if(j==0 && p[j]!=p[i])
            {
                a[i]=0;
                i++;
            }
        else if(j>0 && p[j]!=p[i])
        {
            while(1)
            {
                if(j==0 || p[j]==p[i])
                {
                    if(j>0)
                    a[i]=j+1;
                    else
                    a[i]=0;
                    break;
                }
                j=a[j-1];

            }
            i++;
        }
        else if(p[j]==p[i])
        {
            j++;
            a[i]=j;
            i++;
        }
    }
    i=0;// string
    j=0; // pattern
    int flag=0;
    while(1)
    {
        if(j==sz(p))
        flag++;
        if(i==sz(s))
            break;
        if(s[i]==p[j])
        {
            j++;
            i++;
        }
        else if(j==0 && s[i]!=p[j])
            i++;
        else if(j>0 && s[i]!=p[j])
        {
            j=a[j-1];
        }
    }
    cout << flag ;
}
int main()
{
    ios_base::sync_with_stdio(false);
    string s,p;
    cin >> s >> p;
    kmp(s,p);
    return 0;
}
