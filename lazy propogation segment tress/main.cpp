
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
#define  M           500002
#define INF          1001001001

int t[4*M];
int l[4*M];
int a[M];
void st(int i,int s,int e)
{
    if(s>e)
    return ;
    if(s==e)
    {
     t[i]=a[s];
     return;
    }
    int k= (s+e)/2;
    st(2*i,s,k);
    st(2*i+1,k+1,e);
    t[i]=t[2*i]+t[2*i+1];
}
void update(int i,int s,int e,int n,int m)// odd on , even off vlaue of segment
{//tree
    if(l[i]!=0) // node is not updated
    {
        if(l[i]%2==1)
        {
             t[i]=e-s+1-t[i];
        }
        if(s!=e)
        {
         l[2*i]+=l[i];
         l[2*i+1]+=l[i];
        }
        l[i]=0;
      //  return ;
    }
    if(s>e || e<n|| s>m)
    return;
    //cout << s << " " << e << " " << n << " " << m<< "\n";
    if(s>=n && e<=m)// total overlap or fully within range
    {

     //   cout << s << " " << e << " " << t[i] << "\n";
        t[i]=e-s+1-t[i]; // update the value of the node
        if(s!=e) // to check if the node is leaf or not
        {
         l[2*i]+=1;  //  update the lazy index of children
         l[2*i+1]+=1; //  rather than traversing to update them
        }
        return;
    }
    int k=(s+e)/2;
    update(2*i,s,k,n,m);
    update(2*i+1,k+1,e,n,m);
    t[i]=t[2*i]+t[2*i+1];
}
int sum(int i,int s,int e,int n,int m) // n lower and m upper index of given range
{
    if(s>e || e<n || s>m)
    return 0;
     if(l[i]!=0)
    {
        if(l[i]%2==1)
        {
            t[i]=e-s+1-t[i];
        }
        if(s!=e)
        {
         l[2*i]+=l[i];
         l[2*i+1]+=l[i];
        }
        l[i]=0;
      //  return ;
    }
    if(s>=n && e<=m)// total overlap
    {
       return t[i];
    }
    int k=(s+e)/2;
    int s1=sum(2*i,s,k,n,m);
    int s2=sum(2*i+1,k+1,e,n,m);
    return  s1+s2;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,q,i,j,k;
    cin >> n ;
    //st(1,1,n);
    cin >> m;
    while(m--)
    {

    }
    return 0;
}
