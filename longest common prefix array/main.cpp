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
#define  M           1010
#define INF          1001001001

struct ss{
 int id;
 int r1;
 int r2;
};
ss a[M];
int cmp(ss x, ss y)
{
    if(x.r1==y.r1)
    {
        if(x.r2<y.r2)
            return 1;
        else if(x.r2==y.r2)
        {
            if(x.id<y.id)
                return 1;
            else
                return 0;
        }
        else
        return 0;

    }
    else
    {
       if(x.r1<y.r1)
         return 1;
        else
         return 0;
    }
}
vi suffix_array(string s,int n) // string and its size as argument
{
    int i,j;
    FOR(i,n)
    {
      a[i].id=i;
      a[i].r1=s[i]-'a';   // assigning rank1 according to first character of the suffix
      if(i+1>n-1)         // assigning rank2
        a[i].r2=-1;       // for last suffix
      else
        a[i].r2=s[i+1]-'a';
    }
    sort(a,a+n,cmp);
    int ind[n]={0}; //  store the rank of a particular index
    for(int k=4;k<=2*n;k*=2)
    {
        int pr=a[0].r1;// pr = previous rank
        a[0].r1=0;
        ind[a[0].id]=0;
        FORK(i,1,n-1)
        {
            if(a[i].r1==pr && a[i].r2==a[i-1].r2 )
            {
                pr=a[i].r1;
                a[i].r1=a[i-1].r1;
            }
            else
            {
                pr=a[i].r1;
                a[i].r1=a[i-1].r1+1;
            }
            ind[a[i].id]=a[i].r1;
        }
        FOR(i,n)
        {
            int m=a[i].id+(k)/2;
            if(m>n-1)
                a[i].r2=-1;
            else
             a[i].r2=ind[m];
        }
        sort(a,a+n,cmp);
    }
    vi sa;

    FOR(i,n)
     sa.pb(a[i].id);
     return sa;
}
vector<int> kasai(string s, vector<int> sa)
{
    int n=s.size(),k=0;
    vector<int> lcp(n,0);
    vector<int> rank(n,0);
    int i;
    for(int i=0; i<n; i++){
            rank[sa[i]]=i;
    }
    FOR(i,n)
    cout << rank[i] << " ";
     cout << "\n";
    for(int i=0; i<n; i++)
    {
        if(rank[i]==n-1) {k=0; continue;}
        int j=sa[rank[i]+1];
        while(i+k<n && j+k<n && s[i+k]==s[j+k])
        {
            k++;
        }
        cout << "\n";
        cout << k << "\n";
        lcp[rank[i]]=k;
        if(k>0)
            k--;
    }
    return lcp;
}int main()
{
    ios_base::sync_with_stdio(false);  cin.tie(0);
    string s;
    int n,i,j;
    cin >> s;
    n=sz(s);
    vi sa=suffix_array(s,n);
    FOR(i,sz(sa))
    cout << sa[i]<<" ";
    cout <<"\n";
    vi lcpa=kasai(s,sa);
    FOR(i,sz(lcpa))
    cout << lcpa[i] << " ";

    return 0;
}
